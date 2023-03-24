/**
 *
 * Copyleft 2023 Dmitrii Korchemkin
 *
 */
#include <stdio.h>
#include <string.h>

#define MIN_ARGS 0x2
#define EXIT_SUCCESS 0x0
#define EXIT_FAILURE 0x1

void reverse(char *str);

int main(int argc, char *argv[])
{
    if (argc < MIN_ARGS) {
        printf("Please, pass a string\n");
        return EXIT_FAILURE;
    }

    char *str = *(++argv);

    reverse(str);
    printf("%s\n", str);

    return EXIT_SUCCESS;
}

void reverse(char *str)
{
    char *end = str + strlen(str) - 1;
    while(str < end) {
        char temp = *str;
        *str = *end;
        *end = temp;
        ++str;
        --end;
    }
}

