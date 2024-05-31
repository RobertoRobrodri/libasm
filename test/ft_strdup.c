#include <stdio.h>
#include <string.h>
#include <stdlib.h>
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"
# define YELLOW "\033[0;33m"
# define BIG_STRING "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"

extern char* ft_strdup(const char *s);

int main() {
    char *str[] = {"Hola\n", "Caracola", "", BIG_STRING};
	for (int i = 0; i < sizeof(str) / sizeof(*str); i++)
	{
		char *expected_result = strdup(str[i]);
		char *result = ft_strdup(str[i]);
		if (!strcmp(result, expected_result))
			printf(GREEN"OK\n");
		else
			printf(RED"KO\n");
		free(result);
		free(expected_result);
	}
	return 0;
}