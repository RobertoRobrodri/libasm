#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_list
{
	void *data;
	struct s_list *next;
} t_list;

// Declare the assembly function
void ft_list_push_front(t_list **begin_list, void *data);

void lst_add_back(t_list **lst, t_list *new)
{
	t_list *aux;

	aux = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = new;
		
	}
}

void print_list(t_list *lst)
{
	while (lst != NULL)
	{
		printf("Value->%s\n", (char*)lst->data);
		lst = lst->next;
	}
}

int main(void)
{
	char *str = "Hola";
	t_list *lst = NULL;

	for (int i = 0; i < 1; i++) {
		printf("%d\n", i);
		ft_list_push_front(&lst, str);
		//lst_add_back(&lst, lst_new(str));
	}
	print_list(lst);
}