#include "Matrix.h"
#include <cmath> 
#include <vector>
#include <stdexcept>

const double INFINITY_REPLACEMENT = 1e9;

Matrix::Matrix(const std::vector<std::vector<int>>& matrix1, 
               const std::vector<std::vector<int>>& matrix2, 
               const std::vector<std::vector<int>>& matrix3) : size(matrix1.size()) {
    if(matrix1.size() > 1000) { // Example size limit
        throw std::runtime_error("Matrix size exceeds allowable limit.");
    }
    data.resize(size, std::vector<double>(size, INFINITY_REPLACEMENT));
    initialize(matrix1);
    initialize(matrix2);
    initialize(matrix3);
}

Matrix::Matrix(int size) : size(size), data(size, std::vector<double>(size, 0)) {}

void Matrix::initialize(const std::vector<std::vector<int>>& inputData) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (inputData[i][j] == 0) {
                data[i][j] = 1;
            } else if (inputData[i][j] == 1) {
                data[i][j] = 3 * (size + 1);
            } else if (inputData[i][j] == -1) {
                data[i][j] = 1.0 / (3 * (size + 1));
            }
        }
    }
}

Matrix Matrix::multiply(const Matrix& other) const {
    Matrix result(this->size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            double sum = 0.0;
            for (int k = 0; k < size; ++k) {
                sum += this->data[i][k] * other.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}

void Matrix::normalize(int n) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (detectNegativeOneEdge(data[i][j], n)) {
                data[i][j] = -1;
            } else if (detectPositiveOneEdge(data[i][j], n)) {
                data[i][j] = 1;
            } else if (detectZeroEdge(data[i][j], n)) {
                data[i][j] = 0;
            } else {
                data[i][j] = INFINITY_REPLACEMENT; // A large value for infinity
            }
        }
    }
}

double Matrix::getElement(int row, int col) const {
    return data[row][col];
}

double Matrix::fractionalPart(double value) const {
    return value - std::trunc(value);
}

int Matrix::truncate(double value) const {
    return static_cast<int>(value);
}

bool Matrix::detectNegativeOneEdge(double edgeCost, int n) const {
    double check = (3 * (n + 1)) * fractionalPart(edgeCost);
    return check >= 1 && check < 2 * n;
}

bool Matrix::detectPositiveOneEdge(double edgeCost, int n) const {
    int check = truncate(edgeCost / (3 * (n + 1)));
    return check >= 1 && check < 2 * n;
}

bool Matrix::detectZeroEdge(double edgeCost, int n) const {
    int check = truncate(edgeCost) % (3 * (n + 1));
    return check > 0 && check < 3 * n;
}