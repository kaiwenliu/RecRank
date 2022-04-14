#include <vector>

using std::vector;
using std::pair;

vector<vector<bool>> to_matrix(vector<pair<int, int>> edges, size_t size);
bool is_connected(const vector<vector<bool>>& matrix);