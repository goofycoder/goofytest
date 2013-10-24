/*
    Split a linked list to half. If the length is odd-number, 
    then the first list contains 1 more node.

    Example:  1->2->3->4->5
        After split:
            List 1:  1->2->3
            List 2:  4->5

    Algorithm:
        Use fast and slow pointers.

        When the faster pointer traverse to the end of list,
        the slow ptr is around the half of the list.
 */
#include <iostream>
#include "linked_list.hpp"

void split_linked_list(SNode* head, SNode*& split) 
{
    SNode* fast = head;
    SNode* slow = head;
    SNode* slow_prev = NULL;

    do {
        advance_fast(fast);
        slow_prev = slow;
        advance_slow(slow);
    } while (fast!=NULL);

    split = slow;

    // set the first list's tail->next = NULL; 
    slow_prev->next = NULL;
}

void TEST_split_list()
{
    std::cout << "\n * TEST split the linked list into half\n";
    int arr[] = {2,3,5,7,9};
    unsigned len = sizeof(arr)/sizeof(int);
    SNode *head = buildListFromArray(arr, len);
    
    SNode *head_2;

    split_linked_list(head, head_2);

    std::cout << "After split: \n";
    std::cout << "List 1: ";
    showList(head);
    std::cout << "List 2: ";
    showList(head_2);
}
