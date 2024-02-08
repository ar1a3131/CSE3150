// linked_list.cpp
#include <iostream>
#include "linked_list.h"

using namespace std;

struct node *build_linked_list(int total_new_elements) {
    if (total_new_elements == 0) {
        return nullptr;
    } else {
        struct node *root = new node;
        root->data = -1;
        struct node *linked_list = root;

        for (int i = 0; i < total_new_elements; i++) {
            linked_list->next = new node;
            linked_list->data = i + 1;
            linked_list = linked_list->next;
        }

        return root;
    }
}

void delete_linked_list(struct node *start) {
    struct node *current = start;
    struct node *next;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}