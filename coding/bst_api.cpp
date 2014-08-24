/*
 *  BST APIs
 *      - LCA
 *      - print-by-level
 *
 */
#include <iostream>
using namespace std;

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

void bst_insert(Node*& root, int data);
void bst_inorder_traverse(Node* root);
void bst_free_tree(Node* root);
Node* bst_lca(Node* root, Node* p1, Node* p2);

void bst_insert(Node*& root, int data)
{
    Node *p = new Node;
    p->data = data;
    p->left = NULL;
    p->right = NULL;

    if(root==NULL) {
        root=p;
        return;
    }

    if (root->data < data) {
        bst_insert(root->right, data);
    } else {
        bst_insert(root->left, data);
    }
}

void bst_inorder_traverse(Node* root)
{
    if(root==NULL)
        return;

    bst_inorder_traverse(root->left);
    cout << root->data << " ";
    bst_inorder_traverse(root->right);
}

void bst_free_tree(Node* root)
{
    if(root==NULL)
        return;

    bst_free_tree(root->left);
    bst_free_tree(root->right);

    delete root;
}

Node* bst_search(Node* root, int data)
{
    if (root==NULL)
        return NULL;

    if(data==root->data) {
        return root;
    }

    if(data<root->data) {
        return bst_search(root->left, data);
    } else {
        return bst_search(root->right, data);
    }
}

Node* bst_lca(Node* root, Node* p1, Node* p2) 
{
    if(root==NULL || p1==NULL || p2==NULL)
        return NULL;

    if (p1==root||p2==root) {
        return root;
    }

    if(p1->data<root->data && p2->data<root->data) {
        return bst_lca(root->left, p1, p2);
    }

    if(p1->data>root->data && p2->data>root->data) {
        return bst_lca(root->right, p1, p2);
    }

    if ((p1->data<root->data && p2->data>root->data) ||
        (p1->data>root->data && p2->data<root->data)) 
    {
        return root;
    }

    // won't reach here
}

int main()
{
    Node* root = NULL;

    int a[] = {10,5,15,2,7, 12, 6,13};
    int len = sizeof(a)/sizeof(a[0]);

    int i;
    for(i=0;i<len; i++) {
        bst_insert(root, a[i]);
    }
 
    bst_inorder_traverse(root);
    cout << endl;

    //************ Lowest Common Ancestor **************
    int n1 = 2;
    int n2 = 12;

    Node* p1 = bst_search(root, n1);
    Node* p2 = bst_search(root, n2);

    Node* lca = bst_lca(root, p1, p2);
    if (lca) {
        cout << "LCA: " << lca->data << endl;
    } else {
        cout << "LCA is NULL\n";
    }

    bst_free_tree(root);
}
