// fisher_yates.cpp
#include <cstdlib>
#include "fisher_yates.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void fisher_yates(int array[], const int length, int (*random_fcn)()) {
    for (int i = 0; i < length - 1; i++) {
        int rnd_location = random_fcn() % (length - i);
        swap(&array[i], &array[rnd_location + i]);
    }
}