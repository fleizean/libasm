extern      ___error	; int ___error(int errnum, const char *msg);
section .text
global _ft_read

_ft_read:
    push rbp
    mov rbp, rsp
    mov rax, 0
    syscall
    test rax, rax
    js _ft_error

_ft_error:
    neg rax ; convert to positive
    push rbx
    mov rbx, rax
    call ___error
    mov [rax], rbx

    pop rbx
    mov rax, -1
    mov rsp, rbp
    pop rbp
    ret