section		.text
global		_ft_strcpy

; char *ft_strcpy(char *dest, const char *src);
; rdi: hedef (dest)
; rsi: kaynak (src)
; İlk argüman: rdi (dest)
; İkinci argüman: rsi (src)
; Geri dönüş değeri: rdi (dest) in rax'e kopyalanmış hali

_ft_strcpy:
	mov		rax, 0					; initialise rax to 0
	mov 	rcx, 0					; initialise counter to 0

_loop:
	mov		al, byte[rsi + rcx]		; save src char into al
	mov		[rdi + rcx], al			; save al into dest
	inc		rcx						; increment counter
	cmp		al, 0					; check if it is \0
	jne		_loop					; if not the end, start the loop again

_return:
	mov		rax, rdi				; save dst into rax
	ret								; a pointer to dst will be returned