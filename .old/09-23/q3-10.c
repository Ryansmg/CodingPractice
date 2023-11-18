#include <stdio.h>

int main()
{
    printf("정수 n을 입력: ");
    int n;
    scanf("%d", &n);
    int min = (n-6 > 0) ? n-6 : 1;
    int max = (n > 6) ? 6 : n-1;
    for(int i=min; i<=max; i++)
    {
        for(int j=min; j<=max; j++)
        {
            if(i+j>n) break;
            if(i+j==n) printf("%d %d\n", i, j);
        }
    }
}