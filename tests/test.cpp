#include <iostream>
#include <vector>

#include "catch.hpp"

#include "../dijkstra.hpp"

using std::vector;

TEST_CASE("Dijkstra", "") {
    vector<int> weights = {1, 2, 3, 4};
    vector<vector<bool>> connected(4, vector<bool>(4, false));
    connected[0][1] = true;
    connected[1][0] = true;
    connected[0][2] = true;
    connected[2][0] = true;
    connected[1][3] = true;
    connected[3][1] = true;
    connected[2][3] = true;
    connected[3][2] = true;
    Dijkstra dijkstra(weights, connected, 0);
    vector<int> nodes = dijkstra.generate();
    for(size_t i = 0; i < nodes.size(); i++) {
        std::cout << nodes[i] << " ";
    }
    std::cout << std::endl;
    REQUIRE(nodes[0] < nodes[2]);
    REQUIRE(nodes[2] < nodes[1]);
    REQUIRE(nodes[1] < nodes[3]);
}
