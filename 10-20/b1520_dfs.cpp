#include <stdio.h>

//내리막길

int dfs(int x, int y);

int map[500][500];
int m, //세로
n;     //가로
int routes[500][500] = {0,};

int main()
{  
    scanf("%d %d", &m, &n);
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            {
                scanf(" %d", &map[i][j]);
                routes[i][j] = -1;
            }

    routes[m-1][n-1] = 1;
    
    printf("%d", dfs(0,0));
}

int dfs(int x, int y)
{
    if(routes[y][x]!=-1) return routes[y][x];
    int ans = 0;
    /*
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        을 이용해 for로 반복
    */
    if(x>0) if(map[y][x] > map[y][x-1]) ans += dfs(x-1, y);
    if(x<n-1) if(map[y][x] > map[y][x+1]) ans += dfs(x+1, y);
    if(y>0) if(map[y][x] > map[y-1][x]) ans += dfs(x, y-1);
    if(y<m-1) if(map[y][x] > map[y+1][x]) ans += dfs(x, y+1);
    routes[y][x] = ans;

    return ans;
}