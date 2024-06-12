extern __errno_location
section .text
global _ft_read

; ssize_t read(int fd, void *buf, size_t count);
; rdi = int fd
; rsi = void *buf
; rdx = size_t count
; return value = ssize_t (rax)

_ft_read:
    mov rax, 0x02000003              ; SYS_read | in Linux = 0 | in Macos = 0x02000003
    syscall

    test rax, rax
    jc _set_errno
    ret

_set_errno:
    mov rdi, rax            ; Hata kodunu rdi'ye taşı
    call
    mov [rax], rdx          ; errno = rdx
    mov rax, -1             ; -1 döndür içindeki hata kodu kaybolmaz çünkü işaret ettiğini değiştirmiyoruz 
    ret

