#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i32 = signed;
template <typename T> using v = vector<T>;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(i, n) for(i64 i=0; i<n; i++)
#define Size(v) ((i64) v.size())

#ifndef LOCAL
static char buf[1<<19];
static int idx = 0;
static int bytes = 0;
static inline int _read() {
    if(!bytes || idx == bytes) {
        bytes = (int)fread(buf, sizeof(buf[0]), sizeof(buf), stdin);
        idx = 0;
    }
    return buf[idx++];
}
static inline int _readInt() {
    int x = 0, s = 1;
    int c = _read();
    while (c <= 32) c = _read();
    if(c == '-') s = -1, c = _read();
    while(c > 32) x = 10 * x + (c - '0'), c = _read();
    if(s < 0) x = -x;
    return x;
}
#else
int _readInt() {
    int i; cin >> i; return i;
}
#endif

i32 main() {
    fastio;
    i32 n = _readInt();
    v<v<i32>> con(n, v<i32>());
    v<array<i32, 4>> lines; // x1, x2, y1, y2
    forn(i, n) {
        i32 x1, y1, x2, y2; x1 = _readInt(); y1  = _readInt(); x2 = _readInt(); y2 = _readInt();
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        forn(j, Size(lines)) {
            if(x1 == x2) { // y축에 평행
                if(lines[j][0] == lines[j][1]) continue;
                if(y1 <= lines[j][2] && lines[j][2] <= y2 && lines[j][0] <= x1 && x1 <= lines[j][1]) {
                    con[i].emplace_back(j);
                    con[j].emplace_back(i);
                }
            } else { // x축에 평행
                if(lines[j][2] == lines[j][3]) continue;
                if(x1 <= lines[j][0] && lines[j][0] <= x2 && lines[j][2] <= y1 && y1 <= lines[j][3]) {
                    con[i].emplace_back(j);
                    con[j].emplace_back(i);
                }
            }
        }
        lines.push_back({x1, x2, y1, y2});
    }
    forn(i, n) {
        v<i32> ans(n, -1);
        queue<pair<i32, i32>> bfs;
        v<bool> vis(n, false);
        bfs.emplace(i, 0); vis[i] = true;
        while(!bfs.empty()) {
            auto [cur, dist] = bfs.front(); bfs.pop();
            ans[cur] = dist;
            for(const i32& j : con[cur]) {
                if(vis[j]) continue;
                vis[j] = true;
                bfs.emplace(j, dist+1);
            }
        }
        for(const i32& j : ans) cout << j << ' ';
        cout << '\n';
    }
}
