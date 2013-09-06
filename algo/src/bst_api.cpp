/*
    1. Get number of child node of a node in BST
        Algorithm:
            return number_of_node_on_left_subtree + number_of_node_on_right_subtree

    2. Get the ptr to the parent node
        Algorithm similar to the binary search
        stop on the parent node

    3. Get the inorder successor of a node (N)
        Case#1: node N has right subtree
            - return the smallest node on the right tree
        Case#2: node N has no right subtree, and N is its parent's left child
            - return its parent
        Case#3: node N has no right subtree, and N is its parent's right child
            - trace back towards the root, stop till the node is the parent's left child
                * if all the way back to root's parent(NULL), return NULL
                * otherwise return the node where it stops
        
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

Node* BST::getInorderSuccessor(Node* p) const 
{
    // if p has right subtree
    if (p->right) {
        // return the left most node on the right subtree
        return getSmallestNode(p->right);
    } 

    // p is a root  and p does not have right subtree
    if (p == root) {
        return NULL;
    }

    Node *parent = getParent(p);
    // if p is the left child of the parent
    if (p == parent->left) {
        return parent;   
    } else {
        while (p != parent->left) {
            p = parent;
            parent = getParent(p);
            if (parent == NULL)
                break;
        }

        if (parent==NULL) {
            return NULL;
        } else {
            return parent;
        }
    }
}

Node* BST::getSmallestNode(Node *n) const
{
    Node* p = n;

    while (p->left) {
        p = p->left;
    }
    
    return p;
}

void TEST_BST_API()
{
    std::cout << "\n=========== Test BST APIs.==============\n";
    
    int a[] = {1,2,3,4,5,6,7,8,9,10};
	int len = sizeof(a)/sizeof(a[0]);
	BST bst = BST(a, len);
    bst.printPretty();

    int numOfNodes = bst.numOfNodes();
    int numOfChild;
    Node *p, *parent, *s;

    for(int i=1; i<=numOfNodes; i++) {
        p = bst.kthNode(i);
        numOfChild = bst.getNumOfChild(p);
            
        parent = bst.getParent(p);

        std::cout << "Node: " << p->data << " has " << numOfChild << " children.";

        if (parent!=NULL) {
            std::cout << " Parent node is " << parent->data << ".";  
        } else {
            std::cout << " Parent node is NULL."; 
        }

        s = bst.getInorderSuccessor(p);
        if (s!=NULL) {
            std::cout << " Inorder successor node is " << s->data << "\n";
        } else {
            std::cout << " Inorder successor node is NULL.\n";
        }
    }
}
