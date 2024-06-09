section .text
global _ft_strcmp

_ft_strcmp:
    mov rax, 0
    mov rdx, 0
    mov rcx, 0

_checker:
    mov al, byte[rdi + rcx]
    mov dl, byte[rsi + rcx]

    cmp al, 0           ; al == rax
    je _end
    cmp dl, 0           ; dl == rdx
    je _end
    cmp al, dl
    jne _error_occurred

    inc rcx
    jmp _checker

_error_occurred:
    sub rax, rdx        ; rax = rax - rdx || al - dl (hexadecimal)
    ret                 
    
_end:
    mov rax, 0          ; rax = 0
    ret

