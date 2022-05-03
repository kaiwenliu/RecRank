#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

#include "csv.hpp"

#include "driver.hpp"
#include "pagerank.hpp"
#include "dijkstra.hpp"
#include "adjmatrix.hpp"
#include "bfs.hpp"

using namespace csv;
using std::vector;
using std::unordered_map;

const size_t NUM_NODES = 37700;
const bool DEBUG = false;

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

vector<pair<size_t, size_t>> small_edges() {
    // for testing
    /*
       (children nodes point in parent direction)
└── 2/
    ├── 1/
    │   ├── 0
    │   ├── 3
    │   └── 4
    └── 5
    */
    return {
        {1, 2},
        {0, 1},
        {3, 1},
        {4, 1},
        {5, 2},
    };
}

int main() {
    vector<pair<size_t, size_t>> edges = load_edges();
    /* vector<pair<size_t, size_t>> edges = small_edges(); */

    std::cout << "Loaded " << edges.size() << " edges" << std::endl;

    if (!is_connected(edges, NUM_NODES)) {
        std::cout << "Error: graph is not connected" << std::endl;
        return 1;
    }

    std::cout << "edges.size(): " << edges.size() << std::endl;

    // target node
    size_t start = 3;
    std::cout << "start node: " << start << std::endl;

    // run pagerank
    AdjacencyMatrix matrix(edges);
    PageRank pr(edges, matrix.getSize(), 0.85);
    vector<double> results = pr.result(start);

    if (DEBUG) {
        std::cout << "PageRank results:" << std::endl;
        for (size_t i = 0; i < results.size(); i++) {
            std::cout << i << ": " << results[i] << std::endl;
        }
    }

    // convert pagerank results to weights by averaging adjacent nodes
    vector<pair<pair<size_t, size_t>, double>> weighted_edges(edges.size());
    size_t num_nodes = matrix.getSize();
    for (size_t i = 0; i < edges.size(); i++) {
        double weight = results[edges[i].first] + results[edges[i].second];
        if (DEBUG) {
            std::cout << "weight: " << weight << std::endl;
        }
        // take the reciprocal because higher pagerank is better
        weighted_edges[i] = {edges[i], 1 / (1 + weight / 2)};
    }
    // convert to adjacency list
    vector<vector<pair<size_t, double>>> adjacency_list(num_nodes);
    for (const auto& edge : weighted_edges) {
        adjacency_list[edge.first.first].push_back({edge.first.second, edge.second});
        adjacency_list[edge.first.second].push_back({edge.first.first, edge.second});
    }

    if (DEBUG) {
        for (size_t i = 0; i < adjacency_list.size(); i++) {
            std::cout << "Node " << i << ": ";
            for (const auto& edge : adjacency_list[i]) {
                std::cout << edge.first << " (" << edge.second << ") ";
            }
            std::cout << std::endl;
        }
    }

    Dijkstra dijkstra(adjacency_list, start);
    vector<double> distances = dijkstra.generate();

    if (DEBUG) {
        for (size_t i = 0; i < distances.size(); i++) {
            std::cout << "Distance from " << start << " to " << i << ": " << distances[i] << std::endl;
        }
    }

    BFS bfs(adjacency_list, distances, start);
    vector<pair<double, size_t>> recommendations = bfs.generate();

    for (const auto& rec : recommendations) {
        std::cout << "Recomendation: " << rec.second << " (" << rec.first << ")" << std::endl;
    }

    return 0;
}
