/** @file Hashtable.h
 *  @brief Header file for Hashtable.c.
 *
 *  Header file for Hashtable.c where all the necessary libraries are included,
 *  along with the prototypes for the functions.
 *
 *  @author Andreas Pattichis (apatti01)
 *  @bug No know bugs.
 */

#ifndef HANGMAN_ALLINONE_HASHTABLE_H
#define HANGMAN_ALLINONE_HASHTABLE_H

/* Libraries included */
#include "List.h"

/* Variables to be used */
int sizeOfHashTable;

/**
 * Struct for HASHTABLE
 */
typedef struct {
    LIST **slot;
} HASHTABLE;

/* Methods' prototypes. */
/**
 * @brief Creates and returns the hashtable
 *
 * It calculates the power of the size of the word with 2
 * to calculate the maximum size of the lists that wiil be inserted
 * to the hashtable and cretes the list
 *
 * @param size The size of the hash word
 * @return teh Hashtable
 */
HASHTABLE *createInitialHashTable(int size);

/**
 * @brief Finds and returns the index of the hashtable where the str will be added
 *
 * Finds and returns the index of the hashtable where the str will be added. More
 * specifically the str that is given as a parameter is hashed based on the inputLetter
 * with a unique ID, by converting them to binary numbers' form.
 *
 * @param hashtable The hashtable the the word will be added
 * @param str The word we want to add
 * @param inputLetter The character the the user has inserted from the console
 */
void calculateHash(HASHTABLE *hashtable, char str[], char inputLetter);

/**
 * @brief Inserts the str to the hashtable
 *
 * Gets the index that is found in the calculateHash() and goes to that list
 * and inserts the str.
 *
 * @param hashtable The hashtable the the str will be added
 * @param str The word we want to add
 * @param index The index to the list of the hashtable that the word will go
 */
void hashPlaceWord(HASHTABLE *hashtable, char str[], int index);

//void deleteHashTable(HASHTABLE *hashtable);

/**
 * @brief goes throw the hashtable and prints all the words
 *
 * @param hashtable The hashtable we want to print
 */
void displayInitialHashTable(HASHTABLE *hashtable);

/**
 * @brief Finds and returns the index of the list with the biggest amount of words
 *
 * @param hashtable The hashtable that will be checked
 * @return The index of the list with the biggest amount of words
 */
int findMaxListFromHashTable(HASHTABLE *hashtable);

/**
 * @brief Returns the list with the biggest amount of words, by using the findMaxListFromHashTable() to find the index.
 *
 * @param hashtable hashtable The hashtable that will be checked
 * @return The index of the list with the biggest amount of words
 */
LIST *getMaxListFromHashTable(HASHTABLE *hashtable);

/**
 * @brief Reads the words from the list and adds them to the hashtable
 *
 * @param hashtable Hashtable that the words will be added
 * @param list List that contains the words
 * @param inputLetter The character the user has entered
 */
void updateHashTable(HASHTABLE *hashtable,LIST* list,char inputLetter);

#endif //HANGMAN_ALLINONE_HASHTABLE_H

