#include "types.h"
#include "stat.h"
#include "user.h"

 
int 
main(int len, char ** i) {

    // struct proc *current = myproc();

    // check the length is at least 1
    if (len <= 0){
        // printf("\nLen needs to be one or greater");
        return -1;
    }

    // check the address is greater then zero
    // if (addr <= 0){
    //     cprintf("\nLen needs to be one or greater");
    //     return -1;
    // } 


    printf(1, "return val of system call is %d\n", hello());
    printf(1, "Congrats !! You have successfully added new system  call in xv6 OS :) \n");
    exit();
 }