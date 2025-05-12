#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[300001];
vector<int> child[300001];
long long fac[300001];

int par[300001];
int get(int c) {
    if(par[c] == c) return c;
    return par[c] = get(par[c]);
}
void merge(int a, int b) {
    a = get(a), b = get(b);
    if(a != b) par[a] = b;
}

void dfs(int cur, int par) {
    for(int i : adj[cur]) {
        if(i == par) continue;
        child[cur].push_back(i);
        dfs(i, cur);
    }
}

void tle_assert(bool flag) {
    if(!flag) {
        while(true) {
            // TLE
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    fac[0] = fac[1] = 1;
    for(int i = 2; i <= 300000; i++) fac[i] = fac[i-1] * i % 998244353;
    for(int i = 0; i <= 300000; i++) par[i] = i;

    int n; cin >> n;
    tle_assert(n <= 300000);
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        tle_assert(1 <= u && u <= n);
        tle_assert(1 <= v && v <= n);
        adj[u].push_back(v);
        adj[v].push_back(u);
        tle_assert(get(u) != get(v));
        merge(u, v);
    }
    dfs(1, -1);

    long long ans = 1;
    for(int i = 1; i <= n; i++)
        ans = ans * fac[child[i].size()] % 998244353;
    cout << ans << '\n';
}
