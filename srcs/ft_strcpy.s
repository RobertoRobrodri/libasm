section .text
    global _ft_strcpy

_ft_strcpy:
	push rdi
	call _ft_loop
	pop rax
	ret

_ft_loop:
	mov al, [rsi]
	mov [rdi], al
	cmp byte [rdi], 0
	je _ft_return
	inc rdi
	inc rsi
	jmp _ft_loop

_ft_return:
	ret