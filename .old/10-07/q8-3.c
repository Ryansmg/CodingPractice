#include <stdio.h>

int main()
{
    int n;
    while(1)
    {  
        printf("N = ");
        scanf("%d", &n);
        if(n==4 || n==8) break;
        printf("DATA ERROR! (N=4 or N=8)\n");
    }
    int a[8][8] = {0}, b[8][8] = {0}, c[8][8];
    if(n==4){
        int arr[4][4] = {
            0, 1, 1, 0,
            1, 0, 0, 1,
            1, 0, 0, 1,
            0, 1, 1, 0
        };
        int co = 1;
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                if(arr[i][j] == 1) {a[i][j] = co;c[i][j] = co;}
                else {b[i][j] = 17-co;c[i][j] = 17-co;}
                co++;
            }
        }
    }
    
    if(n==8){
        int arr[8][8] = {
            0, 0, 1, 1, 1, 1, 0, 0,
            0, 0, 1, 1, 1, 1, 0, 0,
            1, 1, 0, 0, 0, 0, 1, 1,
            1, 1, 0, 0, 0, 0, 1, 1, 
            1, 1, 0, 0, 0, 0, 1, 1,
            1, 1, 0, 0, 0, 0, 1, 1,
            0, 0, 1, 1, 1, 1, 0, 0,
            0, 0, 1, 1, 1, 1, 0, 0
        };
        int co = 1;
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                if(arr[i][j] == 1) {a[i][j] = co;c[i][j] = co;}
                else {b[i][j] = 65-co;c[i][j] = 65-co;}
                co++;
            }
        }
    }
        
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%3d", b[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%3d", c[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int ans = 0;
    for(int i=0; i<n; i++) ans += c[0][i];
    printf("행의 합 = %d\n열의 합 = %d\n대각선의 합 = %d", ans, ans, ans);
}