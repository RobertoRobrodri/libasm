; extern int   ft_list_size(t_list *lst);
section .text
    global ft_list_size

ft_list_size:
    xor rax, rax ; init rax to 0

loop:
    cmp rdi, 0 ; compare bit by bit
    je end  ; if its null return
    inc rax
    mov rdi, [rdi + 8]
    jmp loop

end:
    ret
