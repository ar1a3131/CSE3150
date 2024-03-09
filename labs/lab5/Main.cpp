// Main.cpp
#include "ReadFile.h"
#include "Algorithm.h"
#include <ostream>
#include <iostream>

using namespace std;
int main() {
    Matrix X1, X0, Xminus1;
    InitializeMatrices(X1, X0, Xminus1);  // Initialize matrices
    PreciseDirectedPaths(X1, X0, Xminus1);  // Compute the algorithm

    // Print the matrices after computation
    cout << "Matrix X1:" << endl;
    DisplayMatrix(X1);
    
    cout << "Matrix X0:" << endl;
    DisplayMatrix(X0);

    cout << "Matrix Xminus1:" << endl;
    DisplayMatrix(Xminus1);
    
    return 0;
}