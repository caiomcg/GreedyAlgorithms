#include "Dijkstra.h"

Dijkstra::~Dijkstra() {}

std::vector<std::string> Dijkstra::solve(Graph* graph) {
    std::vector<std::vector<Node*> > node_tree;

    auto nodes = graph->getAllNodes();
    
    Node* base_node = nodes.at(0);
    base_node->setWeight(0);

    Node* current_node  = base_node;
    Node* previous_node = base_node;
    Node* end_node  = nodes.at(nodes.size() - 1);

    while (current_node != nullptr) {
        std::vector<long> weights;

        if (!current_node->beenVisited()) {
            auto childs = current_node->getNeighbors();

            for (auto& child : childs) {
                if (!child.first->beenVisited()) {
                    long new_weight =  current_node->getWeight() + child.second;
                    if (child.first->getWeight() < new_weight) {
                        child.first->setWeight(new_weight);
                    }
                }

                
                weights.push_back(child.first->getWeight());
            }
            std::clog << "Node: " << current_node->getName() << " - " << current_node->beenVisited() << std::endl;
            current_node->changeState(true);
            std::clog << "Node: " << current_node->getName() << " - " << current_node->beenVisited() << std::endl;
        }
        if (weights.size() != 0) {
            current_node = nullptr;
            long min_weight = -1;

            for (auto node : nodes) {
                if (!node->beenVisited() && node->getWeight() != -1) {
                    if (min_weight > node->getWeight()) {
                        current_node = node;
                        min_weight = node->getWeight();
                    }
                }
            }
        }   
        //std::clog << "Current Node: " << current_node->getName() << " - " << current_node->getWeight() << std::endl;
        
    }
    return std::vector<std::string>{end_node->getName()};
}