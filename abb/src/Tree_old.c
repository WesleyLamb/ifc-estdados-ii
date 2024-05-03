#include "Tree.h"
#include <stdlib.h>
#include <stdio.h>

int __max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

void innerOrderTree(Node* aNode) {
    if (aNode->left);
}

Node *createNode(int aKey)
{
    Node* node = malloc(sizeof(Node));
    node->key = aKey;
    node->count = 1;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

    return node;
}

void insertNode(int aKey, Node *aTree)
{

    if (akey > aTree->key) {
        if (NULL == aTree->right) {
            aTree->right = aNode;
        } else {
            insertNode(aNode, aTree->right);
        }
    } else if (akey < aTree->key) {
        if (NULL == aTree->left) {
            aTree->left = aNode;
        } else {
            insertNode(aNode, aTree->left);
        }
    }

    // if (aNode->key == aTree->key) {
    //     aTree->count++;
    // } else
    //  if (aNode->key > aTree->key) {
    //     if (NULL == aTree->right) {
    //         aTree->right = aNode;
    //         orderTree(aNode);
    //     }
    //  else {
    //         insertNode(aNode, aTree->right);
    //     }
    // }
    // else {
    //     if (NULL == aTree->left) {
    //         aTree->left = aNode;
    //         orderTree(aTree);
    //     } else {
    //         insertNode(aNode, aTree->left);
    //     }
    // }
}

// void orderTree(Node *aNode) {
//     while (abs(getBalance(aNode)) > 1) {
//         if (getBalance(aNode) > 1)
//             orderTree(aNode->left);
//         else
//             orderTree(aNode->right);
//     }

//     if (NULL != aNode->parent) {
//         orderTree(aNode->parent);
//     }
// }

int getHeight(Node *aNode) {
    if ((NULL != aNode->left) && (NULL != aNode->right)) {
        return 1 + __max(getHeight(aNode->left), getHeight(aNode->right));
    } else if (NULL != aNode->left) {
        return 1 + getHeight(aNode->left);
    } else if (NULL != aNode->right) {
        return 1 + getHeight(aNode->right);
    } else {
        return 1;
    }
}

void inOrder(Node *aNode) {
    if (NULL != aNode->left)
        inOrder(aNode->left);

    printf("%d ", aNode->key);

    if (NULL != aNode->right)
        inOrder(aNode->right);
}

void freeTree(Node *aNode) {
    if (aNode->left)
        freeTree(aNode->left);

    if (aNode->right)
        freeTree(aNode->right);

    free(aNode);
}
