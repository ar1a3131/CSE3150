#include "queueops.h"
#include <iostream>
#include <fstream>

void pushToQueue(std::queue<MyStruct>& myQueue, const std::string& filename) {
    std::ifstream file(filename);
    int num;
    while (file >> num) {
        MyStruct element;
        element.value = num;
        myQueue.push(element);
        std::cout << "Pushed " << num << " onto queue." << std::endl; // Debugging output
    }
    file.close();
}
void popFromQueue(std::queue<MyStruct>& myQueue) {
    int sum = 0;
    while (!myQueue.empty()) {
        sum += myQueue.front().value;
        myQueue.pop();
    }
    std::cout << "Sum from queue: " << sum << std::endl; // Debugging output
    if (sum < 0) {
        throw std::runtime_error("Negative sum found while popping from queue.");
    }
}