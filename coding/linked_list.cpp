/*
 *  linked list APIs
 *      - insert_back()
 *      - insert_front()
 *      - reverse_list()
 *      - print_list()
 *      - free_list()
 */
#include <iostream>
using namespace std;

typedef struct node {
    int data;
    struct node* next;
} Node;

void insert_back(Node** phead, int data);
void insert_front(Node** phead, int data);
void print_list(Node* head);
Node* reverse_list(Node *head);
void free_list(Node* head);

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
