/*
 * Filename: processDB.c
 * Author: Louis Lesmana
 * Userid: cs30xds
 * Description: process anagrams DB
 */


//Headers and Libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "anagrams.h"
#include "strings.h"

/* Function name: processDB()
 * Function prototype: void processDB( struct anagramInfo *anagramInfoPtr );
 * Description: process anagrams DB
 * Parameters: pointer to anagramInfo
 * Side Effects: anagrams processed
 * Error Conditions: no database made, calloc fails, angramsDB fails to open
 *                  fread doesnt return correct #of elems
 * Return Value: none
 */

void processDB( struct anagramInfo *anagramInfoPtr ){
    
    struct stat statStruct; //struct stat
    struct anagram *anArray; // dynamically allocated struct array
    FILE *inFilePtr;//open file to read
    int readValue;// fread return value

    //check if database built
    if (stat (anagramsDB, &statStruct) != 0) {
        perror(STR_STAT_ERR);
        (void)fprintf(stderr, STR_UNBUILT_DICT);
        exit(EXIT_FAILURE);
    }
    
    //calculate #of anagrams
    anagramInfoPtr->numOfAnagrams = statStruct.st_size/sizeof(
                                       struct anagram);
    //allocating anagrams array
    anArray = (struct anagram* ) calloc(anagramInfoPtr->numOfAnagrams,
                                        sizeof(struct anagram) );
    //check if allocation succesful
    if(!anArray){
        perror(STR_CALLOC);
        exit(EXIT_FAILURE);
    }
    
    //check if file open succesfully for reading
    if ( (inFilePtr = fopen (anagramsDB, "r")) == NULL) {
		perror (anagramsDB);
        exit (EXIT_FAILURE);
    }
    
    readValue = fread(anArray, sizeof(struct anagram), anagramInfoPtr->
                      numOfAnagrams, inFilePtr);
    //if fread doesnt return exopected value
    if(readValue != anagramInfoPtr->numOfAnagrams){
        (void)fprintf(stderr, STR_FREAD_ERR, anagramInfoPtr->numOfAnagrams,
                      readValue);
        exit(EXIT_FAILURE);
    }
    //close file
    (void)fclose(inFilePtr);
    
    //sort struct array
    qsort(anArray, anagramInfoPtr->numOfAnagrams, sizeof(struct anagram),
          anagramCompare);
    
    //set pointer
    anagramInfoPtr->anagramPtr = anArray;

    return;
    
}


