// perfect_integer.h
#ifndef PERFECT_INTEGER_H
#define PERFECT_INTEGER_H

#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>

// Function to check if an integer is a perfect number
bool isPerfect(int num);

// Function to check if a vector of integers contains perfect numbers
void checkPerfectNumbers(const std::vector<int>& numbers, std::function<void(int)> action);

#endif 