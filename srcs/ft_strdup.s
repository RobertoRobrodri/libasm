section .text
    global ft_strdup
	extern malloc
	extern ft_strlen
	extern ft_strcpy

ft_strdup:
	xor rax, rax
	push rdi ; no quiero perder mi string
	; en rdi ya tengo el primer argumento str
	call ft_strlen ; rdi = str, me deja en rax la len
	; llamar a malloc, los bytes a reservar van en rdi
	inc rax ; suma el nulo
	mov rdi, rax
	call malloc ; tengo en rax los bytes reservados
	pop rsi ; restaurar la string a copiar
	mov rdi, rax ; dst, primer argumento
	call ft_strcpy ; me pone en rax la string copiada
	ret