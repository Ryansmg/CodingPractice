#include <cstdio>
#include <vector>
#include <cstdlib>

extern std::vector<int> trade(int, std::vector<int>, std::vector<int>, std::vector<int>);

void assertion(bool x, int s) {
    if(x) return;
    else puts("Wrong Input");
    exit(0);
}

int main() {
    int N, M;
    assertion(scanf("%d%d", &N, &M) == 2, -1);
    std::vector<int> U, V, C;
    for(int i = 0; i < N - 1; i++) {
        int u, v;
        assertion(scanf("%d%d", &u, &v) == 2, -1);
        U.push_back(u);
        V.push_back(v);
    }
    for (int i = 0; i < N; i++) {
        int c;
        assertion(scanf("%d", &c) == 1, -1);
        C.push_back(c);
    }

    std::vector<int> ret = trade(M, U, V, C);
    for(int i = 0 ; i < (int)ret.size(); i++) {
        printf("%d ", ret[i]);
    }
    printf("\n");

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
using i32 = int; using i64 = long long;
const i64 i64max = 9223372036854775807;
const i64 INF    = 1000000000000000000;
const i64 inf    = 3000000000;
template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
#define forn(i, n) for(i64 i=0; i<n; i++)
#define forf(i, a, b) for(i64 i=a; i<=b; i++)
#define all(vec) (vec).begin(), (vec).end()
template <typename T> void sort(v<T> &arr) { sort(all(arr)); }
template <typename T> void compress(v<T> &arr, bool autosort = true) { if(autosort) sort(arr); arr.erase(unique(all(arr), arr.end())); }
i64 idx(i64 val, const v<i64> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }

v<int> trade(int M, v<int> U, v<int> V, v<int> C) {
    int N = (int) C.size();
    v2<int> adj(N, v<int>());
    forn(i, N-1) adj[U[i]].push_back(V[i]), adj[V[i]].push_back(U[i]);
    v<int> ans = v<int>(N);

    forn(i, N) {
        v<int> chk(N, -1); // -1 : none, -2 : 겹침, >=0 : 노드 번호
        v<bool> vis(N, false);
        function<void(int, int, int)> dfs = [&](int v, int depth, int par) {
            if(depth && chk[depth] == -1) chk[depth] = v;
            else if(chk[depth] >= 0) chk[depth] = -2;
            for(int j : adj[v]) {
                if(j==par) continue;
                dfs(j, depth+1, v);
            }
        };
        dfs(i, 0, -1);
        set<int> s;
        for(int j : chk) {
            if(j < 0) continue;
            s.insert(C[j]);
        }
        ans[i] = s.size();
    }

    return ans;
}
