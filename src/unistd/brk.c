#include "unistd.h"
#include <stdint.h>

extern void *__sys_brk(void *addr);

int brk(void *addr){
    if (__sys_brk(addr)<addr) return -1;
    return 0;
}

void *sbrk(intptr_t increment){
    void *current_brk = __sys_brk(0);
    if (!increment) return current_brk;
    void *new_brk = (void*)((char*)current_brk+increment);
    if (brk(new_brk)<0) return (void*)-1;
    return current_brk;
}