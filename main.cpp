#include <iostream>
#include <vector>
#include <unordered_map>

#include "csv.hpp"

#include "pagerank.hpp"
#include "dijkstra.hpp"

using namespace csv;
using std::vector;
using std::unordered_map;

int main() {
    // load edges
    CSVReader reader("data/edges.csv");
    std::vector<std::pair<int, int>> edges;
    for (CSVRow& row: reader) {
        int id_1 = row["id_1"].get<int>();
        int id_2 = row["id_2"].get<int>();
        std::pair<int, int> edge(id_1, id_2);
        edges.push_back(edge);
    }

    std::cout << "edges.size(): " << edges.size() << std::endl;

    // run pagerank
    PageRank pr(edges);
    vector<PageRankResult> results = pr.result();

    // put pagerank results into a map for fast lookup
    unordered_map<int, double> page_rank_map;
    for (PageRankResult& result: results) {
        page_rank_map[result.node_id] = result.rank;
    }

    // convert weighted nodes to weighted edges for Dijkstra's
    vector<WeightedEdge> weighted_edges;
    weighted_edges.reserve(edges.size());
    for (const std::pair<int, int>& edge : edges) {
        int id_1 = edge.first;
        int id_2 = edge.second;
        // average the page rank of the two nodes for the edge
        double avg_weight = (page_rank_map[id_1] + page_rank_map[id_2]) / 2;
        int weight = (int)(avg_weight * 10000);
        WeightedEdge weighted_edge { id_1, id_2, weight };
        weighted_edges.push_back(weighted_edge);
    }

    Dijkstra dijkstra(weighted_edges);

    return 0;
}
