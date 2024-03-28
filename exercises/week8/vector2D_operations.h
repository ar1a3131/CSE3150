#ifndef VECTOR2D_OPERATIONS_H_
#define VECTOR2D_OPERATIONS_H_

#include <iostream>
#include <cmath>

using namespace std;

// Represents a 2D vector with x and y components and an identifier.
struct vec2D {
    double x_comp;
    double y_comp;
    int vec_id;
    
    vec2D(const vec2D &v) : x_comp(v.x_comp), y_comp(v.y_comp), vec_id(v.vec_id) {}
    
    vec2D() : x_comp(0.0), y_comp(0.0), vec_id(0) {}
    vec2D(double x, double y, int id) :  x_comp(x), y_comp(y), vec_id(id) {}
};

// Basic vector operations.
double square_val(const double &val);
double dot_product(const vec2D &a, const vec2D &b);
double vector_magnitude(const vec2D &vec);
double vector_cosine_distance(const vec2D &a, const vec2D &b);

#endif