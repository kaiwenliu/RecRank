#include "driver.hpp"

#include <vector>
#include <queue>

#include "adjmatrix.hpp"

using std::vector;
using std::queue;
using std::pair;

bool is_connected(const AdjacencyMatrix& matrix) {
    // do bfs
    vector<bool> visited(matrix.getSize(), false);
    queue<int> q;
    size_t num_visited = 1;
    q.push(0);
    visited[0] = true;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(size_t i = 0; i < matrix.getSize(); i++) {
            if(matrix.hasEdge(node, i) && !visited[i]) {
                q.push(i);
                visited[i] = true;
                num_visited++;
            }
        }
    }
    return num_visited == matrix.getSize();
}
