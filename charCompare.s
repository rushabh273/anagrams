/*
 * Filename: charCompare.s
 * Author: Louis Lesmana
 * Userid: cs30xds
 * Description: compare char
 */

    .global charCompare     ! Declare globally visible

    .section ".text"        ! Text section begins here

    EQUAL = 0               ! Compare Constants
    LESS = -1
    MORE = 1



/* Function name: charCompare()
 * Function prototype: int charCompare (const void *ptr1, const void *ptr2);
 * Description: Compare char
 * Parameters: ptr1 - char1 ptr2 - char2
 * Side Effects: None
 * Error Conditions: None.
 * Return Value: 1 ,or 0, or -1, indicating larger,equal,smaller
 * Registers Used:
 * %i0,1 input params, l0,l1, the char to compares
 */


charCompare:

    save    %fp, -96, %fp   ! slide stack frames

    ldub    [%i0], %l0      ! load first char
    ldub    [%i1], %l1      ! load second char

    cmp     %l0, %l1        ! check if equal
    bne     end_equalif
    nop

    mov     EQUAL, %i0      ! return 0 if equal

end_equalif:

    cmp     %l0, %l1        ! check if less
    bge     end_ifless
    nop

    mov     LESS, %i0       ! return -1 if less

end_ifless:

    cmp     %l0, %l1        ! check if more
    ble     end_ifmore
    nop

    mov     MORE, %i0       ! return 1 if more

end_ifmore:

    ret                     ! return from function
    restore
