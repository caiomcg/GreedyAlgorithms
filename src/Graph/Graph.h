#pragma once

#include "Node.h"
#include <iostream>
#include <string>
#include <vector>

class Graph {
private: 
    std::vector<Node*> nodes;
public:
    Graph();
    void addNode(const std::string& name);
    void addNode(Node* node);
    void addNeighbor(const std::string& node_name, const std::string& neighbors_name, long weight);
    Node* getNode(const std::string& name);
};
