#include "VectorReader.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<std::vector<double>> VectorReader::readVectorsFromFile(const std::string& filename) {
    std::vector<std::vector<double>> vectors;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file");
    }

    while (getline(file, line)) {
        std::istringstream iss(line);
        std::vector<double> vec;
        double num;
        while (iss >> num) {
            vec.push_back(num);
        }
        vectors.push_back(vec);
    }

    file.close();
    return vectors;
}
