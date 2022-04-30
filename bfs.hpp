#include <vector>

using std::vector;
using std::pair;

class BFS {
public:
    BFS(const vector<vector<pair<size_t, double>>> &adjacency_list, const vector<double> &weights, size_t start);

    vector<pair<double, size_t>> generate();

private:
    // pair of pagerank score and neighbor index
    vector<pair<double, size_t>> neighbors;
};