#include "doctest.h"
#include "prefix_sum.h"

int nums_0[] = {};
int nums_1[] = {8,-9,7,6};
int nums_2[] = {5,5,-6,-6};
int nums_3[] = {-7,-7,5,5};

TEST_CASE("Edge cases") {
    CHECK(prefix_sum(nums_0,sizeof(nums_0)/sizeof(nums_0[0])) == 0);  
    CHECK(non_negative_sum(nums_0,sizeof(nums_0)/sizeof(nums_0[0])) );  
    CHECK(non_positive_sum(nums_0,sizeof(nums_0)/sizeof(nums_0[0])) );  
}

TEST_CASE("Testing prefix_sum function") {
  
    CHECK(prefix_sum(nums_1,sizeof(nums_1)/sizeof(nums_1[0])) == 12);
    CHECK(prefix_sum(nums_1,sizeof(nums_1)/sizeof(nums_1[0]) -2) == -2);  
    CHECK(prefix_sum(nums_2,sizeof(nums_2)/sizeof(nums_2[0])) == -2);
    CHECK(prefix_sum(nums_2,sizeof(nums_2)/sizeof(nums_2[0]) -1) == 4);
    CHECK(prefix_sum(nums_3,sizeof(nums_3)/sizeof(nums_3[0])) == -4);
}

TEST_CASE("Testing non_negative_sum function") {
  
    CHECK(non_negative_sum(nums_1,sizeof(nums_1)/sizeof(nums_1[0])) == true);
    CHECK(non_negative_sum(nums_2,sizeof(nums_2)/sizeof(nums_2[0])) == true);
    CHECK(non_negative_sum(nums_3,sizeof(nums_3)/sizeof(nums_3[0])) == true);

}

TEST_CASE("Testing non_positive_sum function") {
  
    CHECK(non_positive_sum(nums_1,sizeof(nums_1)/sizeof(nums_1[0])) == false);
    CHECK(non_positive_sum(nums_2,sizeof(nums_2)/sizeof(nums_2[0])) == false);
    CHECK(non_positive_sum(nums_3,sizeof(nums_3)/sizeof(nums_3[0])) == false);

}