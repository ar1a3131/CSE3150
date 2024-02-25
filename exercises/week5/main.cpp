#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "grade_calculator.h"

TEST_CASE("GradeCalculatorTest") {
    SUBCASE("TotalScoreCalculation") {
        Student student = {1, "Test Student", 90, 85, {80, 85, 88}};
        GradeCalculator gradeCalculator;
        double totalScore = gradeCalculator.calculateTotalScore(student);
        CHECK(totalScore == doctest::Approx(86.2333));
    }
}