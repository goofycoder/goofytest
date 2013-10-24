/*
    Add two linked list as two integers.

    Algorithm:  
        1. Make the linked list from least significant bit to most significant one.
            ex: 123 ==> 3->2->1
        2. Pay attention to the carry bit. 

    Date: 10/22/2013
 */
#include <iostream>
#include "linked_list.hpp"
#include "algo.hpp"

SNode* linked_list_add(SNode* m, SNode* n)
{
    SNode* p = m;
    SNode* q = n;
    int sum;
    int carry_bit = 0;
    SNode* res = NULL;  

    while (p && q) {
        sum = p->data + q->data + carry_bit; 
        carry_bit = sum/10;
        
        SNode *s = new SNode;
        s->data = sum%10;
        s->next = NULL;
        
        insertAtTail(res, s);
    
        p=p->next;
        q=q->next;
    }

    while(p) {
        sum = p->data + carry_bit;
        carry_bit = sum/10;

        SNode *s = new SNode;
        s->data = sum%10;
        s->next = NULL;
        insertAtTail(res,s);
            
        p=p->next;
    }

    while(q) {
        sum = q->data + carry_bit;
        carry_bit = sum/10;
        
        SNode *s = new SNode;
        s->data = q->data;
        s->next = NULL;
        insertAtTail(res,s);
            
        q=q->next;
    }

    if (carry_bit) {
        SNode *s = new SNode;
        s->data = carry_bit;
        s->next = NULL;
        insertAtTail(res,s);
    } 

    return res;
}


/* Convert integer to list
   Example: 123 ==> 3->2->1 */
SNode* int_to_list(int num)
{
    SNode* list=NULL;

    while(num) {
        int d = num%10;

        SNode* p = new SNode;
        p->data = d;
        p->next = NULL;

        insertAtTail(list, p);

        num /= 10;
    } 

    return list;
}

/* Convert list to integer
   Example: 3->2->1 ==> 123 */
int list_to_int(SNode *p)
{
    int res = 0;
    int i = 0;

    while(p) {
        res += p->data * fast_pow(10, i);
        p = p->next;
        i++;
    }

    return res;
}

void TEST_linked_list_add()
{
    std::cout << "TEST added two linked list as integers.\n";

    int m, n;
    std::cout << "Enter integer m: ";
    std::cin >> m;

    std::cout << "Enter integer n: ";
    std::cin >> n;

    SNode *m_list = int_to_list(m);
    SNode *n_list = int_to_list(n);

    showList(m_list);
    showList(n_list);

    // result list 
    SNode *r_list = linked_list_add(m_list, n_list);
    showList(r_list);

    int result = list_to_int(r_list);
    std::cout << "Result: " << result << "\n";

    deleteList(r_list);
    deleteList(m_list);
    deleteList(n_list);
}
