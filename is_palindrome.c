/**
 *
 * Copyleft 2023 Dmitrii Korchemkin
 *
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool is_palindrome(const char *str);

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Please, pass a srting.\n");
        return 1;
    }
 
    char *ptr_source = *++argv;
    if (is_palindrome(ptr_source))
        printf("%s is a palindrome.\n", ptr_source);
    else
        printf("%s is not a palindrome.\n", ptr_source);

    return 0;
}

bool is_palindrome(const char *str)
{
    int start = 0;
    int end = strlen(str) - 1;

    while(start < end)
        if (tolower(str[++start]) != tolower(str[--end])) return false;
    
    return true;
}

