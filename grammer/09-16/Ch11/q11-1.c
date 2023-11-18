#include <stdio.h>

int f(int *a, int n)
{
    int sum = 0, i;
    for(i=0; i<n; i++){
        sum += a[i];
    }
    return sum;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d", f(arr, 10));
}