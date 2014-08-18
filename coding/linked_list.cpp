/*
 *  linked list APIs
 *      - insert_back()
 *      - insert_front()
 *      - print_list()
 *      - free_list()
 */
#include <iostream>
#include "linked_list.h"
using namespace std;

void insert_front(Node** phead, int data)
{
    Node *n = new Node;
    n->data = data;
    n->next = NULL;

    if(*phead == NULL) {
        *phead=n;
        return;
    }

    n->next = *phead;
    *phead = n;
}

void insert_back(Node** phead, int data) 
{
    Node* n = new Node;
    n->data = data;
    n->next = NULL;

    if(*phead==NULL) {
        *phead=n;
        return;
    }

    // find the tail
    Node *t = *phead;
    while(t->next) {
        t = t->next;
    }
    
    t->next = n;
}

void free_list(Node* head) 
{
    if(head==NULL) 
        return;

    Node *cur = head;
    Node *next = NULL;

    while(cur) {
        next = cur->next;
        delete(cur);
        cur = next;
    }
}

void print_list(Node* head)
{
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}
