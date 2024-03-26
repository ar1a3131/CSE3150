#include "Matrix.h"
#include <cmath>

const double INFINITY_REPLACEMENT = 1e9;

Matrix::Matrix(int size) : size(size), data(size, std::vector<double>(size, INFINITY_REPLACEMENT)) {}

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
    Matrix result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            double sum = 0;
            for (int k = 0; k < size; ++k) {
                double mul = data[i][k] * other.data[k][j];
                sum += mul;
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


double Matrix::getElement(int row, int col) const {
    return data[row][col];
}