section .text
    global _ft_strcmp

_ft_strcmp:
	xor eax, eax

loop:
	mov al, [rdi] ; mov to al to compare byte by byte
	mov bl, [rsi]
	cmp al, bl
	jne _ft_return ; not equal
	cmp al, 0 ; reach NULL
	je _ft_return
	cmp bl, 0 ; reach NULL
	je _ft_return
	inc rdi
	inc rsi
	jmp loop

_ft_return:
	sub al, bl ; return difference
	movsx eax, al ; for some reason cant use rax
	ret