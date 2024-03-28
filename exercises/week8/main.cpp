#include <vector>
#include <iomanip>
#include "vector2D_operations.h"
#include "vector_distance.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    vector<vec2D> vectors;
    vector<vector_distance> all_distances;

    ifstream in_file("vectors_2D.txt");
    int vec_id = 0;
    double x, y;

    while (in_file >> x >> y) {
        vec2D new_vec(x, y, vec_id++);
        vectors.push_back(new_vec);
    }

    cout << "Vector IDs, Components, and Cosine Distances:" << endl;
    for (auto& v : vectors) {
        cout << "ID: " << v.vec_id << " - Components: (" << v.x_comp << ", " << v.y_comp << ")" << endl;
    }

    // Calculating and storing distances
    for (size_t i = 0; i < vectors.size(); ++i) {
        for (size_t j = i + 1; j < vectors.size(); ++j) {
            vector_distance dist(i, j, vector_cosine_distance(vectors[i], vectors[j]));
            all_distances.push_back(dist);
        }
    }

    // Sorting distances for better readability
    sort(all_distances.begin(), all_distances.end(), [](const vector_distance& a, const vector_distance& b) {
        return a.cos_distance < b.cos_distance;
    });

    // Displaying distances
    for (const auto& dist : all_distances) {
        cout << "Distance between vectors " << dist.id_1 << " and " << dist.id_2 << ": " << dist.cos_distance << endl;
    }

    return 0;
}