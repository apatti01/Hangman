/** @file List.c
 *  @brief Represents a list that stores nodes of strings.
 *
 *  This class follows the header file List.h and completes
 *  all the functions that are need for the class to represent
 *  a list.
 *
 *  @author Andreas Pattichis (apatti01)
 *  @bug No know bugs.
 */

#include "List.h"

/*NODE * createNode(char *name, NODE *next){
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->name = name;
    newNode->next = next;
    return newNode;
}*/

void deleteNode(NODE *node) {
    free(node);
}

void printNode(NODE *node){
    if(node->next != NULL)
        printf("Node -> name = %s \nNode -> next = %s \n\n",node->name,node->next->name);
    else
        printf("Node -> name = %s \nNode -> next = NULL \n\n",node->name);
}

LIST *createInitialList(){
    LIST *list = (LIST *) malloc(sizeof(LIST));
    if (list == NULL) return NULL;
    list->head = NULL;
    list->size = 0;
    return list;
}

_Bool isEmpty(LIST *list){
    if(list->size == 0)return true;
    return false;
}

int insertNode(LIST *list, char *name) {
    NODE *newNode = NULL;
    if (list == NULL){ printf("Unable to find list.\n"); return EXIT_FAILURE; }

    newNode = (NODE *) malloc(sizeof(NODE));
    if ( newNode == NULL ) {printf("Malloc has not been done correctly!\n"); return EXIT_FAILURE;}
    newNode->name = name;
    newNode->next = list->head;
    list->head = newNode;
    (list->size)++;
    return EXIT_SUCCESS;
}

int deleteList(LIST *list){
    if (isEmpty(list)) {
        //printf("List is already empty.\n\n");
        return EXIT_FAILURE;
    }

    while(!isEmpty(list)) {
        NODE *nodeToDelete;

        if (list->head == NULL) {
            //printf("List is already empty.\n\n");
            return EXIT_FAILURE;
        }
        nodeToDelete = list->head;
        list->head = list->head->next;

        //printf("\nData deleted = %d\n", nodeToDelete->name);

        deleteNode(nodeToDelete);
        list->size--;
        //printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n\n");
    }
    return EXIT_SUCCESS;
}

void printlist(LIST* list){
    if(list == NULL)
        printf("List is already empty.\n");

    NODE *newNode = list->head;
    //printNode(newNode);
    while (newNode != NULL){
        printNode(newNode);
        newNode = newNode->next;
        //printNode(newNode);
    }
}

/*void swapList(LIST *l1,LIST *l2) {
    LIST *temp = (LIST *)malloc(sizeof(LIST));
    temp = l1;
    l1=l2;
    l2=temp;
}*/

LIST *copyList(LIST *list){
    LIST *copiedList = (LIST *) malloc(sizeof(LIST));
    NODE *newNode = list->head;
    int i;
    while (newNode != NULL){
        insertNode(copiedList,newNode->name);
        newNode = newNode->next;
    }
    return copiedList;
}

#ifdef DEBUG1
int main(){
    LIST *list = createInitialList();
    printlist(list);
    insertNode(list,'A');
    printlist(list);
    LIST *list2 = copyList(list);
    deleteList(list);
    if(isEmpty(list))
        printf("List 1 is not empty\n");
    else
        printf("List 1 is empty\n");
    if(isEmpty(list2))
        printf("List 2 is not empty\n");
    else
        printf("List 2 is empty\n");
}
#endif