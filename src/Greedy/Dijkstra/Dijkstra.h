#include "Greedy.h"

#include <map>
#include <climits>
#include <string>

class Dijkstra : public Greedy {
public:
    ~Dijkstra() override;
    std::vector<std::string> solve(Graph* graph) override;
};