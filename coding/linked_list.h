typedef struct node {
    int data;
    struct node* next;
} Node;

void insert_back(Node** phead, int data);

void insert_front(Node** phead, int data);

void print_list(Node* head);

void free_list(Node* head);

Node* reverse_list(Node *head);

void list_pairwise_swap(Node** phead);
