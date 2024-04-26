#include "Tree.h"

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

Node *createNode(int aKey)
{
    Node* node = malloc(sizeof(Node));
    node->key = aKey;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

    return node;
}