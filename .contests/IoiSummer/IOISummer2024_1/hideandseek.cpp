#include <queue>
#include <cstdio>
#include <vector>
#include <cstdlib>

extern int hide(int, std::vector<int>, std::vector<int>) ;
void light_switch(int) ;

static int N, M, curr;
static std::vector<int> adj[2006], adj_rev[2006];
static int lights[2006], res;
static int full;

void assertion(bool x, int s) {
    if (x) return;
    else if (s < 0) puts("Wrong Input");
    else printf("Wrong Answer\n");
    exit(0);
}

void light_switch(int to) {
    if (full != -1) return;
    if (!(to >= 1 && to <= N)) {
        full = 0;
        return;
    }
    to--;
    std::vector<int> visited(N, 0);
    std::queue<int> q;
    q.push(curr);
    visited[curr] = 1;
    while (!q.empty()) {
        int t = q.front(); q.pop();
        for (auto &i: adj[t]) {
            if (visited[i]) continue;
            if (!lights[t]) continue;
            visited[i] = true;
            q.push(i);
        }
        for (auto &i: adj_rev[t]) {
            if (visited[i]) continue;
            if (!lights[i]) continue;
            visited[i] = true;
            q.push(i);
        }
    }
    if (!visited[to]) {
        full = 1;
        return;
    }
    curr = to;
    if (!lights[curr]) res++;
    lights[curr] ^= 1;
}

int main() {
    full = -1;
    assertion(scanf("%d%d", &N, &M) == 2, -1);
    std::vector<int> U, V;
    for (int i = 0; i < M; i++) {
        int u, v;
        assertion(scanf("%d%d", &u, &v) == 2, -1);
        U.push_back(u);
        V.push_back(v);
        adj[u - 1].push_back(v - 1);
        adj_rev[v - 1].push_back(u - 1);
    }
    curr = 0;
    lights[0] = 1;
    int result = hide(N, U, V);
    if (result != -1) {
        if (curr != N - 1 && full == -1) full = 2;
        if (full == -1) for (int i = 0; i < N; i++) if (lights[i]) full = 3;
        if (res != result && full == -1) full = 4;
        printf("%d\n", result);
    } else {
        if (res != 0) full = 5;
        for (int i = 1; i < N; i++) if (lights[i]) full = 5;
        printf("%d\n", -1);
    }
    if (full != -1) printf("Wrong answer [%d]\n", full);
}

/////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define all(vec) (vec).begin(), (vec).end()
using i64 = long long;
using i32 = int;
template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
const i64 inf = 3000000000;
#define forn(i, n) for(i64 i=0; i<n; i++)
#define forf(i, s, e) for(i64 i=s; i<=e; i++)

i32 n;
v2<i32> con;
v2<i32> rev;

struct state {
    v<bool> light, vis;
    i32 lightCnt;
    queue<i32> his;
    i32 pos;
    state() {
        light = vis = v<bool>(n+10, false);
        light[1] = true;
        pos = 1;
        lightCnt = 1;
    }
};

int hide(int nnn, std::vector<int> u, std::vector<int> vin) {
    n = nnn;
    if(n==1) {
        light_switch(1);
        return 0;
    }
    con = rev = v2<i32>(n+1, v<i32>());
    i64 m = u.size();
    forn(i, m) {
        con[u[i]].push_back(vin[i]);
        rev[vin[i]].push_back(u[i]);
    }
    queue<state> q;
    q.emplace();
    state ans;
    while(!q.empty()) {
        state top = q.front(); q.pop();
        if(top.lightCnt == 0) { ans = top; break; }
        queue<i32> bfs;
        bfs.push(top.pos);
        v<bool> vis(n+10, false);
        vis[top.pos] = true;
        while(!bfs.empty()) {
            i32 top2 = bfs.front(); bfs.pop();
            bool last = true;
            for(i32 i : con[top2]) {
                if(!top.light[top2]) break;
                if(vis[i]) continue;
                vis[i] = true;
                bfs.push(i);
                last = false;
            }
            for(i32 i : rev[top2]) {
                if(!top.light[i]) continue;
                if(vis[i]) continue;
                vis[i] = true;
                bfs.push(i);
                last = false;
            }
            if(last && top2 != top.pos) {
                state nxt = top;
                nxt.pos = top2;
                nxt.his.push(top2);
                if(nxt.light[top2]) { nxt.light[top2] = false; nxt.lightCnt--; }
                else { nxt.light[top2] = true; nxt.lightCnt++; }
                q.push(nxt);
            }
        }
    }
    i32 ret = (i32)ans.his.size()/2;
    while(!ans.his.empty()) {
        light_switch(ans.his.front());
        ans.his.pop();
    }
    return ret==0?-1:ret;
}