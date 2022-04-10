#include "catch2/catch.hpp"
#include "include/pagerank.h"

using Parser::Node;

TEST_CASE("PageRank Tests") {
    SECTION("Sanity check", "[pagerank]") {
        Node n("1");
        Node n2("2");
        PageRank::PageRank a(n, n2);

        REQUIRE(a.getResult() == "12");
        // REQUIRE(Node::num_nodes_ == 2);
    }
}
