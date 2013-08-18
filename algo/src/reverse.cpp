/*
 * Reverse the singly linked list 
 */
#include <iostream>
#include <cstdlib>
#include "linked_list.hpp"

/* singly-linked-list reverse */
Node* reverse(Node *cur)
{
	Node* prev = NULL;
	Node* next;
	
	if(cur==NULL) {
	     return NULL;
	}

	while (cur!=NULL) {
		next      = cur->next;
		cur->next = prev;
		prev      = cur;
		cur       = next;
	}
	
	return prev;
}


void TEST_reverse_list()
{
    int arr[] = {2,3,1,4};
    unsigned len = sizeof(arr)/sizeof(int);

    Node *p = buildListFromArray(arr, len);

	std::cout << "Original list: \n";
	showList(p);
	
	Node* newp = reverse(p);

	std::cout << "Reversed list: \n";
	showList(newp);

	deleteList(newp);
}
