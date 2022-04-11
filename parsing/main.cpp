#include <iostream>

#include "csv.hpp"

#include "include/node.h"

using namespace csv;

int main() {
    CSVReader reader("../data/edges.csv");

    std::vector<std::pair<int, int>> edges;
    for (CSVRow& row: reader) { // Input iterator
        int id_1 = row["id_1"].get<int>();
        int id_2 = row["id_2"].get<int>();
        std::pair<int, int> edge(id_1, id_2);
        edges.push_back(edge);
    }
    

    return 0;
}