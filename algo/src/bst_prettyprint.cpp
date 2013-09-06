#include <fstream>
#include <iostream>
#include <deque>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
#include "bst.hpp"
#include "algo.hpp"

// Print the arm branches (eg, /    \ ) on a line
void BST::printBranches(int branchLen, 
                        int nodeSpaceLen, 
                        int startLen, 
                        int nodesInThisLevel, 
                        const std::deque<Node*>& nodesQueue, 
                        std::ostream& out) 
{
    std::deque<Node*>::const_iterator iter = nodesQueue.begin();

    for (int i = 0; i < nodesInThisLevel / 2; i++) {  
        out << ((i == 0) ? std::setw(startLen-1) : std::setw(nodeSpaceLen-2)) << "" 
            << ((*iter++) ? "/" : " ");
        out << std::setw(2*branchLen+2) << "" << ((*iter++) ? "\\" : " ");
    }

    out << std::endl;
}


// Print the branches and node (eg, ___10___ )
void BST::printNodes(int branchLen, 
                     int nodeSpaceLen, 
                     int startLen, 
                     int nodesInThisLevel, 
                     const std::deque<Node*>& nodesQueue, 
                     std::ostream& out) 
{
    std::deque<Node*>::const_iterator iter = nodesQueue.begin();

    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
        out << ((i == 0) ? std::setw(startLen) : std::setw(nodeSpaceLen)) << "" 
            << ((*iter && (*iter)->left) ? std::setfill('_') : std::setfill(' '));

        out << std::setw(branchLen+2) 
            << ((*iter) ? intToStr((*iter)->data) : "");

        out << ((*iter && (*iter)->right) ? std::setfill('_') : std::setfill(' ')) 
            << std::setw(branchLen) << "" << std::setfill(' ');
    }

    out << std::endl;
}

// Print the leaves only (just for the bottom row)
void BST::printLeaves(int indentSpace, 
                      int level, 
                      int nodesInThisLevel, 
                      const std::deque<Node*>& nodesQueue, 
                      std::ostream& out) 
{
    std::deque<Node*>::const_iterator iter = nodesQueue.begin();

    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
        out << ((i == 0) ? std::setw(indentSpace+2) : std::setw(2*level+2)) 
            << ((*iter) ? intToStr((*iter)->data) : "");
    }

    out << std::endl;
}

void BST::printPretty() {
    /* 1: control how wide the printed tree is
     * 0: control the indent of left-most node
     */ 
    _printPretty(root, 1, 0, std::cout);
}


// Pretty formatting of a binary tree to the output stream
// @ param
// level  Control how wide you want the tree to sparse 
//      (eg, level 1 has minimum space between nodes, while level 2 has larger space between nodes)
// indentSpace  Change this to add some indent space to the left 
//      (eg, indentSpace of 0 means the lowest level of the left node will stick to the left margin)
void BST::_printPretty(Node *root, 
                      int level, 
                      int indentSpace, 
                      std::ostream& out) 
{
    int h = getHeight();
    int nodesInThisLevel = 1;

    // eq of the length of branch for each node of each level
    int branchLen = 2*((int)std::pow(2.0,h)-1) - (3-level)*(int)std::pow(2.0,h-1);  

    // distance between left neighbor node's right arm and right neighbor node's left arm
    int nodeSpaceLen = 2 + (level+1)*(int)std::pow(2.0,h);  

    // starting space to the first node to print of each level (for the left most node of each level only)
    int startLen = branchLen + (3-level) + indentSpace;  

    std::deque<Node*> nodesQueue;

    nodesQueue.push_back(root);

    for (int r = 1; r < h; r++) {
        printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
        branchLen = branchLen/2 - 1;
        nodeSpaceLen = nodeSpaceLen/2 + 1;

        startLen = branchLen + (3-level) + indentSpace;

        printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);

        for (int i = 0; i < nodesInThisLevel; i++) {
            Node *currNode = nodesQueue.front();
            nodesQueue.pop_front();

            if (currNode) {
                nodesQueue.push_back(currNode->left);
                nodesQueue.push_back(currNode->right);
            } else {
                nodesQueue.push_back(NULL);
                nodesQueue.push_back(NULL);
            }
        }
        
        nodesInThisLevel *= 2;
    }

    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);

    printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue, out);
}

void TEST_prettyprintBST() 
{
    std::cout << "\n *** TEST for prettyprint of BST ***\n";

    int a[] = {1,2,3,4,5,6,7,8,9,10};
	int len = sizeof(a)/sizeof(a[0]);
	BST bst = BST(a, len);

    bst.printPretty();
}
