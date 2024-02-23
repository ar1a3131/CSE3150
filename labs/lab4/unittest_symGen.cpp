#include "doctest.h"
#include "symbolsGen.h"
#include <numeric> // Include for std::iota

TEST_CASE("Testing generateSymbols") {
    SUBCASE("Generate symbols with size 10") {
        std::vector<int> scrambledSymbols = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        auto symbols = generateSymbols(scrambledSymbols);
        CHECK(symbols.size() == 10);

    }

    SUBCASE("Generate symbols with size 100") {
        std::vector<int> scrambledSymbols(100);
        std::iota(scrambledSymbols.begin(), scrambledSymbols.end(), 1);
        auto symbols = generateSymbols(scrambledSymbols);
        CHECK(symbols.size() == 100);

    }
}