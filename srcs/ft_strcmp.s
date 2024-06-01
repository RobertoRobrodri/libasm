; int   ft_strcmp(const char *s1, const char *s2);
section .text
    global ft_strcmp

ft_strcmp:
	push rdi
	pop rsi
	xor eax, eax

loop:
	mov al, [rdi] ; mov to al to compare byte by byte
	mov bl, [rsi]
	cmp al, bl
	jne ft_return ; not equal
	cmp al, 0 ; reach NULL
	je ft_return
	cmp bl, 0 ; reach NULL
	je ft_return
	inc rdi
	inc rsi
	jmp loop

ft_return:
	sub al, bl ; return difference
	movsx eax, al
	pop rsi
	pop rdi
	ret