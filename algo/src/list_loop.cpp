/* 
    Three related issues:

   Find the loop: Floyd's cycle detection algorithm 
                  - fast and slow ptr (fast: 2X)
                  - both starts at head
                  - meet if there is a loop
            
   Get the loop length
            - from the point fast and slow ptr meet
            - keep going (fast ptr moves 2X, slow ptr moves 1X)
            - till they meet again (fast ptr moves 1 more circle than slow one does)
            - count the steps till they meet (that's the loop length)

    Remove the loop:   
        - from the point fast and slow ptr meet (let's say Node P)
        - put a pointer Q at the head
        - move both pointers at 1X speed
        - check whether the P->next and Q->next meet first, before move both
            * If the next nodes meet, then P points to the original tail of the node
        
        *** Note the special case (the whole list is a loop: A->B->C->A), then list length is LOOP_LEN-1)
            - simply walk from the head node by LOOP_LEN-1 steps should find the tail node.
 */
#include <iostream>
#include "linked_list.hpp"

static void removeLoop(Node *head, Node *p, int loop_len);

bool findAndRemoveLoop(Node* head,
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

        removeLoop(head, slow_p, loop_len);
        
        return true;
    } else {                    // no loop detected
        return false;
    }
}

/* p is the postion where fast and slow ptr meet during loop detection */
static void removeLoop(Node *head, Node *p, int loop_len)
{
    Node *q = head;

    /* !!! Corner case: slow and fast ptr meet at the head node
     *   Ex:  A->B->C->D->A (the whole list is a loop!)
     *       Loop length = list length + 1
     */
    if (p==head) {
        for(int i=0; i<loop_len-1; i++) {
            p = p->next;
        }

        // recover the original tail node at p
        p->next = NULL;
        return;
    }

    while (p->next != q->next) {
        p=p->next;
        q=q->next;
    }

    // p now points to the tail of the list 
    // remove the loop
    p->next = NULL;
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
    int arr[] = {2,9,5,7,4,8,1,6};
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

    // Make a loop for testing purpose
    if (t) {
        t->next = p;
    }

    int loop_len = 0;

    if (findAndRemoveLoop(head, &loop_len)) {
        std::cout << "Loop detected with length: " << loop_len << "\n";
        std::cout << "After removing the loop: ";
        showList(head);
    } else {
        std::cout << "Loop free list.\n";
    }
}


