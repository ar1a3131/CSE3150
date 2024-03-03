//unitTests_mainVectors.cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <sstream>
#include <fstream>
#include "intsreadVector.h"
#include "intsVector.h"

TEST_CASE("int_vector default constructor") {
    int_vector vec;
    CHECK(vec.id == -1);
    CHECK(vec.from == 0);
    CHECK(vec.to == 0);
}


TEST_CASE("int_vector parameterized constructor") {
    int_vector vec(1, 2, 3);
    CHECK(vec.id == 1);
    CHECK(vec.from == 2);
    CHECK(vec.to == 3);
}


TEST_CASE("int_vector copy constructor") {
    int_vector original(1, 2, 3);
    int_vector copy = original;
    CHECK(copy.id == original.id);
    CHECK(copy.from == original.from);
    CHECK(copy.to == original.to);
}


TEST_CASE("ints_read_vector functionality") {

    SUBCASE("Simple input") {
        std::istringstream iss("10 20 30");
        auto result = ints_read_vector(iss);
        CHECK(result.size() == 3);
        CHECK(result[0] == 10);
        CHECK(result[1] == 20);
        CHECK(result[2] == 30);
    }


    SUBCASE("Negative numbers") {
        std::istringstream iss("-1 -2 -3");
        auto result = ints_read_vector(iss);
        CHECK(result.size() == 3);
        CHECK(result[0] == -1);
        CHECK(result[1] == -2);
        CHECK(result[2] == -3);
    }

    SUBCASE("Mixed input with non-integer") {
        std::istringstream iss("1 2 three 4");
        auto result = ints_read_vector(iss);
        CHECK(result.size() == 2); 
        CHECK(result[0] == 1);
        CHECK(result[1] == 2);
    }


    SUBCASE("Empty input") {
        std::istringstream iss("");
        auto result = ints_read_vector(iss);
        CHECK(result.empty() == true);
    }
}


TEST_CASE("ints_read_one_line functionality") {

    SUBCASE("Single line input") {
        std::istringstream iss("1 2 3");
        auto result = ints_read_one_line(iss);
        CHECK(result.size() == 3);
        CHECK(result[0] == 1);
        CHECK(result[1] == 2);
        CHECK(result[2] == 3);
    }


    SUBCASE("Multiple lines input") {
        std::istringstream iss("1 2 3\n4 5 6");
        auto result = ints_read_one_line(iss);
        CHECK(result.size() == 3); 
        CHECK(result[0] == 1);
        CHECK(result[1] == 2);
        CHECK(result[2] == 3);
    }

    
    SUBCASE("Empty line") {
        std::istringstream iss("\n1 2 3");
        auto result = ints_read_one_line(iss);
        CHECK(result.empty() == true);
    }
}

TEST_CASE("Parsing input with special delimiters") {
    std::string input = "1,2;3 4,5;6";
    auto result = parse_input_with_delimiters(input);
    CHECK(result.size() == 6);
    CHECK(result[0] == 1);
    CHECK(result[1] == 2);
    CHECK(result[2] == 3);
    CHECK(result[3] == 4);
    CHECK(result[4] == 5);
    CHECK(result[5] == 6);
}


TEST_CASE("Handling large numbers") {
    std::string input = "9223372036854775807, -9223372036854775808";
    auto result = parse_input_with_delimiters(input);
    CHECK(result.size() == 2);
    CHECK(result[0] == 9223372036854775807LL);
    CHECK(result[1] == -9223372036854775807LL - 1); 
}


TEST_CASE("Special error handling") {
    
    SUBCASE("Non-numeric input after numeric") {
        std::istringstream iss("1 2 three");
        auto result = ints_read_vector(iss);
        CHECK(result.size() == 2); 
        CHECK(result[0] == 1);
        CHECK(result[1] == 2);
    }

}

int test_main(int argc, char* argv[]) {
    doctest::Context context(argc, argv);
    return context.run();
}