%include "sys.inc"

%macro _SYSCALL 2-3
    global %1
    %1:
        %if %3 >= 4
            mov r10, rcx       
        %endif
        mov rax, %2            
        syscall
        ret
%endmacro

.text:
_SYSCALL __sys_read, SYS_READ, 3
_SYSCALL __sys_write, SYS_WRITE, 3
_SYSCALL __sys_open,  SYS_OPEN,  3
_SYSCALL __sys_close, SYS_CLOSE, 1
_SYSCALL __sys_stat,  SYS_STAT,  2
_SYSCALL __sys_fstat, SYS_FSTAT, 2
_SYSCALL __sys_lstat, SYS_LSTAT, 2
_SYSCALL __sys_poll,  SYS_POLL,  3
_SYSCALL __sys_lseek, SYS_LSEEK, 3
_SYSCALL __sys_mmap, SYS_MMAP, 6
_SYSCALL __sys_mprotect, SYS_MPROTECT, 3
_SYSCALL __sys_munmap, SYS_MUNMAP, 2
_SYSCALL __sys_brk, SYS_BRK, 1

global __sys_exit
__sys_exit:
    mov rax, SYS_EXIT
    syscall
