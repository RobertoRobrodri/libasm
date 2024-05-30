section .text
    global _ft_list_size

_ft_list_size:
    xor rax, rax ; init rax to 0
    call _ft_loop

_ft_loop:
    cmp rdi, 0 ; compare bit by bit
    je _end  ; if its null return
    inc rax ; rcx + 1
    mov rdi, [rdi + 8] ; load effective address
    jmp _ft_loop ; loop

_end:
    ret
