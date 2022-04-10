#pragma once

#include "parser_header.h"
#include <string>
#include <vector>

using Parser::Node;

namespace PageRank {
class PageRank {
    public:
        // note: these are not owning pointers
        PageRank(std::vector<std::pair<Node*, Node*>> edges);
};
}
