#include <iostream>
#include "bst.hpp"

int BST::getNumOfChild(const Node *p) const
{   
    int rv;

    if (p==NULL)
        return 0;

    if (isLeaf(p)) {
        return 0;
    } else {            // not a leaf node
        if (p->left && p->right) {  // has two children
            rv = 2 + getNumOfChild(p->left) + getNumOfChild(p->right);
        } else {        // has one child
            rv = 1 + getNumOfChild(p->left) + getNumOfChild(p->right);
        }

        return rv;
    }
}   

void TEST_BST_numOfChild()
{
    std::cout << "\n=========== Test NumOfChild for a node in BST.\n";
    
    int a[] = {1,2,3,4,5,6,7,8,9,10};
	int len = sizeof(a)/sizeof(a[0]);
	BST bst = BST(a, len);
    bst.printPretty();

    int numOfNodes = bst.numOfNodes();
    int numOfChild;
    Node *p;

    for(int i=1; i<=numOfNodes; i++) {
        p = bst.kthNode(i);
        numOfChild = bst.getNumOfChild(p);
        std::cout << "Node: " << p->data << " has " << numOfChild << " children.\n"; 
    }
}
