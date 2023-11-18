#include <stdio.h>

int* min(int *a, int n)
{
    int i, min = a[0], *minP;
    for(i=0; i<n; i++)
    {
        if(min >= a[i]) 
        {
            min = a[i];
            minP = a+i;
        }
    }

    return minP;
}

int main()
{
    int a[10] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int* p_min = min(a, 10);
    printf("%d", *p_min);
}