#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 10

typedef struct sNode {
    int key;
    struct sNode *left;
    struct sNode *right;
    // struct sNode *parent;
} Node;

void inOrder(Node*);
void preOrder(Node*);
void postOrder(Node*);
Node* createNode(int);
void freeTree(Node*);
Node* treeSearch(Node*, int);
Node* treeIterativeSearch(Node*, int);
Node* treeMin(Node*);
Node* treeMax(Node*);
Node* treeInsert(Node*, int);
Node* treeParent(Node*, Node*);
void treeTransplant(Node*, Node*, Node*);
void treeRemove(Node*, Node*);

int main(){
    srand(time(NULL));

    printf("Array: {");
    printf("}\n");

    //           5
    //         /   \
    //        3    7
    //       / \  / \
    //      1  4 6  8
    //       \       \
    //        2      9
    // Node* node = createNode(5);
    // node->left = createNode(3);
    // node->left->left = createNode(1);
    // node->left->right = createNode(4);
    // node->left->left->right = createNode(2);
    // node->right = createNode(7);
    // node->right->left = createNode(6);
    // node->right->right = createNode(8);
    // node->right->right->right = createNode(9);
    // }

    Node* node = createNode(6);
    node->left = createNode(5);
    node->left->left = createNode(2);
    node->left->right = createNode(4);
    node->right = createNode(7);
    node->right->right = createNode(8);

    // printf("inOrder: {");
    // inOrder(node);
    // printf("}\n");

    // printf("preOrder: {");
    // preOrder(node);
    // printf("}\n");

    // printf("postOrder: {");
    // postOrder(node);
    // printf("}\n");

    // printf("Busca recursiva: ");
    // Node* helper = treeSearch(node, 4);
    // if (NULL != helper) {
    //     printf("%d\n", helper->key);
    // } else {
    //     printf("Num achei\n");
    // }

    // printf("Busca iterativa: ");
    // helper = treeIterativeSearch(node, 4);
    // if (NULL != helper) {
    //     printf("%d\n", helper->key);
    // } else {
    //     printf("Num achei\n");
    // }

    // printf("Mínimo: ");
    // helper = treeMin(node);
    // printf("%d\n", helper->key);

    // printf("Máximo: ");
    // helper = treeMax(node);
    // printf("%d\n", helper->key);

    // printf("Insert: ");
    // treeInsert(node, 10);
    // inOrder(node);
    // printf("\n");

    // printf("Transplant: ");
    // treeTransplant(node, treeSearch(node, 5), treeSearch(node, 4));
    // inOrder(node);
    // printf("\n");

    printf("Remove: ");
    treeRemove(node, treeSearch(node, 3));
    inOrder(node);
    printf("\n");

    freeTree(node);

    return 0;
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
    // node->parent = NULL;
    return node;
}

void freeTree(Node* node) {
    if (NULL != node->left)
        freeTree(node->left);
    if (NULL != node->right)
        freeTree(node->right);

    free(node);
}

Node* treeSearch(Node* node, int aKey) {
    if ((NULL == node) || (node->key == aKey)) {
        return node;
    } else {
        if ((NULL != node->left) && (aKey <= node->left->key)) {
            return treeSearch(node->left, aKey);
        } else {
            return treeSearch(node->right, aKey);
        }
    }
}

Node* treeIterativeSearch(Node* node, int aKey) {
    Node* helper = node;
    while ((NULL != helper) && (aKey != helper->key)){
        if ((NULL != helper->left) && (aKey <= helper->left->key)) {
            helper = helper->left;
        } else {
            helper = helper->right;
        }
    }
    return helper;
}

Node* treeMin(Node* node) {
    if (NULL != node->left)
        return treeMin(node->left);
    return node;
}

Node* treeMax(Node* node) {
    if (NULL != node->right)
        return treeMax(node->right);
    return node;
}

Node* treeInsert(Node* node, int aKey) {
    if (NULL == node)
        return node = createNode(aKey);

    if (aKey < node->key){
        node->left = treeInsert(node->left, aKey);
    } else {
        node->right = treeInsert(node->right, aKey);
    }

    return node;
}

Node* treeParent(Node* parent, Node* child) {
    if ((NULL == parent) || (parent->left == child) || (parent->right == child))
        return parent;

    if (child->key < parent->key) {
        return treeParent(parent->left, child);
    } else {
        return treeParent(parent->right, child);
    }
}

void treeTransplant(Node* root, Node* dest, Node* src) {
    Node* parent = treeParent(root, dest);
    if (NULL == parent)
        root = src;
    else if (dest == parent->left) {
        parent->left = src;
    } else {
        parent->right = src;
    }
}

void treeRemove(Node* root, Node* node) {
    Node* helper;
    if (NULL == node->left) {
        treeTransplant(root, node, node->right);
    } else if (NULL == node->right) {
        treeTransplant(root, node, node->left);
    } else {
        helper = treeMin(node->right);
        if (helper != node->right) {
            treeTransplant(root, helper, helper->right);
            helper->right = node->right;
        }
        treeTransplant(root, node, helper);
        helper->left = node->left;
        free(node);
    }

}