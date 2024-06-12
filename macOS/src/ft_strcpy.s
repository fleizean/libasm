section .text
global _ft_strcpy

; char *ft_strcpy(char *dest, const char *src);
; rdi: hedef (dest)
; rsi: kaynak (src)
; İlk argüman: rdi (dest)
; İkinci argüman: rsi (src)
; Geri dönüş değeri: rdi (dest) in rax'e kopyalanmış hali

_ft_strcpy:
    mov rax, 0
    mov rbx, 0

    .loop:
        mov al, [rsi + rbx]
        mov [rdi + rbx], al
        inc rbx
        cmp al, 0
        jne .loop

    .return:
        mov rax, rdi
        ret