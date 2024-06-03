#ifndef OrderedList_h
#define OrderedList_h
#include "Node.h"

typedef struct {
    Node* head;
    Node* tail;
    int size;
} OrderedList;

OrderedList* createList();
void insertNode(OrderedList* aList, Node* aNode);
Node* removeNode(OrderedList* aList, Node* aNode);
Node* searchNode(OrderedList* aList, char anInfo);

#endif