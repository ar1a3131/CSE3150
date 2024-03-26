#include "Matrix.h"
#include <iostream>

int main() {
    int n = 4;
    std::vector<std::vector<int>> graphData = {{0, 1, 0, -1}, {-1, 0, 1, 0}, {0, -1, 0, 1}, {1, 0, -1, 0}};
    
    Matrix graph(n);
    graph.initialize(graphData);
    Matrix result = graph.multiply(graph);
    result.normalize(n);
    
    for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
        std::cout << result.getElement(i, j) << " ";
    }
    std::cout << std::endl;
    }
    
    return 0;
}