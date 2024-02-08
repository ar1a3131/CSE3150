#include <iostream>
#include <vector>
#include <cstdlib> // for std::rand and std::srand
#include <ctime>   // for std::time

// Function to perform Fisher-Yates shuffle
void shuffle(std::vector<int> &arr) {
    int n = arr.size();
    for (int i = n - 1; i > 0; --i) {
        int j = std::rand() % (i + 1); // Generate random index
        std::swap(arr[i], arr[j]);     // Swap elements
    }
}

// Function to check if a list is well-balanced
bool isWellBalanced(const std::vector<int> &arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
        if (sum < 0) return false;
    }
    return true;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the random number generator

    const int n = 2; // Number of matching symbols

    int numValidated = 0;
    const int totalIterations = 10000; // Total number of iterations
    for (int iter = 0; iter < totalIterations; ++iter) {
        std::vector<int> arr;
        // Step 1: Fill the list with 1s and -1s
        for (int i = 0; i < n; ++i) {
            arr.push_back(1);
            arr.push_back(-1);
        }

        // Step 2: Shuffle the list
        shuffle(arr);

        // Step 3: Check if the list is well-balanced
        if (isWellBalanced(arr)) {
            ++numValidated;
        }
    }

    // Step 4: Compute the proportion of well-balanced lists
    double proportion = static_cast<double>(numValidated) / totalIterations;

    // Output the result
    std::cout << "Proportion of well-balanced lists: " << proportion << std::endl;

    return 0;
}