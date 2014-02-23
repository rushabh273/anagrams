/*
 * Filename: buildDB.c
 * Author: Louis Lesmana
 * Userid: cs30xds
 * Description: build anagrams DB
 */


//Headers and Libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "anagrams.h"
#include "strings.h"

/* Function name: buildDB()
 * Function prototype: void buildDB ( const char *const dictFilename )
 * Description: build anagrams DB, from dictionary 
 * Parameters: dictionary file name 
 * Side Effects: anagrams db built
 * Error Conditions: no file found
 * Return Value: none
 */

void buildDB ( const char *const dictFilename ){
    
    FILE *inFilePtr, *outFilePtr;//file ptr
    char charArray[SIZE];//array for processing words
    char *newline; //ptr to newline from strchr
    struct anagram anaStruct;//structure for processing
    int i;//counter for loop
    
    //open file for reading
    if ( (inFilePtr = fopen (dictFilename, "r")) == NULL) {
		perror (dictFilename);
        exit (EXIT_FAILURE);
    }
    
    //open file for writing
    if ( (outFilePtr = fopen (anagramsDB, "wb")) == NULL) {
		perror (anagramsDB);
        exit (EXIT_FAILURE);
    }

    //begin processing files
    while(fgets(charArray, SIZE, inFilePtr)){
        //remove newline from string
        newline = strchr(charArray, STR_NEWLINE);
        *newline = '\0'; //convert to nullstring
        
        //clear memory in struct
        (void) memset(&anaStruct,'\0',sizeof(struct anagram));
        
        //save word
        (void) strncpy(anaStruct.word, charArray, sizeof(charArray));
        
        //save sorted lower case word
        for(i = 0; charArray[i]; i++)
            charArray[i] = tolower(charArray[i]);
        qsort(charArray, strlen(charArray), sizeof(char), charCompare);
        (void) strncpy(anaStruct.sorted, charArray, sizeof(charArray));
        
        //write to anagrams.dat
        if(!fwrite(&anaStruct, sizeof(struct anagram), 1, outFilePtr))
            (void)fprintf(stderr, STR_WRITE_ERR, anaStruct.word);
        
    }

    //closing files
    (void)fclose(inFilePtr);
    (void)fclose(outFilePtr);
    
    //databe created
    (void)fprintf(stderr, STR_DATABASE_BUILT, anagramsDB);
    
    return;
    
}
