/*
 * Filename: userInteractive.c
 * Author: Louis Lesmana
 * Userid: cs30xds
 * Description: UI for user input to search anagrams.
 */

//Headers and Libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "anagrams.h"
#include "strings.h"

/* Function name: userInteractive()
 * Function prototype: void userInteractive( struct anagramInfo *anagramInfoPtr);
 * Description: UI for user input to search anagrams.
 * Parameters: pointer to anagramInfo
 * Side Effects: ask user for input, and search database for the anagram
 * Error Conditions: array out of bounds
 * Return Value: none
 */


void userInteractive( struct anagramInfo *anagramInfoPtr ){
    
    char input[SIZE];//hold input from user
    char *newline;//pointer to newline in the string
    struct anagram anaStruct; // structure for processing
    struct anagram *searchResult;//search result
    struct anagram *temp;//for traversal
    int i;//counter for loop
    
    //ask user for input
    (void)fprintf(stderr, STR_SEARCH);
    
    while(fgets(input, SIZE, stdin)){
        //remove newline from string
        newline = strchr(input, STR_NEWLINE);
        *newline = '\0';//convert to nullstring to end string
        
        //clear memory in struct
        (void)memset(&anaStruct,'\0',sizeof(struct anagram));
        
        //save word
        (void)strncpy(anaStruct.word, input, sizeof(input));
        
        //save sorted lower case word
        for(i = 0; input[i]; i++)
            input[i] = tolower(input[i]);
        qsort(input, strlen(input), sizeof(char), charCompare);
        (void)strncpy(anaStruct.sorted, input, sizeof(input));

        //search
        searchResult = (struct anagram *) bsearch(&anaStruct, anagramInfoPtr->
                        anagramPtr , anagramInfoPtr->numOfAnagrams,
                        sizeof(struct anagram),sortedMemberCompare);
        
        //if not found
        if(!searchResult)
            (void)fprintf(stderr, STR_NO_ANAGRAMS_FOUND);
        else{//if found
            //print first anagram found
            if(!strcmp(searchResult->word, anaStruct.word)){//prevent duplicates
               (void)fprintf(stderr, STR_NO_ANAGRAMS_FOUND);
            }
            else{
               (void)fprintf(stdout, STR_FOUND_ANAGRAMS);
               (void)fprintf(stdout, " %s", searchResult->word);
           
               temp = searchResult;//set traverse
               temp--;//move to next word
               //traverse left
               while(temp && !strcmp(temp->sorted, searchResult->sorted)){
                   if(strcmp(temp->word, anaStruct.word))
                   (void)fprintf(stdout, " %s", temp->word);
                   temp--;
               }
            
               //traverse right
               temp = searchResult;//reset temp
               temp++;//move to next word
               while(temp && !strcmp(temp->sorted, searchResult->sorted)){
                   if(strcmp(temp->word, anaStruct.word))
                   (void)fprintf(stdout, " %s", temp->word);
                   temp++;
               }
            }

        }
        //place newline
        (void)putchar(STR_NEWLINE);
        
        (void)fprintf(stderr, STR_SEARCH);
    }
    
    return;
}
