/*
    The mirror of a BST.
        Recursive algorithm
 */
#include <iostream>
#include "bst.hpp"

Node* BST::mirror() const
{
    return _mirror(root);
}

Node* BST::_mirror(Node *p) const
{
    if (p==NULL) 
        return NULL;

    Node* n = new Node(p);
    n->left = _mirror(p->right);
    n->right= _mirror(p->left);
}

void TEST_bst_mirror()
{
    std::cout << "TEST the mirror of BST.\n";

    int a[] = {1,2,3,4,5,6,7,8,9,10};
	int len = sizeof(a)/sizeof(a[0]);
	BST bst = BST(a, len);
    bst.printPretty();

    Node *root_m = bst.mirror();
    BST bst_m = BST(root_m);
    bst_m.printPretty();
}
