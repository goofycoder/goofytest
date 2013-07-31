/*
 * Reverse the singly linked list 
 */
#include <iostream>
#include <cstdlib>

typedef struct node {
	int data;
	struct node *next;
} Node;

Node* 
reverse(Node *cur)
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

void printList(Node* p)
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
		p=p->next;
		
		free(toDelete);
	}
}

int main(int argc, char* argv[])
{
	Node *n1, *n2, *n3;
	
	n1 = (Node*)malloc(sizeof(Node));
	n1->data = 1;
	
	n2 = (Node*)malloc(sizeof(Node));
	n1->next = n2;
	n2->data = 2;

	n3 = (Node*)malloc(sizeof(Node));
	n2->next = n3;
	n3->data = 3;
	n3->next = NULL;
	
	std::cout << "Original list: \n";
	printList(n1);
	
	Node* newp = reverse(n1);

	std::cout << "Reversed list: \n";
	printList(newp);

	deleteList(newp);

	return 0;
}
