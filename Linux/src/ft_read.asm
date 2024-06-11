extern __errno_location
section .text
global _ft_read

; Değerli bilgi:
; call fonksiyonu iç içe kullanma limitine sahiptir bu sizin stack frame size'ına göre değişir. (alt programlar = call)
; 8 kezden fazla kullanıldığında geri dönüş adresi kaybolur. geri dönüş değeri bir adrestir her bir adres alanında bizim yazdığımız fonksiyonlar vardır.
; eğer iç içe 8 kez fazla kullanırsak program çöker.

; ssize_t read(int fd, void *buf, size_t count);
; rdi = fd
; rsi = buf
; rdx = count
; rax = return value

_ft_read:
    mov rax, 0                      ; SYS_read | in Linux = 0 | in Macos = 0x02000003
    syscall

    test rax, rax
    js _set_errno
    ret

_set_errno:
    neg		rax
    mov rdi, rax                    ; Hata kodunu rdi'ye taşı
    call __errno_location wrt ..plt ; Procedure Linkage Table (PLT) aracılığıyla erişimi belirtir.
    mov [rax], rdi                  ; errno = rdx
    mov rax, -1                     ; -1 döndür içindeki hata kodu kaybolmaz çünkü işaret ettiğini değiştirmiyoruz 
    ret

; Procedure Linkage Table (PLT)
; PLT, bir programın çalıştırılabilir dosyasında bulunan bir tablo olup
; dinamik bağlantı için kullanılır. PLT, programın çalışma zamanında
; dinamik olarak bağlanan kütüphanelere erişim sağlar.
; wrt ..plt, PLT'ye erişimi belirtir. (PLT tablosu içerisinde fonksiyonların adreslerini tutar.)

