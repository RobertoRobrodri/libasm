section .text
    global _ft_strdup
	extern malloc
	extern _ft_strlen
	extern _ft_strcpy

_ft_strdup:
	xor rax, rax
	push rdi ; no quiero perder mi string
	; en rdi ya tengo el primer argumento str
	call _ft_strlen ; rdi = str, me deja en rax la len
	; llamar a malloc, los bytes a reservar van en rdi
	mov rdi, rax
	call malloc ; tengo en rax los bytes reservados
	pop rsi ; restaurar la string a copiar
	mov rdi, rax ; dst, primer argumento
	call _ft_strcpy ; me pone en rax la string copiada
	ret