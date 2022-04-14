#include <iostream>
#include <vector>
#include <unordered_map>

#include "csv.hpp"

#include "pagerank.hpp"
#include "dijkstra.hpp"

using namespace csv;
using std::vector;
using std::unordered_map;

int main() {
    // load edges
    CSVReader reader("data/edges.csv");
    std::vector<std::pair<int, int>> edges;
    for (CSVRow& row: reader) {
        int id_1 = row["id_1"].get<int>();
        int id_2 = row["id_2"].get<int>();
        std::pair<int, int> edge(id_1, id_2);
        edges.push_back(edge);
    }

    std::cout << "edges.size(): " << edges.size() << std::endl;

    // run pagerank
    PageRank pr(edges);
    vector<int> results = pr.result();

    int start = 0;
    // TODO: create adjacency matrix of bools
    vector<vector<bool>> connected;
    Dijkstra dijkstra(results, connected, start);

    return 0;
}
