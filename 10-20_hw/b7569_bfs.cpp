#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
//토마토
int main()
{
    int box[101][101][101]; //(i, j, k) 값은 box[i][j][k]
    bool alreadyComplete = true;
    vector<int> ripeX, ripeY, ripeZ;
    int m, n, h;
    scanf("%d %d %d", &m, &n, &h);
    for(int k=0; k<h; k++)
    for(int j=0; j<n; j++)
    for(int i=0; i<m; i++){
        scanf(" %d", &box[i][j][k]);
        if(box[i][j][k] == 1){
            ripeX.push_back(i);
            ripeY.push_back(j);
            ripeZ.push_back(k);
        } else if(box[i][j][k] == 0)
            alreadyComplete = false;
    }

    if(alreadyComplete) {printf("0"); return 0;}
    int ans = 0;
    
    queue<int> xq, yq, zq;
    int size = ripeX.size();
    for(int i=0; i<size; i++)
    {
        xq.push(ripeX[i]);
        yq.push(ripeY[i]);
        zq.push(ripeZ[i]);
    }
    xq.push(-2); yq.push(-2); zq.push(-2);

    while(!xq.empty())
    {
        int x = xq.front(), y = yq.front(), z = zq.front();
        xq.pop(); yq.pop(); zq.pop();
        if(x == -2) {
            ans++;
            if(xq.empty()) break;
            else{
                xq.push(-2);
                yq.push(-2);
                zq.push(-2);
                continue;
            }
        }
        int dx[] = { 1, -1, 0, 0, 0, 0 };
        int dy[] = { 0, 0, 1, -1, 0, 0 };
        int dz[] = { 0, 0, 0, 0, 1, -1 };
        for(int i=0; i<6; i++)
        {
            int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
            if(nx<0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
            if(box[nx][ny][nz] == 1 || box[nx][ny][nz] == -1) continue;
            else {
                box[nx][ny][nz] = 1;
                xq.push(nx); yq.push(ny); zq.push(nz);
            }
        }
    }
    bool complete = true;

    for(int k=0; k<h; k++)
    for(int j=0; j<n; j++)
    for(int i=0; i<m; i++){
        if(box[i][j][k] == 0)
            complete = false;
    }
    if(complete) printf("%d", --ans);
    else printf("-1");
}