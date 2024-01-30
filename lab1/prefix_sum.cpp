#include <iostream>

#include "prefix_sum.h"


int prefix_sum(int ary[],int length) {
    int sum=0;
    for (int i=0; i<length; i++) {
        sum += ary[i];  
    }

    return sum;

}

bool non_neg_prefix_sum(int ary[],int length) {
    bool negative_found = false;
    int sum=0;
    for (int i=0; i<length; i++) {
        sum += ary[i]; 
        if (sum<0){
            negative_found = true;
            break;
        }
    }

    return negative_found; 

}


bool non_pos_prefix_sum(int ary[], int length) {
    bool positive_found = false;
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += ary[i];
        if (sum > 0) {
            positive_found = true;
            break;
        }
    }

    return positive_found;
}

