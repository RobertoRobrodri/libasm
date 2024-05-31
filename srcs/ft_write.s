section .text
    global ft_write

ft_write:
	mov rax, 1 ; syscall write
	syscall
	cmp rax, 0
	jc error
	ret

error:
    mov rax, -1
    ret