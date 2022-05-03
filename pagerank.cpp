#include "pagerank.hpp"

#include <vector>

using std::vector;

PageRank::PageRank(const std::vector<std::pair<size_t, size_t> > edges, int numNodes, double damping) {
    const size_t numIterations = 100;

    // vector of indicies with no outbound edges
    vector<size_t> noOutbound;
    // calculate decay as damping / number of outbound edges
    vector<double> decayFactor(numNodes, 0);
    for (auto edge : edges) {
        decayFactor[edge.first] += 1;
    }
    for (size_t i = 0; i < decayFactor.size(); i++) {
        double numEdges = decayFactor[i];
        if (numEdges > 0) {
            decayFactor[i] = damping / numEdges;
        } else {
            noOutbound.push_back(i);
        }
    }

    vector<double> oldPagerank(numNodes, 1.0 / numNodes);
    for (size_t i = 0; i < numIterations; i++) {
        vector<double> newPagerank(numNodes, 0);
        // outbound edges
        for (auto edge : edges) {
            newPagerank[edge.second] += oldPagerank[edge.first] * decayFactor[edge.first];
        }
        // add (1-d)/N to all nodes
        for (double &pagerank : newPagerank) {
            pagerank += (1 - damping) / numNodes;
        }
        // add residual for no outbound edges
        double inc = 0;
        for (size_t node : noOutbound) {
            inc += damping * oldPagerank[node] / numNodes;
        }
        for (double &pagerank : newPagerank) {
            pagerank += inc;
        }
        oldPagerank = newPagerank;
    }
    _pageRank = oldPagerank;
}

vector<double> PageRank::result() const {
    return _pageRank;
}
