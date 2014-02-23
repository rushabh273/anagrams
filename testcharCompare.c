/*
 * Filename: testcharCompare.c
 * Author: Louis Lesmana
 * Userid: cs30xds
 * Description: Unit test program to test the function charCompare.
 * Date: 2/22/14
 * Sources of Help: cse15L previous quarter
 */

#include "test.h"	/* For TEST() macro and stdio.h */
#include <stdlib.h>	/* For rand() function prototype */
#include "anagrams.h"	/* For charCompare() function prototype */

/*
 * int charCompare( const void *ptr1, const void *ptr2 );
 *
 * Returns -1, 0, 1 less, equal ,larger
 * Returns 0 otherwise.
 *
 */

void
testcharCompare()
{
    char a1;
    char a2;
    printf( "Testing charCompare()\n" );
    
    a1 = 'a';
    a2 = 'a';
    TEST(charCompare(&a1,&a2) == 0);
    
    a1 = 'a';
    a2 = 'b';
    TEST(charCompare(&a1,&a2) < 0);

    a1 = 'c';
    a2 = 'a';
    TEST(charCompare(&a1,&a2) > 0);

    
    printf( "Finished running tests on charCompare()\n" );
}

int
main()
{
    testcharCompare();
    
    return 0;
}
