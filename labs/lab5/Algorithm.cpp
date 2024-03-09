// Algorithm.cpp
#include "Algorithm.h"  // Include the file that reads matrices

// Function to perform the Precise-Directed-paths algorithm

void PreciseDirectedPaths(Matrix& D1, Matrix& D0, Matrix& Dminus1) {
    int n = D0.size();  // Assuming square matrices
    
    // Loop over all vertices
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Update D0 based on D1 and Dminus1
            for (int k = 0; k < n; ++k) {
                if (Dminus1[i][k] == 0 && D1[k][j] == 0)
                    D0[i][j] = 0;
                if (D1[i][k] == 1 && D0[k][j] == 1)
                    D1[i][j] = 1;
                if (Dminus1[i][k] == -1 && D0[k][j] == -1)
                    Dminus1[i][j] = -1;
            }
        }
    }
}

/*
void PreciseDirectedPaths(Matrix& X1, Matrix& X0, Matrix& Xminus1) {
    int n = X0.size();  // Assuming square matrices
    for (int l = 2; l <= 3 * n * n + 1; ++l) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (Xminus1[i][k] + X1[k][j] == 0 || X1[i][k] + Xminus1[k][j] == 0)
                        X0[i][j] = 0;
                    if (X1[i][k] + X0[k][j] == 1 || X0[i][k] + X1[k][j] == 1)
                        X1[i][j] = 1;
                    if (Xminus1[i][k] + X0[k][j] == -1 || X0[i][k] + Xminus1[k][j] == -1)
                        Xminus1[i][j] = -1;
                }
            }
        }
    }
}*/