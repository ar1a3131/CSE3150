#ifndef GRADE_CALCULATOR_H
#define GRADE_CALCULATOR_H

#include "student.h"

class GradeCalculator {
public:
    double calculateTotalScore(const Student& student);
};

#endif