/**
 *
 * Copyleft 2023 Dmitrii Korchemkin
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *shuffle(char *str);

int main(int argc, char **argv)
{
    argc > 1
        ? printf("%s\n", shuffle(*++argv)) 
        : printf("Please pass a string.\n");

    return 0;
}

char *shuffle(char *str)
{
    srand(time(NULL));
    int end = strlen(str) - 1;

    for(int i = 0; i < end; ++i) {
        int num = rand() % end;
        char temp = str[i];
        str[i] = str[num];
        str[num] = temp;
    }

    return str;
}

