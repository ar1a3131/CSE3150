#ifndef COSINE_DISTANCE_CALCULATOR_H
#define COSINE_DISTANCE_CALCULATOR_H

#include <vector>
#include <utility>

class CosineDistanceCalculator {
public:
    static double calculateCosineSimilarity(const std::vector<double>& vecA, const std::vector<double>& vecB);
    static std::vector<std::pair<std::pair<int, int>, double>> calculateAllPairwiseDistances(
        const std::vector<std::vector<double>>& vectors);
};

#endif
