section .text
    global ft_list_size

ft_list_size:
    xor rax, rax ; init rax to 0
    call ft_loop

ft_loop:
    cmp rdi, 0 ; compare bit by bit
    je end  ; if its null return
    inc rax ; rcx + 1
    mov rdi, [rdi + 8] ; load effective address
    jmp ft_loop ; loop

_end:
    ret
