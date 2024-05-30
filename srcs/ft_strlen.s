section .text
    global _ft_strlen

_ft_strlen:
    xor rax, rax ; init rax to 0
    call _ft_loop

_ft_loop:
    cmp byte [rdi], 0 ; compare bit by bit
    je _strlen_end  ; if its null return
    inc rax ; rcx + 1
    inc rdi ; go to the next bit
    jmp _ft_loop ; loop

_strlen_end:
    ret
