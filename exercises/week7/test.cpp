// test.cpp
#include "perfect_integer.h"
#include <cassert>

void testIsPerfect() {
    assert(isPerfect(6) == true);
    assert(isPerfect(28) == true);
    assert(isPerfect(12) == false);
    assert(isPerfect(10) == false);
}

int main() {
    testIsPerfect();
    return 0;
}