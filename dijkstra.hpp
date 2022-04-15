#pragma once

#include <string>
#include <vector>
#include <set>

#include "adjmatrix.hpp"

using std::vector;
using std::set;

struct WeightedEdge {
    int from;
    int to;
    int weight;
};

class Dijkstra {
public:
    /**
     * Create a new Dijkstra object given an adjacendy matrix of weighted nodes
     */
    Dijkstra(const vector<double>& input_weights, const AdjacencyMatrix& connected, int start);
    // do dijkstra's algorithm
    vector<double> generate();

private:
    // find the node with the minimum distance
    int min_distance();

    // node weights (we will minimum the weights)
    // these are the distances from start
    vector<double> nodes;
    int start;
    // node weights
    vector<double> weights;
    set<int> visited;
    AdjacencyMatrix connected;
};

