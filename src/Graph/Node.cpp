#include "Node.h"

Node::Node(const std::string& name) {
    this->name_ = name;
    this->visited_ = false;
    this->weight_ = LONG_MAX;
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

bool Node::beenVisited(){
    return this->visited_;
}

void Node::changeState(bool state){
    this->visited_ = state;
}

long Node::getWeight() {
    return this->weight_;
}

void Node::setWeight(long weight) {
    this->weight_ = weight;
}

bool Node::operator==(const Node& other) {
    return this->name_ == other.name_;
}