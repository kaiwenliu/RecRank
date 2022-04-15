#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

#include "csv.hpp"

#include "driver.hpp"
#include "pagerank.hpp"
#include "dijkstra.hpp"

using namespace csv;
using std::vector;
using std::unordered_map;

#define SIZE 37700

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

    vector<vector<bool>> matrix = to_matrix(edges, SIZE);
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
