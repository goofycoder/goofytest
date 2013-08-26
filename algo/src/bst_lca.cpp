/* 
    Least Common Ancestor of two nodes 

    search from the root to bottom
    
   Different cases:
	1. Both nodes are to the left of the tree (recursively search on left subtree)
	2. Both nodes are to the right of the tree (recursively search on right subtree)..
	3. One node is on the left while the other is on the right
	4. One of (or both) the search nodes equals to the current tree-root node.
		** Both 3 and 4 return the current root node (p in the code below)

    Time Complexity: O(logn)
 */

#include "algo.hpp"
#include "bst.hpp"

/* Least Common Ancestor (LCA) of two nodes
   Input:   
  	p: the root node of the current subtree 
    	a: search node 1
 	b: search node 2
   Output:
   	the LCA node
 */
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
    bst.printPretty(bst.root, 1, 0, std::cout);

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
