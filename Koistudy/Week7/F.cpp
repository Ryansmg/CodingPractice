#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> weights;
vector<int> ans;
vector<bool> vis;
vector<vector<pair<int, int>>> adj;
int n, m, k;

void dfs(int cur) {
    if(cur == n) {
        int weightSum = 0;
        for(int i : weights) weightSum += i;
        for(int i : weights) ans.push_back(weightSum - i + i / 2);
        return;
    }
    for(auto p : adj[cur]) {
        if(vis[p.first]) continue;
        weights.push_back(p.second);
        vis[p.first] = true;
        dfs(p.first);
        weights.pop_back();
        vis[p.first] = false;
    }
}

int main() {
    cin >> n >> m >> k;
    adj.resize(n+1);
    vis.resize(n+1);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vis[1] = true;
    dfs(1);
    sort(ans.begin(), ans.end());
    if(ans.size() < k) cout << "-1\n";
    else cout << ans[k-1] << '\n';
}
