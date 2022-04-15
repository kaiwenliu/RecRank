#include <iostream>
#include <vector>

#include "catch.hpp"

#include "../dijkstra.hpp"
#include "../driver.hpp"
#include "../pagerank.hpp"
#include "../adjmatrix.hpp"

using std::vector;

bool equal(double a, double b) {
  return fabs(a - b) < 1e-6;
}

TEST_CASE("Pagerank Simple", "") {
    vector<std::pair<size_t, size_t>> edges;
    edges.push_back(std::pair<size_t, size_t>(0,1));
    PageRank pg(edges, 3, 0.85);
    vector<double> testResults = pg.result(0);
    REQUIRE(equal(testResults[0], 0.05));
    REQUIRE(equal(testResults[2], 0.05));
    REQUIRE(equal(testResults[1], 0.9));
}

TEST_CASE("Dijkstra simple", "") {
    vector<double> weights = {0.1, 0.2, 0.3};
    AdjacencyMatrix connected(weights.size());
    connected.addEdge(0, 1);
    connected.addEdge(0, 2);
    Dijkstra dijkstra(weights, connected, 0);
    vector<double> nodes = dijkstra.generate();
    REQUIRE(nodes[0] < nodes[2]);
    REQUIRE(nodes[2] < nodes[1]);
}

TEST_CASE("Dijkstra medium", "") {
    vector<double> weights = {0.1, 0.2, 0.3, 0.4};
    AdjacencyMatrix connected(weights.size());
    connected.addEdge(0, 1);
    connected.addEdge(0, 2);
    connected.addEdge(1, 3);
    connected.addEdge(2, 3);
    Dijkstra dijkstra(weights, connected, 0);
    vector<double> nodes = dijkstra.generate();
    REQUIRE(nodes[0] < nodes[2]);
    REQUIRE(nodes[2] < nodes[1]);
    REQUIRE(nodes[1] < nodes[3]);
}

TEST_CASE("Driver is_connected", "") {
    AdjacencyMatrix matrix(4);
    matrix.addEdge(0, 1);
    matrix.addEdge(0, 2);
    matrix.addEdge(2, 3);
    REQUIRE(is_connected(matrix));
}
