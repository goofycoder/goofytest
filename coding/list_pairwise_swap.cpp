/*
 *  Given a singly linked list, write a function to swap elements pairwise. 
 *  For example:
 *      Input:  1->2->3->4->5->6->7 
 *      Output: 2->1->4->3->6->5->7
 *
 *      Input:  1->2->3->4->5->6 
 *      Output: 2->1->4->3->6->5
 *
 *  Compile:
 *      g++ -Wall -o list_pairwise_swap list_pairwise_swap.cpp linked_list.cpp
 */
#include <iostream>
#include "linked_list.h"

using namespace std;

void list_pairwise_swap(Node** phead)
{
    Node *zero = *phead;
    if (zero==NULL) 
        return;

    Node* one = zero->next;
    if (one==NULL) 
        return;
    
    Node* two = one->next;
    
    // revert node_one & node_two
    zero = one;
    one = *phead;
    zero->next = one;

    *phead = zero;

    // recursively pairwise swap the rest of the list
    list_pairwise_swap(&two);
    one->next = two;
}

int main()
{
    Node* head = NULL;

    insert_back(&head, 1);
    insert_back(&head, 2);
    insert_front(&head, 3);
    insert_front(&head, 4);
    insert_back(&head, 5);

    cout << "Original list: ";
    print_list(head);

    list_pairwise_swap(&head);

    cout << "List after swap: ";
    print_list(head);

    free_list(head);
    return 0;
}
