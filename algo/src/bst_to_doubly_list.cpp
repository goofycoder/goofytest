/* 
    Given an ordered binary tree, returns a sorted circular
  doubly-linked list. The conversion is done in-place.
 
    Algorithm:
        - Recusion: similar to in-order traversal
        - left-doubly-list -> the node -> right-doubly-list

    Caution: (TO-DO)
        - coredump generated with _convertToDoublyList() call
            * it's because the in-place conversion messed up the deallocator of BST
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
}
