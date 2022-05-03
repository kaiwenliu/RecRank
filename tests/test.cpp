#include <iostream>
#include <vector>

#include "catch.hpp"

#include "../dijkstra.hpp"
#include "../driver.hpp"
#include "../pagerank.hpp"
#include "../adjmatrix.hpp"
#include "../bfs.hpp"

using std::vector;

bool equal(double a, double b) {
  return fabs(a - b) < 1e-6;
}

vector<vector<pair<size_t, double>>> to_adjacency_list(const vector<pair<size_t, size_t>>& edges, const vector<double>& weights) {
    // convert to weights by averaging adjacent nodes
    vector<pair<pair<size_t, size_t>, double>> weighted_edges(edges.size());
    size_t num_nodes = 0;
    for (size_t i = 0; i < edges.size(); i++) {
        double weight = weights[edges[i].first] + weights[edges[i].second];
        // take the reciprocal because higher pagerank is better
        weighted_edges[i] = {edges[i], 1 / (1 + weight / 2)};
        num_nodes = std::max(std::max(num_nodes, edges[i].first), edges[i].second);
    }
    num_nodes++;
    // convert to adjacency list
    vector<vector<pair<size_t, double>>> adjacency_list(num_nodes);
    for (const auto& edge : weighted_edges) {
        adjacency_list[edge.first.first].push_back({edge.first.second, edge.second});
        adjacency_list[edge.first.second].push_back({edge.first.first, edge.second});
    }
    return adjacency_list;
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
    vector<pair<size_t, size_t>> edges = {{0, 1}, {0, 2}};
    vector<vector<pair<size_t, double>>> adjacency_list = to_adjacency_list(edges, weights);
    Dijkstra dijkstra(adjacency_list, 0);
    vector<double> nodes = dijkstra.generate();
    REQUIRE(nodes[0] < nodes[2]);
    REQUIRE(nodes[2] < nodes[1]);
}

TEST_CASE("Dijkstra medium", "") {
    vector<double> weights = {0.1, 0.2, 0.3, 0.4};
    vector<pair<size_t, size_t>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    vector<vector<pair<size_t, double>>> adjacency_list = to_adjacency_list(edges, weights);
    Dijkstra dijkstra(adjacency_list, 0);
    vector<double> nodes = dijkstra.generate();
    REQUIRE(nodes[0] < nodes[2]);
    REQUIRE(nodes[2] < nodes[1]);
    REQUIRE(nodes[1] < nodes[3]);
}

TEST_CASE("Driver is_connected small", "") {
    vector<pair<size_t, size_t>> edges = {{0, 1}, {0, 2}, {2, 3}};
    REQUIRE(is_connected(edges, 4));
}

TEST_CASE("Driver is_connected tiny", "") {
    vector<pair<size_t, size_t>> edges = {{0, 1}};
    REQUIRE(is_connected(edges, 2));
}

TEST_CASE("BFS works tiny", "") {
    vector<vector<pair<size_t, double>>> adjacency_list = {
        {{1, 1234}, {2, 5678}},
        {{2, 3456}, {0, 1234}, {3, 5678}},
        {{0, 5678}, {1, 1234}, {4, 1234}},
        {{1, 1234}},
        {{2, 5678}},
    };
    vector<double> weights = {0, 10, 20, 30, 40};
    BFS bfs(adjacency_list, weights, 0);
    vector<pair<double, size_t>> best = bfs.generate();
    REQUIRE(best[0].first == 40);
    REQUIRE(best[0].second == 4);
    REQUIRE(best[1].first == 30);
    REQUIRE(best[1].second == 3);
}
