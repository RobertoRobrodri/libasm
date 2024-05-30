section .text
    global _ft_write

_ft_write:
	mov rax, 1 ; syscall write
	syscall
	cmp rax, 0
	jc _error
	ret

_error:
    mov rax, -1
    ret