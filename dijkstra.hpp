#pragma once

#include <string>
#include <vector>

using std::vector;

struct WeightedEdge {
    int from;
    int to;
    int weight;
};

class Dijkstra {
public:
    /**
     * Create a new Dijkstra object given a list of weighted edges
     */
    Dijkstra(const vector<WeightedEdge> edges);

private:
};

