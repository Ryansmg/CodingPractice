#include <stdio.h>

int main()
{
    int n, shape = -1, arr[10][10] = {0}, arr2[10][20] = {0};
    printf("N = ");
    scanf("%d", &n);
    arr[0][0] = 1;
    //파스칼의 삼각형 계산
    for(int i=1; i<n; i++)
    {
        arr[i][0] = 1;
        arr[i][i] = 1;
        for(int j=1; j<=i-1; j++)
        {
            arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
    }

    arr2[0][n-1] = 1;
    for(int i=1; i<n; i++)
    {
        int x = n-i-1;
        int x1 = x;
        arr2[i][x] = 1;
        arr2[i][n-x] = 1;
        for(; x<2*n-x1; x+=2)
        {
            arr2[i][x] = arr2[i-1][x-1] + arr2[i-1][x+1];
        }
    }

    while(shape != 0)
    {
        printf("Shape ? ");
        scanf(" %d", &shape);
        switch(shape)
        {
            case 1:
                for(int i=0; i<n; i++)
                {
                    for(int j=0; j<n-i-1; j++) printf("  ");
                    for(int j=0; j<n; j++)
                    {
                       if(arr[i][j] != 0) printf("%4d", arr[i][j]);
                       else printf("  ");
                    }
                    printf("\n");
                }
                break;
            case 2:
                for(int i=n-1; i>=0; i--)
                {
                    for(int j=0; j<n-i-1; j++) printf("  ");
                    for(int j=0; j<n; j++)
                    {
                       if(arr[i][j] != 0) printf("%4d", arr[i][j]);
                       else printf("  ");
                    }
                    printf("\n");
                }
                break;
            case 3:
                for(int i=0; i<n; i++)
                {
                    for(int j=0; j<n-i-1; j++) printf("  ");
                    for(int j=0; j<n; j++)
                    {
                       if(arr[i][j] != 0) printf("%4d", arr[i][j]);
                       else printf("  ");
                    }
                    printf("\n");
                }
                for(int i=n-2; i>=0; i--)
                {
                    for(int j=0; j<n-i-1; j++) printf("  ");
                    for(int j=0; j<n; j++)
                    {
                       if(arr[i][j] != 0) printf("%4d", arr[i][j]);
                       else printf("  ");
                    }
                    printf("\n");
                }
                break;
            case 4:
                for(int j=0; j<2*n; j++)
                {
                    for(int i=0; i<n; i++)
                    {
                       if(arr2[n-1-i][2*n-1-j] != 0) printf("%2d", arr2[n-1-i][2*n-1-j]);
                       else printf("  ");
                    }
                    printf("\n");
                }
                break;
            case 5:
                for(int j=0; j<2*n; j++)
                {
                    for(int i=0; i<n; i++)
                    {
                       if(arr2[i][2*n-1-j] != 0) printf("%2d", arr2[i][2*n-1-j]);
                       else printf("  ");
                    }
                    printf("\n");
                }
                break;
            case 6:
                for(int j=0; j<2*n; j++)
                {
                    for(int i=0; i<n; i++)
                    {
                       if(arr2[i][2*n-1-j] != 0) printf("%2d", arr2[i][2*n-1-j]);
                       else printf("  ");
                    }
                    for(int i=2; i<=n; i++)
                    {
                       if(arr2[n-i][2*n-1-j] != 0) printf("%2d", arr2[n-i][2*n-1-j]);
                       else printf("  ");
                    }
                    printf("\n");
                }
                break;
            case 0:
                break;
            default:
                printf("Error!\n");
                break;
        }
    }
}