; char* ft_strcpy(char *dest, const char *src);
section .text
    global ft_strcpy

ft_strcpy:
	push rdi
	call ft_loop
	pop rax
	ret

ft_loop:
	mov al, [rsi]
	mov [rdi], al
	cmp byte [rdi], 0
	je ft_return
	inc rdi
	inc rsi
	jmp ft_loop

ft_return:
	ret