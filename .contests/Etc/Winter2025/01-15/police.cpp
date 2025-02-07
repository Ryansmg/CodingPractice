#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> con;
vector<int> id;
int curid=0;
vector<bool> finished;
vector<int> st;
vector<vector<int>> sccs;

bool sccsCmp(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
}

int dfs(int node) {
    id[node] = ++curid;
    st.push_back(node);
    int parent = id[node];
    for(int i : con[node]) {
        if(id[i] == -1) parent = min(parent, dfs(i));
        else if(!finished[i]) parent = min(parent, id[i]);
    }
    if(parent == id[node]) {
        vector<int> scc;
        while(true) {
            int top = st.back(); st.pop_back();
            scc.push_back(top);
            finished[top] = true;
            if(top == node) break;
        }
        sort(scc.begin(), scc.end());
        sccs.push_back(scc);
    }
    return parent;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int v, e; cin >> v >> e;
    con = vector<vector<int>>(v+1, vector<int>());
    vector<int> arr(1, -1); int asdf;
    for(int i=0; i<v; i++) {
        cin >> asdf; arr.push_back(asdf);
    }
    int a, b;
    for(int i=0; i<e; i++) {
        cin >> a >> b;
        con[a].push_back(b);
    }
    finished = vector<bool>(v+1, false);
    id = vector<int>(v+1, -1);
    for(int i=1; i<=v; i++) {
        if(finished[i]) continue;
        dfs(i);
    }
    int ans = 0;
    for(const auto &scc : sccs) {
        int cans = 124748364;
        for(int i : scc) cans = min(cans, arr[i]);
        ans += cans;
    }
    cout << ans << '\n';
}
