#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "stackops.h"
#include "queueops.h"

TEST_CASE("SumOfStack") {
    std::stack<MyStruct> myStack;

    pushToStack(myStack, "input_positive.txt");
    popFromStack(myStack);

    pushToStack(myStack, "input_negative.txt");
    CHECK_NOTHROW(popFromStack(myStack));
}

TEST_CASE("SumOfQueue") {
    std::queue<MyStruct> myQueue;

    pushToQueue(myQueue, "input_positive.txt");
    popFromQueue(myQueue);

    pushToQueue(myQueue, "input_negative.txt");
    CHECK_NOTHROW(popFromQueue(myQueue));
}