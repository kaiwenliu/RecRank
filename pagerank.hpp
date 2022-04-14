#pragma once

#include <string>
#include <vector>

using std::vector;
using std::pair;

class PageRank {
public:
    /**
     * Create a new PageRank object given a list of edges (represented as pairs
     * of node ids).
     */
    PageRank(const vector<pair<int, int>> edges);

    /**
     * Get the result of the PageRank algorithm.
     */
    vector<int> result() const;

    // add member functions if necessary
private:
    // use an adjaceny matrix to represent the graph?
};
