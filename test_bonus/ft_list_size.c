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
extern int   ft_list_size(t_list *lst);

t_list *lst_new(void *data)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return NULL;
	new->data = data;
	new->next = NULL;
	return new;
}

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

int main(void)
{
	char *str = "Hola";
	t_list *lst = NULL;

	for (int i = 0; i < 10; i++) {
		lst_add_back(&lst, lst_new(str));
	}
	int len = ft_list_size(lst);
	printf("Longitud lista %d\n", len);
}