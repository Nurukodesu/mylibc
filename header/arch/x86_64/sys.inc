; x86_64 Syscall Opcodes

%define SYS_READ          0
%define SYS_WRITE         1
%define SYS_OPEN          2
%define SYS_CLOSE         3
%define SYS_STAT          4
%define SYS_FSTAT         5
%define SYS_LSTAT         6
%define SYS_POLL          7
%define SYS_LSEEK         8

%define SYS_MMAP          9
%define SYS_MPROTECT      10
%define SYS_MUNMAP        11
%define SYS_BRK           12

%define SYS_RT_SIGACTION  13
%define SYS_RT_SIGPROCMASK 14
%define SYS_RT_SIGRETURN  15
%define SYS_IOCTL         16
%define SYS_NANOSLEEP     35

%define SYS_EXIT 60

; Standard File Descriptors
%define STDIN       0
%define STDOUT      1
%define STDERR      2

