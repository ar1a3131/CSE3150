#include <iostream>
#include <random>
#include "fisher_yates.h"

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void show_data(int array[], const int length) {
    for (int i = 0; i < length; i++) {
        std::cout << array[i] << " ";
    }
}

void fisher_yates(int array[], const int length, int (*random_fcn)()) {
    for (int i = 0; i < length - 1; i++) {
        int rnd_location = random_fcn() % (length - i);
        swap(&array[i], &array[rnd_location + i]);
    }
}