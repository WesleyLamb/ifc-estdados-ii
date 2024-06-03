#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "src/OrderedList.h"
#include "src/Node.h"
#include "src/HNode.h"

#define BUFFER_SIZE 4096

/**
 * Lê uma linha do stdin e retorna um ponteiro para a string
 * Fonte: https://www.youtube.com/watch?v=4_2BEgOFd0E
*/
char* getLn(int* length) {
    char *buffer = malloc(BUFFER_SIZE * sizeof(char));

    // Lê a linha
    fgets(buffer, BUFFER_SIZE, stdin);
    *length = strlen(buffer) - 1;
    // Remove a quebra de linha e substitui por \0
    buffer[*length] = '\0';
    return buffer;
}

void populateList(OrderedList* aList, char* anInfo, int anInfoSize);
int countChar(char* aStr, int aStrSize, char aChar);
void printList(OrderedList* aList);
void inOrder(HNode* aNode);
void preOrder(HNode* aNode, char* path);
void postOrder(HNode* aNode);
void replaceInfo(char* anInfo, HNode* aNode);

int main() {
    char* info = malloc(sizeof(char) * 4096);
    OrderedList* list = createList();
    int infoSize;

    printf("Informe uma frase para compactar: \n");
    info = getLn(&infoSize);

    populateList(list, info, infoSize);
    printf("Dicionario: \n");
    preOrder(list->head->info, "");
    replaceInfo(info, list->head->info);

    free(list);
    free(info);
    return 0;
}

void populateList(OrderedList *aList, char *anInfo, int anInfoSize)
{
    int freq = 0;
    for (int i = 0; i < anInfoSize; i++) {
        if (NULL == searchNode(aList, anInfo[i])) {
            freq = countChar(anInfo, anInfoSize, anInfo[i]);
            insertNode(aList, createNode(createHNode(anInfo[i], freq)));
        }
    }
    // printList(aList);
    while (aList->size > 1) {
        Node* newNode = createNode(createHNode('\0', 0));

        newNode->info->freq = aList->head->info->freq + aList->head->next->info->freq;
        newNode->info->left = aList->head->info;
        newNode->info->right = aList->head->next->info;

        free(removeNode(aList, aList->head));
        free(removeNode(aList, aList->head));

        insertNode(aList, newNode);
    }
}

int countChar(char *aStr, int aStrSize, char aChar)
{
    int result = 0;
    for (int i = 0; i < aStrSize; i++) {
        if (aStr[i] == aChar)
            result++;
    }
    return result;
}

void printList(OrderedList *aList)
{
    Node* helper = aList->head;
    while (NULL != helper) {
        printf("%c %d \n", helper->info->key, helper->info->freq);

        helper = helper->next;
    }
}

void inOrder(HNode* aNode) {
    if (NULL != aNode) {
        inOrder(aNode->left);
        printf("(%c %d)", aNode->key, aNode->freq);
        inOrder(aNode->right);
    }
}

void preOrder(HNode* aNode, char* path) {
    if (NULL != aNode) {
        if (NULL == aNode->left && NULL == aNode->right) {
            printf("(%c %d) - %s \n", aNode->key, aNode->freq, path);
        }
        //  else {
        //     printf("(%c %d) \n", aNode->key, aNode->freq, path);
        // }
        char* newPath1 = malloc(sizeof(char*) * strlen(path) + 2);
        strcpy(newPath1, path);
        strcat(newPath1, "0");
        preOrder(aNode->left, newPath1);
        free(newPath1);

        char* newPath2 = malloc(sizeof(char*) * strlen(path) + 2);
        strcpy(newPath2, path);
        strcat(newPath2, "1");
        preOrder(aNode->right, newPath2);
        free(newPath2);
    }
}

void postOrder(HNode* aNode) {
    if (NULL != aNode) {
        postOrder(aNode->left);
        postOrder(aNode->right);
        printf("(%c %d)", aNode->key, aNode->freq);
    }
}

void replaceInfo(char *anInfo, HNode *aNode)
{

}
