#include <stdio.h>
#include <string.h>
#include <stdlib.h>
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"
# define YELLOW "\033[0;33m"
# define BIG_STRING "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"

extern int   ft_strcmp(const char *s1, const char *s2);

int main() {
    char *str[] = {"Hola\n", "Caracola", "", BIG_STRING};
	for (int i = 0; i < sizeof(str) / sizeof(*str); i++)
	{
		// compare with itself expected result == 0
		int expected_result = strcmp(str[i], str[i]);
		int result = ft_strcmp(str[i], str[i]);
		if (result == expected_result)
			printf(GREEN"OK\n");
		else
			printf(RED"KO\n");
		
		// compare with a different one expected result > 0
		expected_result = strcmp(str[i], "random string");
		result = ft_strcmp(str[i], "random string");
		if (result == expected_result)
			printf(GREEN"OK\n");
		else
			printf(RED"KO\n");
	}
	return 0;
}