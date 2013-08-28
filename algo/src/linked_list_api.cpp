/*
 * singly linked list APIs
 */
#include <iostream>
#include <cstdlib>
#include "linked_list.hpp"

void showList(Node* p)
{
    if (p==NULL) 
        return;
    
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
                          
        free(toDelete);
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
