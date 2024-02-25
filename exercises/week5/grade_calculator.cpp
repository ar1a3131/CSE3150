#include "grade_calculator.h"
#include <iostream>

double GradeCalculator::calculateTotalScore(const Student& student) {
    // Define weights for each component
    double midtermWeight = 0.3;
    double finalWeight = 0.3;
    double hwWeight = 0.4;

    // Calculate weighted scores for each component
    double midtermScore = student.midterm * midtermWeight;
    double finalScore = student.final * finalWeight;

    double hwTotal = 0;
    for (int grade : student.hw_grades) {
        hwTotal += grade;
    }
    double hwAverage = student.hw_grades.empty() ? 0 : hwTotal / student.hw_grades.size();
    double hwScore = hwAverage * hwWeight;

    // Calculate total score by summing weighted scores
    double totalScore = midtermScore + finalScore + hwScore;

    return totalScore;
}