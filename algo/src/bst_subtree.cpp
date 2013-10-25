/*
    check BST s is BST t's subtree.
        - start with the root, compare the data
        - if root's data are same, check whether they are same
          else
            if (t->data < s->data)
                recursively compare t->right with s
            if (t->data > s->data)
                recursively compare t->left with s 
    
    check BST s and BST t are identical
        - start with the root, compare the data
        - if root's data are same,
            go ahead compare the left subtree and right subtree
 */
#include <iostream>
#include "bst.hpp"

// check whether BST s is BST t's subtree.
bool isSubTree(Node *t, Node *s)   
{
    if (t==NULL) 
        return false;

    if (s==NULL)
        return true;

    if (t->data == s->data)
        return isSameTree(t,s);
    
    if (t->data < s->data) {
        return isSubTree(t->right, s);
    }

    if (t->data > s->data) {
        return isSubTree(t->left, s);
    }
}

// check whether BST s and BST t
bool isSameTree(Node *t, Node *s)
{
    if (t==NULL && s==NULL)
        return true;

    if (t==NULL || s==NULL) 
        return false;

    if (t->data == s->data) { 
        return ( isSameTree(t->left, s->left) && 
                 isSameTree(t->right, s->right) );
    } else { 
        return false;
    }
}

void TEST_subtree()
{
    std::cout << "TEST whether BST s is BST t's subtree.\n";

    int t[] = {1,2,3,4,5,6,7,8,9,10};
    int len_t = sizeof(t)/sizeof(t[0]);

    int s[] = {1,2,3,4};
    int len_s = sizeof(s)/sizeof(s[0]);

    BST bst_t = BST(t, len_t);
    std::cout << "Tree t: \n";
    bst_t.printPretty();

    BST bst_s = BST(s, len_s);
    std::cout << "Tree s: \n";
    bst_s.printPretty();

    if ( isSubTree(bst_t.getRoot(), bst_s.getRoot()) ) {
        std::cout << "Tree s is Tree t's subtree.\n";
    } else {
        std::cout << "Tree s is NOT Tree t's subtree.\n";
    }
}
