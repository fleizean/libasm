section .text
global _ft_strcpy

_ft_strcpy:
    ; char* verilerini tutan arkadaş
    push rbp
    mov rbp, rsp
    mov rsi, rdi
    mov rdx, rsi

    .copy_loop:
        cmp byte [rsi], 0
        je .copy_done

        ; al register'ı 8lik olarak bir veriyi okuyup rsi'ye atar yani tek tek karakter okuyoruz.
        mov al, [rsi]
        mov [rdx], al

        inc rsi
        inc rdx
        jmp .copy_loop

    .copy_done:
        mov byte [rdx], 0

    pop rbp
    ret
