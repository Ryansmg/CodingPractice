#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int main() {
    int w, h; cin >> w >> h;
    vector<string> arr(h);
    for(int i = 0; i < h; i++) cin >> arr[i];
    int ans = 0;

    vector<vector<bool>> vis(h, vector<bool>(w));

    for(int r = 0; r < h; r++)
        for(int c = 0; c < w; c++) {
            if(vis[r][c] || arr[r][c] == '.') continue;
            queue<pair<int, int>> bfs;
            bfs.push({r, c});
            vis[r][c] = true;
            int cans = 1;

            while(!bfs.empty()) {
                int r1 = bfs.front().first, c1 = bfs.front().second;
                bfs.pop();
                for(int i = 0; i < 4; i++) {
                    int r2 = r1 + dy[i], c2 = c1 + dx[i];
                    if(r2 < 0 || c2 < 0 || r2 >= h || c2 >= w || vis[r2][c2] || arr[r2][c2] == '.') continue;
                    vis[r2][c2] = true;
                    cans++;
                    bfs.push({r2, c2});
                }
            }

            ans = max(ans, cans);
        }

    cout << ans << "\n";
}
