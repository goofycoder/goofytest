/* Test driver for binary search tree */

#include <iostream>
#include <vector>
#include "bst.h"

int main() 
{
    test_InsertNode();

    test_TreeTraverse();
    
    test_TreeAPI();

    test_BinarySearch();

	return 0;
}

void test_InsertNode() 
{
    std::cout << "\n========== Running " << __FUNCTION__ <<"\n";
	
    BST bst;
	bst.insertNode(10);
	bst.insertNode(3);
	bst.insertNode(8);
	bst.insertNode(18);
	bst.insertNode(7);
	bst.insertNode(9);
	bst.insertNode(12);
	bst.insertNode(21);

	std::cout << "In-order traverse: ";
	bst.inorderTraverse();
	std::cout << "\n";
    
    std::cout << "Pre-order traverse: ";
	bst.preorderTraverse();
	std::cout << "\n";
	
    std::cout << "Post-order traverse: ";
	bst.postorderTraverse();
	std::cout << "\n";
}

void test_TreeTraverse() 
{
    std::cout << "\n=========== Running " << __FUNCTION__ <<"\n";

	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int len = sizeof(a)/sizeof(a[0]);
	BST bst = BST(a, len);
	
	std::cout << "In-order traverse: ";
	bst.inorderTraverse();
	std::cout << "\n";
    
    std::cout << "Pre-order traverse: ";
	bst.preorderTraverse();
	std::cout << "\n";

	std::cout << "Post-order traverse: ";
	bst.postorderTraverse();
	std::cout << "\n";
}

void test_TreeAPI()
{
    std::cout << "\n=========== Running " << __FUNCTION__ <<"\n";
	
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int len = sizeof(arr)/sizeof(arr[0]);
	BST bst = BST(arr, len);
	
    /* Basic stats of the BST */
    std::cout << "Number of Nodes: " << bst.numOfNodes() << "\n";		
	unsigned height = bst.getHeight();
	std::cout << "Height of tree: " << height << "\n";
	
    /* Range search
     * Given range [left, right], find all the elements in the BST that 
     * fall into this range. 
     */
    int left = -1;
	int right = 5;
    std::cout << "\n=========== Range search test ==========\n";
    std::cout << "Search the nodes with values between " << left << " and " << right << "\n";
	bst.searchRange(left, right);
	std::cout << "\n";
	
    /* fetch the k-th node */
    unsigned idx = 7;
	std::cout << "\nGet the " << idx << "_th Node in the tree: \n";
	Node* p = bst.kthNode(idx);
	if (p!=NULL) {
        std::cout << idx << "th node is: " << p->data << "\n";
    }

    std::cout << "\n=========== Printing all layers in the tree\n";
    for(unsigned i=1; i<=height; i++) {
		std::cout << "Layer " << i << ": ";
		bst.printKthLayer(i);
		std::cout << "\n";
	}
	
    std::cout << "\n=========== Printing the width of all layers in the tree\n";
	for(unsigned i=1; i<=height; i++) {
		std::cout << "Width of layer " << i << ": " << bst.getWidth(i) << "\n";
	}

    std::cout << "\n=========== Printing All Paths in the tree\n";
	bst.printAllPath();
}

void test_BinarySearch() 
{
    std::cout << "\n=========== Running " << __FUNCTION__ <<"\n";
  
    int a[] = {1,2,3,4,5,6,7,8,9,10};
	int len = sizeof(a)/sizeof(a[0]);
	BST bst = BST(a, len);
	std::cout << "In-order traverse: ";
	bst.inorderTraverse();
	std::cout << "\n";
	
	int key = 11;
    std::cout << "Binary search for value: " << key << "\n";
	bst.searchNode(key);
}
