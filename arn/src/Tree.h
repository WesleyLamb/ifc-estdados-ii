#ifndef Tree_h
#define Tree_h

typedef struct sNode
{
    float key;
    struct sNode *left;
    struct sNode *right;
    int color;
    int count;
} Node;

Node *insertNode(Node *, float);
Node *deleteNode(Node *, float);
void printPreOrder(Node *);
void printInOrder(Node *);
void printPostOrder(Node *);

#endif