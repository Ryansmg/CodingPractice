#include <stdio.h>
int main() {
    int n, i, j, k, x, y, a[20][20]={};
    for(i=1;i<=19;i++)
    {
        for(j=1;j<=19;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    scanf(" %d", &n);
    for(k=1;k<=n;k++)
    {
        scanf(" %d %d", &x, &y);
        for(i=1;i<=19;i++)
        {
            if(a[i][y]==1) a[i][y]=0;
            else a[i][y]=1;
        }
        for(j=1;j<=19;j++)
        {
            if(a[x][j]==1) a[x][j]=0;
            else a[x][j]=1;
        }
    }
    for(i=1;i<=19;i++)
    {
        for(j=1;j<=19;j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}