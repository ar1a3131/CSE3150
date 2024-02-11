#ifndef STACKOPS_H
#define STACKOPS_H

#include <stack>
#include <string>
#include <fstream>
#include <stdexcept>
#include "struct.h"

void pushToStack(std::stack<MyStruct>& myStack, const std::string& filename);

void popFromStack(std::stack<MyStruct>& myStack);

#endif