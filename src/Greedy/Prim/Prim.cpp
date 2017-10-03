#include "Prim.h"

/* 4
23 17 19
22 20
25 */

Prim::~Prim() {}

std::vector<std::string> Prim::solve(Graph* graph) {
    auto nodes = graph->getAllNodes();

    std::vector<std::string> result;
    
    Node* current_node = nodes.at(0);
    current_node->setWeight(0);
    Node* end_node  = nodes.at(nodes.size() - 1);

    while (current_node != nullptr) {
        std::vector<long> weights;

        if (!current_node->beenVisited()) {
            auto childs = current_node->getNeighbors();

            for (auto& child : childs) {
                if (!child.first->beenVisited()) {
                    long new_weight =  current_node->getWeight() + child.second;
                    
                    if (child.first->getWeight() > new_weight) {
                        child.first->setWeight(new_weight);
                    }
                }
                weights.push_back(child.first->getWeight());
            }
            current_node->changeState(true);
        }

        if (weights.size() != 0) {
            result.push_back(current_node->getName());
            current_node = nullptr;
            long min_weight = LONG_MAX;

            for (auto node : nodes) {
                if (!node->beenVisited() && node->getWeight() != -1) {
                    if (min_weight > node->getWeight()) {
                        current_node = node;
                        min_weight = node->getWeight();
                    }
                }
            }
        }   
    }
    return result;
}