#include <stdio.h>
#include <string.h>
#include <stdlib.h>
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"
# define YELLOW "\033[0;33m"
# define BIG_STRING "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"

extern size_t   ft_strlen(char *str);

int main() {
    char *str[] = {"Hola\n", "Caracola", "", BIG_STRING};
	for (int i = 0; i < sizeof(str) / sizeof(*str); i++)
	{
		int result = ft_strlen(str[i]);
		int expected_result = strlen(str[i]);
		if (result == expected_result)
			printf(GREEN"OK\n");
		else
			printf(RED"KO\n");
	}
	return 0;
}