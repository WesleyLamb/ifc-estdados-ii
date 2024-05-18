#include "OrderedList.h"
#include <stdlib.h>

void insertNode(OrderedList *aList, Node *aNode)
{
    Node* helper = aList->head;
    if (aList->size == 0) {
        // Se a lista está zerada
        aList->head = aNode;
        aList->tail = aNode;
    } else {
        // Se não, verifico a posição certa pra inserir
    }

    aList->size++;

    if (pivo == NULL) {
        if (lista->head != NULL) {
            nodo->next = lista->head;
            lista->head->prev = nodo;
            lista->head = nodo;
        } else {
            lista->head = nodo;
            lista->tail = nodo;
        }
    } else {
        nodo->next = pivo->next;
        nodo->prev = pivo;
        if (nodo->prev != NULL) {
            pivo->next = nodo;
        }
        if (nodo->next != NULL) {
            nodo->next->prev = nodo;
        } else {
            lista->tail = nodo;
        }
    }
    lista->size++;
}