#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>

float __max(float, float);
int __height(Node *);
Node *__minValueNode(Node *);
Node *__newNode(float);
Node *__rightRotate(Node *);
Node *__leftRotate(Node *);
int __getBalance(Node *);


// Retorna a altura, se o nodo não existir, retorna zero
int __height(Node *aNode)
{
    if (aNode == NULL)
        return 0;
    return aNode->height;
}

float __max(float a, float b)
{
    if (a > b)
        return a;
    return b;

}

// Create a aNode
Node *__newNode(float aKey)
{
    Node *aNode = malloc(sizeof(Node));
    aNode->key = aKey;
    aNode->left = NULL;
    aNode->right = NULL;
    aNode->height = 1;
    aNode->count = 1;
    return aNode;
}

// Right rotate
/** Diagrama de entrada da árvore
 *              p
 *              |
 *              y
 *            /  \
 *          x   alpha
 *        /  \
 *     gamma beta
 *
 *  Diagrama de saída da árvore
 *              p
 *              |
 *              x
 *            /  \
 *         gamma  y
 *              /  \
 *           beta alpha
*/
Node *__rightRotate(Node *y)
{
    Node *x = y->left;
    Node *beta = x->right;

    x->right = y;
    y->left = beta;

    y->height = __max(__height(y->left), __height(y->right)) + 1;
    x->height = __max(__height(x->left), __height(x->right)) + 1;

    return x;
}

// Left rotate
/** Diagrama da árvore
 *              p
 *              |
 *              x
 *            /  \
 *         alpha  y
 *              /  \
 *            beta gamma
 *
 *  Diagrama de saída da árvore
 *              p
 *              |
 *              y
 *            /  \
 *          x   gamma
 *        /  \
 *     alpha beta
*/
Node *__leftRotate(Node *x)
{
    Node *y = x->right;
    Node *beta = y->left;

    y->left = x;
    x->right = beta;

    x->height = __max(__height(x->left), __height(x->right)) + 1;
    y->height = __max(__height(y->left), __height(y->right)) + 1;

    return y;
}

// Retorna o fator de balanceamento do galho
int __getBalance(Node *aNode)
{
    if (aNode == NULL)
        return 0;
    return __height(aNode->left) - __height(aNode->right);
}


Node *insertNode(Node *aNode, float aKey)
{

    if (aNode == NULL) {
        // Se o galho pai não tem filhos, crio um novo nó e o retorno
        return __newNode(aKey);
    }

    if (aKey < aNode->key) {
        // Se o valor a ser inserido é menor que o valor do nó atual, insere a esquerda
        aNode->left = insertNode(aNode->left, aKey);
    }
    else if (aKey > aNode->key) {
        // Se não, insere a direita
        aNode->right = insertNode(aNode->right, aKey);
    }
    else {
        // Se é igual, só soma a contagem de ocorrências e retorna
        aNode->count++;
        return aNode;
    }

    // Atualiza o height
    aNode->height = 1 + __max(__height(aNode->left),
                             __height(aNode->right));

    // Balanceia a árvore
    int balance = __getBalance(aNode);
    if (balance > 1 && aKey < aNode->left->key) {
        /**
         *          p
         *        /
         *      y
         *    /
         *  x
        */
        return __rightRotate(aNode);
    }

    if (balance < -1 && aKey > aNode->right->key)
        /**
         *  p
         *   \
         *    x
         *     \
         *      y
        */
        return __leftRotate(aNode);

    if (balance > 1 && aKey > aNode->left->key)
    {
        /**
         *  p
         *   \
         *    x
         *   /
         * y
        */
        aNode->left = __leftRotate(aNode->left);
        return __rightRotate(aNode);
    }

    if (balance < -1 && aKey < aNode->right->key)
    {
        /**
         *          p
         *        /
         *      y
         *       \
         *        x
        */
        aNode->right = __rightRotate(aNode->right);
        return __leftRotate(aNode);
    }

    return aNode;
}
// Retorna o menor valor do galho
Node *__minValueNode(Node *aNode)
{
    Node *current = aNode;

    while (current->left != NULL)
        current = current->left;

    return current;
}

