#include <stdio.h>

void one(int count)
{
    int sum;
    for(int i=1; i<=count; i++)
    {
        int lsum=0;
        printf("(");
        for(int j=1; j<=i; j++)
        {
            if(j==1) {printf("1"); lsum=1;}
            else if(j%2==0) 
            {
                printf("-%d", j);
                lsum -= j;
            }
            else {
                printf("+%d", j);
                lsum += j;
            }
        }
        printf(") = %d\n", lsum);
        if(i==1)sum += lsum;
        else if(i%2 == 0) sum += lsum;
        else sum -= lsum;
    }
    printf("총합 = %d", sum);
}

void two(int count)
{
    int sum;
    for(int i=1; i<=count; i++)
    {
        int lsum=0;
        printf("(");
        for(int j=1; j<=i; j++)
        {
            if(j==1) {printf("1"); lsum=1;}
            else if(i%2==0) 
            {
                printf("-%d", j);
                lsum -= j;
            }
            else {
                printf("+%d", j);
                lsum += j;
            }
        }
        printf(") = %d\n", lsum);
        if(i==1)sum += lsum;
        else if(i%2 == 0) sum += lsum;
        else sum -= lsum;
    }
    printf("총합 = %d", sum);
}   

int main()
{
    int choice;
    printf("선택(1,2,3) = ");
    scanf("%d", &choice);

    if(choice==3) return 0;

    int count;
    printf("반복 횟수 = ");
    scanf(" %d", &count);

    if(choice==1) one(count);
    else two(count);

    return 0;
}