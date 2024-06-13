extern      ___error	; int ___error(int errnum, const char *msg);
section     .text
global      _ft_write

; ssize_t write(int fd, const void *buf, size_t count);
; rdi = int fd
; rsi = const void *buf
; rdx = size_t count
; return value = ssize_t (rax)

_ft_write:
    mov rax, 0x2000004  ; SYS_write | in Linux = 1 | in Macos = 0x2000004
    syscall             ; ; int write(int fd, const void *buf, size_t count);
    jc _ft_error        ; if carry flag is set, jump to error
    ret

_ft_error:
    push rax
    call ___error
    pop rdx
    mov [rax], rdx
    mov rax, -1
    ret