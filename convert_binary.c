/**
 *
 * Copyleft 2023 Dmitrii Korchemkin
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define BINARY "-b"
#define DECIMAL "-d"
#define WORD_LENGTH 32
#define ASCII_48 '0'

void usage_message(void);
int convert_binary(const char *binary);
int convert_decimal(const char *decimal);

int main(int argc, char **argv)
{
    if (argc != 3) {
        usage_message();
        return 1;
    }

    char *flag = argv[1];
    char *source = argv[2];

    if (strcmp(flag, BINARY) == 0)
        convert_binary(source);
    else if (strcmp(flag, DECIMAL) == 0)
        convert_decimal(source);
    else
        usage_message();

    return 0;
}

void usage_message(void)
{
    printf("\nPlease, pass a number and one at a time.\n\n-b <binary>\n-d <decimal>\n\n");
}

// Convert binary to decimal
int convert_binary(const char *binary)
{
    int decimal = 0;
    int i = 0;
    int j = strlen(binary) - 1;

    while(i < j) {
        if ((binary[i] - ASCII_48) == 1)
            decimal += pow(2, j);
        else if ((binary[j] - ASCII_48) == 1)
            decimal += pow(2, i);

        ++i;
        --j;
    }
    printf("%d\n", decimal);
    return 0;
}

// Convert decimal to binary
int convert_decimal(const char *decimal)
{
    int num = atoi(decimal);
    for (int i = WORD_LENGTH - 1; i >= 0; --i)
        printf("%d", (num >> i) & 1);
  
    printf("\n");
    return 0;
}

