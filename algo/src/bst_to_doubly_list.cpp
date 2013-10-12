/* 
    Given an ordered binary tree, returns a sorted circular
  doubly-linked list. The conversion is done in-place.
 
    Idea: 'left' pointer in Node struct means "prev" ptr.
          'right' pointer in Node struct means "next" ptr.

    Algorithm:
        - Recusion: similar to in-order traversal
        - left-doubly-list -> the node -> right-doubly-list

    Note:
        Because of in-place convertion from BST to doubly-linked-list.
    The deallocation of BST cannot be called. We need to manually free 
    the doubly-linked list.
*/
#include <iostream>
#include "bst.hpp"

Node* BST::convertToDoublyList() 
{
    Node *prev = NULL;
    Node *head = NULL;
    
    _convertToDoublyList(root, prev, head);
  
    return head;
}

void BST::_convertToDoublyList(Node *p, Node *& prev, Node *& head)
{
    if (!p) 
        return; 

    // left substree
    _convertToDoublyList(p->left, prev, head);

    // current node's left points to previous node
    p->left = prev;

    if (prev)
        prev->right = p;
    else
        head = p;
    
    // as soon as the recursion ends, the head's left pointer 
    // points to the last node, and the last node's right pointer
    // points to the head pointer.
    Node *right = p->right;
    head->left = p;
    p->right = head;

    // updates previous node
    prev = p;

    // right substree
    _convertToDoublyList(right, prev, head);
}

void TEST_convertToDoublyList()
{
    std::cout << "TEST convert BST to doubly-linked list.\n";
    
    int a[] = {1,2,3,4,5,6,7,8,9,10};
	int len = sizeof(a)/sizeof(a[0]);
	BST bst = BST(a, len);
    bst.printPretty();

    Node *head = bst.convertToDoublyList();

    // print the circular doubly-linked list
    std::cout << "Converted circular doubly-linked list: \n"; 
    Node *p = head;
    for (int i=0; i<len; i++) {
        std::cout << p->data << " ";
        p = p->right;
    }
    std::cout << "\n";

    // free the list
    for (int i=0; i<len; i++) {
        Node *d = p;
        p=p->right;
        delete d;
    }

    bst.root = NULL;
}
