; int   ft_strcmp(const char *s1, const char *s2);
section .text
    global ft_strcmp

ft_strcmp:
	xor rax, rax

loop:
	mov al, [rdi] ; mov to al to compare byte by byte
	cmp al, 0 ; reach NULL
	je ft_return
	cmp byte [rsi], 0 ; reach NULL
	je ft_return
	cmp byte al, [rsi]
	jne ft_return ; not equal
	inc rdi
	inc rsi
	jmp loop

ft_return:
	sub al, [rsi] ; return difference
	movzx rax, al
	ret