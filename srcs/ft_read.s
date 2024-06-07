section .text
    global ft_write
	extern __errno_location

ft_write:
	mov rax, 0  ; sys_read
    syscall     ; call read
    cmp rax, 0
    jl error
    ret
error:
    call __errno_location
    mov rdi, [rax]  ; set the value of errno
    mov rax, -1
    ret