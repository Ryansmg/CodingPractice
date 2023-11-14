#include <stdio.h>

int main()
{
    int out[4], in[4], i, now = 0, max = -1;
    for(i=0; i<4; i++)
    {
        scanf(" %d %d", out+i, in+i);
    }
    for(i=0; i<4; i++)
    {
        now -= out[i];
        now += in[i];
        if(max < now) max = now;
    }
    printf("%d", max);
}