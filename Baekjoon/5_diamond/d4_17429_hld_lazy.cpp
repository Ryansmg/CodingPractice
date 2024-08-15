#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using i32 = signed;
using u32 = unsigned;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(name, val) for(int name = 0; name < val; name++)
template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
template <typename T = u32> T input() {T t; cin >> t; return t;}

// 국제 메시 기구
// #hld #lazyprop

class lazyprop {
public:
    lazyprop()=default;
    class L {
    public:
        u32 plus = 0, times = 1;
        L()=default;
        L(u32 p, u32 t) : plus(p), times(t) {}
        void operator+=(const L &i) {
            times *= i.times; plus *= i.times; plus += i.plus;
        }
        L operator*(u32 i) const { return {plus*i, times}; }
        void operator*=(const u32 &i) { plus *= i;}
        L& operator=(const L &i) = default;
    };
    class T {
    public:
        u32 val = 0;
        T()=default;
        explicit T(u32 v) : val(v) {}
        T operator+(const T &t2) const { return T(val + t2.val); }
        void operator+=(const T &i) { val += i.val; }
        T& operator=(u32 i) { val = i; return *this; }
        void operator+=(const L &i) { val *= i.times; val += i.plus; }
        T operator%(const u32 &i) const { return T(val%i); }
    };
protected:
    v<T> tree; v<L> lazy;
    u32 n=-1;
    void update_lazy(u32 node, u32 start, u32 end) {
        tree[node] += lazy[node] * (end-start+1);
        if(start!=end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = {};
    }
public:
    explicit lazyprop(u32 treeSize, bool inputInit = false) {
        lazy = v<L>(4*treeSize, L());
        tree = v<T>(4*treeSize, T());
        n = treeSize;
        if(inputInit) {
            v<u32> a; forn(i, n) a.push_back(input());
            init(a, 1, 1, n);
        }
    }
    explicit lazyprop(const v<u32> &a) : lazyprop((u32) a.size()) {
        init(a, 1, 1, n);
    }
    lazyprop(const v<u32> &a, u32 treeSize) : lazyprop(treeSize) {
        init(a, 1, 1, n);
        assert(a.size() == treeSize);
    }
    void update(u32 left, u32 right, L diff) { update(1, left, right, 1, n, diff); }
    T query(u32 tar) { return query(tar, tar); }
    T query(u32 left, u32 right) { return query(1, left, right, 1, n); }
protected:
    void init(const v<u32> &a, u32 node, u32 start, u32 end) {
        if(start==end) {
            tree[node] = a[start-1];
        } else {
            init(a, node*2, start, (start+end)/2);
            init(a, node*2+1, (start+end)/2+1, end);
            tree[node] = tree[node*2] + tree[node*2+1];
        }
    }
    void update(u32 node, u32 left, u32 right, u32 start, u32 end, L diff) {
        update_lazy(node, start, end);
        if(end<left || right < start) return;
        if(left <= start && end <= right) {
            tree[node] += diff * (end-start+1);
            if(start!=end) {
                lazy[node*2] += diff;
                lazy[node*2+1] += diff;
            }
            return;
        }
        update(node*2, left, right, start, (start+end)/2, diff);
        update(node*2+1, left, right, (start+end)/2+1, end, diff);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    T query(u32 node, u32 left, u32 right, u32 start, u32 end) {
        update_lazy(node, start, end);
        if(right < start || end < left) return {};
        if(left <= start && end <= right) return tree[node];
        return (query(node*2, left, right, start, (start+end)/2) +
                query(node*2+1, left, right, (start+end)/2+1, end));
    }
};

v<u32> sz, dep, par, top, in, out, vis;
v2<u32> con, conraw;
u32 pv = 0;

lazyprop seg;

void dfs0(u32 v=1) {
    vis[v] = true;
    for(const u32 &j : conraw[v]) {
        if(vis[j]) continue;
        vis[j] = true;
        con[v].push_back(j);
        dfs0(j);
    }
}

void dfs1(u32 v=1) {
    sz[v] = 1;
    for(u32 &i : con[v]) {
        dep[i] = dep[v] + 1; par[i] = v;
        dfs1(i);
        sz[v] += sz[i];
        if(sz[i] > sz[con[v][0]]) swap(i, con[v][0]);
    }
}

void dfs2(u32 v=1) {
    in[v] = ++pv;
    for(u32 i : con[v]) {
        top[i] = (i==con[v][0]) ? top[v] : i;
        dfs2(i);
    }
    out[v] = pv;
}

u32 query(u32 a, u32 b) {
    u32 ret = 0;
    while(top[a] != top[b]) {
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        u32 st = top[a];
        ret += seg.query(in[st], in[a]).val;
        a = par[st];
    }
    if(dep[a] > dep[b]) swap(a, b);
    ret += seg.query(in[a], in[b]).val;
    return ret;
}

void update(u32 a, u32 b, lazyprop::L l) {
    while(top[a] != top[b]) {
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        u32 st = top[a];
        seg.update(in[st], in[a], l);
        a = par[st];
    }
    if(dep[a] > dep[b]) swap(a, b);
    seg.update(in[a], in[b], l);
}

void initHld() {
    dep[1] = 0; par[1] = 1; top[1] = 1;
    dfs0(); dfs1(); dfs2();
}

i32 main() {
    fastio;
    u32 n, q; cin >> n >> q;
    sz = dep = par = top = in = out = vis = v<u32>(n+1, 0);
    con = conraw = v2<u32>(n+1, v<u32>());
    forn(i, n-1) {
        u32 s, e; cin >> s >> e;
        conraw[s].push_back(e);
        conraw[e].push_back(s);
    }
    seg = lazyprop(n+1);
    initHld();
    forn(qi, q) {
        u32 query_type = input(), x, y, v;
        switch(query_type) {
            case 1:
                cin >> x >> v;
                seg.update(in[x], out[x], {v, 1});
                break;
            case 2:
                cin >> x >> y >> v;
                update(x, y, {v, 1});
                break;
            case 3:
                cin >> x >> v;
                seg.update(in[x], out[x], {0, v});
                break;
            case 4:
                cin >> x >> y >> v;
                update(x, y, {0, v});
                break;
            case 5:
                cin >> x;
                cout << seg.query(in[x], out[x]).val << '\n';
                break;
            case 6:
                cin >> x >> y;
                cout << query(x, y) << '\n';
                break;
            default:
                assert(false);
        }
    }
}


