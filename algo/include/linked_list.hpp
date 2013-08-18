#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/* Singly linked list */
typedef struct node {
        int data;
        struct node *next;
} Node;

/* basic singly list APIs */
Node* 
buildListFromArray(const int *array, unsigned len);

void showList(Node *p);

void deleteList(Node *p);

Node* reverse(Node *);

#endif // LINKED_LIST_H
