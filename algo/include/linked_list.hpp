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

/* Insert the node at the tail. */
void insertAtTail(Node*& head, Node* p);

void showList(Node *p);

void deleteList(Node *p);

// get the pointer to the tail node
Node* getTail(Node *p);

// get the n_th node in the list
// the header node is 1st node
Node* getNthNode(Node *p, int n);

void deleteNthNode(Node*& p, int idx);

/*  Input: a pointer to a node on the list (do not need head ptr)
        NOTE: p cannot be the head or tail node   */
void deleteNode(Node*& p);

Node* getPrevNode(Node *head, Node *p);

// get the length of the list
// return 0 if empty list
int getLengthOfList(Node *p);

// reverse the singly-linked list
// return the head pointer to the reversed list
Node* reverse(Node *);

// detect whether a list has loop
bool findAndRemoveLoop(Node* head, int* loop_len);

// advance the fast and slow ptr on the linked list
//  - used in the loop detection and split list algorithms
void advance_fast(Node*& p);
void advance_slow(Node*& p);

// split the linked list into two halves
// the first list starts at head
// the second list starts at split.
void split_linked_list(Node* head, Node*& split);

// add two linked lists as integers
Node* linked_list_add(Node* m, Node* n);

/* Convert integer to list
   Example: 123 ==> 3->2->1 */
Node* int_to_list(int num);

/* Convert list to integer
   Example: 3->2->1 ==> 123 */
int list_to_int(Node *p);

#endif // LINKED_LIST_H
