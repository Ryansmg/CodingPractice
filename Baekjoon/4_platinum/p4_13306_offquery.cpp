#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//13306. 트리
//#union_find #offline_queries

struct query {
    int type, a, b;
    query(){}
    query(int x, int y) {
        type=x; a=y; b=0;
    }
    query(int x, int y, int z) {
        type=x; a=y; b=z;
    }
};

int findRoot(vector<int> &parent, int n) {
    if(parent[n] == n) return n;
    else return parent[n] = findRoot(parent, parent[n]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> preparent(n+1);
    for(int i=2; i<=n; i++) {
        int a; cin >> a;
        preparent[i] = a;
    }
    stack<query> qst;
    for(int i=0; i<n-1+q; i++){
        int a, b; cin >> a >> b;
        if(a==0) qst.emplace(a, b, b);
        else {
            int c; cin >> c; qst.emplace(a, b, c);
        }
    }
    stack<bool> ans;
    vector<int> parent(n+1);
    for(int i=1; i<=n; i++) parent[i] = i;
    while(!qst.empty()) {
        query top = qst.top();
        qst.pop();
        if(top.type == 0) {
            parent[findRoot(parent, top.a)] = findRoot(parent, preparent[top.a]);
        } else {
            ans.push(findRoot(parent, top.a) == findRoot(parent, top.b));
        }
    }
    while(!ans.empty()) {
        cout << (ans.top() ? "YES\n" : "NO\n");
        ans.pop();
    }
}