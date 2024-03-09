// ReadFile.h
#ifndef READ_FILE_H
#define READ_FILE_H

#include <vector>
#include <string>
#include <istream>

extern const int INF;
using Matrix = std::vector<std::vector<int>>;

Matrix ReadMatrixFromFile(const std::string& filename);
Matrix ReadMatrixFromStream(std::istream& in);

void InitializeMatrices(Matrix& X1, Matrix& X0, Matrix& Xminus1);
void DisplayMatrix(const Matrix& matrix);

#endif
