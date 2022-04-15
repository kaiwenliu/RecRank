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

#define SIZE 37700

int main() {
    // load edges
    CSVReader reader("data/edges.csv");
    std::vector<std::pair<size_t, size_t>> edges;
    for (CSVRow& row: reader) {
        int id_1 = row["id_1"].get<size_t>();
        int id_2 = row["id_2"].get<size_t>();
        std::pair<size_t, size_t> edge(id_1, id_2);
        edges.push_back(edge);
    }

    AdjacencyMatrix matrix(edges);
    if (!is_connected(matrix)) {
        std::cout << "Graph is not connected" << std::endl;
        return 1;
    }

    std::cout << "edges.size(): " << edges.size() << std::endl;

    // run pagerank
    PageRank pr(edges, SIZE, 0.85);
    vector<double> results = pr.result(1);

    int start = 0;
    Dijkstra dijkstra(results, matrix, start);

    return 0;
}
