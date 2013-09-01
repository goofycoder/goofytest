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

// get the pointer to the tail node
Node* getTail(Node *p);

// get the n_th node in the list
// the header node is 1st node
Node* getNthNode(Node *p, int n);

void deleteNthNode(Node*& p, int idx);

Node* getPrevNode(Node *head, Node *p);

// get the length of the list
// return 0 if empty list
int getLengthOfList(Node *p);

void showList(Node *p);

void deleteList(Node *p);

// reverse the singly-linked list
// return the head pointer to the reversed list
Node* reverse(Node *);

// detect whether a list has loop
bool findAndRemoveLoop(Node* head, int* loop_len);

#endif // LINKED_LIST_H
