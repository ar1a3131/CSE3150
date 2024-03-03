//vectorsMain.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include "intsVector.h"  // Include the header file that declares intvector

using namespace std;

int main() {
    vector<intvector> vect;  // Use intvector instead of int_vector
    intvector i_v;

    // Populate vector
    for (int i = 0; i < 10; ++i) {
        i_v.id = i;
        i_v.from = i * 2;
        i_v.to = i * 3;
        vect.push_back(i_v);
    }

    // Sort vector
    sort(vect.begin(), vect.end(), [](const intvector &left, const intvector &right) {
        return left.id < right.id;
    });

    // Print vector
    for (const auto &v : vect) {
        cout << v.id << " " << v.from << " " << v.to << endl;
    }

    return 0;
}