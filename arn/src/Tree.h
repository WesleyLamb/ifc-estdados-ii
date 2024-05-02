#ifndef Tree_h
#define Tree_h

#define C_BLACK 0
#define C_RED 1

// Todo no é colorido como vermelho ou preto
// Nó raiz é preto
// Todo nó folha é preto
// Se um nó é vermelho, então seus filhos devem ser pretos
// Para cada nó, todos os caminhos da raiz até as folhas devem ter o mesmo número de nós pretos

typedef struct sNode {
    struct sNode* left;
    struct sNode* right;
    struct sNode* parent;
    int color; // 0: Preto, 1: Vermelho
    int key;
} Node;



Node* leftRotate(Node* root, Node* x) {

}

#endif