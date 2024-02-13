#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linkedlist.h"
#include <sstream>

using namespace std;

TEST_CASE("TestInitializeLinkedList") {
    // Test with zero nodes
    Node* list0 = initializeLinkedList(0);
    CHECK(list0 == nullptr);

    // Test with one node
    Node* list1 = initializeLinkedList(1);
    CHECK(list1 != nullptr);
    CHECK(list1->data == 0);
    CHECK(list1->next == nullptr);
    CHECK(list1->jumper == list1);

    // Clean up
    deleteLinkedList(list1);

    // Test with multiple nodes
    Node* list2 = initializeLinkedList(5);
    CHECK(list2 != nullptr);
    Node* current = list2;
    Node* last = nullptr;
    int count = 0;
    while (current != nullptr) {
        CHECK(current->data == count);
        last = current;
        current = current->next;
        count++;
    }
    CHECK(count == 5);

    // Check if jumpers point to the last node
    current = list2;
    while (current->next != nullptr) {
        if (current->next != nullptr) {
        CHECK(current->jumper == last);
        }
        current = current->next;
    }

    // Clean up
    deleteLinkedList(list2);
}

TEST_CASE("TestPointerJumping") {
    // Prepare the linked list
    Node* list = initializeLinkedList(3);

    // Call the function to test
    pointerJumping(list);

    // Check if all nodes point to the last node
    Node* current = list;
    while (current->next != current) {
        CHECK(current->next == list);
        current = current->next;
    }

    // Clean up
    deleteLinkedList(list);
}

TEST_CASE("TestPrintLinkedList") {
    // Prepare the linked list
    Node* list = initializeLinkedList(3);

    // Capture the output
    stringstream buffer;
    streambuf *old = cout.rdbuf(buffer.rdbuf());

    // Call the function to test
    printLinkedList(list);

    // Restore the original buffer
    cout.rdbuf(old);

    // Check the output
    string expected = "Node data: 0 Jumper data: 2\nNode data: 1 Jumper data: 2\nNode data: 2 Jumper data: 2\n";
    CHECK(buffer.str() == expected);

    // Clean up
    deleteLinkedList(list);
}

TEST_CASE("TestDeleteLinkedList") {
    // Test deletion of an empty list
    Node* list0 = nullptr;
    deleteLinkedList(list0); // No need to check return value

    // Test deletion of a non-empty list
    Node* list1 = initializeLinkedList(3);
    deleteLinkedList(list1); // No need to check return value
}