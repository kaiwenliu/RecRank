#pragma once

#include <string>
#include <vector>

using std::vector;
using std::pair;

class PageRank {
public:
    /**
     * Create a new PageRank object given a list of edges (represented as pairs
     * of node ids). Damping should usually be 0.85
     */
    PageRank(const vector<pair<int, int>> edges, int numNodes, double damping);

    /**
     * Get the result of the PageRank algorithm.
     */
    vector<double> result(int col) const;

    // add member functions if necessary
private:
    // use an adjaceny matrix to represent the graph?
    vector<vector<double>> graph; //Each entry is the chance that the column number node goes to the row number node

};
