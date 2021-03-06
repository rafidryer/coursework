#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "stat.h"
// #include "user.h"
#include "fcntl.h"

int 
sys_mprotect(void){

  // printf(1, "m protect sysproc.c");

  int addr;
  int len;

  if(argint(0, &addr) < 0){
		return -1;
	}

  // check the length is at least 1
    if(argint(1, &len) <= 0){
		return -1;
	}

    // check the address is greater then zero
    if ((int) addr % PGSIZE != 0){
        return -1;
    }

  return protect((void*)addr, len);
}

int 
sys_munprotect(void){
  int addr;
  int len;

  if(argptr(0, (void *) &addr, sizeof(void *)) < 0){
		return -1;
	}

  // check the length is at least 1
    if(argint(1, &len) <= 0){
		return -1;
	}

    // check the address is greater then zero
    if ((int) addr % PGSIZE != 0){
        return -1;
    }

  return unprotect((void*)addr, len);
}

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->vlimit;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
