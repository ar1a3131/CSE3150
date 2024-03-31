#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Matrix.h"

TEST_CASE("Testing Matrix initialization and operations") {
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

    Matrix matrix(matrix1, matrix2, matrix3);

    SUBCASE("Matrix multiplication") {
        Matrix result = matrix.multiply(matrix);
        double expectedValue = 17.0667; // Update this based on the correct expected outcome
        CHECK(result.getElement(0, 0) == doctest::Approx(expectedValue));
    }

    SUBCASE("Matrix normalization") {
        matrix.normalize(4);
        double expectedNormalizedValue = 0; // Update this based on the correct expected outcome
        CHECK(matrix.getElement(0, 0) == doctest::Approx(expectedNormalizedValue));
    }
}