extern      __errno_location	; int ___error(int errnum, const char *msg);
section     .text
global      _ft_write

_ft_write:
    mov rax, 1          ; SYS_write | in Linux = 1 | in Macos = 0x2000004
    syscall             ; ; int write(int fd, const void *buf, size_t count);
    jc _ft_error        ; if carry flag is set, jump to error
    ret

_ft_error:
    neg		rax	
    mov rdi, rax        ; Hata kodunu rdi'ye taşı
    call __errno_location wrt ..plt
    mov [rax], rdi      ; errno'yu ayarla
    mov rax, -1         ; rax'i -1 yap
    ret