#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 dx[] = { -1, 0, 1, 0 };
i64 dy[] = { 0, -1, 0, 1 };

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    i64 n, m, k; cin >> n >> m >> k;
    vector<vector<i64>> ans(n, vector<i64>(m));
    queue<array<i64, 3>> bfs; // { x, y, 시간 }
    for(int i = 0; i < k; i++) {
        i64 x, y; cin >> x >> y;
        ans[x-1][y-1] = 1;
        bfs.push({x-1, y-1, 1});
    }
    while(!bfs.empty()) {
        i64 x = bfs.front()[0], y = bfs.front()[1], t = bfs.front()[2];
        bfs.pop();
        for(int i = 0; i < 4; i++) {
            i64 nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || ans[nx][ny]) continue;
            ans[nx][ny] = t + 1;
            bfs.push({nx, ny, t + 1});
        }
    }
    for(const auto& i : ans) {
        for(i64 j : i) cout << j << " ";
        cout << "\n";
    }
}
