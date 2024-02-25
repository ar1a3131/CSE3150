#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

struct Student {
    int id;
    std::string name;
    int final;
    int midterm;
    std::vector<int> hw_grades;
};

#endif