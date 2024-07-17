#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define int long long
#define cint const int &
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forn(n,v) for(int n=0;n<v;n++)
template <typename T> using v = vector<T>;
int input() {int t; cin >> t; return t;}

// 수열과 쿼리 24
// #segtree

class segtree_ {
#define MID ((start+end)/2)
public:
    class T {
    public:
        int val = 0, idx = -1;
        T()=default;
        explicit T(int v, int i) : val(v), idx(i) {}
        T operator+(const T &t2) const {
            if(val>t2.val) return T(val, idx);
            if(t2.val>val) return T(t2.val, t2.idx);
            return T(val, min(idx, t2.idx));
        }
        T& operator=(cint i) { val = i; return *this; }
        T& operator=(const T &i) = default;
    };
    vector<T> tree;
    int n;
    explicit segtree_(int treeSize, bool inputInit = false) {
        n = treeSize;
        tree = v<T>(4*treeSize, T());
        if(inputInit) {
            v<int> a;
            forn(i, treeSize) a.push_back(input());
            init(a, 1, 1, n);
        }
    }
    void update(int tar, int val) { update(tar, tar, val); }
    T query(int left, int right) { return query(1, left, right, 1, n); }
protected:
    void update(int left, int right, int diff) { update(1, left, right, 1, n, diff); }
    T init(const v<int> &a, int node, int start, int end) {
        if (start == end) return tree[node] = T(a[start - 1], start);
        return tree[node] = init(a, node * 2, start, MID) +
                            init(a, node * 2 + 1, MID + 1, end);
    }
    void update(int node, int left, int right, int start, int end, int diff) {
        if(end<left || right < start) return;
        if(left <= start && end <= right) { tree[node] = diff; return; }
        update(node*2, left, right, start, MID, diff);
        update(node*2+1, left, right, MID+1, end, diff);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    T query(int node, int left, int right, int start, int end) {
        if(right < start || end < left) return {};
        if(left <= start && end <= right) return tree[node];
        return query(node*2, left, right, start, MID) +
               query(node*2+1, left, right, MID+1, end);
    }
};

signed main() {
    fastio; int n, m; cin >> n;
    segtree_ seg(n, true);
    cin >> m;
    forn(k, m) {
        int t,l,r; cin>>t>>l>>r;
        if(t==2) {
            auto a = seg.query(l, r);
            cout << a.val + max(a.idx==l?-1:seg.query(l, a.idx-1).val, a.idx==r?-1:seg.query(a.idx+1, r).val) << '\n';
        } else seg.update(l, r);
    }
}
