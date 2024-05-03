#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>

void __insertNode(Node* aRoot, Node* aNode);
Node* __searchTree(Node* aRoot, int aKey);
void __balanceTree(Node* aNode);
int __getBalance(Node* aNode);
int __getHeight(Node* aNode);
int __max(int a, int b);
void __balanceLL(Node* aNode);
void __balanceLR(Node* aNode);
void __balanceRR(Node* aNode);
void __balanceRL(Node* aNode);
void __rotateLeft(Node* aNode);
void __rotateRight(Node* aNode);

Node* insertNode(Node* aRoot, int aKey) {
    // Procura o nó na árvore;
    Node* helper = __searchTree(aRoot, aKey);
    if (NULL == helper  || NULL == aRoot) {
        // Se não achou, cria um novo nó e o adiciona à árvore
        Node* newNode = createNode(aKey);
        __insertNode(aRoot, newNode);
    } else {
        // Senão, só incrementa o count
        helper->count++;
    }
    while (NULL != aRoot->parent) {
        // Procura o novo root
        aRoot = aRoot->parent;
    }
    return aRoot;
}

Node* createNode(int aKey) {
    Node* newNode = malloc(sizeof(Node));
    newNode->count = 1;
    newNode->height = 1;
    newNode->key = aKey;
    newNode->left = NULL;
    newNode->parent = NULL;
    newNode->right = NULL;

    return newNode;
}

void __insertNode(Node* aRoot, Node* aNode) {
    if (NULL == aRoot) {
        aRoot = aNode;
        return;
    }

    if (aNode->key > aRoot->key) {
        if (NULL != aRoot->right) {
            return __insertNode(aRoot->right, aNode);
        } else {
            aRoot->right = aNode;
            aRoot->right->parent = aRoot;
        }
    } else if (aNode->key < aRoot->key) {
        if (NULL != aRoot->left) {
            __insertNode(aRoot->left, aNode);
        } else {
            aRoot->left = aNode;
            aRoot->left->parent = aRoot;
        }
    } else {
        aNode->count++;
        return;
    }

    aNode->height = __max(__getHeight(aNode->left), __getHeight(aNode->right));

    __balanceTree(aNode);
}

int __max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int __getHeight(Node* aNode) {
    if (NULL == aNode)
        return 0;
    return aNode->height;
}

int __getBalance(Node* aNode) {
    return __getHeight(aNode->left) - __getHeight(aNode->right);
}

void __balanceTree(Node* aNode) {
    int balance = __getBalance(aNode);

    if (balance > 1) {
        // Pendendo para esquerda
        if (__getBalance(aNode->left) >= 0) {
            __balanceLL(aNode);
        } else {
            __balanceLR(aNode);
        }
    } else if (balance < 1) {
        if (__getBalance(aNode->right) >= 0) {
            __balanceRR(aNode);
        } else {
            __balanceRL(aNode);
        }
    }
}

void __balanceLL(Node* aNode) {
    __rotateLeft(aNode);
}

void __balanceLR(Node* aNode) {
    __rotateLeft(aNode->left);
    __rotateRight(aNode);
}

void __balanceRR(Node* aNode) {
    __rotateRight(aNode);
}

void __balanceRL(Node* aNode) {
    __rotateRight(aNode->right);
    __rotateLeft(aNode);
}

void printPreOrder(Node* aRoot) {
    printf("%d", aRoot->key);

    if (NULL != aRoot->left)
        printPreOrder(aRoot->left);

    if (NULL != aRoot->right)
        printPreOrder(aRoot->right);
}

Node* __searchTree(Node* aRoot, int aKey) {
    if (NULL == aRoot || aRoot->key == aKey) {
        return aRoot;
    } else if (aKey > aRoot->key) {
        if (NULL != aRoot->right)
            return __searchTree(aRoot->right, aKey);
        return NULL;
    } else {
        if (NULL != aRoot->left)
            return __searchTree(aRoot->left, aKey);
        return NULL;
    }
}

void __rotateLeft(Node* aNode) {

}

void __rotateRight(Node* aNode) {

}