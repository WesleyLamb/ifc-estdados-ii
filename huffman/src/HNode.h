#ifndef HNode_h
#define HNode_h

typedef struct sHNode {
    int freq;
    char key;
    struct sHNode* left;
    struct sHNode* right;
} HNode;

HNode* createHNode(char aKey, int aFrequence);

#endif