/*
    Three cases to consider:

    * Case #1: Deleting a leaf (node with no children): 
        - Deleting a leaf is easy, as we can simply remove it from the tree.
    * Case #2: Deleting a node with one child: 
        - Remove the node and replace it with its child.
    * Case #3: Deleting a node with two children: 
        - The node to be deleted is N. Do not delete N. 
          Instead, choose either its in-order successor node or its in-order predecessor node, R. 
          Replace the value of N with the value of R, then delete R.

 */
#include <iostream>
#include "bst.hpp"

void BST::deleteNode(Node *d)
{
    if (!d) {
        std::cout << "The node to delete does not exist.\n";
        return;
    }

    /* Case #1: No child (Leaf node) */
    if (isLeaf(d)) {
        std::cout << "case 1\n";
        Node *p = getParent(d);
        
        // unlink the deleting node and free the node
        if (p->left==d) 
            p->left = NULL;
        else 
            p->right= NULL;

        delete(d);
    }

    /* Case #2: Only one child */
    /* d is parent's left child */
    if (d->left!=NULL && d->right==NULL) {
        std::cout << "case 2: left\n";
        Node *c = d->left;
        Node *p = getParent(d);
        
        if (p->left == d) {
            p->left=c;
        } else {
            p->right=c;
        }

        delete(d);
    }

    /* d is parent's right child */
    if (d->left==NULL && d->right!=NULL) {
        Node *c = d->right;
        Node *p = getParent(d);
        
        if (p->left == d) {
            p->left=c;
        } else {
            p->right=c;
        }

        delete(d);
    }
        
    /* Case #3: Two children */
    if (d->left && d->right) {
        Node *s = getInorderSuccessor(d);

        int tmp = s->data;  // store it temporarily, don't overwrite d's data
                            // otherwise two ndoes have s->data, cannot delete node S

        deleteNode(s);

        d->data = tmp;      // !!! must do it after deleting the node S, otherwise there are two nodes have s->data
    }
}

void TEST_BST_deleteNode()
{
    std::cout << "\n=========== Test the deletion of a node from BST. ============\n";
    
    int a[] = {1,2,3,4,5,6,7,8,9,10};
	int len = sizeof(a)/sizeof(a[0]);
	BST bst = BST(a, len);
    bst.printPretty();
    Node *p;
    int num;

    std::cout << "Enter an interger: ";
    std::cin >> num;
    
    p = bst.searchNode(num);
    bst.deleteNode(p);
    bst.printPretty();
}
