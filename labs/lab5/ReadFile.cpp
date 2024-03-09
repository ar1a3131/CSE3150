// ReadFile.cpp
#include "ReadFile.h"

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream> // Required for std::istringstream
#include <limits>  // Required for std::numeric_limits
#include <stdexcept>

using namespace std;

const int INF = numeric_limits<int>::max(); // Representation of infinity


using Matrix = vector<std::vector<int>>;

Matrix ReadMatrixFromStream(std::istream& in) {
    Matrix matrix;
    std::string line;

    while (getline(in, line)) {
        std::istringstream lineStream(line);
        std::vector<int> row;
        int value;

        while (lineStream >> value) {

            row.push_back(value == 2 ? INF : value);
        }

        if (!matrix.empty() && row.size() != matrix[0].size()) {
            throw std::runtime_error("Matrix row size mismatch");
        }

        matrix.push_back(row);
    }

    if (matrix.empty()) {
        throw std::runtime_error("Empty matrix input");
    }

    return matrix;
}

Matrix ReadMatrixFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }


    return ReadMatrixFromStream(file);
}


void InitializeMatrices(Matrix& X1, Matrix& X0, Matrix& Xminus1) {
    X1 = ReadMatrixFromFile("X1.txt");
    X0 = ReadMatrixFromFile("X0.txt");
    Xminus1 = ReadMatrixFromFile("Xminus1.txt");
}


void DisplayMatrix(const Matrix& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            if (elem == std::numeric_limits<int>::max()) {
                cout << "INF" << "\t";
            } else {
                cout << elem << "\t";
            }
        }
        cout << endl;
    }
    cout << endl;
}