#include "algo.hpp"
#include "bst.hpp"

BST::BST(int *sorted_arr, int len)
{
    int left  = 0; 
    int right = len-1;
	
    root = sortedArrayToBST(sorted_arr, left, right);
}

Node* BST::sortedArrayToBST(int *arr, int start, int end) 
{
    if (start > end) 
        return NULL;

    int mid = start + (end - start) / 2;

    Node *node  = new Node(arr[mid]);
    node->left  = sortedArrayToBST(arr, start, mid-1);
    node->right = sortedArrayToBST(arr, mid+1, end);
 
    return node;
}

BST::~BST()
{
    if (root != NULL) {
    	deleteWholeTree(root);
    }
}

void BST::deleteWholeTree(Node* p)
{
    if (p == NULL) 
        return;

    deleteWholeTree(p->left);
    deleteWholeTree(p->right);

    delete p;
}

void BST::inorderTraverse() const
{
    inorderVisit(root);
}

/* Internal function for inorderTraverse() */
void BST::inorderVisit(Node* p) const
{
    if (p == NULL) 
        return;

    inorderVisit(p->left);
    std::cout << p->data << " ";
    inorderVisit(p->right);
}

void BST::preorderTraverse() const
{
    preorderVisit(root);
}

void BST::preorderVisit(Node *p) const
{
    if (p == NULL) 
        return;

    std::cout << p->data << " ";
    preorderVisit(p->left);
    preorderVisit(p->right);
}

void BST::postorderTraverse() const
{
    postorderVisit(root);
}

void BST::postorderVisit(Node *p) const
{
    if(p == NULL) return;

    postorderVisit(p->left);
    postorderVisit(p->right);
    std::cout << p->data << " ";
}
void BST::insertNode(const int& data)
{
    Node* pNewNode = new Node(data);
    pNewNode->left = NULL;
    pNewNode->right = NULL;

    if (root == NULL) {
  	    root = pNewNode;
	    return;
    }

    Node* p = root;
    
    while (p != NULL) {
    	if (p->data <= data) {
    	    if (p->right == NULL) {
	        p->right = pNewNode;
	    	return;
	    } else { 
                p = p->right;
            }
	} else {
	    if (p->left == NULL) {
	        p->left = pNewNode;
	        return;
	    } else {
                p = p->left;
            }
	}   
    }
}

void BST::deleteNode(const int& key)
{
#if 0
    if(root == NULL) return;

	// find the node to delete
	Node* p = root;
	while(p != NULL)
	{
		if(p->data)
	}
#endif
}

// wrapper fo bstSearch()
void BST::searchNode(const int& key) const	
{
    bstSearch(root, key);
}

void BST::bstSearch(Node* p, int v) const
{
    if (p==NULL) {
    	std::cout << "Could not find.\n";
	return;
    }

    if (p->data == v) {
	std::cout << "Found.\n";
	return;
    } else if(p->data < v) {
    	bstSearch(p->right, v);
    } else if(p->data > v) {
	bstSearch(p->left, v);
    }	
}

int BST::getHeight() const
{	
     return DoGetHeight(root);
}

int BST::DoGetHeight(Node* p) const
{
    if(p==NULL) 
        return 0;

    return std::max(DoGetHeight(p->left)+1, 
                    DoGetHeight(p->right)+1);
}

int BST::getWidth(int k) const
{
    if(k>getHeight()) {	
	std::cout << "k is larger than the height of the tree\n";
	return -1;
    }
	
    return DoGetWidth(root, k);
}

int BST::DoGetWidth(Node* p, int k) const
{
    if(p==NULL) 
        return 0;
	
    if(k==1)  
        return 1;

    return ( DoGetWidth(p->left, k-1) + 
             DoGetWidth(p->right,k-1) ) ;
}

void BST::printAllPath() const
{
    int height = getHeight();
    int path[height];           // variable-length array

    DoPrintAllPath(root,path, 0);
}

