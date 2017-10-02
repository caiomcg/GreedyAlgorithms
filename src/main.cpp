#include <iostream>

#include "Graph.h"

int main(int argc, char** argv) {
    Graph graph{};
    
    graph.addNode("A");
    graph.addNode("B");
    graph.addNode("C");

    graph.addNeighbor("A", "B", 10);
    graph.addNeighbor("A", "C", 24);
    graph.addNeighbor("B", "C", 12);
    graph.addNeighbor("C", "D", 14);

    Node* node = graph.getNode("A");
    if (node != nullptr) {
        for (auto node_info : node->getNeighbors()) {
            std::clog << "A - [" << node_info.first->getName() << ", " << node_info.second << "]" << std::endl;
            for (auto node_child_info : node_info.first->getNeighbors()) {
                std::clog << "\t" << node_info.first->getName() << " - [" << node_child_info.first->getName() << ", " << node_child_info.second << "]" << std::endl;
            }
        }
    }
    
    return 0;
}