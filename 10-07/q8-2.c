#include <stdio.h>

int main()
{
    printf("N = ? ");
    int n, c;
    scanf("%d", &n);
    c=n;
    int arr[10][10] = {0};
    int x, y, i, j;
    for(i=0; i<n; i++)
    {
        x = 0; y = i;
        for(j=0; j<=i; j++)
        {
            arr[y--][x++] = c++;
        }
    }
    for(i=0; i<n-1; i++)
    {
        y = n-1; x = i+1;
        for(j=0; j<3-i; j++)
        {
            arr[y--][x++] = c++;
        }
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
}