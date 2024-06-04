; extern void   ft_list_push_front(t_list **lst, t_list *new);
section .text
    global ft_list_push_front

ft_list_push_front:
    cmp byte [rdi], 0
    je place
    mov [rsi + 8], rdi

place:
    mov [rdi], rsi
    ret
