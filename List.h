/** @file List.h
 *  @brief Header file for List.c.
 *
 *  Header file for List.c where all the necessary libraries are included,
 *  along with the prototypes for the functions.
 *
 *  @author Andreas Pattichis (apatti01)
 *  @bug No know bugs.
 */

#ifndef HANGMAN_ALLINONE_LIST_H
#define HANGMAN_ALLINONE_LIST_H

/* Libraries included */
#include<stdio.h>
#include<stdlib.h> /* Malloc, EXIT */
#include<string.h>
#include <stdbool.h>


/**
 * Struct for NODE
 */
typedef struct node {
    char *name;
    struct node *next;
} NODE;

/**
 * Struct for LIST
 */
typedef struct {
    NODE* head;
    int size;
} LIST;

/* Methods' prototypes. */
//NODE * createNode(char *, NODE *);

/**
 * @brief Deletes NODE from memory
 *
 * Function that clears the memory from the NODE that is given as
 * a parameter, by using the free() method;
 *
 * @param NODE * The node we want to delete.
*/
void deleteNode(NODE *);

/**
 * @brief Prints NODE
 *
 * Function that prints the name of the NODE that is given as a
 * parameter and the name of the NODE that is pointer at next.
 *
 * @param NODE * The node we want to print.
 */
void printNode(NODE *);

/**
 * @brief Initializes a list
 *
 * Allocates the list to the memory and initializes head with
 * null and size with 0.
 *
 * @return LIST * Returns the pointer of a LIST that the method just created,
 */
LIST *createInitialList();

/**
 * @brief Inserts new node to ther list
 *
 * It receives as a parameter the list along with the new character that
 * we want to insert to the list as a node. It creates the new node and
 * adds it to the list as a first node.
 *
 * @param list List that the new node will be added
 * @param x The char that will be added as the new node
 * @return EXIT_SUCCESS or EXIT_FAILURE
 */
int insertNode(LIST *list, char *x);

/**
 * @brief Deletes all the nodes that are on the list
 *
 * Goes throught the list until the list is empty and deletes all the nodes.
 *
 * @param list List that we want to delete.
 * @return EXIT_SUCCESS or EXIT_FAILURE
 */
int deleteList(LIST *list);

/**
 * @brief Checks if the list is empty
 *
 * Check the size of the list and return true or false to indicate if the
 * list is empty.
 *
 * @param list List that we want to check
 * @return True or False
 */
_Bool isEmpty(LIST *list);

/**
 * @brief Prints the list
 *
 * Goes througth the list and prints all the nodes using the printNode() function
 *
 * @param list List we want to print
 */
void printlist(LIST *list);

//void swapList(LIST *l1,LIST *l2);

/**
 * @brief Returns a copy of the list that is given as a parameter
 *
 * @param list we want to print
 * @return A copy of the list
 */
LIST *copyList(LIST *list);

#endif //HANGMAN_ALLINONE_LIST_H
