#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
    int data;
    Node* next;
    Node* jumper;
};

Node* initializeLinkedList(int size);
void pointerJumping(Node* head);
void printLinkedList(Node* head);
void deleteLinkedList(Node* head);

#endif