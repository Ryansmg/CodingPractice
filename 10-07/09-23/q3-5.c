#include <stdio.h>

int main()
{
    int n;
    printf("n을 입력하시오. : ");
    scanf("%d", &n);
    if(n%2==0) {
        printf("%d은(는) 소수가 아닙니다.", n);
        return 0;
    }
    
    for(int i=3; i<n; i+=2)
    {
        if(n%i==0) {
            printf("%d은(는) 소수가 아닙니다.", n);
            return 0;
        }
    }
    
    printf("%d은(는) 소수입니다.", n);
    return 0;
}