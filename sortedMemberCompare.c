/*
 * Filename: sortedMemberCompare.c
 * Author: Louis Lesmana
 * Userid: cs30xds
 * Description: compare 2 anagrams sorted member
 */


//Headers and Libs
#include <stdio.h>
#include <string.h>
#include "anagrams.h"

/* Function name: sortedMemberCompare()
 * Function prototype: int sortedMemberCompare(const void *ptr1, 
 *                          const void *ptr2);
 * Description: comapre 2 anagrams sorted member
 * Parameters:  ptr1 to anagram1 ptr 2 to anagram2
 * Side Effects: none
 * Error Conditions: none
 * Return Value: less,more,equal - {-1,1,0}
 */

int sortedMemberCompare(const void *ptr1, const void *ptr2){
    
    struct anagram *ana1 = (struct anagram *) ptr1;
    struct anagram *ana2 = (struct anagram *) ptr2;
    
    //comparing
    return strcmp(ana1->sorted, ana2->sorted);

}





