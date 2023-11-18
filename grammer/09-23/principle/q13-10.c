#include <stdio.h>

int main()
{
    int i, now, first = -1, second = -1;
    for(i=0; i<7; i++)
    {
        scanf(" %d", &now);
        if(now > first) {
            second = first;
            first = now;
        }
        else if(now > second){
            second = now;
        }
    }
    printf("%d\n%d", first, second);
}