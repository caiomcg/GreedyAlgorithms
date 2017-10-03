#include "Node.h"
#include <iostream>

Node::Node(const std::string& name) {
    this->name_ = name;
}

void Node::addNeighbor(Node* node, const long weight) {
    this->neighbors_.insert(std::pair<Node*, long>(node, weight));
}

std::map<Node*, long> Node::getNeighbors() {
    return this->neighbors_;
}

std::string Node::getName() {
    return this->name_;
}