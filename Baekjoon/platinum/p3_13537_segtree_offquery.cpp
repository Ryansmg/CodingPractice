#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 수열과 쿼리 1
// #segtree #offline_queries #sorting
// 정석 풀이 : #merge_sort_tree

struct segtree {
    vector<int> tree;
    int n;
    segtree(){}
    segtree(int a) {
        tree.resize(4*a);
        n = a;
    }
    void update(int index, int val) {
        _update(1, 1, n, index, val);
    }
    void _update(int node, int start, int end, int index, int val)
    {
        if(index<start || end<index) return;
        if(start==end) {
            tree[node] = 1;
        } else {
            _update(node*2, start, (start+end)/2, index, val);
            _update(node*2+1, (start+end)/2+1, end, index, val);
            tree[node] = tree[node*2] + tree[node*2+1];
        }
    }
    int query(int left, int right) {
        return _query(1, 1, n, left, right);
    }
    int _query(int node, int start, int end, int left, int right) {
        if(end < left || right < start) return 0;
        if(left <= start && end <= right) return tree[node];
        return _query(node*2, start, (start+end)/2, left, right) 
            + _query(node*2+1, (start+end)/2+1, end, left, right);
    }
};

struct query {
    bool isInsert;
    int i, j, k, l;
    query(){}
    query(int c, int d, int e, int f) {
        isInsert = false;
        i = c;
        j = d;
        k = e;
        l = f;
    }
    query(int c, int d) {
        isInsert = true;
        i = k = c;
        j = d;
    }
    
};
bool qcmp(query a, query b) {
    if(a.k == b.k) {
        if(a.isInsert == !b.isInsert) return !a.isInsert;
        else return a.j < b.j;
    }
    else return a.k > b.k;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    segtree tree(n);
    vector<query> queries;
    int t, a, b, c;
    for(int i=0; i<n; i++) {
        cin >> t; queries.push_back(*new query(t, i+1));
    }
    int m; cin >> m;
    vector<int> ans(m);
    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        queries.push_back(*new query(a, b, c, i));
    }
    sort(queries.begin(), queries.end(), qcmp);
    for(query q : queries) {
        if(q.isInsert) {
            tree.update(q.j, q.k);
        } else {
            ans[q.l] = tree.query(q.i, q.j);
        }
    }
    for(int a : ans) cout << a << "\n";
}