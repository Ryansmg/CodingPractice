#include <stdio.h>

int main()
{
    printf("한 줄에 출력할 개수 : ");
    int n;
    scanf("%d", &n);
    int ans[1000] = {0};
    int found = 0;
    for(int i=100; i<1000; i++)
    {
        //i = abc
        int a = i/100;
        int b = (i%100)/10;
        int c = (i%10);
        if(a<b && b<c) ans[found++] = i;
    }
    int i = 0;
    while(ans[i] != 0) {
        printf("%4d", ans[i]);
        if(i%n==n-1) printf("\n");
        i++;
    }
}