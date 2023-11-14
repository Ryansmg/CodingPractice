#include <stdio.h>

int main()
{
    int answer = 0, n, prevTime = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int mph, time;
        scanf(" %d %d", &mph, &time);
        answer += mph * (time - prevTime);
        prevTime = time;
    }
    printf("%d miles", answer);
}