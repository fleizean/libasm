section .text
global _ft_strcpy

; rdi: hedef (dest)
; rsi: kaynak (src)
; İlk argüman: rdi (dest)
; İkinci argüman: rsi (src)
; Geri dönüş değeri: rdi (dest) in rax'e kopyalanmış hali

_ft_strcpy:
    

    ; Kaynak ve hedef işaretçilerini ayarla
    mov rdx, rdi  ; rdx şimdi hedefi tutacak

    .copy_loop:
        ; Kaynağın sonuna geldik mi?
        cmp byte [rsi], 0
        je .copy_done

        ; Kaynağın her karakterini hedefe kopyala
        mov al, [rsi] ; rsi 
        mov [rdx], al

        inc rsi
        inc rdx
        jmp .copy_loop

    .copy_done:
        ; Son null karakteri hedefe yaz
        mov byte [rdx], 0

    ; Hedef diziyi döndür
    mov rax, rdi
    ret