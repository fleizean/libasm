extern ___error
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
    jc _set_errno
    ret

_set_errno:
    push rax
    call ___error
    pop rdx
    mov [rax], rdx
    mov rax, -1
    ret

