#include "adjmatrix.hpp"

#include <vector>

using std::vector;
using std::pair;

AdjacencyMatrix::AdjacencyMatrix(size_t n) {
    size = n;
    matrix.reserve(n);
    for (size_t i = 0; i < n; i++) {
        matrix.push_back(vector<bool>(i + 1, false));
    }
}

AdjacencyMatrix::AdjacencyMatrix(const vector<pair<size_t, size_t>> &edges) {
    size = 0;
    for (auto &edge : edges) {
        if (edge.first >= size) {
            size = edge.first + 1;
        }
        if (edge.second >= size) {
            size = edge.second + 1;
        }
    }
    matrix.reserve(size);
    for (size_t i = 0; i < size; i++) {
        matrix.push_back(vector<bool>(i, false));
    }
    for (auto &edge : edges) {
        if (edge.first >= edge.second) {
            matrix[edge.first][edge.second] = true;
        } else {
            matrix[edge.second][edge.first] = true;
        }
    }
}

void AdjacencyMatrix::setMatrix(size_t a, size_t b, bool val) {
    // sanity checks
    assert(a < size && b < size);
    assert(a >= 0 && b >= 0);

    if (a < b) {
        setMatrix(b, a, val);
        return;
    }

    assert(a >= b);
    matrix[a][b] = val;
}

bool AdjacencyMatrix::getMatrix(size_t a, size_t b) const {
    // sanity checks
    assert(a < size && b < size);
    assert(a >= 0 && b >= 0);

    if (a < b) {
        return getMatrix(b, a);
    }

    assert(a >= b);
    return matrix[a][b];
}

void AdjacencyMatrix::addEdge(size_t from, size_t to) {
    setMatrix(from, to, true);
}

void AdjacencyMatrix::removeEdge(size_t from, size_t to) {
    setMatrix(from, to, false);
}

bool AdjacencyMatrix::hasEdge(size_t from, size_t to) const {
    return getMatrix(from, to);
}
size_t AdjacencyMatrix::getSize() const {
    return size;
}
