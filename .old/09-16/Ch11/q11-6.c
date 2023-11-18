#include <stdio.h>

void strswap(char** a, char** b)
{
    char *temp = *a; //temp = "keyboard"
    *a = *b; //main¿« a = "mouse"
    *b = temp; //main¿« b = "keyboard"
}

int main()
{
    char *a = "keyboard";
    char *b = "mouse";
    strswap(&a, &b);
    printf("%s \n%s", a, b);
}