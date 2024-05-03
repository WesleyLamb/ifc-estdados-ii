#ifndef Tree_h
#define Tree_h


typedef struct sNode {
  int key;
  struct sNode *left;
  struct sNode *right;
  int height;
  int count;
} Node;

Node* insertNode(Node*, int);
Node *deleteNode(Node *, int);
void printPreOrder(Node *);
void printInOrder(Node *);
void printPostOrder(Node *);

#endif