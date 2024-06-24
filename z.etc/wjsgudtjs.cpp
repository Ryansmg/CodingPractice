#include <bits/stdc++.h>
using namespace std;

struct M {
    int m[3][3] = {0};
    M()=default;
    M(const M& m2) {
        for(int i=0; i<3; i++) for(int j=0; j<3; j++) m[i][j] = m2.m[i][j];
    }
};
int m2i(M& m) {
    int a = 0;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++) {
            if(m.m[i][j] == 3)  a += (1<<9)*(i*3+j);
            if(m.m[i][j] == 1)  a += 1<<(i*3+j);
        }
    return a;
}
int vis[2000];

int main() {
    int n; cin >> n;
    if(n<=1) { cout << 0; return 0; }
    M st;
    for(auto & i : st.m)
        for(int & j : i) cin >> j;
    vis[m2i(st)] = true;
    queue<pair<M, int>> q;
    q.emplace(st, 0);
    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};
    while(!q.empty()) {
        M frm = q.front().first;
        int fri = q.front().second;
        q.pop();
        queue<array<int, 2>> bfs;
        bfs.push({2, 0});
        bool visited[3][3] = {false};
        while(!bfs.empty()) {
            auto bfr = bfs.front(); bfs.pop();
            if(visited[bfr[0]][bfr[1]]) continue;
            visited[bfr[0]][bfr[1]] = true;
            for(int i=0; i<4; i++) {
                int nr = bfr[0]+dr[i], nc = bfr[1]+dc[i];
                if(nr<0||nc<0||nr>2||nc>2) continue;
                if(frm.m[nr][nc]==3) {
                    cout << fri; return 0;
                }
                if(frm.m[nr][nc]==1) continue;
                bfs.push({nr, nc});
            }
        }
        for(int r=0; r<3; r++) for(int c=0; c<3; c++) {
            if(frm.m[r][c] != 1) continue;
            for(int i=0; i<4; i++) {
                int nr = r+dr[i], nc = c+dc[i];
                if(nr<0||nc<0||nr>2||nc>2) continue;
                if(frm.m[nr][nc] != 0) continue;
                if(nr==2&&nc==0) continue;
                M pum(frm);
                pum.m[r][c] = 0;
                pum.m[nr][nc] = 1;
                if(vis[m2i(pum)]) continue;
                vis[m2i(pum)] = true;
                q.emplace(pum, fri+1);
            }
        }
    }
    cout << -1;
}
