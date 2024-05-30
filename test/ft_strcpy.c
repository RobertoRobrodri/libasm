#include <stdio.h>
#include <string.h>
#include <stdlib.h>
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"
# define YELLOW "\033[0;33m"
# define BIG_STRING "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"

extern char* _ft_strcpy(char *dest, const char *src);

int main() {
    char *str[] = {"Hola\n", "Caracola", "", BIG_STRING};
	char cpy[1000], expected_cpy[1000];
	for (int i = 0; i < sizeof(str) / sizeof(*str); i++)
	{
		char *expected_result = strcpy(expected_cpy, str[i]);
		char *result = _ft_strcpy(cpy, str[i]);
		if (!strcmp(result, expected_result) && !strcmp(cpy, expected_result) &&\
			!strcmp(result, expected_cpy) && !strcmp(cpy, expected_cpy))
			printf(GREEN"OK\n");
		else
			printf(RED"KO\n");
	}
	return 0;
}