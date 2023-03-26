#include <stdio.h>
#include <string.h>
#include <limits.h>

#define RECURSIVE "-r"
#define LOOP "-l"
#define MAX_NUMBER SHRT_MAX

int fib(int n);
void fib_recursive();
void fib_loop();
void usage_message();

int main(int argc, char **argv)
{
    char *flag = *++argv;

    if (argc < 2) usage_message();
    else if (strcmp(flag, RECURSIVE) == 0) fib_recursive();
    else if (strcmp(flag, LOOP) == 0) fib_loop();
    else usage_message();

    return 0;
}

void usage_message()
{
    printf("\nUSAGE:\n-r recursive calculations\n-l calculation in loop\n\n");
}

int fib(int n)
{
    return n > 1 ? fib(n - 1) + fib(n - 2) : n;
}

void fib_recursive()
{
    int i = 0;
    int num = 0;
    while (num < MAX_NUMBER) {
        num = fib(i);
        printf("%d ", num);
        ++i;
    }
    printf("...\n");
}

void fib_loop()
{   
    int num1 = 0;
    int num2 = 1;
    int num3 = 0;

    printf("%d %d ", num1, num2);
    while(num3 < MAX_NUMBER) {
        num3 = num1 + num2; 
        printf("%d ", num3);
        num1 = num2;
        num2 = num3;
    }
    printf("...\n");
}

