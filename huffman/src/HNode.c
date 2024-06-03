#include "HNode.h"
#include <stdlib.h>

HNode *createHNode(char aKey, int aFrequence)
{
    HNode* node = malloc(sizeof(HNode));
    node->key = aKey;
    node->freq = aFrequence;
    node->path = malloc(sizeof(char) * 32);
    node->left = NULL;
    node->right = NULL;

    return node;
}