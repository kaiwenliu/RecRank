#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

#include "csv.hpp"

#include "driver.hpp"
#include "pagerank.hpp"
#include "dijkstra.hpp"
#include "adjmatrix.hpp"

using namespace csv;
using std::vector;
using std::unordered_map;

vector<pair<size_t, size_t>> load_edges() {
    // load edges
    CSVReader reader("data/edges.csv");
    vector<pair<size_t, size_t>> edges;
    for (CSVRow& row: reader) {
        int id_1 = row["id_1"].get<size_t>();
        int id_2 = row["id_2"].get<size_t>();
        pair<size_t, size_t> edge(id_1, id_2);
        edges.push_back(edge);
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
    /* vector<pair<size_t, size_t>> edges = load_edges(); */
    vector<pair<size_t, size_t>> edges = small_edges();

    AdjacencyMatrix matrix(edges);
    if (!is_connected(matrix)) {
        std::cout << "Graph is not connected" << std::endl;
        return 1;
    }

    std::cout << "edges.size(): " << edges.size() << std::endl;

    // run pagerank
    PageRank pr(edges, matrix.getSize(), 0.85);
    vector<double> results = pr.result(1);

    std::cout << "PageRank results:" << std::endl;
    for (size_t i = 0; i < results.size(); i++) {
        std::cout << i << ": " << results[i] << std::endl;
    }

    int start = 0;
    Dijkstra dijkstra(results, matrix, start);

    return 0;
}
