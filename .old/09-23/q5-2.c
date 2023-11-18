#include <stdio.h>

int main()
{
    printf("N = ");
    int n, t1=0, t2=0, t3=0, t4=0, sum=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int a;
        printf("Data(%d) = ", i+1);
        scanf(" %d", &a);
        t1 += a%10;
        t2 += (a%100)/10;
        t3 += (a%1000)/100;
        t4 += a/1000;
        sum += a;
    }
    printf("1000의 자리수 합 = %d\n100의 자리수 합 = %d\n10의 자리수 합 = %d\n1의 자리수 합 = %d\n합계 = %d", t4, t3, t2, t1, sum);
}