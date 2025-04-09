#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 dc[] = { -1, 0, 1, 0 };
i64 dr[] = { 0, -1, 0, 1 };

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    i64 h, w; cin >> h >> w;
    vector<string> board(h);
    vector<vector<bool>> visited(h, vector<bool>(w));
    i64 startH = -1, startW = -1;
    for(i64 i = 0; i < h; i++) {
        cin >> board[i];
        for(i64 j = 0; j < w; j++)
            if(board[i][j] == 'S') startH = i, startW = j;
    }
    queue<array<i64, 3>> bfs; // { h, w, 거리 }
    bfs.push({startH, startW, 0});
    visited[startH][startW] = true;
    while(true) {
        i64 row = bfs.front()[0], col = bfs.front()[1], dist = bfs.front()[2];
        bfs.pop();
        for(int i = 0; i < 4; i++) {
            i64 nr = row + dr[i], nc = col + dc[i];
            if(nr < 0 || nr >= h || nc < 0 || nc >= w
                || visited[nr][nc] || board[nr][nc] == '#') continue;
            if(board[nr][nc] == 'G') {
                cout << dist + 1 << "\n";
                return 0;
            }
            visited[nr][nc] = true;
            bfs.push({nr, nc, dist + 1});
        }
    }
}
