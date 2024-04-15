#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 10

typedef struct sNode {
    int key;
    struct sNode *left;
    struct sNode *right;
    struct sNode *parent;
} Node;

void addToTree(Node*, int);
void inOrder(Node*);
void preOrder(Node*);
void postOrder(Node*);
Node* createNode(int);
void freeTree(Node*);

int main(){
    srand(time(NULL));

    // int* arr = malloc(sizeof(int) * ARR_SIZE);
    // int i;
    printf("Array: {");
    // for (i = 0; i < ARR_SIZE; i++) {
    //     i[arr] = i + 1;
    //     if (0 != i)
    //         printf(", ");
    //     printf("%d", i[arr]);
    // }
    printf("}\n");

    //           5
    //         /   \
    //        3    7
    //       / \  / \
    //      1  4 6  8
    //       \       \
    //        2      9


    Node* node = createNode(5);
    node->left = createNode(3);
    node->left->left = createNode(1);
    node->left->right = createNode(4);
    node->left->left->right = createNode(2);
    node->right = createNode(7);
    node->right->left = createNode(6);
    node->right->right = createNode(8);
    node->right->right->right = createNode(9);
    // for (i = 1; i < ARR_SIZE; i++) {
    //     if (ARR_SIZE / 2 != i)
    //         addToTree(node, i[arr]);
    // }

    printf("inOrder: {");
    inOrder(node);
    printf("}\n");

    printf("preOrder: {");
    preOrder(node);
    printf("}\n");

    printf("postOrder: {");
    postOrder(node);
    printf("}\n");

    freeTree(node);
    // free(arr);

    return 0;
}

void addToTree(Node* node, int aKey) {

}

void inOrder(Node *node)
{
    if (NULL != node) {
        inOrder(node->left);
        printf("%d ", node->key);
        inOrder(node->right);
    }
}

void preOrder(Node* node) {
    if (NULL != node) {
         printf("%d ", node->key);
         preOrder(node->left);
         preOrder(node->right);
    }
}

void postOrder(Node* node) {
    if(NULL != node) {
        postOrder(node->left);
        postOrder(node->right);
        printf("%d ", node->key);
    }
}

Node* createNode(int aKey) {
    Node* node = malloc(sizeof(Node));
    node->key = aKey;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void freeTree(Node* node) {
    if (NULL != node->left)
        freeTree(node->left);
    if (NULL != node->right)
        freeTree(node->right);

    free(node);
}