void BST::DoPrintAllPath(Node* p, int path[], int pathLen) const
{
    if(p==NULL) return;

    path[pathLen]=p->data;
    pathLen++;

    if (p->left==NULL && p->right==NULL) {
	printPath(path, pathLen);
    } else {
     	DoPrintAllPath(p->left, path, pathLen);
	DoPrintAllPath(p->right,path, pathLen);
    }
}

void BST::printPath(int path[], int len) const
{
    for(int i=0; i<len; i++) {
	std::cout << path[i] << " ";
    }
    std::cout << "\n";
}

void BST::printKthLayer(int k) const		// root is layer 1
{
    if ( k>getHeight() ) {
	std::cout << "The max height of tree is: " << getHeight() << "\n";
	return;
    }

    DoPrintKthLayer(root, k);
}

void BST::DoPrintKthLayer(Node* p, int k) const
{
    if (p==NULL) return;

    if (k==1) {
	std::cout << p->data << " ";
	return;
    }

    DoPrintKthLayer(p->left, k-1);
    DoPrintKthLayer(p->right, k-1);
}

int BST::numOfNodes() const
{
    return DoNumOfNodes(root);
}

int BST::DoNumOfNodes(Node* p) const
{	
    if (p==NULL)
        return 0;
	
    if (p->right==NULL && p->left==NULL) 
        return 1;

    return DoNumOfNodes(p->left) + DoNumOfNodes(p->right) + 1;	
}

Node* BST::kthNode(int k) const
{
    return DoKthNode(root,k);
}

Node* BST::DoKthNode(Node* p, int k) const
{
    if (p==NULL) 
    	return NULL;

    int leftNodes = DoNumOfNodes(p->left);

    if (k<=leftNodes) 
	return DoKthNode(p->left, k);
    else if(k==leftNodes+1) 
 	return p;
    else if(k>leftNodes+1)
	return DoKthNode(p->right, k-leftNodes-1);
}

void BST::searchRange(int key1, int key2) const
{
     searchRange_int(root, key1, key2);
}

/* internal function for searchRange() */
void BST::searchRange_int(Node* p, int k1, int k2) const
{
    if (p==NULL) 
        return;

    if (k1 < p->data)
 	searchRange_int(p->left,k1,k2);
	
    if (k1 <= p->data && k2 >= p->data)
	std::cout << p->data << " ";
	
    if (k2 > p->data)
	searchRange_int(p->right,k1,k2);
}

Node* BST::convTreeToList()
{
    DoConvTreeToList(root);
}

Node* BST::DoConvTreeToList(Node* p)
{
    if (p==NULL) 
        return NULL;

    Node* lList = DoConvTreeToList(p->left);
    Node* rList = DoConvTreeToList(p->right);

    // make a length-1 doubly-linked list for p
    p->left = p;
    p->right = p;

    lList = append(lList, p);
    lList = append(lList, rList);

    return lList;
}

Node* BST::append(Node* p, Node* q) 
{
    if (p==NULL) 
     	return q;
    if (q==NULL) 
        return p;

    // circular doubly-linked list
    Node* pLast = p->left;
    Node* qLast = q->left;

    // pLast && q
    pLast->right = q;
    q->left = pLast;
	
    // qLast && p
    qLast->right = p;
    p->left = qLast;
    
    return p;
}

void BST::printList(Node* head) const
{
    if (head==NULL) return;

    Node* p = head;

    while (p!=NULL) {
    	std::cout << p->data << " ";
	p=p->right;
	if (p==head) 
            break;
    }

    std::cout << "\n";
}

Node* BST::sortedListToBST(Node* head, int n) 
{
    return sortedListToBST(head, 0, n-1);
}

Node* BST::sortedListToBST(Node* list, int start, int end) 
{
    if (start > end) return NULL;
 
    // same as (start+end)/2, avoids overflow
    int mid = start + (end - start) / 2;
  	
    Node* parent = new Node(list->data);
  	
    Node* leftChild = sortedListToBST(list, start, mid-1);
    parent->left = leftChild;
  	
    list = list->right;
  	
    parent->right = sortedListToBST(list, mid+1, end);
  	
    return parent;
}
