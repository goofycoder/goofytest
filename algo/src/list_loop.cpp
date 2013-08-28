#include <iostream>
#include "linked_list.hpp"

bool list_hasLoop(Node* head,
                  int* loop_size) 
{
    Node *fast_p = head;
    Node *slow_p = head;

    do {
        advance_fast(fast_p);
        advance_slow(slow_p);
    } while (fast_p!=slow_p && fast_p != NULL);

    if (fast_p == slow_p) {     // loop detected
        // Fast ptr and slow ptr keep going to find the length of loop
        int loop_len = 0;
        do {
            advance_fast(fast_p);
            advance_slow(slow_p);
            loop_len++;
        } while (fast_p != slow_p);

        *loop_size = loop_len;
        
        return true;
    } else {                    // no loop detected
        return false;
    }
}

// pay attention to the argument: the reference to the pointer
// If not pass as reference, the pointer won't move in the caller function.
inline Node* advance_fast(Node *& p) 
{
    (p) ? p=p->next : NULL;
    (p) ? p=p->next : NULL;
}

// pay attention to the argument: the reference to the pointer
// If not pass as reference, the pointer won't move in the caller function.
inline Node* advance_slow(Node*& p)
{
    (p) ? p=p->next : NULL;
}

void TEST_find_loop() 
{
    int arr[] = {2,9,5,7,4,8,1,6,3};
    unsigned arr_len = sizeof(arr)/sizeof(int);
    
    Node *head = buildListFromArray(arr, arr_len);

    showList(head);

    int len = getLengthOfList(head);
    std::cout << "The length of list: " << len << "\n";

    int idx;
    std::cout << "Input an integer to indicate the linked list loops at N_th node (N in [1, len] ): ";
    std::cin >> idx;

    Node *t = getTail(head);

    Node *p = getNthNode(head, idx);
    if (p) {
        std::cout << "Get node to form the loop: " << p->data <<"\n";
    } else {
        std::cout << "Cannot get " << idx << "_th node\n";
        return;
    }

    // Make a loop
    if (t) {
        t->next = p;
    }

    int loop_len = 0;

    if (list_hasLoop(head, &loop_len)) {
        std::cout << "Loop detected with length: " << loop_len << "\n";
    } else {
        std::cout << "Loop free list.\n";
    }
}


