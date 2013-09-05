#include "bst.hpp"

// MAX_VALUE specify the max value of any node in the tree
//      - used to build the hash table
const int MAX_VALUE = 256;           
int hashTbl[MAX_VALUE] = {0};

static void initHashTbl(int* in, int *pre, int len);
static inline int hash_lookup(int key);

void BST::buildFromInPreOder(int* in, int* pre, int len)
{
    initHashTable(in, pre, len);

    root = _buildFromInPreOrder(in, pre, len);
}

Node* BST::_buildFromInPreOrder(int* in, int* pre, int len)
{
    // *pre is the root node in the subtree 
    // because pre-order traverse visits root node first
    Node *r = new Node(*pre);

    if (len == 0) 
        return NULL;

    // inorder array:  { [left-subtree], root, [right-subtree] }
    int idx = hash_lookup(*pre);    // find root's index in inorder array

    r->left  = _buildFromInPreOrder(in, pre+1, i+1);

    r->right = _buildFromInPreOrder(in+i+1, pre+i+1, len-(i+1));

    return r;
}

// hash table is used to convert the node value in the pre-order array
// to the index in the in-order array
static void initHashTbl(int* in, int *pre, int len) 
{
    for(int i=0; i<len; i++) {
        hashTbl[in[i]] = i;
    }
}

static inline int hash_lookup(int key)
{
    return hashTbl[key];
}


void TEST_buildBSTFromInPreOrder() 
{
    std::cout << "\n *** TEST for LeastCommon Ancestor of two nodes ***\n";


}
