extern __errno_location
section .text
global _ft_read

; Değerli bilgi:
; call fonksiyonu maksimum 8 kez kullanılabilir. (iç içe 8 kez) (alt programlar = call)
; 8 kezden fazla kullanıldığında geri dönüş adresi kaybolur. geri dönüş değeri bir adrestir her bir adres alanında bizim yazdığımız fonksiyonlar vardır.
; eğer iç içe 8 kez fazla kullanırsak program çöker.

_ft_read:
    mov rax, 0              ; SYS_read | in Linux = 0 | in Macos = 0x02000003
    syscall

    test rax, rax
    js _set_errno
    ret

_set_errno:
    mov rdi, rax            ; Hata kodunu rdi'ye taşı
    call __errno_location wrt ..plt
    mov [rax], rdx          ; errno = rdx
    mov rax, -1             ; -1 döndür içindeki hata kodu kaybolmaz çünkü işaret ettiğini değiştirmiyoruz 
    ret

