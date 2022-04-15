#include "pagerank.hpp"

#include <iostream>


PageRank::PageRank(const std::vector<std::pair<int, int> > edges, int numNodes, double damping) {
    // TODO: create the pagerank and run the algorithm
    std::vector<double> temp(numNodes, 0);
    for (int i = 0; i < numNodes; i++) {
        graph.push_back(temp);
    }
    for(size_t i=0; i< edges.size(); i++) {
        graph[edges[i].first][edges[i].second] += 1; //first used for column
        temp[edges[i].first] += 1; // keep track of sum of col
    }

    for(size_t j = 0; j < graph.size(); j++) {
        for (size_t i = 0; i < graph[i].size(); i++) {
            if (temp[j] == 0) {
                graph[j][i] = 1.0/numNodes; //fill with 1/n so it isnt empty
            }
            else {
                graph[j][i] = damping * graph[j][i]/temp[j] + (1.0-damping)/numNodes; //Pagerank dampening
            }
        }
    }

}

vector<double> PageRank::result(int col) const {
    // return the result
    return graph[col]; // returns column, used first dim as column
}
