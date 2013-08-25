/* 
    Least Common Ancestor of two nodes 

    search from the root to bottom

    Time Complexity: O(logn)
 */

#include "algo.hpp"
#include "bst.hpp"

/* Least Common Ancestor of two nodes */
Node* BST::lca(Node* a, Node* b, Node *p) const
{
    int pV = p->data;
    int aV = a->data;
    int bV = b->data;

    if (p==NULL) 
        return NULL;
    
    if ( (aV<pV) && (bV<pV) ) {         // both search nodes < the root
        return lca(a, b, p->left);
    } 
    else if ((aV>pV) && (bV>pV)) {    //both search nodes > the root 
        return lca(a, b, p->right);
    } else {                // pV == aV  or pV == bV
                            // aV < pV < bV
                            // bV < pV < aV
        return p;
    }
}

void TEST_lca() 
{
    std::cout << "\n *** TEST for LeastCommon Ancestor of two nodes ***\n";

    int a[] = {1,2,3,4,5,6,7,8,9,10};
	int len = sizeof(a)/sizeof(a[0]);
	BST bst = BST(a, len);
	std::cout << "In-order traverse: ";
	bst.inorderTraverse();
	std::cout << "\nPre-order traverse: ";
	bst.preorderTraverse();
	std::cout << "\nPost-order traverse: ";
	bst.postorderTraverse();

    int n1_v;
    int n2_v;
    std::cout << "\nEnter the value of 1st node: ";
    std::cin >> n1_v;
    std::cout << "\nEnter the value of 2nd node: ";
    std::cin >> n2_v;

    Node *n1 = bst.searchNode(n1_v);
    Node *n2 = bst.searchNode(n2_v);

    Node *node_lca;
    node_lca = bst.lca(n1, n2, bst.root);

    std::cout << "The least common ancestor node: " << node_lca->data << "\n";
}
