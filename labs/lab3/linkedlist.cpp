#include "linkedlist.h"
#include <iostream>

Node* initializeLinkedList(int size) {
    if (size <= 0) {
        return nullptr;
    } else {
        Node* head = new Node();
        head->data = 0; // Initialize data for the head node
        head->jumper = head; // Set the jumper pointer of the head node to point to itself
        Node* current = head;

        for (int i = 1; i < size; ++i) {
            current->next = new Node();
            current->next->data = i; // Initialize data for each node
            current->next->jumper = current->next; // Set the jumper pointer of each node to point to itself
            current = current->next;
        }

        current->next = head; // Make the last node point back to the head to form a cycle

        return head;
    }
}

void pointerJumping(Node* head) {
    Node* last = head;
    while (last->next != last) {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = last;
        last = last->next;
    }
}

void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void deleteLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        temp->next = nullptr; // Set next pointer to nullptr to avoid double deletion
        delete temp;
    }
}