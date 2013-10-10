/*
    Circular sorted singly-linked list (CSList)

    Given a random ptr to a node on the CSList,
    insert a number to CSList.

    Algorithm: insert x into the list (ascending order)
        Traverse the list:
        Case 1. if find t <= x < t->next
                Action: insert x node
        Case 2. if traverse encounters the minimum node ( t->data > t->next->data)
                Action: check whether x is max node or min node.
                        if x is max node, insert before the min node
                        if x is min node, insert before the min node, update min_node
        Case 3. if traverse back to the starting node
                It means one node case or all the nodes have same value
                Action: insert x before the staring node                
 */

#include <iostream>

typedef struct _node {
    int data;
    struct _node *next;
} Node;

/************************************************
 ******* Circular Sorted List (CSList) ***********
 ************************************************/
class CSList {
public:
    CSList() { min_node = NULL; }

    CSList(int x) { min_node = new Node; min_node->data = x; min_node->next = min_node; }

    ~CSList() { delete_list(); }

    /* Given the random ptr to list, insert a number to the list */
    void insert(Node* p, int x);

    /* Get the ptr to the random node on the list (for test purpose) */
    Node* getRandomNode() const;
    
    Node* getMinNode() const { return min_node; }    
    
    void printList() const;

private:
    Node* min_node; 

    /* free all the nodes on the list */
    void delete_list();
    
    int getLength() const;
};

/* Suppose no idea about min_node's existence, 
 * only knowledge about the list is random node p */
void CSList::insert(Node* p, int x)
{
    if (!p)
        return;

    Node* n = new Node;
    n->data = x;
    n->next = NULL;

    Node* t = p;

    /* traverse the list */
    do {
        /* Case 1: x falls in the gap*/
        if (t->data <= x && x < t->next->data) {
            Node *q = t->next;
            t->next = n;
            n->next = q;
            return;
        }

        /* Case 2: */
        if (t->next->data < t->data) {
            // t is the max node
            // t->next is the min node
            if (x >= t->data || x < t->next->data) {
                Node *q = t->next;
                t->next = n;
                n->next = q;
        
                // update the min_node
                if (n->data < min_node->data) {
                    min_node = n;
                }

                return;
            }
        }

        /* Case 3 */
        if (t->next == p) {
            Node *q = t->next;
            t->next = n;
            n->next = q;
            return;
        }

        t = t->next;
    } while (t!=p);
}


void CSList::delete_list()
{
    /* empty list */
    if (!min_node)
        return;

    Node *d;        // node to delete
    Node *p = min_node->next;

    while (p != min_node) {
        d = p;
        delete d;
        p = p->next;
    }

    delete min_node;
}


void CSList::printList() const
{
    if (!min_node)
        std::cout << "Empty list\n";

    Node *p = min_node;

    std::cout << "\nCircular sorted list: \n";
    
    do {
        std::cout << p->data << " ";
        p=p->next;
    } while (p != min_node);
    
    std::cout << "\n";
}

Node* CSList::getRandomNode() const
{
    int len = getLength();


    // generate a random number 
    srand(time(NULL));
    int rand_idx = rand()%len;

    /* find the N th node */
    Node *p = min_node;
    for (int i=rand_idx; i>0; i--) {
        p=p->next;
    }

    return p;
}

int CSList::getLength() const
{
    if (!min_node)
        return 0;

    int len = 1;

    Node *p = min_node;

    while(p->next != min_node) {
        p = p->next;
        len++;
    }

    return len;
}

void TEST_circular_sorted_list()
{
    std::cout << "TEST circular sorted list.\n";  
    
    CSList csl(2); 
    csl.printList();

    Node *m = csl.getMinNode();
    csl.insert(m, 4);
    csl.printList();

    Node *p;
    // insert another node
    p = csl.getRandomNode();
    csl.insert(p, 1);
    csl.printList();

    // insert another node
    p = csl.getRandomNode();
    csl.insert(p, 2);
    csl.printList();
}
