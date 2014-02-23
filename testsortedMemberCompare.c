/*
 * Filename: testsortedMemberCompare.c
 * Author: Louis Lesmana
 * Userid: cs30xds
 * Description: Unit test program to test the function sortedMemberCompare.
 * Date: 2/22/14
 * Sources of Help: cse15L previous quarter
 */

#include "test.h"	/* For TEST() macro and stdio.h */
#include <string.h> //for strcpy
#include <stdlib.h>	/* For rand() function prototype */
#include "anagrams.h"	/* For sortedMemberCompare() function prototype */

/*
 * int sortedMemberCompare( const void *ptr1, const void *ptr2 );
 *
 * Returns -1, 0, 1 less, equal ,larger
 * Returns 0 otherwise.
 *
 */

void
testsortedMemberCompare()
{
    printf( "Testing sortedMemberCompare()\n" );
    
    struct anagram ana1;
    struct anagram ana2;
    
    //test same sorted
    strcpy (ana1.sorted, "alory");
    strcpy (ana2.sorted, "alory");
    TEST(sortedMemberCompare(&ana1, &ana2) == 0 );
    
    //test greater sorted
    strcpy(ana1.sorted, "bbbbb");
    strcpy(ana2.sorted, "aaaaa");
    TEST(sortedMemberCompare(&ana1, &ana2) > 0 );
    
    //test lesser sorted
    strcpy(ana1.sorted, "aaaaa");
    strcpy(ana2.sorted, "bbbbb");
    TEST(sortedMemberCompare(&ana1, &ana2) < 0 );

    
    printf( "Finished running tests on sortedMemberCompare()\n" );
}

int
main()
{
    testsortedMemberCompare();
    
    return 0;
}
