//내려가기
#include <stdio.h>
using namespace std;

int max(int a,int b){return (a>b)?a:b;}
int max(int a,int b,int c){return max(max(a,b),c);}
int min(int a,int b){return (a>b)?b:a;}
int min(int a,int b,int c){return min(min(a,b),c);}

int main()
{
    int n;
    scanf("%d", &n);
    int map[2][3], maxn[2][3], minn[2][3];
    scanf(" %d %d %d", &map[0][0], &map[0][1], &map[0][2]);
    for(int i=0; i<3; i++){ maxn[0][i] = map[0][i]; minn[0][i] = map[0][i]; }
    for(int i=1; i<n; i++)
    {
        scanf(" %d %d %d", &map[1][0], &map[1][1], &map[1][2]);
        maxn[1][0] = max(maxn[0][0], maxn[0][1]) + map[1][0];
        maxn[1][1] = max(maxn[0][0], maxn[0][1], maxn[0][2]) + map[1][1];
        maxn[1][2] = max(maxn[0][1], maxn[0][2]) + map[1][2];
        minn[1][0] = min(minn[0][0], minn[0][1]) + map[1][0];
        minn[1][1] = min(minn[0][0], minn[0][1], minn[0][2]) + map[1][1];
        minn[1][2] = min(minn[0][1], minn[0][2]) + map[1][2];
        for(int j=0; j<3; j++)
        {
            maxn[0][j] = maxn[1][j];
            minn[0][j] = minn[1][j];
            maxn[1][j] = 0;
            minn[1][j] = 0;
        }
    }
    printf("%d %d", max(maxn[0][0], maxn[0][1], maxn[0][2]), min(minn[0][0], minn[0][1], minn[0][2]));
}