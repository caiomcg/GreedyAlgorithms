#pragma once

#include <vector>
#include "Graph.h"

class Greedy {
public:
    Greedy(){}
    virtual ~Greedy() {}
    virtual std::vector<std::string> solve(Graph* graph) = 0;
};