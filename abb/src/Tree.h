#ifndef Tree_h
#define Trre_h

typedef struct sNode {
    int key;
    struct sNode *left;
    struct sNode *right;
    int count;
    int height;
} Node;

Node *insertNode(Node *node, int key);
void printPreOrder(Node *root);
void printInOrder(Node *root);
Node *deleteNode(Node *root, int key);

#endif