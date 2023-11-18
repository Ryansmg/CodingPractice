#include <stdio.h>

int input(int* lowp, int* highp, int guess, int count)
{
    char c;
    scanf(" %c", &c);
    switch(c)
    {
        case 'l':
            *lowp = guess+1; return 1; break;
        case 'h':
            *highp = guess-1; return 1; break;
        case 'y':
            printf("%d번만에 맞추었지요!", count); return 0; break;
    }
}

int main()
{
    int low = 1, high = 100, guess, count=0;
    guess = (low+high)/2;
    printf("당신이 생각하고 있는 숫자가 %d입니까? ", guess);
    count++;
    while(input(&low, &high, guess, count)==1)
    {
        guess = (low+high)/2;
        printf("당신이 생각하고 있는 숫자가 %d입니까? ", guess);
        count++;
    }
}