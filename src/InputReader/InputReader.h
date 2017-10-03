#pragma once

#include "Graph.h"
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

class InputReader {
private:
    std::fstream* file_;
public:
    InputReader(const std::string& file_name);
    ~InputReader();

    Graph* createGraph();
};
