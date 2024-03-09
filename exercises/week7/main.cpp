// main.cpp
#include "perfect_integer.h"
#include <iostream>
#include <vector>

int main() {

    std::vector<int> numbers = {6, 28, 12, 10};
    checkPerfectNumbers(numbers, [](int num) {
        if (isPerfect(num)) {
            std::cout << num << " is a perfect number." << std::endl;
        } else {
            std::cout << num << " is not a perfect number." << std::endl;
        }
    });
    return 0;
}