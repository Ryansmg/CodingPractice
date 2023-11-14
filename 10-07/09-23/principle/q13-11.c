#include <stdio.h>

int main()
{
    int day, car, ans = 0;
    scanf("%d", &day);
    for(int i=0; i<5; i++)
    {
        scanf(" %d", &car);
        if(car == day) ans++;
    }
    printf("%d", ans);
    
    return 0;
}