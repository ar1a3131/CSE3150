CXX = g++
CXXFLAGS = -std=c++11 -Wall -I.
TESTFLAGS = -DDOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
SRC_DIR = . # If your .cpp files are in a separate directory, change this

# Source files for the application
APP_SRCS = fisher_yates.cpp gen_permut.cpp prefix_sum.cpp symbolsGen.cpp main.cpp

# Test source files
TEST_FISHER_YATES = unittest_fisherYates.cpp
TEST_GEN_PERMUTATION = unittestpermut.cpp
TEST_PREFIX_SUM = unittest_prefixSum.cpp
TEST_SYM_GEN = unittest_symGen.cpp

# Executable name for the main application
MAIN = wellFormedSymbols

# Executable names for the tests
TEST_EXECUTABLES = fisherYates_test genPermutation_test prefixSum_test symGen_test

.PHONY: all clean run tests check

all: $(MAIN) tests

$(MAIN): $(APP_SRCS)
	$(CXX) $(CXXFLAGS) -o $(MAIN) $(APP_SRCS)

# Test targets
tests: $(TEST_EXECUTABLES)

fisherYates_test: $(TEST_FISHER_YATES)
	$(CXX) $(CXXFLAGS) $(TESTFLAGS) -o fisherYates_test $(TEST_FISHER_YATES) $(filter-out main.cpp, $(APP_SRCS))

genPermutation_test: $(TEST_GEN_PERMUTATION)
	$(CXX) $(CXXFLAGS) $(TESTFLAGS) -o genPermutation_test $(TEST_GEN_PERMUTATION) $(filter-out main.cpp, $(APP_SRCS))

prefixSum_test: $(TEST_PREFIX_SUM)
	$(CXX) $(CXXFLAGS) $(TESTFLAGS) -o prefixSum_test $(TEST_PREFIX_SUM) $(filter-out main.cpp, $(APP_SRCS))

symGen_test: $(TEST_SYM_GEN)
	$(CXX) $(CXXFLAGS) $(TESTFLAGS) -o symGen_test $(TEST_SYM_GEN) $(filter-out main.cpp, $(APP_SRCS))

# Clean up the executable and test executables
clean:
	rm -f $(MAIN) $(TEST_EXECUTABLES)

# Run the main program
run: $(MAIN)
	./$(MAIN)

# Run all tests
check: tests
	@echo "Running tests..."
	@for test in $(TEST_EXECUTABLES); do \
		echo "Running $$test"; \
		./$$test || exit 1; \
	done