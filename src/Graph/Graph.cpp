#include "Graph.h"

Graph::Graph() {}

void Graph::addNode(const std::string& name) {
    this->nodes_.push_back(new Node(name));
}

void Graph::addNode(Node* node) {
    this->nodes_.push_back(node);
}

void Graph::addNeighbor(const std::string& node_name, const std::string& neighbors_name, long weight) {
    Node* base = nullptr;
    Node* neighbor = nullptr;

    if (!(base = this->getNode(node_name))) {
        base = new Node(node_name);
        this->addNode(base);
    }

    if (!(neighbor = this->getNode(neighbors_name))) {
        neighbor = new Node(neighbors_name);
        this->addNode(neighbor);
    }

    base->addNeighbor(neighbor, weight);
}

Node* Graph::getNode(const std::string& name) {
    for (auto node : this->nodes_) {
        if (node->getName() == name) {
            return node;
        }
    }
    return nullptr;
}

std::vector<Node*> Graph::getAllNodes() {
    return this->nodes_;
}