#include "stackops.h"
#include <iostream>
#include <fstream>

void pushToStack(std::stack<MyStruct>& myStack, const std::string& filename) {
    std::ifstream file(filename);
    int num;
    while (file >> num) {
        MyStruct element;
        element.value = num;
        myStack.push(element);
        std::cout << "Pushed " << num << " onto stack." << std::endl; // Debugging output
    }
    file.close();
}

void popFromStack(std::stack<MyStruct>& myStack) {
    int sum = 0;
    while (!myStack.empty()) {
        sum += myStack.top().value;
        myStack.pop();
    }
    std::cout << "Sum from stack: " << sum << std::endl; // Debugging output
    if (sum < 0) {
        throw std::runtime_error("Negative sum found while popping from stack.");
    }
}