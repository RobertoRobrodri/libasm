; char* ft_strcpy(char *dest, const char *src);
section .text
    global ft_strcpy

ft_strcpy
	push rdi

loop:
	mov al, [rsi]
	mov [rdi], al
	cmp byte [rdi], 0
	je ft_return
	inc rdi
	inc rsi
	jmp loop

ft_return:
	pop rax
	ret