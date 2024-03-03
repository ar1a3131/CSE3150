#ifndef INTSREADVECTOR_H
#define INTSREADVECTOR_H

#include <iostream>
#include <vector>
#include <string>

std::vector<int> ints_read_vector(std::istream& in_stream);
std::vector<int> ints_read_one_line(std::istream& in_stream);
std::vector<int> ints_read(std::istream& in_stream, const std::string& terminal);
std::vector<long long> parse_input_with_delimiters(const std::string& input);

#endif