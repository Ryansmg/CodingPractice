#include <bits/stdc++.h>
using namespace std;
#define int long long

// 2150. Strongly Connected Components
// #scc

// https://blog.naver.com/ndb796/221236952158

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

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int v, e; cin >> v >> e;
    vector<int> temp;
    vector<vector<int>> tcon(v+1, temp); con = tcon;
    int a, b;
    for(int i=0; i<e; i++) {
        cin >> a >> b;
        con[a].push_back(b);
    }
    vector<bool> tfinished(v+1, false); finished = tfinished;
    vector<int> tid(v+1, -1); id = tid;
    for(int i=1; i<=v; i++) {
        if(finished[i]) continue;
        dfs(i);
    }
    sort(sccs.begin(), sccs.end(), sccsCmp);
    cout << sccs.size() << "\n";
    for(auto v : sccs) {
        for(int i : v) {
            cout << i << " ";
        }
        cout << "-1\n";
    }
}
