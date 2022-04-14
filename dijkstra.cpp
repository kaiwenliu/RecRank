#include "dijkstra.hpp"

#include <iostream>
#include <cassert>

Dijkstra::Dijkstra(const vector<int> input_weights, const vector<vector<bool>> connected, int start)
    : start(start), visited(), connected(connected) {
        nodes = vector<int>(input_weights.size(), 0);
        weights = vector<int>(input_weights.size(), 0);
        for (size_t i = 0; i < input_weights.size(); i++) {
            assert(input_weights[i] >= 0);
            weights[i] = (1/(double)(1 + input_weights[i])) * INT32_MAX;
        }
    }

int Dijkstra::min_distance() {
    int min_weight = INT32_MAX;
    int min_index = -1;

    std::cout << "min_distance()" << std::endl;
    std::cout << "size of visited: " << visited.size() << std::endl;

    for (size_t i = 0; i < weights.size(); i++) {
        // must not be in spanning set
        std::cout << "> size of visited: " << visited.size() << std::endl;
        for (auto it = visited.begin(); it != visited.end(); it++) {
            std::cout << "> " << *it << std::endl;
        }
        if (visited.find(i) != visited.end()) {
            std::cout << "skipping " << i << std::endl;
            std::cout << "find: " << *visited.find(i) << std::endl;
            continue;
        }

        std::cout << "i: " << i << std::endl;

        // check for all the neighbors that are in the spanning set
        for (size_t j = 0; j < connected[i].size(); j++) {
            // must be a neighbor
            if (!connected[i][j]) {
                continue;
            }
            // must be in spanning set
            if (visited.find(j) == visited.end()) {
                continue;
            }

            int cur_weight = weights[i] + nodes[j];
            if (cur_weight < min_weight) {
                min_weight = cur_weight;
                min_index = i;
            }
        }
    }

    if (min_index == -1) {
        // every node is in the spanning set
        return -1;
    }
    nodes[min_index] = min_weight;
    visited.insert(min_index);
    return min_index;
}

vector<int> Dijkstra::generate() {
    // add initial node
    nodes[start] = 0;
    visited.insert(start);

    while (visited.size() != nodes.size()) {
        int min_index = min_distance();
        if (min_index == -1) {
            // we should be done
            break;
        }
    }

    return nodes;
}