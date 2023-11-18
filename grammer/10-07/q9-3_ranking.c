#include <stdio.h>
#include <string.h>

int rank(int* arrp, int n)
{
    int rank = 1;
    for(int i=0; i<10; i++)
        if(*(arrp+i) < n) rank++;
    return rank;
}

int main()
{
    int i, arr[10];
    
    for(i=0; i<10; i++)
    {
        printf("Enter : ");
        scanf(" %d", arr+i);
    }
    printf("배열의 내용 : %d", arr[0]);
    for(i=1; i<10; i++)
        printf(", %d", arr[i]);
    
    printf("\n값의 순위 : %d(%d)", arr[0], rank(arr, arr[0]));
    
    for(i=1; i<10; i++)
        printf(", %d(%d)", arr[i], rank(arr, arr[i]));
}