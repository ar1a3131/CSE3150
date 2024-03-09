#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "ReadFile.h"
#include "Algorithm.h"

TEST_CASE("Read matrix from file") {
        Matrix testMatrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    REQUIRE(testMatrix.size() == 3);
    REQUIRE(testMatrix[0].size() == 3);
    REQUIRE(testMatrix[1][1] == 5);

}

TEST_CASE("Compute Expensive Digraph Exact Paths") {
    Matrix D1 = {{0, 2, 2}, {2, 0, 2}, {2, 2, 0}};
    Matrix D0 = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    Matrix Dminus1 = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    PreciseDirectedPaths(D1, D0, Dminus1);

    CHECK(D1[0][0] == 0);
    CHECK(D1[1][1] == 0);
    CHECK(D1[2][2] == 0);

}

TEST_CASE("Compute Expensive Digraph Exact Paths with Barbell Graph") {
    Matrix D1 = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
    Matrix D0 = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    Matrix Dminus1 = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    PreciseDirectedPaths(D1, D0, Dminus1);

    CHECK(D0[0][1] == 0);
    CHECK(D0[1][0] == 0); 
    CHECK(D0[0][2] == 0); 
    CHECK(D0[2][0] == 0); 
}