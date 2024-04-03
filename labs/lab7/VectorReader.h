#ifndef VECTOR_READER_H
#define VECTOR_READER_H

#include <vector>
#include <string>

class VectorReader {
public:
    static std::vector<std::vector<double>> readVectorsFromFile(const std::string& filename);
};

#endif
