#include <stdio.h>

int twoPow(int n)
{
    int ans = 1;
    for(int i=0; i<n; i++)
    {
        ans *= 2;
    }
    return ans;
}

int main()
{
    int n = -1;
    while(1){
        printf("범위를 입력하세요 = ? ");
        scanf(" %d", &n);
        if(n==0) break;
        printf("%d번째 값 = %d\n", n, twoPow(n-1));
        printf("합계 = %d\n", twoPow(n)-1);
    }
}