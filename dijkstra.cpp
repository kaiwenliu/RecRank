#include "dijkstra.hpp"

#include <iostream>
#include <cassert>
#include <vector>
#include <queue>

using std::vector;
using std::pair;
using std::priority_queue;

Dijkstra::Dijkstra(const vector<vector<pair<size_t, double>>>& adjacency_list, size_t start) {
    vector<double> dists(adjacency_list.size(), std::numeric_limits<double>::max());
    vector<size_t> prevs(adjacency_list.size(), 0);
    priority_queue<size_t> q;

    dists[start] = 0;
    q.push(start);

    while (!q.empty()) {
        size_t curr = q.top();
        q.pop();

        for (const auto& edge : adjacency_list[curr]) {
            size_t neighbor = edge.first;
            double dist = edge.second;

            if (dists[curr] + dist < dists[neighbor]) {
                dists[neighbor] = dists[curr] + dist;
                prevs[neighbor] = curr;
                q.push(neighbor);
            }
        }
    }

    results = dists;
}

vector<double> Dijkstra::generate() {
    return results;
}
