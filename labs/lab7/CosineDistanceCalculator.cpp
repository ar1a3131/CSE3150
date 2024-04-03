#include "CosineDistanceCalculator.h"
#include <cmath>
#include <numeric>
#include <algorithm>

double CosineDistanceCalculator::calculateCosineSimilarity(const std::vector<double>& vecA, const std::vector<double>& vecB) {
    double dot_product = std::inner_product(vecA.begin(), vecA.end(), vecB.begin(), 0.0);
    double normA = std::sqrt(std::inner_product(vecA.begin(), vecA.end(), vecA.begin(), 0.0));
    double normB = std::sqrt(std::inner_product(vecB.begin(), vecB.end(), vecB.begin(), 0.0));
    return dot_product / (normA * normB);
}

std::vector<std::pair<std::pair<int, int>, double>> CosineDistanceCalculator::calculateAllPairwiseDistances(
    const std::vector<std::vector<double>>& vectors) {

    std::vector<std::pair<std::pair<int, int>, double>> distances;

    for (size_t i = 0; i < vectors.size(); ++i) {
        for (size_t j = i + 1; j < vectors.size(); ++j) {
            double similarity = calculateCosineSimilarity(vectors[i], vectors[j]);
            distances.push_back({{i, j}, 1 - similarity});
        }
    }

    // Sorting based on the cosine distance
    std::sort(distances.begin(), distances.end(),
        [](const std::pair<std::pair<int, int>, double>& a, const std::pair<std::pair<int, int>, double>& b) -> bool {
            return a.second < b.second;
        });

    return distances;
}
