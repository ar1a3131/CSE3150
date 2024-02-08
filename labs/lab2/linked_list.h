// linked_list.h
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node {
    int data;
    struct node *next;
};

struct node *build_linked_list(int total_new_elements);
void delete_linked_list(struct node *start);

#endif
