/*
 *  LRU cache
 *  
 *      because need to move the entry around, thus double-linked list is a good fit
 *      
 *      head of the list: most recently visited data
 *      tail of the list: least recently visited data 
 *
 *      // NOTE: !!! still broken, but the idea is right!
 *
 */
#include <iostream>
#include <unordered_map>
using namespace std;

typedef struct node {
    void *data;
    struct node* prev;
    struct node* next;
} Node;

Node *head = NULL;
const int CACHE_SIZE = 3;
unordered_map<int, Node*> hashmap;
int size = 0;

void insert_front(Node*& head, void* data);
void remove_tail(Node*& head);
void free_double_list(Node* head);
void print_double_list(Node* head);
void print_node(Node* p);
bool isListFull(Node* head);
void move_to_front(Node*& head, Node* p);

void set(int key, void* data)
{
    Node *p = hashmap[key];

    if(p==NULL) {
        insert_front(head, data);

        hashmap[key] = head;
    } else {
        p->data = data;

        move_to_front(head, p);
        hashmap[key] = head;
    }
}

void* get(int key)
{
    // update hash table
    Node* p = hashmap[key];

    // move the just visited node to the front
    move_to_front(head, p);

    return p;
}

void move_to_front(Node*& head, Node* p)
{
    if (p==NULL || head==NULL)
        return;

    if(p==head) {   // alreay in front
        return;
    }

    Node* prev = p->prev;
    Node* next = p->next;

    prev->next = next;
    next->prev = prev;

    p->next = head;
    p->prev = NULL;

    head = p;
}

void insert_front(Node*& head, void* data)
{
    Node* p = new Node;

    p->data = data;
    p->prev = NULL;
    p->next = NULL;

    if(head==NULL) {
        head = p;
        return;
    }

    if (isListFull(head)) {
        remove_tail(head);
        //update hash table
    }

    p->next = head;
    head->prev = p;

    head = p;
}

bool isListFull(Node* head)
{
    int len = 0;
    
    while(head!=NULL) {
        len++;
        head = head->next;
    }

    if (len == CACHE_SIZE)
        return true;
    else
        return false;
}

void remove_tail(Node*& head)
{
    if (head==NULL) {
        return;
    }

    // only one node (head)
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* tail = head;

    while(tail->next) {
        tail = tail->next;
    }
    
    Node* new_tail = tail->prev;
 
    if(new_tail) {
        new_tail->next = NULL;
    }

    //update hash table
    int key = *(int*)tail->data;
    cout << "remove key: " << key << endl;
    hashmap[key] = NULL;

    delete tail;
}

void free_double_list(Node* head)
{
    if (head==NULL)
        return;

    Node* to_delete = head;
    Node* p = to_delete->next;

    while(p!=NULL) {
        delete to_delete;
        to_delete = p;
        
        if (p->next==NULL) {    // tail of the list; done
            return;
        } 

        p = p->next;
    }
}

void print_node(Node* p)
{
    if (p!=NULL) {
        cout << *(int*)(p->data) << " ";
    }
}

void print_double_list(Node* head)
{
    while(head!=NULL) {
        print_node(head);
        head = head->next;
    }

    cout << endl;
}

int main()
{
    int a[] = {2,3,7,3,5,2};
    //int a[] = {2};
    int len = sizeof(a)/sizeof(a[0]);

    for(int i=0; i<len; i++) {
        set(a[i], &a[i]);
        print_double_list(head);
    }

    free_double_list(head);

    return 0;
}
