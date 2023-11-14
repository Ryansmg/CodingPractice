#include <stdio.h>
#define MAX 3
void output(int*, int);
int main()
{
    int arr[3] = {10, 20, 30};
    output(arr, MAX);
    return 0;
}

void output(int *p, int n)
{
    int i;
    for(i=0; i<n; i++) printf("arr[%d] : %d\n", i, *(p+i));
    return;
}