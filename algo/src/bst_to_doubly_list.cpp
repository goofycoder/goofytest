/* 
    Given an ordered binary tree, returns a sorted  doubly-linked list. The conversion is done in-place.
 
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
    Node* root_node = root;
    root = NULL;        // set root to NULL to avoid freeing in the destructor

    return  _convertToDoublyList(root_node);
}

Node* BST::_convertToDoublyList(Node* p)
{
    Node *result = NULL;

    if (p==NULL) 
        return NULL;

    Node* l = _convertToDoublyList(p->left);

    if (l) {
        Node *tail = l;
        while(tail->right) {
            tail = tail->right;
        }
        
        tail->right = p; 
        p->left = tail;
    }

    Node* r = _convertToDoublyList(p->right);
    p->right = r;
  
    if (r) {
        r->left = p;
    }

    if (l) {
        result = l;
    } else {
        result = p;
    }

    return result;
}

void TEST_convertToDoublyList()
{
    std::cout << "TEST convert BST to doubly-linked list.\n";
    
    int a[] = {1,2,3,4,5,6,7,8,9,10};
	int len = sizeof(a)/sizeof(a[0]);
	BST bst = BST(a, len);
    bst.printPretty();

    Node *p = bst.convertToDoublyList();

    // print the circular doubly-linked list
    std::cout << "Converted circular doubly-linked list: \n";
    if (p==NULL)
        std::cout << "empty list.\n";

    while (p) {
        std::cout << p->data << " ";
        p = p->right;
    }
    std::cout << "\n";

    // free the list
    while (p) {
        Node *d = p;
        p = p->right;
        delete d;
    }
}
