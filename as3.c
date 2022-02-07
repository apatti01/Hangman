/** @file as3.c
 *  @brief Represents the game hangman.
 *
 *  This class includes the previous headers and by combining them
 *  with the methods that are applied in this .c file, it creates
 *  the game hangman as the instructions of the homework have asked to.
 *
 *  @author Andreas Pattichis (apatti01)
 *  @bug No know bugs.
 */

#include "Hashtable.h"

/**
 * @brief Reads the size of the word from the text file
 *
 * @param file Text file
 * @return the size of the words
 */
int readSize (FILE* file){
    int i = 0;
    fscanf (file, "%d", &i);
    //printf ("%d \n", i);

    return i;
}

/**
 * @brief Returns the word with capital letters
 *
 * Returns the word with capital letters by using toupper() method for each character
 *
 * @param word Word that we want to capitalise
 */
void capitaliseWord(char *word){
    int i=0;
    char chr;
    while (word[i]) {
        chr = word[i];
        if(chr >= 'a' && chr <= 'z')
            word[i] = chr-(int)'a'+(int)'A';
        i++;
    }
}

/**
 * @brief Updates the progress string that shows what characters the user has found
 *
 * Checks if any of the characters in the optimal list that is added as a parameter,
 * are also in the inputLetter and if so the progress string is updated. It returns
 * 0 if no progress has been made and 1 if any progress has been made.
 *
 * @param progress String that shows what characters the user has found
 * @param list The optimal list that contains the maximum number of words
 * @param inputLetter The character that the user has entered
 * @return 0 or 1
 */
int updateProgress(char *progress,LIST *list,char inputLetter){
    int i,flag=0;
    for(i=0;i<strlen(list->head->name);i++)
        if(list->head->name[i] == inputLetter) {
            progress[i] = inputLetter;
            flag = 1;
        }
    return flag;
}

/**
 * @brief Reads all the words from text file and inserts them to list that is returned
 *
 * @param file Text file
 * @param wordSize the length of the words that are in the text
 * @return A LIST that has all the words of the text file
 */
LIST *readWordsFromFile (FILE* file, int wordSize){
    LIST *list = createInitialList();
    char *str = (char *)malloc((wordSize+1)*sizeof(char));

    if (file == NULL) return NULL;
    int count = 0;
    while (!feof(file))
    {
        fscanf(file,"%s",str);
        capitaliseWord(str);
        int i;
        char *newStr = (char *)malloc((strlen(str))*sizeof(char));
        for(i=0;i<strlen(str);i++)
            newStr[i] = str[i];
        insertNode(list,newStr);
        //printf("%s", str);
        count++;
    }
    //printf("\nThis file has %d words in it.\n", count);
    //printlist(list);
    fclose(file);
    return list;
}

int main(int args, char* argv[]) {

    if (args < 2) {
        printf("You should enter all 2 files.\n");
        exit(1);
    }

    FILE *textReader = fopen(argv[1], "r");
    if (textReader == NULL) {
        printf("File not found.\n");
        exit(1);
    }


    int wordSize = readSize(textReader);

    printf("**************************************************\n"
           "*** Welcome to (Evil) Hangman ***\n"
           "*** You are going to play against the computer ***\n"
           "**************************************************\n\n");

    printf("How many total guesses?  ");
    int totalGuesses;
    scanf("%d",&totalGuesses);

    char *progress = (char *)malloc((wordSize + 1) * sizeof(char));
    int i;
    for(i=0;i<wordSize;i++)
        progress[i] = '_';
    progress[wordSize] = '\0';

    char userLetter=0;
    int wordFound = 0, firstCycle = 1;
    LIST *optimalList, *currentList;
    HASHTABLE *hashtable;

    int *alphabet = (int *)malloc(26 * sizeof(int));
    int z;
    for(z=0;z<26;z++)
        alphabet[z] = 0;

    while(totalGuesses>0 && wordFound == 0){
        printf("-------------------------------\n");
        if(firstCycle == 0) printf("Words possible: %d\n",optimalList->size);
        printf("Progress: %s\n", progress);
        printf("Number of Guesses: %d\n", totalGuesses);
        printf("Guess a letter: ");
        scanf(" %c",&userLetter);
        if(userLetter >= 'a' && userLetter <= 'z')
            userLetter = userLetter - (int)'a'+ (int)'A';

        if(alphabet[(int)(userLetter-'A')] == 0)
            alphabet[(int)(userLetter-'A')]++;
        else
        {
            printf("Letter %c was given before\n",userLetter);
            continue;
        }
        hashtable = createInitialHashTable(wordSize);
        currentList = createInitialList();

        if(firstCycle==1) {
            currentList = readWordsFromFile(textReader, wordSize);
            firstCycle=0;
        }
        else{
            currentList = optimalList;
        }
        updateHashTable(hashtable,currentList,userLetter);
        //displayInitialHashTable(hashtable);
        optimalList = createInitialList();
        optimalList = getMaxListFromHashTable(hashtable);
        //printf("Optimal list: \n");
        //printlist(optimalList);
        int flag = updateProgress(progress,optimalList,userLetter);
        if(flag == 0) {
            printf("%c not in secret word.\n\n",userLetter);
            totalGuesses--;
        }
        else
            printf("You guessed a letter correctly.\n\n");

        int k,check=1;
        for(k=0;k<strlen(progress);k++)
            if(progress[k]=='_')
                check=0;

        if(check==1)
            wordFound=1;
    }

    if(wordFound == 1)
        printf("**************************************************\n"
               "Congratulations, you win the game\n"
               "The secret word is: %s\n"
               "**************************************************",progress);
    else
        printf("**************************************************\n"
               "You run out of guesses. You lost\n"
               "The secret word was: %s\n"
               "**************************************************",optimalList->head->name);
    return 0;
}