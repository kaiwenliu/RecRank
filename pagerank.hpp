#pragma once

#include <string>
#include <vector>

using std::vector;
using std::pair;

struct PageRankResult {
    int node_id;
    // should be between 0 and 1
    double rank;
};

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
    vector<PageRankResult> result() const;

    // add member functions if necessary
private:
    // use an adjaceny matrix to represent the graph?
};
