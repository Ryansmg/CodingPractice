#include <stdio.h>

int main()
{
    int n, answer = 1;
    printf("n을 입력하시오. : ");
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        answer *= i;
    }
    printf("%d", answer);
}