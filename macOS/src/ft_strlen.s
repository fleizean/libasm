section .text
global _ft_strlen

; size_t strlen(const char *s); (rdi = s)

_ft_strlen:
    mov rax, 0

_loop:
    cmp byte[rdi + rax], 0
    je _return
    inc rax
    jmp _loop

_return:
    ret