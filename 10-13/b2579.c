#include <stdio.h>

static int stairs[500];
static int max2[500]; //+2->최댓값 = max[n-2] + stairs[n]
static int max1[500]; //+1->최댓값 = max2[n-1] + stairs[n]

int main()
{
    int size;
    scanf("%d", &size);

    for(int i=0; i<size; i++)
        scanf(" %d", stairs + i);

    max1[0] = stairs[0];
    max2[0] = stairs[0];
    max1[1] = stairs[0] + stairs[1];
    max2[1] = stairs[1];
    for(int i=2; i<size; i++)
    {
        max2[i] = ((max1[i-2] > max2[i-2]) ? max1[i-2] : max2[i-2]) + stairs[i];
        max1[i] = max2[i-1] + stairs[i];
    }

    printf("%d", (max1[size-1] > max2[size-1]) ? max1[size-1] : max2[size-1]);

}