; size_t   ft_strlen(char *str);
section .text
    global ft_strlen

ft_strlen:
    xor rax, rax ; init rax to 0

loop:
    cmp byte [rdi], 0 ; compare bit by bit
    je strlen_end  ; if its null return
    inc rax ; rcx + 1
    inc rdi ; go to the next bit
    jmp loop ; loop

strlen_end:
    ret