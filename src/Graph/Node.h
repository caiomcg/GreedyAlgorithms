#pragma once

#include <map>
#include <climits>
#include <string>

class Node {
private:
    std::string name_;
    bool visited_;
    long weight_;
    std::map<Node*, long> neighbors_;
public:
    Node(const std::string& name);

    void addNeighbor(Node* node, const long weight);
    std::map<Node*, long> getNeighbors();
    std::string getName();
    bool beenVisited();
    void changeState(bool state);
    long getWeight();
    void setWeight(long weight);

    bool operator==(const Node& other);
};
