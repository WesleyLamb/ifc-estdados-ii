#ifndef OrderedList_h
#define OrderedList_h
#include "Node.h"

typedef struct {
    Node* head;
    Node* tail;
    int size;
} OrderedList;

void insertNode(OrderedList* aList, Node* aNode);

#endif