#pragma once

#include <map>
#include <string>

class Node {
private:
    std::string name_;
    std::map<Node*, long> neighbors_;
public:
    Node(const std::string& name);

    void addNeighbor(Node* node, const long weight);
    std::map<Node*, long> getNeighbors();
    std::string getName();
};
