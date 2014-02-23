/*
 * Filename: main.s
 * Author: Louis Lesmana
 * Userid: cs30xds
 * Description: Driver program for anagrams lister
 */

    .global     main         ! Declare globally available

    .section    ".data"      ! Data section begins here

usage:
    .asciz      "Usage: %s [--build dictionary_file]\n"

build:
    .asciz      "--build"

    .section    ".text"      ! text section begins here

    SPACE   =   8            ! space to alloacate

    EXIT_FAIL       =   1    ! Exit codes
    EXIT_SUCCESS    =   0


/* Function name: main()
 * Function prototype: int main( int argc, char *argv[] );
 * Description: driver to anagram list generator
 * Parameters: argc, argv, command line arguments
 * Side Effects: program ran
 * Error Conditions: none
 * Return Value: exit status
 * Registers Used:
 *
 */

main:

    save    %sp, -(92 + SPACE) & -8 , %sp   ! Allocate Stack space

    cmp     %i0, 1                          ! Check if there is arguments
    bne     endif
    nop

    add     %fp, -8, %o0                    ! pass the struct address
    call    processDB                       ! process database
    nop

    add     %fp, -8, %o0                    ! pass struct address
    call    userInteractive                 ! Load UI
    nop

    ba      endif_two                       ! go to the end
    nop

    mov     EXIT_SUCCESS, %i0               ! exit code return

endif:

    cmp     %i0, 3                          ! check if there is 2 arguments
    bne     else
    nop

    ld      [%i1 + 4], %o0                  ! get argv[1]
    set     build, %o1                      ! pass string to be compared
    call    strcmp, 2                       ! compare strings
    nop

    cmp     %o0, 0                          ! compare if same or not
    bne     else                            ! go to print usage
    nop

    ld      [%i1 + 8], %o0                  ! pass string name argv[2]
    call    buildDB                         ! build database
    nop

    ba      endif_two                       ! go to the end
    nop

    mov     EXIT_SUCCESS, %i0               ! exit code return

else:

    set     stdError, %o0
    ld      [%o0], %o0                      ! pass stdError
    set     usage, %o1                      ! pass format string
    mov     %i1, %o2                        ! pass string
    ld      [%o2], %o2                      ! get string
    call    fprintf, 3                      ! print usage message
    nop

    mov     EXIT_FAIL, %i0                  ! exit code return

endif_two:

    add     %fp, -8, %o0                    ! free memory
    call    free, 1

    ret                                     ! end function
    restore











