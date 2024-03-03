#ifndef INTSVECTOR_H
#define INTSVECTOR_H

struct intvector {
    int id;
    int from;
    int to;

    intvector(); // Default constructor
    intvector(const intvector &i_v); // Copy constructor
    intvector(int id, int from, int to); // Parameterized constructor
};

#endif

