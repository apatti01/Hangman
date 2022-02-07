/** @file Hashtable.c
 *  @brief Represents a hashtable.
 *
 *  This class follows the header file Hashtable.h and completes
 *  all the functions that are need for the class to represent
 *  a hashtable.
 *
 *  @author Andreas Pattichis (apatti01)
 *  @bug No know bugs.
 */

#include "Hashtable.h"
#include<math.h>

HASHTABLE *createInitialHashTable(int size){
    sizeOfHashTable = (int)pow(2.0,size);
    HASHTABLE *hashtable = (HASHTABLE *) malloc(sizeof(HASHTABLE));
    hashtable->slot = (LIST **) malloc(sizeOfHashTable * sizeof(LIST *));
    int i;
    for(i=0;i<sizeOfHashTable;i++)
        hashtable->slot[i] = createInitialList();

    return hashtable;
}

void calculateHash(HASHTABLE *hashtable, char str[], char inputLetter){
    unsigned id = 0U;
    unsigned i;
    for (i = 0; i < strlen(str); ++i)
        if (str[i] == inputLetter)
            id |= 1U << i;
    hashPlaceWord(hashtable, str, id);
}

void hashPlaceWord(HASHTABLE *hashtable, char str[], int index){
    insertNode(hashtable->slot[index], str);
}

void deleteHashTable(HASHTABLE *hashtable){
    int i;
    for(i=0;i<sizeOfHashTable;i++)
        deleteList(hashtable->slot[i]);

    /* Reinitiazise for the next loop cycle
    for(i=0;i<sizeOfHashTable;i++)
        hashtable->slot[i] = createInitialList();*/
}

void displayInitialHashTable(HASHTABLE *hashtable){
    int i;
    for(i=0;i<sizeOfHashTable;i++) {
        if(hashtable->slot[i]->size>0)printf("LIST no.%d:\n",i);
        printlist(hashtable->slot[i]);
    }
}

int findMaxListFromHashTable(HASHTABLE *hashtable){
    int maxSize = 0, idxOfList = 0, i;
    for(i=0;i<sizeOfHashTable;i++)
        if(hashtable->slot[i]->size>maxSize) {
            maxSize = hashtable->slot[i]->size;
            idxOfList = i;
        }
    return idxOfList;
}

LIST *getMaxListFromHashTable(HASHTABLE *hashtable){
    int idx = findMaxListFromHashTable(hashtable);
    return copyList(hashtable->slot[idx]);
}

void updateHashTable(HASHTABLE *hashtable,LIST* list,char inputLetter){
    NODE *newNode = list->head;
    while (newNode != NULL){
        calculateHash(hashtable, newNode->name, inputLetter);
        newNode = newNode->next;
    }

}

#ifdef DEBUG2
int main() {
    char userLetter = 'A';

    HASHTABLE *hashtable = createInitialHashTable(4);
    LIST *currentList = createInitialList();
    insertNode(currentList, "NEAR");
    insertNode(currentList, "GOOD");
    insertNode(currentList, "HERE");
    insertNode(currentList, "INTO");
    updateHashTable(hashtable, currentList, userLetter);
    displayInitialHashTable(hashtable);
    LIST *optimalList = createInitialList();
    optimalList = getMaxListFromHashTable(hashtable);
    printf("Optimal list: \n");
    printlist(optimalList);
}
#endif