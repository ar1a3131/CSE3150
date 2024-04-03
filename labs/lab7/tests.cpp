#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "VectorReader.h"
#include "CosineDistanceCalculator.h"

TEST_CASE("Testing the VectorReader") {
    std::vector<std::vector<double>> expected = {
        {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}
    };
    std::vector<std::vector<double>> result = VectorReader::readVectorsFromFile("vectors.txt"); // Changed to vectors.txt
    CHECK(result == expected);
}

TEST_CASE("Testing the CosineDistanceCalculator") {
    std::vector<double> vecA = {1, 0};
    std::vector<double> vecB = {0, 1};
    double expected_similarity = 0.0; // Cosine of 90 degrees
    double similarity = CosineDistanceCalculator::calculateCosineSimilarity(vecA, vecB);
    CHECK(doctest::Approx(similarity) == expected_similarity);

    std::vector<std::vector<double>> vectors = {vecA, vecB};
    auto distances = CosineDistanceCalculator::calculateAllPairwiseDistances(vectors);
    CHECK(distances.size() == 1);
    CHECK(distances[0].second == doctest::Approx(1.0)); // Cosine distance is 1 - similarity
}
