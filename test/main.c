#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

// Declare the assembly function
extern int   _ft_strlen(char *str);
extern int   _ft_write(int fd, const void *buf, size_t count);
extern int   _ft_read(int fd, const void *buf, size_t count);
extern char* _ft_strcpy(char *dest, const char *src);
extern int   _ft_strcmp(const char *s1, const char *s2);
extern char* _ft_strdup(const char *s);

int main() {
    char *str = "Hola\n";
    char cpy[5];
    // // strlen
    int result = _ft_strlen(str);
    // printf("Result: %d\n", result);
    // // read
    // char buffer[24];
    // int fd = open("sample.txt", 0);
    // int bytes = _ft_read(10, buffer, 5);
    // buffer[5] = 0;
    // printf("%s\n", buffer);
    // printf("Bytes leidos %d\n", bytes);
    // printf("Errno %d\n", errno);
    // // write
    result = _ft_write(3, str, result);
    printf("Caracteres printados %d\n", result);
    printf("Errno %d\n", errno);
    result = write(3, str, result);
    printf("Caracteres printados %d\n", result);
    printf("Errno %d\n", errno);
    // // strcpy
    // char *ret = _ft_strcpy(cpy, str);
    // printf("%s\n", str);
    // printf("%s\n", cpy);
    // printf("%s\n", ret);
    // // strcmp
    // char *string_1 = "zasdas";
    // char *string_2 = "";
    // int i = strcmp(string_1, string_2);
    // printf("Result %i\n", i);
    // i = _ft_strcmp(string_1, string_2);
    // printf("Result %i\n", i);
    // // strdup
    // char *new_string = _ft_strdup(str);
    // printf("La nueva string %s\n", new_string);
    return 0;
}
