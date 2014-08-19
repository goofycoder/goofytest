#include <iostream>
#include "bst.hpp"
using namespace std;

Node* BST::inorderPredecessor(Node *p) const
{
    if (root==NULL || p==NULL) {
        return NULL;
    }

    // if p's left subtree is not null, 
    // return the right-most node of left tree
    if (p->left!=NULL) {
        Node *q = p->left;

        while(q->right) {
            q=q->right;
        }

        return q;
    }

    Node *parent = getParent(p);
    while(parent!=NULL) {
        if (parent->right == p) {
            return parent;
        }

        p = parent;
        parent = getParent(p);
    }
    
    return NULL;
}

Node* BST::inorderSuccessor(Node *p) const
{
    if(root==NULL || p==NULL)
        return NULL;

    if(p->right!=NULL) {
        Node *q = p->right;

        while(q->left) {
            q = q->left;
        }

        return q;
    }

    Node *parent = getParent(p);
    while (parent) {
        if (parent->left == p) {
            return parent;
        }

        p = parent;
        parent = getParent(p);
    }

    return NULL;
}

void TEST_predecessor_successor()
{
    std::cout << "\n *** TEST for predecessor/successor of a given node  ***\n";
    
    /*
                _______5______
               /              \
            ___2__          ___8__
            /      \        /      \
            1       3       6       9
                     \       \       \
                     4       7      10
    */

    int a[] = {1,2,3,4,5,6,7,8,9,10};
	int len = sizeof(a)/sizeof(a[0]);
	BST bst = BST(a, len);
    bst.printPretty();
    
    Node *pre;
    Node *suc;
    Node *p;

    for(int i=1; i<=len; i++) {
        p = bst.kthNode(i);
    
        pre = bst.inorderPredecessor(p);
        if(pre) {
            cout << "Inorder predecessor node is " << pre->data << endl;
        } else {
            cout << "Inorder predecessor node is NULL\n";
        }

        suc = bst.inorderSuccessor(p);
        if(suc) {
            cout << "Inorder successor node is " << suc->data << endl;
        } else {
            cout << "Inorder successor node is NULL\n";
        }
    }
}
