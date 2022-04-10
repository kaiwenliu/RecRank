#include "include/pagerank.h"
#include <iostream>

using Parser::Node;

int main() {
    Node n("5");
    Node n2("6");

    PageRank::PageRank a(n, n2);

    std::cout << a.getResult() << std::endl;
    std::cout << Node::num_nodes_ << std::endl;

    return 0;
}
