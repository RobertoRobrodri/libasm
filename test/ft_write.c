#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"
# define YELLOW "\033[0;33m"
# define BIG_STRING "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"

extern int   ft_write(int fd, const void *buf, size_t count);

int main() {
    char *str[] = {"Hola\n", "Caracola", "", BIG_STRING};
	int devNull = open("/dev/null", O_WRONLY);
	for (int i = 0; i < sizeof(str) / sizeof(*str); i++)
	{
		// write to fd
		printf(RESET"Normal write\n");
		int expected_result = write(devNull, str[i], strlen(str[i]));
		int real_errno = errno;
		int result = ft_write(devNull, str[i], strlen(str[i]));
		if (result == expected_result/* && real_errno == errno*/)
			printf(GREEN"OK\n");
		else
			printf(RED"KO\n");
		// write less characters
		printf(RESET"Write less characters\n");
		expected_result = write(devNull, str[i], strlen(str[i]) - 1);
		real_errno = errno;
		result = ft_write(devNull, str[i], strlen(str[i]) - 1);
		if (result == expected_result/* && real_errno == errno*/)
			printf(GREEN"OK\n");
		else
			printf(RED"KO\n");
		printf("%d && %d\n", result, expected_result);
		// write to bad fd
		printf(RESET"Bad fd\n");
		expected_result = write(-1, str[i], strlen(str[i]));
		real_errno = errno;
		result = ft_write(-1, str[i], strlen(str[i]));
		if (result == expected_result/* && real_errno == errno*/)
			printf(GREEN"OK\n");
		else
			printf(RED"KO\n");
		printf("%d && %d\n", result, expected_result);
		printf(RESET"-------------\n");
	}
	return 0;
}