#include "unistd.h"
#include "stdint.h"

uintptr_t __stack_chk_guard = 0x595e9fbd94fdb612;

void __stack_chk_fail(void){
    write(STDERR, "stack smashing detected. terminating\n", 38);
    _exit(42);
}