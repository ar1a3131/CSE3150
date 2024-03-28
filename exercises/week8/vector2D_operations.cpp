#include "vector2D_operations.h"

using namespace std;

double square_val(const double &val) {
    return val * val;
}

double dot_product(const vec2D &a, const vec2D &b) {
    return a.x_comp * b.x_comp + a.y_comp * b.y_comp;
}

double vector_magnitude(const vec2D &vec) {
    return sqrt(square_val(vec.x_comp) + square_val(vec.y_comp));
}

double vector_cosine_distance(const vec2D &a, const vec2D &b) {
    double dot_prod = dot_product(a, b);
    double magnitude_a = vector_magnitude(a);
    double magnitude_b = vector_magnitude(b);
    double cos_value = dot_prod / (magnitude_a * magnitude_b);
    cos_value = max(-1.0, min(1.0, cos_value)); // Clamp to valid range
    return acos(cos_value);
}