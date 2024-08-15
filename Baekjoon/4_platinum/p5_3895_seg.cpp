#include <bits/stdc++.h>
using namespace std;
using i32 = signed; using i64 = long long; using i128 = __int128;
#define int i64
#define ci64 const i64 &
#define cint ci64
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(name, val) for(i64 name = 0; name < val; name++)
template <typename T> using v = vector<T>;
class segtree {
protected:
    vector<int> tree; int n;
public:
    explicit segtree(cint treeSize) {
        tree = v<int>(4*treeSize, 1); n = treeSize;
        init(1, 1, n);
    }
    void update(cint tar, cint diff) { update(1, tar, 1, n, diff); }
    int query(cint left, cint right) {
        return query(1, left, right, 1, n);
    }
    i64 query2(ci64 val) {
        return query2(1, val, 1, n);
    }
protected:
    int init(int node, int start, int end) {
        if(start==end) return tree[node];
        else return tree[node] = init(node*2, start, (start+end)/2)
                                 + init(node*2+1, (start+end)/2+1, end);
    }
    int update(int node, int tar, int start, int end, int diff) {
        if(end < tar || tar < start) return tree[node];
        if(start == end) return tree[node] = diff;
        return tree[node] = update(node*2, tar, start, (start+end)/2, diff)
                            + update(node*2+1, tar, (start+end)/2+1, end, diff);
    }
    int query(int node, int left, int right, int start, int end) {
        if(right < start || end < left) return 0;
        if(left <= start && end <= right) return tree[node];
        return query(node*2, left, right, start, (start+end)/2) +
               query(node*2+1, left, right, (start+end)/2+1, end);
    }
    int query2(int node, int val, int start, int end) {
        if(start==end) return start;
        if(tree[node*2]>=val) return query2(node*2, val, start, (start+end)/2);
        return query2(node*2+1, val-tree[node*2], (start+end)/2+1, end);
    }
};

// 3895. 그리고 하나가 남았다
// #segtree

i32 main() {
    fastio;
    for (;;) {
        i64 t = 0;
        i64 n, k;
        cin >> n >> k >> t;
        if (!n && !k && !t) return 0;
        bool b = true;
        segtree seg(n);
        forn(asdf, n) {
            i64 off = 0;
            if(b) {
                b = false;
                seg.update(t, 0);
                continue;
            }
            if (t) off = seg.query(1, t);
            i64 tar = (off + k) % (n - asdf);
            if (!tar) tar = n - asdf;
            t = seg.query2(tar);
            seg.update(t, 0);
            if (asdf == n - 1) cout << t << '\n';
        }
    }
}
