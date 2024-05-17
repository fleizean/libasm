section .text
global _ft_strcpy

_ft_strcpy:
    ; char* verilerini tutan arkadaş
    push rbp
    mov rbp, rsp
    mov rsi, rdi
    mov rdi, rdx ; hedef adresi rdi'ye taşı
    mov rdx, rsi

.copy_loop:
    ; al register'ı 8lik olarak bir veriyi okuyup rsi'ye atar yani tek tek karakter okuyoruz.
    mov al, [rsi]
    test al, al ; null byte kontrolü
    je .copy_done

    ; okunan karakteri hedef adresine kopyala
    mov [rdi], al

    inc rsi
    inc rdi
    jmp .copy_loop

.copy_done:
    mov byte [rdi], 0 ; hedef adresin sonuna null byte ekle

    pop rbp
    ret
