section .text
extern malloc
extern _ft_strlen
extern _ft_strcpy
global _ft_strdup

; void* malloc(size_t size);
; malloc değer olarak bir size istediği için rdi, rax işlemimiz önemli ayrıca rdi'ye atma sebebimiz ilk argümanı destion olması yüzünden

_ft_strdup:
    push rdi            ; Kaydediciyi kaybetmemek için argümanları kaydediyoruz
    call _ft_strlen     ; Kaydediciyi kaybetmemek için argümanları kaydediyoruz
    inc rax             ; '\0' karakteri için bir byte daha yer ayırıyoruz
    mov rdi, rax        ; Yer ayırmak için ayrılan toplam bellek miktarını rdi'ye aktarıyoruz

    call malloc         ; Bellek ayırma işlevini çağırıyoruz
    test rax, rax       ; malloc başarılı oldu mu kontrol ediyoruz
    jz _malloc_failed   ; Eğer malloc başarısız olursa, _malloc_failed etiketine atlıyoruz
    pop rdi             ; Kaydediciyi geri alıyoruz

    mov rsi, rdi        ; _ft_strcpy fonksiyonuna kopyalanacak olan karakter dizisinin adresini rsi'ye aktarıyoruz
    mov rdi, rax        ; _ft_strcpy fonksiyonuna kopyalanacak olan bellek bloğunun adresini rdi'ye aktarıyoruz
    call _ft_strcpy     ; Karakter dizisini kopyalıyoruz
    ret

_malloc_failed:
    mov rax, -1         ; Hata durumunda -1 döndürülür
    ret
