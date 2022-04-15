#pragma once

#include <vector>

using std::vector;
using std::pair;

class AdjacencyMatrix {
public:
    AdjacencyMatrix(size_t n);
    // from adjacency list
    AdjacencyMatrix(const vector<pair<size_t, size_t>> &edges);
    void addEdge(size_t from, size_t to);
    void removeEdge(size_t from, size_t to);
    bool hasEdge(size_t from, size_t to) const;
    size_t getSize() const;
private:
    size_t size;
    void setMatrix(size_t a, size_t b, bool val);
    bool getMatrix(size_t a, size_t b) const;
    // larger index first
    vector<vector<bool>> matrix;
};
