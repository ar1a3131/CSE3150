#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "vector2D_operations.h"
#include "vector_distance.h"

TEST_CASE("Vector operations are computed correctly") {
    vec2D v1(1.0, 2.0, 0);
    vec2D v2(2.0, 4.0, 1);
    
    CHECK(vector_cosine_distance(v1, v2) == doctest::Approx(0.0).epsilon(0.01));
}