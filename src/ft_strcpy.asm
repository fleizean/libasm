section .text
global _ft_strcpy

_ft_strcpy:
    ; char* verilerini tutan arkadaş
    push rbp
    mov rbp, rsp
    mov rsi, rdi    ; rdi'deki src'yi rsi'ye kopyala
    mov rdx, rsi    ; rsi'deki dst'yi rdx'e kopyala
    ; Bu yaptığımız işlemle sorgulamış olabileceğiniz bir soruya cevap vereyim. eğer rdi'yi rsi'ye yani "Hello World"'ü atıyorsak ve rsi'ye rdx'e yani dstye atıyorsak
    ; bunun sonucunda aslında kopyalamış olmaz mıyız? diye düşünmüş olabilirsiniz aslında cevap evet ama hayır diyebilirim çünkü siz bu işlemle bellek adresini
    ; kopyalamış olursunuz fakat her karakteri ayrı olarak kopyalamamız gerek. (mantıken C'de de bunu öğrendik aslında)

    .copy_loop:
        cmp byte [rsi], 0
        ; sürekli gördüğümüz ve bildiğimiz o komut compare byte [rsi] 0'a eşit mi byte olarak 0'a eşit mi onu kontrol ediyoruz null kontrol
        je .copy_done
        ; cevap evet ise kopyalama biter.

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
