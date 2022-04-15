#include <iostream>
#include <vector>

#include "catch.hpp"

#include "../dijkstra.hpp"
#include "../driver.hpp"
#include "../pagerank.hpp"

using std::vector;

bool equal(double a, double b) {
  return fabs(a - b) < 1e-6;
}

TEST_CASE("Pagerank Simple", "") {
    vector<std::pair<int,int>> edges;
    edges.push_back(std::pair<int,int>(0,1));
    PageRank pg(edges, 3, 0.85);
    vector<double> testResults = pg.result(0);
    REQUIRE(equal(testResults[0], 0.05));
    REQUIRE(equal(testResults[2], 0.05));
    REQUIRE(equal(testResults[1], 0.9));
}

TEST_CASE("Dijkstra simple", "") {
    vector<double> weights = {0.1, 0.2, 0.3};
    vector<vector<bool>> connected(weights.size(), vector<bool>(weights.size(), false));
    connected[0][1] = true;
    connected[1][0] = true;
    connected[0][2] = true;
    connected[2][0] = true;
    Dijkstra dijkstra(weights, connected, 0);
    vector<double> nodes = dijkstra.generate();
    REQUIRE(nodes[0] < nodes[2]);
    REQUIRE(nodes[2] < nodes[1]);
}

TEST_CASE("Dijkstra medium", "") {
    vector<double> weights = {0.1, 0.2, 0.3, 0.4};
    vector<vector<bool>> connected(weights.size(), vector<bool>(weights.size(), false));
    connected[0][1] = true;
    connected[1][0] = true;
    connected[0][2] = true;
    connected[2][0] = true;
    connected[1][3] = true;
    connected[3][1] = true;
    connected[2][3] = true;
    connected[3][2] = true;
    Dijkstra dijkstra(weights, connected, 0);
    vector<double> nodes = dijkstra.generate();
    REQUIRE(nodes[0] < nodes[2]);
    REQUIRE(nodes[2] < nodes[1]);
    REQUIRE(nodes[1] < nodes[3]);
}

TEST_CASE("Driver to_matrix", "") {
    vector<pair<int, int>> edges = {
        {0, 1},
        {1, 0},
        {2, 1}
    };
    vector<vector<bool>> matrix = to_matrix(edges, 3);
    for (auto &edge : edges) {
        REQUIRE(matrix[edge.first][edge.second]);
    }
}

TEST_CASE("Driver is_connected", "") {
    vector<vector<bool>> matrix = {
        {false, true, false, false},
        {true, false, true, false},
        {false, true, false, true},
        {false, false, true, false}
    };
    REQUIRE(is_connected(matrix));
}
