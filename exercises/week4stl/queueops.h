#ifndef QUEUEOPS_H
#define QUEUEOPS_H

#include <queue>
#include <string>
#include <fstream>
#include <stdexcept>
#include "struct.h"

void pushToQueue(std::queue<MyStruct>& myQueue, const std::string& filename);

void popFromQueue(std::queue<MyStruct>& myQueue);

#endif