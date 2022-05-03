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
    PageRank(const vector<pair<size_t, size_t>> edges, int numNodes, double damping);

    /**
     * Get the result of the PageRank algorithm. Values are between 0 and 1.
     */
    vector<double> result() const;

private:
    vector<double> _pageRank;

};
