#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

//벽 부수고 이동하기
int main()
{
    vector<vector<bool>> map;
    vector<vector<bool>> visited;
    vector<vector<int>> min;
    vector<vector<int>> minWithoutDest;
    int height, width;
    scanf("%d %d", &height, &width);
    map.resize(height+1);
    visited.resize(height+1);
    min.resize(height+1);
    minWithoutDest.resize(height+1);
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            char c;
            scanf(" %c", &c);
            map[i].push_back(c=='0');
            visited[i].push_back(false);
            bool vert = i==0 || i==height-1;
            bool hori = j==0 || j==width-1;
            min[i].push_back(0);
            minWithoutDest[i].push_back(0);
        }
    }
    
    queue<pair<int, int>> q;
    q.push({width-1, height-1});
    min[height-1][width-1] = 1;
    minWithoutDest[height-1][width-1] = 1;

    while(!q.empty())
    {
        pair<int, int> front = q.front();
        q.pop();
        int x = front.first;
        int y = front.second;
        //printf("visited (%d, %d)", x, y);
        visited[y][x] = true;
        int dx[] = { 0, 0, 1, -1 };
        int dy[] = { 1, -1, 0, 0 };
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= width) continue;
            if(ny < 0 || ny >= height) continue;
            bool doPush = false;
            if(min[y][x] == 0) continue; //계산 필요없음 || 이전에 접근 불가능
            else if(!map[ny][nx] && minWithoutDest[y][x] == 0) {} //이번에 접근 불가능
            else if(!map[ny][nx] && minWithoutDest[y][x] != 0) { //이번에 부숴야 접근 가능
                if(min[ny][nx] == 0){
                    doPush = true;
                    min[ny][nx] = minWithoutDest[y][x] + 1;
                }
            }
            else if(map[ny][nx] && minWithoutDest[y][x] == 0) { //이전에 부숴야 접근 가능
                if(min[ny][nx] == 0){
                    min[ny][nx] = min[y][x] + 1;
                    doPush = true;
                }
            }
            else { //조건 없이 접근 가능
                if(min[ny][nx] == 0) {
                    min[ny][nx] = min[y][x] + 1;
                    doPush = true;
                }
                if(minWithoutDest[ny][nx] == 0){
                    minWithoutDest[ny][nx] = minWithoutDest[y][x] + 1;
                    doPush = true;
                }
            }
            if(doPush) q.push({nx, ny});
        }
        //printf(" = %d, %d\n", min[y][x], minWithoutDest[y][x]);
        
    }
    if(min[0][0]==0) min[0][0]--;
    printf("%d", min[0][0]);

}