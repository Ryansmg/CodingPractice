#include <stdio.h>
#include <float.h>
#include <math.h>

int main()
{
    int n, x[11], sum, count = 0, ls[100], close;
    scanf("%d", &n);
    if(n<3 || n>10) return 0;
    for(int i=0; i<n; i++)
    {
        scanf(" %d", x+i);
    }
    for(int i=0; i<n; i++)
    {
        if(x[i]==0) continue;
        for(int j=0; j<n; j++)
        {
            if(x[i]==x[j]) continue;
            for(int k=0; k<n; k++)
            {
                if(x[i]==x[k] || x[j]==x[k]) continue;
                count++;
                ls[count-1] = x[i]*100 + x[j]*10 + x[k];
                sum += ls[count-1];
            }
        }
    }
    float avg = (sum+0.0f)/count, diff = 10000;
    for(int i=0; i<count; i++)
    {
        printf("%d ", ls[i]);
        if(abs(avg-ls[i]) < diff)
        {
            diff = abs(avg-ls[i]);
            close = ls[i];
        }
    }
    printf("\n수의 개수 : %d\n", count);
    printf("수의 합 : %d\n", sum);
    printf("수의 평균 : %f\n", (sum+0.0f)/count);
    printf("평균에 가장 가까운 수 : %d", close);
}