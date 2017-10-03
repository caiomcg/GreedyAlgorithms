#include "InputReader.h"

InputReader::InputReader(const std::string& file_name) {
    this->file_ = new std::fstream(file_name, std::ios::in);
}

InputReader::~InputReader() {
    delete this->file_;
}

Graph* InputReader::createGraph() {
    Graph* graph = nullptr;
    std::vector<std::string> data;

    std::string line{""};
    std::string num{""};
    int size   = 0;
    int depth  = 1;
    int offset = 3;
    
    if (this->file_->is_open()) {
        *this->file_ >> size;

        graph = new Graph();

        for (int i = 1; i <= size; i++) {
            graph->addNode(std::to_string(i));
        }

        while (getline(*this->file_, line)) {
            std::stringstream ss{line};

            while (ss >> num) data.push_back(num);
            
            if (data.size() == 0) continue;

            for (int i = data.size(); i >= 1; i--) {
                int index   = i + (size - offset);
                long weight = std::stol(data[i-1]);
                graph->addNeighbor(std::to_string(depth), std::to_string(index), weight);
                graph->addNeighbor(std::to_string(index), std::to_string(depth), weight);
            }
            depth++;
            offset--;
            data.clear();
        }
    }

    return graph;
}