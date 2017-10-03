#pragma once

#include <vector>
#include "Greedy.h"

class Prim : public Greedy {
public:
    ~Prim() override;
    std::vector<std::string> solve(Graph* graph) override;
};