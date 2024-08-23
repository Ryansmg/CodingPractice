#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int yl, xl; cin >> yl >> xl; int t;
    vector<int> temp(xl,0);
    vector<bool> temp2(xl, 0);
    vector<vector<int>> paper(yl, temp);
    int cheesecnt = 0;
    for(int i=0; i<yl; i++) {
        for(int j=0; j<xl; j++) {
            cin >> t;
            paper[i][j] = t;
            if(t) cheesecnt++;
        }
    }
    if(cheesecnt==0) {
        cout << 0; return 0;
    }
    int ans = 0;
    while(cheesecnt > 0) {
        ans++;
        queue<tuple<int, int>> bfs;
        vector<vector<bool>> visited(yl, temp2);
        vector<vector<int>> ocnt(yl, temp);
        bfs.emplace(0, 0);
        while(!bfs.empty()) {
            tuple<int, int> top = bfs.front(); bfs.pop();
            if(visited[get<1>(top)][get<0>(top)]) continue;
            visited[get<1>(top)][get<0>(top)] = true;
            int dx[] = {0, 0, 1, -1};
            int dy[] = {1, -1, 0, 0};
            for(int i=0; i<4; i++) {
                int nx = get<0>(top) + dx[i], ny = get<1>(top) + dy[i];
                if(nx<0 || ny<0 || nx>=xl | ny>=yl) continue;
                ocnt[ny][nx]++;
                if(paper[ny][nx]) continue;
                bfs.emplace(nx, ny);
            }
        }
        for(int i=0; i<yl; i++) 
            for(int j=0; j<xl; j++) 
                if(ocnt[i][j]>=2 && paper[i][j] == 1) {
                    paper[i][j] = 0;
                    cheesecnt--;
                }
        
    }
    cout << ans;
}