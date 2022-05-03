#pragma once

#include <string>
#include <vector>
#include <set>

using std::vector;
using std::set;
using std::pair;

struct WeightedEdge {
    int from;
    int to;
    int weight;
};

class Dijkstra {
public:
    /**
     * Create a new Dijkstra object given a list of edges with weights.
     */
    Dijkstra(const vector<vector<pair<size_t, double>>>& adjacency_list, size_t start);
    // do dijkstra's algorithm
    vector<double> generate();

private:
    vector<double> results;
};

