/* doubly-linked list */
typedef struct dnode {
    char data;
    struct dnode* prev;
    struct dnode* next;
} DNode;

void insertNode(DNode*& head, DNode* p, DNode*& tail);
void removeNode(DNode*& head, DNode* p, DNode*& tail);
void showDList(DNode* head);
void deleteDList(DNode* head);
