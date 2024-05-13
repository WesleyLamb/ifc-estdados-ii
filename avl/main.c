#include <stdio.h>

#include "src/Tree.h"

int main()
{
    Node *root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 9);
    root = insertNode(root, 8);
    root = insertNode(root, 8.5);

    // root = insertNode(root, 15);
    // root = insertNode(root, 25);
    // root = insertNode(root, 37);
    // root = insertNode(root, 7);
    // root = insertNode(root, 5);
    // root = insertNode(root, 40);
    // root = insertNode(root, 30);
    // root = insertNode(root, 77);
    // root = insertNode(root, 62);
    // root = insertNode(root, 65);
    // root = insertNode(root, 39);
    // root = insertNode(root, 70);

    // printPreOrder(root);
    // printf("\n");

    // root = deleteNode(root, 62);
    // root = deleteNode(root, 65);
    // root = deleteNode(root, 39);
    // root = deleteNode(root, 77);
    // root = deleteNode(root, 30);
    // root = deleteNode(root, 37);

    // printf("Após deletar: ");
    printPreOrder(root);
    printf("\n");

    return 0;
}