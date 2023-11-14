#include <stdio.h>
int factorial(int n)
{
    return ((n==0)? 1 : n*factorial(n-1));
}

int main()
{
    int num1;
    printf("정수 입력?");
    scanf("%d", &num1);
    printf("%d!=%d\n", num1, factorial(num1));
}