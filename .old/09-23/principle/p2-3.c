#include <stdio.h>

int main()
{
    int n, y=0, x=0, num = 0;
    int ans[50][50] = {0};
    scanf("%d", &n);
    for(int i=n-1; i>=0; i-=2)
    {
        if(i==0) ans[x][y] = ++num;
        for(int j=0; j<i; j++)
        {
            ans[y][x] = ++num;
            y+=1;
        }
        for(int j=0; j<i; j++)
        {
            ans[y][x] = ++num;
            x+=1;
        }
        for(int j=0; j<i; j++)
        {
            ans[y][x] = ++num;
            y-=1;
        }
        for(int j=0; j<i; j++)
        {
            ans[y][x] = ++num;
            x-=1;
        }
        y++; x++;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%3d ", ans[i][j]);
        }
        printf("\n");
    }
}