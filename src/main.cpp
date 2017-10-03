#include <iostream>
#include "Graph.h"
#include "InputReader.h"

//    1  2  3  4
// 1 00 23 17 19
// 2 23 00 22 20 
// 3 17 22 00 25 
// 4 19 20 25 00 

int main(int argc, char** argv) {
    InputReader input{argv[1]};
    Graph* graph = input.createGraph();

    Node* node = graph->getNode("2");
    if (node != nullptr) {
        for (auto node_info : node->getNeighbors()) {
            std::clog << "2 - [" << node_info.first->getName() << ", " << node_info.second << "]" << std::endl;
            for (auto node_child_info : node_info.first->getNeighbors()) {
                std::clog << "\t" << node_info.first->getName() << " - [" << node_child_info.first->getName() << ", " << node_child_info.second << "]" << std::endl;
            }
        }
    } else {
        std::clog << "No NOde";
    }
    
    delete node;
    return 0;
}