// Delete um nó
Node *deleteNode(Node *aRoot, float aKey)
{
    if (aRoot == NULL) {
        // Se a árvore está vazia ou o nó não existe
        return aRoot;
    }

    if (aKey < aRoot->key)
    {
        // Se o nó está a esquerda
        aRoot->left = deleteNode(aRoot->left, aKey);
    }

    else if (aKey > aRoot->key) {
        // Se está a direita
        aRoot->right = deleteNode(aRoot->right, aKey);
    }

    else
    {
        // Se é o nó que quero deletar
        if ((aRoot->left == NULL) || (aRoot->right == NULL))
        {
            // Se não tem uma das folhas ou não tem as duas folhas

            Node *temp = NULL;
            if (NULL != aRoot->left)
                temp = aRoot->left;
            else
                temp = aRoot->right;

            if (temp == NULL)
            {
                temp = aRoot;
                aRoot = NULL;
            }
            else
                *aRoot = *temp;
            free(temp);
        }
        else
        {
            // Se tem as duas folhas, pego a menor maior que a atual e trago ela para a posição do nó que estamos deletando
            Node *temp = __minValueNode(aRoot->right);

            aRoot->key = temp->key;
            // Deleto a folha que subiu
            aRoot->right = deleteNode(aRoot->right, temp->key);
        }
    }

    if (aRoot == NULL)
     {
        // Se o que foi realizado acima acabou com uma folha
        return aRoot;
     }

    // Atualizo o height do galho
    aRoot->height = 1 + __max(__height(aRoot->left),
                             __height(aRoot->right));

    // Balanceio o galho
    int balance = __getBalance(aRoot);
    if (balance > 1 && __getBalance(aRoot->left) >= 0)
        // Se está pendendo à esquerda e é um desbalanceamento LL, rotaciono à direita
        /**
         *          p
         *        /
         *      y
         *    /
         *  x
        */
        return __rightRotate(aRoot);

    if (balance > 1 && __getBalance(aRoot->left) < 0)
    {
        // Se está pendendo à esquerda e é um desbalanceamento LR,
        // rotaciono à esquerda e depois à direita
        /**
         *  p
         *   \
         *    x
         *   /
         * y
        */
        aRoot->left = __leftRotate(aRoot->left);
        return __rightRotate(aRoot);
    }

    if (balance < -1 && __getBalance(aRoot->right) <= 0)
        // Se está pendendo à direita e é um desbalanceamento RR, rotaciono à esquerda
        /**
         *  p
         *   \
         *    x
         *     \
         *      y
        */
        return __leftRotate(aRoot);

    if (balance < -1 && __getBalance(aRoot->right) > 0)
    {
        // Se está pendendo à direita e é um desbalanceamento RL,
        // rotaciono à direita e depois à esquerda
        /**
         *          p
         *        /
         *      y
         *       \
         *        x
        */
        aRoot->right = __rightRotate(aRoot->right);
        return __leftRotate(aRoot);
    }

    return aRoot;
}

void printPreOrder(Node *aRoot)
{
    if (aRoot != NULL)
    {
        printf("%.2f ", aRoot->key);
        printPreOrder(aRoot->left);
        printPreOrder(aRoot->right);
    }
}

void printInOrder(Node* aRoot) {
    if (aRoot != NULL)
    {
        printInOrder(aRoot->left);
        printf("%.2f ", aRoot->key);
        printInOrder(aRoot->right);
    }
}

void printPostOrder(Node* aRoot) {
    if (aRoot != NULL)
    {
        printPostOrder(aRoot->left);
        printPostOrder(aRoot->right);
        printf("%.2f ", aRoot->key);
    }
}