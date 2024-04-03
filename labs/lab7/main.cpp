#include "VectorReader.h"
#include "CosineDistanceCalculator.h"
#include <iostream>
#include <iomanip>

int main() {
    try {
        auto vectors = VectorReader::readVectorsFromFile("vectors.txt");
        auto distances = CosineDistanceCalculator::calculateAllPairwiseDistances(vectors);

        for (const auto& pair : distances) {
            std::cout << "Vector " << pair.first.first << " and Vector " << pair.first.second
                      << " Cosine Distance: " << std::fixed << std::setprecision(4) << pair.second << '\n';
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
