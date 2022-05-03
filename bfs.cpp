#include "bfs.hpp"

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::pair;
using std::queue;

BFS::BFS(
    const vector<vector<pair<size_t, double>>> &adjacency_list,
    const vector<double> &weights,
    size_t start,
    size_t limit
) {
    vector<bool> visited(adjacency_list.size(), false);
    vector<size_t> depth(adjacency_list.size(), 0);
    queue<size_t> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        size_t node = q.front();
        q.pop();

        for (const auto& edge : adjacency_list[node]) {
            if (!visited[edge.first]) {
                // visiting new node
                visited[edge.first] = true;
                q.push(edge.first);
                depth[edge.first] = depth[node] + 1;
                // only consider nodes that are not direct neighbors with the start node
                if (depth[edge.first] > 1) {
                    neighbors.push_back({weights[edge.first], edge.first});
                    if (neighbors.size() >= limit) {
                        break;
                    }
                }
            }
        }
        if (neighbors.size() >= limit) {
            break;
        }
    }

    sort(neighbors.begin(), neighbors.end());
}

vector<pair<double, size_t>> BFS::generate() {
    return neighbors;
}
