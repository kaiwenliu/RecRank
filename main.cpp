#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

#include "csv.hpp"

#include "driver.hpp"
#include "pagerank.hpp"
#include "dijkstra.hpp"
#include "bfs.hpp"

using namespace csv;
using std::vector;
using std::unordered_map;
using std::string;

const size_t NUM_NODES = 37700;

vector<pair<size_t, size_t>> load_edges() {
    // load edges
    CSVReader reader("data/edges.csv");
    vector<pair<size_t, size_t>> edges;
    for (CSVRow& row: reader) {
        size_t id_1 = row["id_1"].get<size_t>();
        size_t id_2 = row["id_2"].get<size_t>();
        if (id_1 < NUM_NODES && id_2 < NUM_NODES) {
            pair<size_t, size_t> edge(id_1, id_2);
            edges.push_back(edge);
        }
    }
    return edges;
}

vector<string> load_names() {
    CSVReader reader("data/names.csv");
    vector<string> names;
    for (CSVRow& row: reader) {
        string name = row["name"].get<string>();
        names.push_back(name);
    }
    return names;
}

void print_usage(char* program_name) {
    std::cout << "Usage: " << program_name << " <github_username>" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2 || strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
        print_usage(argv[0]);
        return argc == 2 ? 0 : 1;
    }
    string username = argv[1];

    size_t start = NUM_NODES + 1;
    vector<string> names = load_names();
    // look for index of username
    for (size_t i = 0; i < names.size(); i++) {
        if (names[i] == username) {
            start = i;
            break;
        }
    }
    if (start == NUM_NODES + 1) {
        std::cout << "Username '" << username << "' not found" << std::endl;
        return 2;
    }

    vector<pair<size_t, size_t>> edges = load_edges();

    std::cout << "Loaded " << edges.size() << " edges" << std::endl;

    if (!is_connected(edges, NUM_NODES)) {
        std::cout << "Error: graph is not connected" << std::endl;
        return 1;
    }

    std::cout << "Analyzing connections..." << std::endl;

    // run pagerank
    PageRank pr(edges, NUM_NODES, 0.85);
    vector<double> results = pr.result();

    // convert pagerank results to weights by averaging adjacent nodes
    vector<pair<pair<size_t, size_t>, double>> weighted_edges(edges.size());
    size_t num_nodes = NUM_NODES;
    for (size_t i = 0; i < edges.size(); i++) {
        double weight = results[edges[i].first] + results[edges[i].second];
        // take the reciprocal because higher pagerank is better
        weighted_edges[i] = {edges[i], 1 / (1 + weight / 2)};
    }
    // convert to adjacency list
    vector<vector<pair<size_t, double>>> adjacency_list(num_nodes);
    for (const auto& edge : weighted_edges) {
        adjacency_list[edge.first.first].push_back({edge.first.second, edge.second});
        adjacency_list[edge.first.second].push_back({edge.first.first, edge.second});
    }

    Dijkstra dijkstra(adjacency_list, start);
    vector<double> distances = dijkstra.generate();

    size_t limit = 500;
    BFS bfs(adjacency_list, distances, start, limit);
    vector<pair<double, size_t>> recommendations = bfs.generate();

    size_t top_limit = 10;
    std::cout << "Top " << top_limit << " follower recommendations for " << username << ":" << std::endl;
    for (size_t i = 0; i < top_limit; i++) {
        const auto &rec = recommendations[i];
        printf("    %-20s (score: %.6g) (%lu)\n", names[rec.second].c_str(), rec.first, rec.second);
    }

    return 0;
}
