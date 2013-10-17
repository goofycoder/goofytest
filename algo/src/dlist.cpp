#include "dlist.hpp"
#include <iostream>

/* insert node at the tail of list */
void insertNode(DNode*& head, DNode* p, DNode*& tail)
{
    if (head == NULL) {
        head = p;
        tail = p;
    
        return;
    }

    tail->next = p;
    p->prev = tail;
    tail = p;
}

void removeNode(DNode*& head, DNode* p, DNode*& tail)
{
    // empty list
    if (head == NULL)
        return;
    
    if (head == p && head->next == NULL) {
        delete p;
        head = NULL;
        tail = NULL;
        return;  
    }

    // if p is the head node
    if (head == p) {
        head = head->next;
        delete p;
        return;
    }

    // if the node to delete is tail
    if (p == tail) {
        DNode* prev = p->prev;
        prev->next = NULL;
        tail = prev;
     
        delete p;
        return;
    }

    // delete the p;
    DNode *prev = p->prev;
    DNode *next = p->next;
    prev->next = next;
    next->prev = prev;
    delete p;
}


void showDList(DNode* head)
{
    if (head == NULL) {
        std::cout << "Empty doubly-linked list.\n";
        return;
    }

    DNode *p = head;
    
    while (p) {
        std::cout << p->data;
        p = p->next;
    }

    std::cout << "\n";
}

void deleteDList(DNode* head)
{
    if (head==NULL) 
        return;

    DNode *p = head;

    while (p!=NULL) {
        DNode *toDelete = p;
        p = p->next;

        free(toDelete);
    }
}
