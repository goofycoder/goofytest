/*
 *  reverse the linked list
 */
#include <iostream>
#include "linked_list.h"
using namespace std;

Node* reverse_list(Node *head)
{
    Node *prev=NULL;
    Node *next = NULL;
    Node *p = head;

    while(p) {
        next = p->next;

        p->next = prev;

        prev = p;

        p = next;
    }

    return prev;
}

int main()
{
    Node* head = NULL;

    insert_back(&head, 1);
    insert_back(&head, 2);
    insert_front(&head, 3);
    insert_front(&head, 4);

    print_list(head);

    Node *rhead = reverse_list(head);
    print_list(rhead);

    free_list(rhead);

    return 0;
}
