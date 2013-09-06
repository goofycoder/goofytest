/*
    1. Get number of child node of a node in BST
        Algorithm:
            return number_of_node_on_left_subtree + number_of_node_on_right_subtree

    2. Get the ptr to the parent node
        Algorithm similar to the binary search
        stop on the parent node
 */
#include <iostream>
#include "bst.hpp"

int BST::getNumOfChild(const Node *p) const
{   
    if (p==NULL)
        return 0;

    return _numOfNodes(p->left) + _numOfNodes(p->right);
}

Node* BST::getParent(const Node* p) const
{
    if (p==root) {      // the parent of ROOT node is NULL
        return NULL;
    }

    return _getParent(root, p);   
}  

Node* BST::_getParent(Node* r, const Node* p) const
{
    if (r==NULL) 
        return NULL;

    if (r->left == p || r->right == p) {
        return r;
    }
    
    if (r->data<p->data) {
        return _getParent(r->right, p);
    } else {
        return _getParent(r->left, p);
    }
}

void TEST_BST_API()
{
    std::cout << "\n=========== Test getNumOfChild() and getParent() for a node in BST.\n";
    
    int a[] = {1,2,3,4,5,6,7,8,9,10};
	int len = sizeof(a)/sizeof(a[0]);
	BST bst = BST(a, len);
    bst.printPretty();

    int numOfNodes = bst.numOfNodes();
    int numOfChild;
    Node *p, *parent;

    for(int i=1; i<=numOfNodes; i++) {
        p = bst.kthNode(i);
        numOfChild = bst.getNumOfChild(p);
            
        parent = bst.getParent(p);

        std::cout << "Node: " << p->data << " has " << numOfChild << " children.";

        if (parent!=NULL) {
            std::cout << " Parent node is " << parent->data << "\n"; 
        } else {
            std::cout << " Parent node is NULL\n"; 
        }
    }
}
