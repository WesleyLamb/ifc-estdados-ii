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
    length = 0;

    // Lê a linha
    fgets(buffer, BUFFER_SIZE, stdin);
    length = strlen(buffer) - 1;
    // Remove a quebra de linha e substitui por \0
    buffer[*length] = '\0';
    return buffer;
}

void populateList(OrderedList* aList, char* anInfo, int anInfoSize);
int countChar(char* aStr, int aStrSize, char aChar);

int main() {
    char* info = malloc(sizeof(char) * 4096);
    OrderedList* list = createList();
    int infoSize;

    printf("Informe uma frase para compactar: \n");
    info = getLn(&infoSize);

    printf("%s", info);

    populateList(list, info, infoSize);

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
