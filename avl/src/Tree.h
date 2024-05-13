#ifndef Tree_h
#define Tree_h

typedef struct sNode
{
    float key;
    struct sNode *left;
    struct sNode *right;
    int height;
    int count;
} Node;

// 1. Todo nó é colorido como vermelho ou preto
// 2. O nó raíz é preto
// 3. Todo nó folha(NULL) é preto
// 4. Se um nó é vermelho, então os seus filhos devem ser pretos
// 5. Para cada nó, todos os caminhos da raíz até as folhas devem ter o mesmo número de nós pretos

Node *insertNode(Node *, float);
Node *deleteNode(Node *, float);
void printPreOrder(Node *);
void printInOrder(Node *);
void printPostOrder(Node *);

#endif