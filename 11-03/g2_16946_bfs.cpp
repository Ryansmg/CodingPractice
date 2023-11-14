#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

//벽 부수고 이동하기 4

int height, width;
vector<vector<bool>> map; //벽이면 true, [y][x]
vector<vector<int>> ans;
vector<vector<bool>> visited;
vector<int> emptyx;
vector<int> emptyy;

void calc(int x, int y);

int main()
{
    scanf("%d %d", &height, &width);
    for(int i=0; i<height; i++)
    {
        vector<bool> temp;
        vector<int> temp2;
        map.push_back(temp);
        ans.push_back(temp2);
        vector<bool> temp3(width, false);
        visited.push_back(temp3);

        for(int j=0; j<width; j++)
        {
            int a;
            scanf(" %1d", &a);
            map[i].push_back(a == 1);
            ans[i].push_back(1);
            if(a!=1){
                emptyx.push_back(j);
                emptyy.push_back(i);
            }
        }
    }

    int size = emptyx.size();
    for(int i=0; i<size; i++)
        calc(emptyx[i], emptyy[i]);

    for(int y=0; y<height; y++){
        for(int x=0; x<width; x++)
        {
            if(!map[y][x]) printf("0");
            else printf("%d", ans[y][x]%10);
        }
        printf("\n");
    }
}

void calc(int fx, int fy)
{
    if(visited[fy][fx]) return;

    int size = 0; //공간의 크기
    queue<pair<int, int>> que;
    vector<int> wallx;
    vector<int> wally;
    que.push({fx, fy});
    
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        if(visited[y][x]) continue;
        visited[y][x] = true;
        size++;

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i]; int ny = y + dy[i];
            if(ny < 0 || ny >= height || nx < 0 || nx >= width) continue;
            if(visited[ny][nx]) continue;
            if(map[ny][nx]){
                visited[ny][nx] = true;
                wallx.push_back(nx);
                wally.push_back(ny);
                continue;
            }
            que.push({nx, ny});
        }
    }

    int cnt = wallx.size();
    for(int i=0; i<cnt; i++)
    {
        ans[wally[i]][wallx[i]] += size;
        visited[wally[i]][wallx[i]] = false;
    }

}