section .text
global _ft_strcpy

; rdi: hedef (dest)
; rsi: kaynak (src)
; İlk argüman: rdi (dest)
; İkinci argüman: rsi (src)

_ft_strcpy:
    ; Kaynak ve hedef işaretçilerini ayarla
    mov rdx, rdi  ; rdx şimdi hedefi (dest) tutacak

    .copy_loop:
        ; Kaynağın sonuna geldik mi?
        cmp byte [rsi], 0
        je .copy_done

        ; Kaynağın her karakterini hedefe kopyala
        mov al, [rsi] ; rsi 
        mov [rdx], al

        ; iki farklı erişim belirteci kullanabilirdik
        ; biri bizim yaptığımız ikincisi ise şu;
        ; nov al, byte[rdi + rcx]

        inc rsi
        inc rdx
        jmp .copy_loop

    .copy_done:
        ; Son null karakteri hedefe yaz
        mov byte [rdx], 0

    ; Hedef diziyi döndür
    mov rax, rdi
    ret
