#include <iostream>

#include "Dijkstra.h"
#include "Prim.h"
#include "Graph.h"
#include "InputReader.h"

//    1  2  3  4
// 1 00 23 17 19
// 2 23 00 22 20 
// 3 17 22 00 25 
// 4 19 20 25 00 

void usage(void) {
    std::clog << "Greedy [FILE]" << std::endl;
}

int main(int argc, char** argv) {

    if (argc < 2) {
        usage();
        return 1;
    }

    InputReader input{argv[1]};

    Graph* graph = input.createGraph();

    Prim* prim = new Prim();

    auto prim_result = prim->solve(graph);
    long sum = 0;
    for (auto name : prim_result) {
        sum += graph->getNode(name)->getWeight();
    }
    std::clog << "Prim (MST) - path sum: " << sum << std::endl;


    for (auto node : graph->getAllNodes()) {
        node->reset();  
    }

    Dijkstra* dijkstra = new Dijkstra();

    auto result = dijkstra->solve(graph);
    Node* node  = graph->getNode(result[0]);

    std::clog << "Dijkstra - Node: " << node->getName() << " - path sum: " << node->getWeight() << std::endl;

    delete graph;
    delete prim;
    delete dijkstra;
    return 0;
}