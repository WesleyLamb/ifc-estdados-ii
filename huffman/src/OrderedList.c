#include "OrderedList.h"
#include <stdlib.h>

OrderedList *createList()
{
    OrderedList* list = malloc(sizeof(OrderedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void insertNode(OrderedList *aList, Node *aNode)
{
    Node* helper = aList->head;
    if (aList->size == 0) {
        // Se a lista está zerada
        aList->head = aNode;
        aList->tail = aNode;
    } else {
        // Se não, verifico a posição certa pra inserir

        helper = aList->tail;

        while (helper->info->freq > aNode->info->freq) {
            helper = helper->prev;
        }
        aNode->next = helper->next;
        aNode->prev = helper;
        if (helper == aList->tail)
            aList->tail = aNode;
        helper->next = aNode;
        if (NULL != aNode->next)
            aNode->next->prev = aNode;
    }

    aList->size++;
}

Node *removeNode(OrderedList *aList, Node *aNode)
{
    Node* helper = aList->head;
    while (NULL != helper) {
        if (helper == aNode) {
            if (aList->head == helper)
                aList->head = helper->next;

            if (aList->tail == helper)
                aList->tail = helper->prev;

            if (NULL != helper->next)
                helper->next->prev = helper->prev;

            if (NULL != helper->prev)
                helper->prev->next = helper->next;

            aList->size--;
            return helper;
        }
        helper = helper->next;
    }
    return NULL;
}

Node *searchNode(OrderedList *aList, char anInfo)
{
    Node* helper = aList->head;
    while (NULL != helper) {
        if (helper->info->key == anInfo)
            return helper;
        helper = helper->next;
    }
    return NULL;
}
