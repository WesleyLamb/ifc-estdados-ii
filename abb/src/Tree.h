#ifndef Tree_h
#define Trre_h

typedef struct sNode {
    int key;
    struct sNode *left;
    struct sNode *right;
    struct sNode *parent;
    int count;
    int height;
} Node;

Node *insertNode(Node *node, int key);
Node *__insertNode(Node *node, int key);
void printPreOrder(Node *root);
void printInOrder(Node *root);
Node *deleteNode(Node *root, int key);
Node *rightRotate(Node *y);
Node *leftRotate(Node *x);
int getBalance(Node *aNode);

#endif