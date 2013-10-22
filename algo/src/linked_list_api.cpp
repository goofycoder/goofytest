/*
 * singly linked list APIs
 */
#include <iostream>
#include <cstdlib>
#include "linked_list.hpp"

void showList(Node* p)
{
    if (p==NULL) {
        std::cout << "List is empty\n";
        return;
    }
    
    while (p!=NULL) {
        std::cout << p->data<< " ";
        p=p->next;
    }
    std::cout << std::endl;
}


void deleteList(Node *p)
{
    if (p==NULL) 
        return;

    while (p!=NULL) {
        Node* toDelete = p;
        p = p->next;
                          
        delete toDelete;
    }
}


Node* buildListFromArray(const int *array, unsigned len)
{
    Node *head = NULL;
    Node *tail = NULL;

    for (unsigned i=0; i<len; i++) {
        Node *n = new Node();
        n->data = array[i];
        n->next = NULL;

        if (tail != NULL) {
            tail->next = n;
        } else {    // empty list
            head = n;
        }
   
        tail = n;     
    }

	return head;
}

Node* getTail(Node *p) 
{
    if (p==NULL) 
        return p;

    while(p->next!=NULL) {
        p=p->next;
    }

    return p;
}

int getLengthOfList(Node *p) 
{   
    int len = 0;

    while (p!=NULL) {
        p=p->next;
        len++;
    }

    return len;
}

Node* getNthNode(Node *p, int idx) 
{
    int len = getLengthOfList(p);

    if (idx<=0 || idx>len) {
        return NULL;
    }

    for (int i=1; i<idx; i++) {
        p=p->next;
    }

    return p;
}

void deleteNthNode(Node*& p, int idx) 
{
    Node *toDelete = getNthNode(p, idx);
    if (!toDelete) {
        std::cout << "DeleteNthNode() fails. N_th node is NULL.\n";
        return;
    }

    if (toDelete == p) {    // delete head node
        p = p->next;
        delete toDelete;
    } else {
        Node *prev = getPrevNode(p, toDelete);
        prev->next = toDelete->next;
    }
}

/* 
    Input: Only a pointer to a node on the list (do not need head ptr)
        NOTE: p cannot be the head or tail node       
 */
void deleteNode(Node*& p)
{   
    if (!p) {
        std::cout << "Delete node fails since the node ptr to delete is NULL.\n";
        return;    
    }

    Node *d = p->next;
    if (!d) {           // cannot be tail node 
        std::cout << "Does not support the deletion of tail node.\n";
        return;
    }

    p->data = d->data;
    p->next = d->next;

    delete d;
}

Node* getPrevNode(Node *head, Node *p)
{
    Node *q = head;

    if (p==head)         // previous node of head node is NULL
        return NULL;

    while (q->next!=p) {
        q=q->next;
    }

    return q;
}

void TEST_linked_list()
{
    std::cout << "\n *** TEST for linked list APIs***\n";
    std::cout << "\n * TEST: delete N_th node in linked list\n";
    int arr[] = {2,6,3,1,4,5};
    unsigned len = sizeof(arr)/sizeof(int);
    Node *p = buildListFromArray(arr, len);

    int idx;
    std::cout << "Enter the idx of the node to delete [1, " << len << "]: ";
    std::cin >> idx;  

	std::cout << "\nOriginal list: \n";
	showList(p);
    
    deleteNthNode(p, idx);

    std::cout << "\nThe list after deletion: \n";
	showList(p);

    std::cout << "Enter the idx of the node to delete (cannot be head or tail node) [2, " << len-2 << "]: ";
    std::cin >> idx;  

    Node* d =  getNthNode(p, idx); 
    deleteNode(d);
    
    std::cout << "\nThe list after deletion: \n";
	showList(p);


    deleteList(p);
}
