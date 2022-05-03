#include "driver.hpp"

#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;

bool is_connected(const vector<pair<size_t, size_t>>& edges, size_t size) {
    // create adjacency list
    vector<vector<size_t>> adj_list(size);
    for (const auto& edge : edges) {
        adj_list[edge.first].push_back(edge.second);
        adj_list[edge.second].push_back(edge.first);
    }

    // do bfs
    vector<bool> visited(size, false);
    queue<int> q;
    size_t num_visited = 1;
    q.push(0);
    visited[0] = true;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for (const auto& neighbor : adj_list[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                num_visited++;
            }
        }
    }
    return num_visited == size;
}
