/*
 * Filename: testanagramCompare.c
 * Author: Louis Lesmana
 * Userid: cs30xds
 * Description: Unit test program to test the function anagramCompare.
 * Date: 2/22/14
 * Sources of Help: cse15L previous quarter
 */

#include "test.h"	/* For TEST() macro and stdio.h */
#include <string.h> //for strcpy
#include <stdlib.h>	/* For rand() function prototype */
#include "anagrams.h"	/* For anagramCompare() function prototype */

/*
 * int anagramCompare( const void *ptr1, const void *ptr2 );
 *
 * Returns -1, 0, 1 less, equal ,larger
 * Returns 0 otherwise.
 *
 */

void
testanagramCompare()
{
    printf( "Testing anagramCompare()\n" );
    
    struct anagram ana1;
    struct anagram ana2;
    
    //test same anagram
    strcpy(ana1.word, "royal");
    strcpy(ana2.word, "royal");
    strcpy(ana1.sorted, "alory");
    strcpy(ana2.sorted, "alory");
    TEST(anagramCompare(&ana1, &ana2) == 0 );
    
    //test greater anagram
    strcpy(ana1.word, "bbbbb");
    strcpy(ana2.word, "aaaaa");
    strcpy(ana1.sorted, "bbbbb");
    strcpy(ana2.sorted, "aaaaa");
    TEST(anagramCompare(&ana1, &ana2) > 0 );

    //test lesser anagram
    strcpy(ana1.word, "aaaaa");
    strcpy(ana2.word, "bbbbb");
    strcpy(ana1.sorted, "aaaaa");
    strcpy(ana2.sorted, "bbbbb");
    TEST(anagramCompare(&ana1, &ana2) < 0 );
    
    //test word checking
    strcpy(ana1.word, "aaaaa");
    strcpy(ana2.word, "bbbbb");
    strcpy(ana1.sorted, "aaaaa");
    strcpy(ana2.sorted, "aaaaa");
    TEST(anagramCompare(&ana1, &ana2) < 0 );
    
    strcpy(ana1.word, "ccccc");
    strcpy(ana2.word, "bbbbb");
    strcpy(ana1.sorted, "aaaaa");
    strcpy(ana2.sorted, "aaaaa");
    TEST(anagramCompare(&ana1, &ana2) > 0 );
    
    //test sorted checking
    strcpy(ana1.word, "aaaaa");
    strcpy(ana2.word, "aaaaa");
    strcpy(ana1.sorted, "bbbbb");
    strcpy(ana2.sorted, "aaaaa");
    TEST(anagramCompare(&ana1, &ana2) > 0 );
    
    strcpy(ana1.word, "aaaaa");
    strcpy(ana2.word, "aaaaa");
    strcpy(ana1.sorted, "bbbbb");
    strcpy(ana2.sorted, "ccccc");
    TEST(anagramCompare(&ana1, &ana2) < 0 );
    
    printf( "Finished running tests on anagramCompare()\n" );

}

int
main()
{
    testanagramCompare();
    
    return 0;
}
