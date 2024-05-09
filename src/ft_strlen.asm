section .text                   ; assembly programı genellikle birkaç bölümden oluşur. .text bölümü, CPU tarafından yürütülen kodu içerir. 
                                ; bu bölüm genellikle programın ana işlevselliğini içerir ve CPU tarafından doğrudan yürütülür.
                                ; diğer yaygın bölüm olarak .data (sabit değer veya global değişkenler için)
                                ; ve .bss (sıfırlanmış veya henüz atanmamış veriler için)
global _ft_strlen              ; _ft_strlen fonksiyonunu dışarıya açık hale getirir

_ft_strlen:                         ; _ft_strlen etiket alanı
    mov rax, 0                      ; rax'i sıfırla (move rax'ı 0a taşır)

_loop:
    cmp byte[rdi + rax], 0          ; compare byte rdi + rax == 0 değilse
    je _return                      ; eğer NULL karakter bulunursa, döngüden çık
    inc rax                         ; inc rax
    jne _loop                       ; _loop'u tekrar başlat, eğer bitmemişse!

_return:                            ; return etiket alanı 
    ret                             ; rax'ın length değerini döndürür