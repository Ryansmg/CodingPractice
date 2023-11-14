#include <stdio.h>

int main()
{
    printf("INPUT N= ? ");
    int n, c = 0;
    scanf("%d", &n);
    int arr[10][10] = {0};
    int x=0, y=0, i, j;
    if(n%2==0){
        for(i=n-1; i>=0; i-=2){
            for(j=0; j<i; j++)
                arr[y++][x] = ++c;
            for(j=0; j<i; j++)
                arr[y][x++] = ++c;
            for(j=0; j<i; j++)
                arr[y--][x] = ++c;
            for(j=0; j<i; j++)
                arr[y][x--] = ++c;
            x++; y++;
        }
    }
    else{
        for(i=n-1; i>=0; i-=2){
            if(i==0) arr[y][x] = ++c;
            for(j=0; j<i; j++)
                arr[y][x++] = ++c;
            for(j=0; j<i; j++)
                arr[y++][x] = ++c;
            for(j=0; j<i; j++)
                arr[y][x--] = ++c;
            for(j=0; j<i; j++)
                arr[y--][x] = ++c;
            x++; y++;
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