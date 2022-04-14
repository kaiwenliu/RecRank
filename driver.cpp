#include "driver.hpp"

#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;

vector<vector<bool>> to_matrix(vector<pair<int, int>> edges, size_t size) {
    vector<vector<bool>> answer(size, vector<bool>(size, false));
    for (auto &edge : edges) {
      answer[edge.first][edge.second] = true;
    }
    return answer;
}


bool is_connected(const vector<vector<bool>>& matrix) {
    // do bfs
    vector<bool> visited(matrix.size(), false);
    queue<int> q;
    size_t num_visited = 1;
    q.push(0);
    visited[0] = true;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(size_t i = 0; i < matrix.size(); i++) {
            if(matrix[node][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
                num_visited++;
            }
        }
    }
    return num_visited == matrix.size();
}
