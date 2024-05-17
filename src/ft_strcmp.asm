section .text
global _ft_strcmp

_ft_strcmp:
    push rbp
    mov rbp, rsp
    mov rsi, rdi
    mov rdx, rsi

    .compare_loop:
        cmp byte [rsi], 0
        je .strings_match
        cmp byte [rdx], 0
        je .strings_match

        mov al, [rsi]
        cmp al, [rdx]
        jne .strings_differ

        inc rsi
        inc rdx
        jmp .compare_loop
    
    .strings_match:
        xor eax, eax
        jmp .exit

    .strings_differ:
        mov eax, 1
        jl .exit
        mov eax, -1

    .exit:
        pop rbp
        ret

