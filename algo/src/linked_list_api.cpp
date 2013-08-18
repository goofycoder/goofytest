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
