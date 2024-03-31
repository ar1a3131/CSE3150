#include "Matrix.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> matrix1 = {
        {0, 1, 0, -1},
        {-1, 0, 1, 0},
        {0, -1, 0, 1},
        {1, 0, -1, 0}
    };
    std::vector<std::vector<int>> matrix2 = {
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1}
    };
    std::vector<std::vector<int>> matrix3 = {
        {0, -1, 0, 1},
        {1, 0, -1, 0},
        {-1, 0, 1, 0},
        {0, 1, 0, -1}
    };

    Matrix graph(matrix1, matrix2, matrix3);
    Matrix result = graph.multiply(graph);
    result.normalize(4);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << result.getElement(i, j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}