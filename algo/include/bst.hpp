/*
 * bst.h: header file 
 */

#ifndef BST_H_
#define BST_H_

#include <vector>

class Node
{
public:
	Node(int _data):data(_data),left(NULL),right(NULL) { }
	int   data;
	Node *left;
	Node *right;
};

class BST
{
public:
	BST():root(NULL) {}
	BST(int a[], int len);
	~BST();

	void    insertNode(const int& dataToInsert);
	void    deleteNode(const int& dataToDelete);
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

    Node*   kthNode(int k) const;
	
    void    printKthLayer(int k) const;
	
    int     getWidth(int k) const;
	
    void    printAllPath() const;
	
	Node*   convTreeToList();
	
    void    printList(Node* p) const;
	
	Node*   sortedListToBST(Node* head, int n);

    Node*   lca(Node* a, Node* b, Node *p) const;    // Least Common Ancestor
	
    Node*   root;

private:
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
	int     DoNumOfNodes(Node* p) const;
	Node*   DoKthNode(Node* p, int k) const;
	void    DoPrintKthLayer(Node* p, int k) const;
	int     DoGetWidth(Node* p, int k) const;
	void    DoPrintAllPath(Node* p, int path[], int len) const;	
	void    printPath(int path[], int len) const;
	
	// convert BST to doubly-linked list
	Node*   DoConvTreeToList(Node *p);
	Node*   append(Node* p, Node* q);
	
	Node*   sortedListToBST(Node* list, int start, int end);
};

#endif /* BST_H_ */
