#include "dijkstra.hpp"

#include <iostream>
#include <cassert>

Dijkstra::Dijkstra(const vector<double>& input_weights, const vector<vector<bool>>& connected, int start)
    : start(start), visited(), connected(connected) {
        nodes = vector<double>(input_weights.size(), 0);
        weights = vector<double>(input_weights.size(), 0);
        for (size_t i = 0; i < input_weights.size(); i++) {
            // input weights are between 0 and 1
            // invert to get weights between 1 and 0
            weights[i] = 1 - input_weights[i];
        }
    }

int Dijkstra::min_distance() {
    double min_weight = std::numeric_limits<double>::max();
    int min_index = -1;

    for (size_t i = 0; i < weights.size(); i++) {
        // must not be in spanning set
        if (visited.find(i) != visited.end()) {
            continue;
        }

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

            double cur_weight = weights[i] + nodes[j];
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

vector<double> Dijkstra::generate() {
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
