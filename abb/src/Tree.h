typedef struct sNode {
    int key;
    int height;
    struct sNode* parent;
    struct sNode* left;
    struct sNode* right;
} Node;

Node* createNode(int aKey);
Node* insertNode(Node* aNode, Node* aTree);
void orderTree(Node* aTree);
int getHeight(Node* aNode);
void fixLeftLeft(Node*);
void fixRightRight(Node*);
void fixLeftRight(Node*);
void fixRightLeft(Node*);
void inOrder(Node* aNode);
void removeNode(Node* aNode);
Node* searchNode(int aKey);
void freeTree(Node* aNode);
