#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 dc[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
i64 dr[] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int main() {
    i64 n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;
    x--; y--;

    // 범위 줄이기
    i64 maxR = min(n - 1, x + 2 * k), minR = max(0LL, x - 2 * k);
    i64 maxC = min(m - 1, y + 2 * k), minC = max(0LL, y - 2 * k);

    // (0, 0) ~ (maxR, maxC) 범위만 쓰기 위해 좌표 조정
    i64 r = x - minR, c = y - minC, dist;
    maxR -= minR; maxC -= minC;

    // 처음 상태에서 전혀 움직일 수 없는 경우 아무 곳에도 도착할 수 없음.
    bool flag = true;
    for(int i = 0; i < 8; i++) {
        i64 nxr = r + dr[i], nxc = c + dc[i];
        if(nxr < 0 || nxc < 0 || nxr > maxR || nxc > maxC) continue;
        flag = false; break;
    }
    if(flag) {
        cout << n * m << "\n";
        return 0;
    }

    // BFS 진행
    vector<vector<i64>> ans(maxR + 1, vector<i64>(maxC + 1, -1));
    queue<array<i64, 3>> bfs;
    bfs.push({r, c, 0});
    ans[r][c] = 0;
    while(!bfs.empty()) {
        r = bfs.front()[0], c = bfs.front()[1], dist = bfs.front()[2];
        bfs.pop();
        for(i64 i = 0; i < 8; i++) {
            i64 nxr = r + dr[i], nxc = c + dc[i];
            if(nxr < 0 || nxc < 0 || nxr > maxR || nxc > maxC || ans[nxr][nxc] != -1) continue;
            ans[nxr][nxc] = dist + 1;
            bfs.push({nxr, nxc, dist + 1});
        }
    }
    i64 avail = 0;
    for(const auto& arr : ans) for(i64 i : arr) {
        if(i != -1 && i <= k && i % 2 == k % 2) avail++;
    }
    cout << n * m - avail << "\n";
}
