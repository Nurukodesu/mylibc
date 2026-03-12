#include "unistd.h"

_Noreturn extern void __sys_exit(int status);

_Noreturn void _exit(int status){
    __sys_exit(status);
}