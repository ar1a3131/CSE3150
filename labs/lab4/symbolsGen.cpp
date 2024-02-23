#include <vector>
#include "prefix_sum.h"
#include "gen_permut.h"
#include "symbolsGen.h"

std::vector<int> generateSymbols(const std::vector<int>& scrambledSymbols) {
    if (scrambledSymbols.empty() || scrambledSymbols[0] == -1) {
        return std::vector<int>(); // Return an empty vector to indicate skipping
    }

    int min_valley_index = index_of_lowest_prefix_sum_element(&scrambledSymbols[0], scrambledSymbols.size());

    std::vector<int> P1(scrambledSymbols.begin(), scrambledSymbols.begin() + min_valley_index + 1);
    std::vector<int> P2(scrambledSymbols.begin() + min_valley_index + 1, scrambledSymbols.end());

    P1.pop_back(); 

    std::vector<int> well_balanced_symbols;
    well_balanced_symbols.insert(well_balanced_symbols.end(), P2.begin(), P2.end());
    well_balanced_symbols.insert(well_balanced_symbols.end(), P1.begin(), P1.end());

    return well_balanced_symbols;
}
