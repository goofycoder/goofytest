/*
 * bst.h: header file 
 */

#ifndef BST_H_
#define BST_H_

#include <vector>
#include <fstream>
#include <sstream>
#include <deque>

class Node
{
public:
	Node(int _data):data(_data),left(NULL),right(NULL) { }
    Node(Node *p):data(p->data), left(p->left), right(p->right) { }

    //Node& operator= (const

	int   data;
	Node *left;
	Node *right;
};

class BST
{
public:
	BST():root(NULL) {}
    BST(Node *r):root(r) {}
	BST(int a[], int len);
	~BST();

    /* Very useful API */
    void    printPretty();

    Node*   goo(Node* p);

	void    insertNode(const int& dataToInsert);
	void    deleteNode(Node *d);
	Node*   searchNode(const int& key) const;       // Binary search
	void    searchRange(int key1, int key2) const;  // search Range
	
	Node*   sortedArrayToBST(int *arr, int start, int end);

	// Depth-First Traverse
	void    preorderTraverse() const;
	void    inorderTraverse() const;
	void    postorderTraverse() const;	

	//height:
	int     getHeight() const;
	int     numOfNodes() const;

    /* Return the k_th node in the BST
       Index starting with 1, end with the total number of nodes in the tree.
    Example: if a BST has 10 nodes, the index is in the range of [1, 10].
    */
    Node*   kthNode(int k) const;
	
    void    printKthLayer(int k) const;
	
    int     getWidth(int k) const;
	
    void    printAllPath() const;
    
    void    printTreeByLevel() const;
	
	Node*   convTreeToList();
	
    void    printList(Node* p) const;
	
	Node*   sortedListToBST(Node* head, int n);

    Node*   lca(Node* a, Node* b, Node *p) const;    // Least Common Ancestor
	
    void    buildFromInPreOder(int* in, int* pre, int len);
    
    int     getNumOfChild(const Node *p) const;

    Node*   getParent(const Node* p) const;

    // get the smallest node (left most) in the subtree rooted at n.
    Node*   getSmallestNode(Node *n) const;

    Node*   getInorderSuccessor(Node* p) const;

    Node*   mirror() const;             // get the mirror image of a BST
   
    Node*   convertToDoublyList();      // convert BST to doubly-linked list

    bool    isBalanced() const;         // check whether the tree is balanced 
                                        // (no two nodes has height diff larger than 1

    int     getMinDepth() const;
    int     getMaxDepth() const;

    Node*   getRoot() const;            // return root node

    void    write_to_file(std::ofstream& out) const;       // write BST to file
    
    Node*   inorderPredecessor(Node *p) const;
    Node*   inorderSuccessor(Node* p) const;

private:
    Node*   root;                       

	void    deleteWholeTree(Node* p);			// used in the destructor

	// binary search
	Node*   bstSearch(Node* p, int v) const;	// used in search();
	void    searchRange_int(Node* p, int k1, int k2) const;

	// merge two binary search trees
	void    mergeBST(BST* b);
	
    void    preorderVisit(Node* p) const;	    // used in preorderTraverse()
	void    inorderVisit(Node* p) const;		// used in inorderTraverse()
	void    postorderVisit(Node* p) const;		// used in postorderTraverse()

	int     DoGetHeight(Node* p) const; 	
	int     _numOfNodes(Node* p) const;
	Node*   DoKthNode(Node* p, int k) const;
	void    DoPrintKthLayer(Node* p, int k) const;
	int     DoGetWidth(Node* p, int k) const;
	void    DoPrintAllPath(Node* p, int path[], int len) const;	
	void    printPath(int path[], int len) const;
	
	// convert BST to doubly-linked list
	Node*   DoConvTreeToList(Node *p);
	Node*   append(Node* p, Node* q);
	
	Node*   sortedListToBST(Node* list, int start, int end);
    
    void    printBranches(int branchLen, 
                          int nodeSpaceLen, 
                          int startLen, 
                          int nodesInThisLevel, 
                          const std::deque<Node*>& nodesQueue, 
                          std::ostream& out);
    void    printNodes(int branchLen, 
                       int nodeSpaceLen, 
                       int startLen, 
                       int nodesInThisLevel, 
                       const std::deque<Node*>& nodesQueue, 
                       std::ostream& out);

    void    printLeaves(int indentSpace, 
                        int level, 
                        int nodesInThisLevel, 
                        const std::deque<Node*>& nodesQueue, 
                        std::ostream& out);


    Node*   __buildFromInPreOrder(int* in, int* pre, int len);

    bool    isLeaf(const Node* p) const;
    
    void    _printPretty(Node* root, 
                        int level, 
                        int indentSpace, 
                        std::ostream& out);

    Node*   _getParent(Node* r, const Node* p) const;
    
    Node*   _mirror(Node *p) const;
    
    Node*   _convertToDoublyList(Node *p);

    int     _getMinDepth(Node *p) const;
    int     _getMaxDepth(Node *p) const;

    void    _write_to_file(Node* p, std::ofstream& out) const;
};

// Non-member functions
bool isSameTree(Node *t, Node *s);
bool isSubTree(Node *t, Node *s);

#endif /* BST_H_ */
