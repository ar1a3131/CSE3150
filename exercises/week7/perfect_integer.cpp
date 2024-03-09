// perfect_integer.cpp
#include "perfect_integer.h"
#include <iostream>

bool isPerfect(int num) {
    int sum = 0;
    for (int i = 1; i <= num / 2; ++i) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum == num;
}

void checkPerfectNumbers(const std::vector<int>& numbers, std::function<void(int)> action) {
    std::for_each(numbers.begin(), numbers.end(), [&](int num) {
        action(num);
    });
}