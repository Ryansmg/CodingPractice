#include <stdio.h>

int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    int *p = arr, i;

    for(i=0; i<5; i++)
    {
        *(p+i) += 5;
    }

    for(i=0; i<5; i++)
    {
        printf("%d ", arr[i]);
    }
}