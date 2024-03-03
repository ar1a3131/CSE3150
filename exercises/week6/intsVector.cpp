#include "intsVector.h"

intvector::intvector() : id(-1), from(0), to(0) {}

intvector::intvector(const intvector &i_v) : id(i_v.id), from(i_v.from), to(i_v.to) {}

intvector::intvector(int id_val, int from_val, int to_val) : id(id_val), from(from_val), to(to_val) {}