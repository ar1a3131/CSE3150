#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Matrix.h"

TEST_CASE("Matrix initialization and operations") {
    int n = 4; 
    Matrix m(n);

    std::vector<std::vector<int>> data = {
        {0, 1, 0, -1},
        {-1, 0, 1, 0},
        {0, -1, 0, 1},
        {1, 0, -1, 0}
    };
    m.initialize(data);

    SUBCASE("Initialization") {
        CHECK(m.getElement(0, 1) == 3 * (n + 1));
        CHECK(m.getElement(1, 0) == 1.0 / (3 * (n + 1)));
    }

    SUBCASE("Multiplication") {
    Matrix result = m.multiply(m); 
    result.normalize(n);           
    CHECK(result.getElement(0, 0) == 0); 
}

    SUBCASE("Normalization") {
        Matrix result = m.multiply(m);
        result.normalize(n);
        CHECK(result.getElement(0, 0) == 0); 
    }
}