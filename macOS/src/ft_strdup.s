section .text
extern _malloc
extern ___error
extern _ft_strlen
extern _ft_strcpy
global _ft_strdup

; char *ft_strdup(const char *s1); (rdi = s1)
; size_t strlen(const char *s); (rdi = s)
; char *ft_strcpy(char *dest, const char *src);
; void* malloc(size_t size);
; malloc değer olarak bir size istediği için rdi, rax işlemimiz önemli ayrıca rdi'ye atma sebebimiz ilk argümanı destion olması yüzünden

_ft_strdup:
    push rdi
    call _ft_strlen
    inc rax
    mov rdi, rax

    call _malloc
    test rax, rax               ; malloc sonucu 0 mı değil mi kontrol ediyoruz
                                ; ek olarak cmp rax, 0 işlemi de yapılabilirdi
    jz _error                   ; Eğer malloc başarısız olursa, _error etiketine gidiyoruz
    pop rdi                     ; Kaydediciyi geri alıyoruz ( sıfırlandı )

    mov rsi, rdi                ; _ft_strcpy fonksiyonuna kopyalanacak olan karakter dizisinin adresini rsi'ye aktarıyoruz
    mov rdi, rax                ; _ft_strcpy fonksiyonuna kopyalanacak olan bellek bloğunun adresini rdi'ye aktarıyoruz
    call _ft_strcpy             ; Karakter dizisini kopyalıyoruz
    ret

_error:
	pop		rdi					; clean up stack if malloc fails
	call	___error
	mov		rdx, 12			    ; 12 stands for ENOMEM
	mov		[rax], rdx			; save errro code into rax
	mov		rax, 0				; change rax to 0
	ret							; NULL is returned when malloc fails