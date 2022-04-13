#include "types.h"
#include "stat.h"
#include "user.h"
#include "mmu.h"
#include "fcntl.h"

 
int 
main(int argc,char *argv[]) {

    printf(1, "mProtect file\n\n");

    // struct proc *current = myproc();
    int *str;
    str = (int*)PGROUNDUP((uint)sbrk(0));
    int len = 1;


    printf(1, "return val of system call is %d\n");
    printf(1, "Congrats !! You have successfully added new system  call in xv6 OS :) \n");
    printf(1,"\n\nrunning MPROTECT\n");
    mprotect((void *)str, len);
    exit();
 }