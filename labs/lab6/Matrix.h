#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix {
public:
    Matrix(const std::vector<std::vector<int>>& matrix1, 
           const std::vector<std::vector<int>>& matrix2, 
           const std::vector<std::vector<int>>& matrix3);
    void initialize(const std::vector<std::vector<int>>& data);
    Matrix multiply(const Matrix& other) const;
    void normalize(int n);
    double getElement(int row, int col) const;

private:
    Matrix(int size); // Private constructor for internal use
    std::vector<std::vector<double>> data;
    int size;
    double fractionalPart(double value) const;
    int truncate(double value) const;
    bool detectNegativeOneEdge(double edgeCost, int n) const;
    bool detectPositiveOneEdge(double edgeCost, int n) const;
    bool detectZeroEdge(double edgeCost, int n) const;
};

#endif


