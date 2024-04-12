#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

class linkedlist {
public:
    linkedlist();
    ~linkedlist();
    void prepend(int value);
    void append(int value);
    int getNodeCount() const;
    void printLst() const;

private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;
};

#endif
