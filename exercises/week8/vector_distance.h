#ifndef VECTOR_DISTANCE_H
#define VECTOR_DISTANCE_H


struct vector_distance {
    int id_1, id_2;
    double cos_distance;

    vector_distance(): id_1(-1), id_2(-1), cos_distance(0.0) {}

    vector_distance(int id1, int id2, double distance): id_1(id1), id_2(id2), cos_distance(distance) {}
};

#endif