#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define forn(i, n) for(int i=0; i<n; i++)
#define forf(i, a, b) for(int i = a; i <= b; i++)
template <typename T> using v = vector<T>;

v<int> count_graphs(int N, v<int> U, v<int> V){
    v<v<int>> adj(N, v<int>());
    v<int> answer(4, 0);

    int M = int(U.size());
    forn(i, M) {
        adj[U[i]].emplace_back(V[i]);
        adj[V[i]].emplace_back(U[i]);
    }
    function<void(int, int, int, int)> dfs = [&](int tar, int node, int dep, int par) {
        if(dep > 4) return;
        for(int i : adj[node]) {
            if(i == par) continue;
            if(i == tar && dep == 4) {
                answer[0]++;
            }
            else {
                dfs(tar, i, dep+1, node);
            }
        }
    };
    forn(i, N) {  dfs(i, i, 2, -1); }
    answer[0]/=6;

    function<void(int, int, int, int)> dfs2 = [&](int tar, int node, int dep, int par) {
        if(dep > 5) return;
        for(int i : adj[node]) {
            if(i == par) continue;
            if(i == tar && dep == 5) {
                answer[1]++;
            }
            else {
                dfs2(tar, i, dep+1, node);
            }
        }
    };
    forn(i, N) {  dfs2(i, i, 2, -1); }
    answer[1] /= 8;

    return answer;
}
