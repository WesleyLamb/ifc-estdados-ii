#include <stdio.h>

#include "src/Tree.h"

int main() {
  Node *root = NULL;

  root = insertNode(root, 2);
//   root = insertNode(root, 1);
//   root = insertNode(root, 7);
//   root = insertNode(root, 4);
//   root = insertNode(root, 5);
//   root = insertNode(root, 3);
//   root = insertNode(root, 8);

  printInOrder(root);

//   root = deleteNode(root, 3);

//   printf("\nAfter deletion: ");
//   printPreOrder(root);

  return 0;
}

// int main() {
//     Node* tree = createNode(15) ;
//     insertNode(createNode(25), tree);
//     insertNode(createNode(37), tree);
//     // insertNode(createNode(7), tree);
//     // insertNode(createNode(5), tree);
//     // insertNode(createNode(40), tree);
//     // insertNode(createNode(30), tree);
//     // insertNode(createNode(77), tree);
//     // insertNode(createNode(62), tree);
//     // insertNode(createNode(65), tree);
//     // insertNode(createNode(39), tree);
//     // insertNode(createNode(70), tree);
//     inOrder(tree);

//     // removeNode(searchNode(62));
//     // inOrder(tree);

//     // removeNode(searchNode(65));
//     // inOrder(tree);

//     // removeNode(searchNode(39));
//     // inOrder(tree);

//     // removeNode(searchNode(77));
//     // inOrder(tree);

//     // removeNode(searchNode(30));
//     // inOrder(tree);

//     // removeNode(searchNode(37));
//     // inOrder(tree);

//     freeTree(tree);

//     return 0;
// }