#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include <stdio.h>
#include "vm.c"

 
int 
main(int argc,char *argv[]) {

    printf( "mProtect file\n\n");

    struct proc *currentproc = myproc();
    // int *str;
    // str = (int*)PGROUNDUP((uint)sbrk(0));
    int len;
    int addr;
    argint(0, &addr);
    argint(1,&len);


    // printf(1, "return val of system call is %d\n");
    // printf(1, "Congrats !! You have successfully added new system  call in xv6 OS :) \n");
    // printf(1,"\n\nrunning MPROTECT\n");
    // mprotect((void *)str, len);
    if (len <= 0){
        printf("\nMprotect Failed");
        return -1;
    }

    // check the address is greater then zero
    if ((int)(&addr) % PGSIZE != 0){
        return -1;
    }

    // int current = (int) addr;
    pte_t *pageTableEntry;

    // iterate through the pages in the range
    int current = (int) addr;
    for (int i = 0; i < len; ++i) {
        pageTableEntry = walkpgdir(currentproc->pgdir, (void *) current, 0);
        if (pageTableEntry == 0){
            printf("\nMprotect Failed");
            return -1;
        }
        
        // set the page to be writable
        *pageTableEntry |= PTE_W;
        current += PGSIZE;
    }

    lcr3(V2P(currentproc->pgdir));
    printf("\nMprotect Passed");

    return 0;
    exit();
 }