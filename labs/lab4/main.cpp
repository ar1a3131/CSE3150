#include <iostream>
#include <vector>
#include "symbolsGen.h"
#include "gen_permut.h"

int main() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;
    std::cout << std::endl;

    for (int trial = 0; trial < 10; ++trial) {
        std::cout << "Trial " << (trial + 1) << ":" << std::endl;

        std::vector<int> symbols(2 * n + 1);
        // Step 1: Initialize the list
        for (int i = 0; i < n; ++i) symbols[i] = 1;
        for (int i = n; i < 2 * n + 1; ++i) symbols[i] = -1;
        // Print the original list
        std::cout << "Original: ";
        for (int symbol : symbols) {
            std::cout << symbol << " ";
        }
        std::cout << std::endl;


        // Step 2: Scramble the list using Fisher-Yates
        compute_permutation_of_array(&symbols[0], symbols.size());

        // Print the scrambled list
        std::cout << "Scrambled: ";
        for (int symbol : symbols) {
            std::cout << symbol << " ";
        }
        std::cout << std::endl;

        // Check if the first element is -1 and skip processing if so
        if (symbols[0] == -1) {
            std::cout << "Sequence starts with -1, skipping..." << std::endl;
            std::cout << std::endl;
            continue; // Skip this trial

        }

        // Steps 3 to 7: Process the scrambled list into a well-formed sequence
        std::vector<int> wellFormedSymbols = generateSymbols(symbols);

        // Print the well-formed symbols sequence
        std::cout << "Well-formed symbols sequence: ";
        for (int symbol : wellFormedSymbols) {
            std::cout << symbol << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }

    return 0;
}