#include "Node.h"
#include <stdlib.h>

Node *createNode(HNode *anInfo)
{
    Node* node = malloc(sizeof(Node));
    node->info = anInfo;
    node->prev = NULL;
    node->next = NULL;

    return node;
}