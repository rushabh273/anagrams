/*
 * Filename: anagrams.h
 * Author: Louis Lesmana
 * Userid: cs30xds
 * Description: Function definitions and constants used in PA3
 */

#ifndef ANAGRAMS_H
#define ANAGRAMS_H

//Constants
#define SIZE 80

#define anagramsDB "anagrams.dat"

#define EQUAL 0

#define TRUE 1
#define FALSE 0

struct anagram {
    
	char word[SIZE];
    
	char sorted[SIZE];
    
};



struct anagramInfo {
    
    struct anagram *anagramPtr;
    
    int    numOfAnagrams;
    
};

//C-Functions
void buildDB ( const char *const dictFilename );

void processDB( struct anagramInfo *anagramInfoPtr );

void userInteractive( struct anagramInfo *anagramInfoPtr );

int anagramCompare( const void *ptr1, const void *ptr2 );

int sortedMemberCompare( const void *ptr1, const void *ptr2 );

//Assembly functions
int charCompare( const void *ptr1, const void *ptr2 );

/* Assembly Functions not called from C file
 int main( int argc, char *argv[] );
*/

#endif /* ANAGRAMS_H */

