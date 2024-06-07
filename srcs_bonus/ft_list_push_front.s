; void ft_list_push_front(t_list **begin_list, void *data);
section .text
    extern malloc
    global ft_list_push_front


ft_list_push_front:
    cmp byte [rdi], 0
    push qword [rdi]
    je allocate

allocate:
    mov rdi, 16
    call malloc
    mov rax, rdi
place:
    pop rdi
    mov [rdi], rsi
    ret
