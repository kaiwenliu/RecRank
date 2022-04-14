#pragma once

#include <string>
#include <vector>
#include <set>

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
    Dijkstra(const vector<int> weights, const vector<vector<bool>> connected, int start);
    // do dijkstra's algorithm
    vector<int> generate();

private:
    // find the node with the minimum distance
    int min_distance();

    // node weights (we will minimum the weights)
    // these are the distances from start
    vector<int> nodes;
    int start;
    // node weights
    vector<int> weights;
    set<int> visited;
    vector<vector<bool>> connected;
};

