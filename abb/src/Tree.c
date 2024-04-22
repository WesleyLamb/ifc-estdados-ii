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
    node->height = 0;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

    return node;
}

void insertNode(Node *aNode, Node *aTree)
{
    if (aNode->key < aTree->key) {

    }
}

int getHeight(Node *aNode)
{
    if ((NULL != aNode->left) && (NULL != aNode->right)) {
        return 1 + max(getHeight(aNode->left), getHeight(aNode->right));
    } else if (NULL != aNode->left) {
        return 1 + getHeight(aNode->left);
    } else if (NULL != aNode->right) {
        return 1 + getHeight(aNode->right);
    } else {
        return 1;
    }
}
