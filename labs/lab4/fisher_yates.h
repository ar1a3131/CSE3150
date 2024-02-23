#ifndef FISHER_YATES_H_
#define FISHER_YATES_H_

void swap(int* x, int* y);
void show_data(int array[], const int length);
void fisher_yates(int array[], const int length, int (*random_fcn)());

#endif

