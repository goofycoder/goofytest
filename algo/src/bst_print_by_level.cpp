#include <iostream>
#include <queue>
#include "bst.hpp"

static void _printTreeByLevel(Node *p);

void BST::printTreeByLevel() const
{
    _printTreeByLevel(root);
}

static void _printTreeByLevel(Node *p)
{
    int nodeInThisLevel = 0;
    int nodeInNextLevel = 0;
    Node* cur;

    if (p==NULL)
        return;

    std::queue<Node*> nodeQ;

    nodeQ.push(p);
    nodeInThisLevel++;

    while (!nodeQ.empty()) {
        cur = nodeQ.front();
        nodeQ.pop();
        nodeInThisLevel--;

        if(cur) {
            std::cout << cur->data << " ";
            
            nodeQ.push(cur->left);
            nodeQ.push(cur->right);
            nodeInNextLevel += 2;
        }

        if (nodeInThisLevel==0) {
            std::cout << std::endl;
            nodeInThisLevel = nodeInNextLevel;
            nodeInNextLevel = 0;
        }
    }
}

void TEST_printTreeByLevel()
{
    std::cout << "\n *** TEST for print BST  ***\n";
    
    /*
                _______5______
               /              \
            ___2__          ___8__
            /      \        /      \
            1       3       6       9
                     \       \       \
                     4       7      10
    */

    int a[] = {1,2,3,4,5,6,7,8,9,10};
	int len = sizeof(a)/sizeof(a[0]);
	BST bst = BST(a, len);

    bst.printTreeByLevel();
}
