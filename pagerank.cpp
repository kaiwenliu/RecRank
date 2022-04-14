#include "pagerank.hpp"

#include <iostream>


PageRank::PageRank(const std::vector<std::pair<int, int> > edges) {
    // TODO: create the pagerank and run the algorithm
    std::pair<int, int> p;
    p.first = edges.size();
    p.second = edges.size();
    std::vector<std::pair<int, int> > ans(1 / (double) edges.size(), p);
    for(size_t i=0; i< edges.size(); i++){
        int temp = 0;
        temp = p.first;
        p.first = p.second;
        p.second = temp;

        std::vector<std::pair<int, int> > ans2(1/ (double) edges.size(), p);
       
    }
    
    
    

}

vector<PageRankResult> PageRank::result() const {
    // return the result
    return vector<PageRankResult>();
}
