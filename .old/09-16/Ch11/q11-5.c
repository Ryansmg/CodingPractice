#include <stdio.h>
#include <string.h>

int main()
{
    char arr[3][50];
    int n, i, j;
    for(i=0; i<3; i++)
    {
        scanf("%s %d", arr[i], &n);
        for(j=n-1; j<strlen(arr[i]); j++)
        {
            printf("%c", *(arr[i] + j));
        }
        printf("\n");
    }
}