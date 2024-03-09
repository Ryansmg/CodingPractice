#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct segtree {
    vector<int> tree;
    int n;
    segtree(){}
    segtree(int a) {
        tree.resize(4*a);
        n = a;
    }
    int identity_source = 0;
    int _segf(int a, int b) {
        return a + b;
    }
    void init(vector<int> a) {
        init(a.size(), a);
    }
    void init(int n, vector<int> a) {
        _init(a, 1, 1, n);
    }
    void _init(vector<int> a, int node, int start, int end) {
        if(start==end) tree[node] = a[start-1];
        else {
            _init(a, node*2, start, (start+end)/2);
            _init(a, node*2+1, (start+end)/2+1, end);
            tree[node] = _segf(tree[node*2], tree[node*2+1]);
        }
    }
    void update(int index, int val) {
        _update(1, 1, n, index, val);
    }
    void _update(int node, int start, int end, int index, int val)
    {
        if(index<start || end<index) return;
        if(start==end) {
            tree[node] = val;
        } else {
            _update(node*2, start, (start+end)/2, index, val);
            _update(node*2+1, (start+end)/2+1, end, index, val);
            tree[node] = _segf(tree[node*2], tree[node*2+1]);
        }
    }
    int query(int left, int right) {
        return _query(1, 1, n, left, right);
    }
    int _query(int node, int start, int end, int left, int right) {
        if(end < left || right < start) return identity_source;
        if(left <= start && end <= right) return tree[node];
        return _segf( _query(node*2, start, (start+end)/2, left, right),
            _query(node*2+1, (start+end)/2+1, end, left, right) );
    }
};

struct multiseg {
    vector<segtree> tree;
    int n;
    multiseg(){}
    multiseg(int a) {
        tree.resize(4*a);
        n = a;
    }
    int identity_source = 0;
    segtree _segf(segtree a, segtree &b) {
        for(int i=0; i<b.n*4; i++) {
            a.tree[i] += b.tree[i];
        }
        return a;
    }
    void init(vector<segtree> a) {
        init(a.size(), a);
    }
    void init(int n, vector<segtree> a) {
        _init(a, 1, 1, n);
    }
    void _init(vector<segtree> a, int node, int start, int end) {
        if(start==end) tree[node] = a[start-1];
        else {
            _init(a, node*2, start, (start+end)/2);
            _init(a, node*2+1, (start+end)/2+1, end);
            tree[node] = _segf(tree[node*2], tree[node*2+1]);
        }
    }
    void update(int yidx, int xidx, int val) {
        _update(1, 1, n, yidx, xidx, val);
    }
    void _update(int node, int start, int end, int yidx, int xidx, int val)
    {
        if(yidx<start || end<yidx) return;
        if(start==end) {
            tree[node].update(xidx, val);
        } else {
            _update(node*2, start, (start+end)/2, yidx, xidx, val);
            _update(node*2+1, (start+end)/2+1, end, yidx, xidx, val);
            tree[node] = _segf(tree[node*2], tree[node*2+1]);
        }
    }
    int query(int yl, int yr, int xl, int xr) {
        return _query(1, 1, n, yl, yr, xl, xr);
    }
    int _query(int node, int start, int end, int yl, int yr, int xl, int xr) {
        if(end < yl || yr < start) return identity_source;
        if(yl <= start && end <= yr) return tree[node].query(xl, xr);
        return tree[0]._segf( _query(node*2, start, (start+end)/2, yl, yr, xl, xr),
            _query(node*2+1, (start+end)/2+1, end, yl, yr, xl, xr) );
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<segtree> a;
    for(int i=0; i<n; i++) {
        vector<int> b;
        for(int j=0; j<n; j++) {
            int temp; cin >> temp; b.emplace_back(temp);
        }
        segtree ttree(n);
        ttree.init(n, b);
        a.emplace_back(ttree);
    }
    multiseg tree(n);
    tree.init(n, a);
    for(int i=0; i<m; i++) {
        int e, f, g, h, j;
        cin >> e;
        if(e==0) {
            cin >> f >> g >> h;
            tree.update(g, f, h);
        } else {
            cin >> f >> g >> h >> j;
            cout << tree.query(g, j, f, h) << "\n";
        }
    }
}