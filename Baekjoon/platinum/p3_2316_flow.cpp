#define USE_MACROS true
#define GCC_OPTIMIZE_ENABLE true
#pragma region macros
#if USE_MACROS
#include <bits/stdc++.h>
#if GCC_OPTIMIZE_ENABLE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
#endif
#pragma endregion

// 2316. 도시 왕복하기 2
// #flow

v2<int> capacity, flow, con;

signed main() {
    fastio;
    int n, p; cin >> n >> p;
    // inNode : n, outNode : n+1000
    const int source = 1001, sink = 2;
    capacity = flow = v2<int>(n+1010, v<int>(n+1010, 0));
    con = v2<int>(n+1010, v<int>());
    for(int i=1; i<=n; i++) {
        capacity[i][i + 1000] = 1;
        con[i].push_back(i+1000);
        con[i+1000].push_back(i);
    }
    for(int i=0; i<p; i++) {
        int a, b; cin >> a >> b;
        con[a+1000].push_back(b);
        con[b+1000].push_back(a);
        con[a].push_back(b+1000);
        con[b].push_back(a+1000);
        capacity[a+1000][b]++;
        capacity[b+1000][a]++;
    }
    int maxFlow = 0;
    while(true) {
        queue<int> bfs;
        v<int> pre(n+1010, -1);
        bfs.push(source);
        while(!bfs.empty()) {
            int top = bfs.front(); bfs.pop();
            if(top == sink) break;
            for(const int &i : con[top]) {
                if(pre[i] == -1 && capacity[top][i] - flow[top][i] > 0) {
                    pre[i] = top;
                    bfs.push(i);
                }
            }
        }
        if(pre[sink] == -1) break;
        for(int i = sink; i != source; i = pre[i]) {
            flow[i][pre[i]]--;
            flow[pre[i]][i]++;
        }
        maxFlow++;
    }
    cout << maxFlow;
}
