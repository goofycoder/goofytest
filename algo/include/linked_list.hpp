#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/* Singly linked list */
typedef struct node {
        int data;
        struct node *next;
} SNode;

/* basic singly list APIs */
SNode* 
buildListFromArray(const int *array, unsigned len);

/* Insert the node at the tail. */
void insertAtTail(SNode*& head, SNode* p);

void showList(SNode *p);

void deleteList(SNode *p);

// get the pointer to the tail node
SNode* getTail(SNode *p);

// get the n_th node in the list
// the header node is 1st node
SNode* getNthNode(SNode *p, int n);

void deleteNthNode(SNode*& p, int idx);

/*  Input: a pointer to a node on the list (do not need head ptr)
        NOTE: p cannot be the head or tail node   */
void deleteNode(SNode*& p);

SNode* getPrevNode(SNode *head, SNode *p);

// get the length of the list
// return 0 if empty list
int getLengthOfList(SNode *p);

// reverse the singly-linked list
// return the head pointer to the reversed list
SNode* reverse(SNode *);

// detect whether a list has loop
bool findAndRemoveLoop(SNode* head, int* loop_len);

// advance the fast and slow ptr on the linked list
//  - used in the loop detection and split list algorithms
void advance_fast(SNode*& p);
void advance_slow(SNode*& p);

// split the linked list into two halves
// the first list starts at head
// the second list starts at split.
void split_linked_list(SNode* head, SNode*& split);

// add two linked lists as integers
SNode* linked_list_add(SNode* m, SNode* n);

/* Convert integer to list
   Example: 123 ==> 3->2->1 */
SNode* int_to_list(int num);

/* Convert list to integer
   Example: 3->2->1 ==> 123 */
int list_to_int(SNode *p);

#endif // LINKED_LIST_H
