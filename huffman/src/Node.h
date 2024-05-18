#ifndef Node_h
#define Node_h
#include "HNode.h"

typedef struct sNode {
    HNode* info;
    struct sNode *next;
    struct sNode *prev;
} Node;

Node* createNode(HNode* anInfo);

#endif