#include "Tree.h"
// AVL tree implementation in C

#include <stdio.h>
#include <stdlib.h>

void balanceTree(Node* aNode) {
    int balance = __getBalance(aNode);

    if (balance > 1) {
        // Se > 1, significa que a árvore está desbalanceada à esquerda
        if (__getBalance(aNode->left->key) >= 0) {
            // Desbalanceamento LL
            __rightRotate(aNode);
        } else if (__getBalance(aNode->left) < 0) {
            // Desbalanceamento LR
            aNode->left = __leftRotate(aNode->left);
            __rightRotate(aNode);
        }
    } else if (balance < -1) {
        // Se < -1, significa que a árvore está desbalanceada à direita
        if (__getBalance(aNode->right) >= 0) {
            // Desbalanceamento RR
            __leftRotate(aNode);
        } else if (__getBalance(aNode->right) < 0) {
            // Desbalanceamento RL
            aNode->right = __rightRotate(aNode->right);
            __leftRotate(aNode);
        }
    }

    // int balance = getBalance(aNode);
    // if (balance > 1 && getBalance(aNode->left) >= 0)
    //     rightRotate(aNode);

    // if (balance > 1 && getBalance(aNode->left) < 0)
    // {
    //     aNode->left = leftRotate(aNode->left);
    //     rightRotate(aNode);
    // }

    // if (balance < -1 && getBalance(aNode->right) <= 0)
    //     leftRotate(aNode);

    // if (balance < -1 && getBalance(aNode->right) > 0)
    // {
    //     aNode->right = rightRotate(aNode->right);
    //     leftRotate(aNode);
    // }
}

int __max(int a, int b);

// Calculate height
int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int __max(int a, int b)
{
    return (a > b) ? a : b;
}

// Create a node
Node *__newNode(int key)
{
    Node *node = (Node *)
        malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->height = 1;
    node->count = 1;
    return (node);
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

    x->parent = y->parent;
    y->parent = x;

    y->height = __max(height(y->left), height(y->right)) + 1;
    x->height = __max(height(x->left), height(x->right)) + 1;

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

    y->parent = x->parent;
    x->parent = y;

    x->height = __max(height(x->left), height(x->right)) + 1;
    y->height = __max(height(y->left), height(y->right)) + 1;

    return y;
}

// Get the balance factor
int __getBalance(Node *aNode)
{
    if (aNode == NULL)
        return 0;
    return height(aNode->left) - height(aNode->right);
}

Node* insertNode(Node *aNode, int aKey) {
    aNode = __insertNode(aNode, aKey);
    while (NULL != aNode->parent) {
        aNode = aNode->parent;
    }
    return aNode;
}

// Insert node
Node *insertNode(Node *aNode, int aKey)
{
    // Como a função é recursiva, se o nó onde eu quero inserir é nulo,
    // retorno um novo nó
    if (aNode == NULL) {
        return __newNode(aKey);
    }

    if (aKey < aNode->key) {
        aNode->left = __insertNode(aNode->left, aKey);
        aNode->left->parent = aNode;
    }
    else if (aKey > aNode->key) {
        aNode->right = __insertNode(aNode->right, aKey);
        aNode->right->parent = aNode;
    } else {
        // Como só adicionei +1 ao count do registro,
        // não alterou a estrutura da árvore
        aNode->count++;
        return aNode;
    }

    // Atualiza o height para facilitar o cálculo do balanceamento
    aNode->height = 1 + __max(height(aNode->left),
                           height(aNode->right));

    balanceTree(aNode);

    return aNode;
}

Node *__minValueNode(Node *node)
{
    Node *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

// Delete a nodes
Node *deleteNode(Node *root, int key)
{
    // Find the node and delete it
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            Node *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            Node *temp = __minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    // Update the balance factor of each node and
    // balance the tree
    root->height = 1 + __max(height(root->left),
                           height(root->right));

    balanceTree(root);

    return root;
}

// Print the tree
void printPreOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printInOrder(Node *root)
{
    if (NULL != root)
    {
        printInOrder(root->left);
        printf("%d:%d ", root->key, root->height);
        printInOrder(root->right);
    }
}