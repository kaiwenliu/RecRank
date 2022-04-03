#include <iostream>

#include "nlohmann/json.hpp"

#include "include/node.h"

using json = nlohmann::json;

int main() {
    // test to see that it works
    nlohmann::json j;
    j["name"] = "John Doe";
    std::cout << j.dump() << std::endl;

    Parser::Node n("5");
    Parser::Node n2("6");

    std::cout << n.getID() << ", " << n.getData() << std::endl;
    std::cout << n2.getID() << ", " << n2.getData() << std::endl;
    std::cout << Parser::Node::num_nodes_ << std::endl;

    // Parser::Node<int> n(1);
    // Parser::Node<int> n2(2);

    // std::cout << n.getID() << ", " << n.getData() << std::endl;
    // std::cout << n2.getID() << ", " << n2.getData() << std::endl;
    // std::cout << Parser::Node::num_nodes_ << std::endl;

    return 0;
}
