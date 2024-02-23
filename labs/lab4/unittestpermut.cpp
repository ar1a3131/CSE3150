#include "doctest.h"
#include "gen_permut.h"

TEST_CASE("Testing compute_permutation_of_array") {
    SUBCASE("Permutation of size 5") {
        int array[5] = {1, 2, 3, 4, 5};
        compute_permutation_of_array(array, 5);

    }

    SUBCASE("Permutation of size 10") {
        int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        compute_permutation_of_array(array, 10);

    }
}

TEST_CASE("Testing get_lowest_prefix_sum_value") {
    SUBCASE("Array with positive values") {
        int array[5] = {1, 2, 3, 4, 5};
        int result = get_lowest_prefix_sum_value(array, 5);
        CHECK(result == 0); // Expected result when all values are positive
    }

    SUBCASE("Array with mixed values") {
        int array[7] = {1, -2, 3, -4, 5, -6, 7};
        int result = get_lowest_prefix_sum_value(array, 7);
        CHECK(result == -4); // Expected result when some values are negative
    }
}

TEST_CASE("Testing index_of_lowest_prefix_sum_element") {
    SUBCASE("Array with positive values") {
        int array[5] = {1, 2, 3, 4, 5};
        int result = index_of_lowest_prefix_sum_element(array, 5);
        CHECK(result == 0); // Expected result when all values are positive
    }

    SUBCASE("Array with mixed values") {
        int array[7] = {1, -2, 3, -4, 5, -6, 7};
        int result = index_of_lowest_prefix_sum_element(array, 7);
        CHECK(result == 3); // Expected result when some values are negative
    }
}