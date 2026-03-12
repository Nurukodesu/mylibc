.text:
    global _start
    extern main
_start:
    xor rbp, rbp
    mov rdi, [rsp]
    lea rsi, [rsp+8]
    lea rdx, [rsi + rdi*8 + 8]
    mov rax, rsp
    and rsp, -16
    sub rsp, 8
    call main
    mov rdi, rax
    mov rax, 60
    syscall