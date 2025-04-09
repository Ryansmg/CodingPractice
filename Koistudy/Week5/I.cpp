#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 dc[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
i64 dr[] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    i64 n, m, x, y;
    cin >> n >> m >> x >> y; x--; y--;
    vector<vector<i64>> ans(n, vector<i64>(m, -1));
    queue<array<i64, 3>> bfs; // { row, column, 거리 }
    ans[x][y] = 0; bfs.push({x, y, 0});
    while(!bfs.empty()) {
        i64 r = bfs.front()[0], c = bfs.front()[1], dist = bfs.front()[2];
        bfs.pop();
        for(int i = 0; i < 8; i++) {
            i64 nxtR = r + dr[i], nxtC = c + dc[i];
            if(nxtR < 0 || nxtC < 0 || nxtR >= n || nxtC >= m) continue;
            if(ans[nxtR][nxtC] != -1) continue;
            ans[nxtR][nxtC] = dist + 1;
            bfs.push({nxtR, nxtC, dist + 1});
        }
    }
    for(const auto& row : ans) {
        for(i64 i : row) cout << i << " ";
        cout << "\n";
    }
}
