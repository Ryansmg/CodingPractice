// #pragma GCC optimize("O3")

// 1-based index

using T = int;
constexpr int N = 100100;
constexpr T INF = 2147483647;

#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
#include <bitset>

namespace AAA {
    int root;      // current root
    int true_root; // expected root (on subtree queries)
    int par[N];    // parent on lct
    T val[N];      // value

    // lazy는 자신에게 미리 적용

    struct {
        T c; // chain
        T t; // tree (virtual only)
    } mx[N], mn[N], sum[N], // values
      add[N], // add tag
      set[N]; // set tag, default INF

    struct {
        int c, t;
    } sz[N];

    std::bitset<N> flip;

    // lct structure
    // [0]: left, [1]: right
    int real[N][2], virt[N][2], vson[N];

#define mxa(x) std::max(mx[x].t, mx[x].c)
#define mna(x) std::min(mn[x].t, mn[x].c)
#define suma(x) (sum[x].t + sum[x].c)
#define sza(x) (sz[x].t + sz[x].c)

    void pull_c(int x) {
        if(!x) return;
        mx[x].c = std::max({val[x], mx[real[x][0]].c, mx[real[x][1]].c});
        mn[x].c = std::min({val[x], mn[real[x][0]].c, mn[real[x][1]].c});
        sum[x].c = val[x] + sum[real[x][0]].c + sum[real[x][1]].c;
        sz[x].c = sz[real[x][0]].c + sz[real[x][1]].c + 1;
    }

    void pull_t(int x) {
        if(!x) return;
        mx[x].t = std::max({ mx[real[x][0]].t, mx[real[x][1]].t,
            mxa(vson[x]), mxa(virt[x][0]), mxa(virt[x][1])});
        mn[x].t = std::min({ mn[real[x][0]].t, mn[real[x][1]].t,
                    mna(vson[x]), mna(virt[x][0]), mna(virt[x][1])});
        sum[x].t = sum[real[x][0]].t + sum[real[x][1]].t +
                    suma(vson[x]) + suma(virt[x][0]) + suma(virt[x][1]);
        sz[x].t = sz[real[x][0]].t + sz[real[x][1]].t +
                    sza(vson[x]) + sza(virt[x][0]) + sza(virt[x][1]);
    }

    void pull(int x) {
        if(!x) return;
        pull_c(x); pull_t(x);
    }

    int ptype(int x) {
        int p = par[x];
        if(real[p][0] == x || real[p][1] == x) return 1; // real
        if(virt[p][0] == x || virt[p][1] == x) return 2; // virt
        if(vson[p] == x) return 3;                       // virt tree (x is root)
        return 0;                                        // root
    }

    // child pos (l/r) in real[par[x]]
    inline int cposr(int x) {
        return real[par[x]][1] == x;
    }

    inline int cposv(int x) {
        return virt[par[x]][1] == x;
    }

    void rotate_real(int x) {
        int y = par[x], z = par[y], k = ptype(y);
        if(k == 1) /* real */ real[z][cposr(y)] = x;
        else if(k == 2 || k == 3) { // virt / virt tree
            (k == 2 ? virt[z][cposv(y)] : vson[z]) = x;
            std::swap(virt[x], virt[y]);
        }

        int L = cposr(x), R = !L;
        par[x] = z; par[y] = x; par[real[x][R]] = y;
        real[y][L] = real[x][R]; real[x][R] = y;
        pull(y); pull(x);
    }

    void rotate_virt(int x) {
        int y = par[x], z = par[y], k = ptype(y);
        if(k == 2 || k == 3)
            (k == 2 ? virt[z][cposv(y)] : vson[z]) = x;

        int L = cposv(x), R = !L;
        par[x] = z; par[y] = x; par[virt[x][R]] = y;
        virt[y][L] = virt[x][R]; virt[x][R] = y;
        pull(y); pull(x);
    }

    void set_chain(int x, T v) {
        if(!x) return;

        set[x].c = val[x] = mn[x].c = mx[x].c = v;
        sum[x].c = sz[x].c * v;
        add[x].c = 0;
    }

    void add_chain(int x, T v) {
        if(!x) return;
        if(set[x].c != INF) set[x].c += v;
        else add[x].c += v;
        val[x] += v;
        mn[x].c += v; mx[x].c += v;
        sum[x].c += sz[x].c * v;
    }

    void set_tree(int x, T v) {
        if(!x) return;
        set[x].t = v; add[x].t = 0;
        if(sz[x].t) mn[x].t = mx[x].t = v;
        sum[x].t = sz[x].t * v;
    }

    void add_tree(int x, T v) {
        if(!x) return;
        if(set[x].t != INF) set[x].t += v;
        else add[x].t += v;

        if(sz[x].t) mn[x].t += v, mx[x].t += v;
        sum[x].t += sz[x].t * v;
    }

    void set_all(int x, T v) {
        set_chain(x, v); set_tree(x, v);
    }

    void add_all(int x, T v) {
        add_chain(x, v); add_tree(x, v);
    }

    void rev(int x) {
        if(!x) return;
        std::swap(real[x][0], real[x][1]);
        flip[x].flip();
    }

    void push(int x) {
        if(!x) return;
        if(flip[x]) {
            rev(real[x][0]); rev(real[x][1]);
            flip[x] = false;
        }
        if(set[x].c != INF) {
            set_chain(real[x][0], set[x].c);
            set_chain(real[x][1], set[x].c);
        }
        if(add[x].c) {
            add_chain(real[x][0], add[x].c);
            add_chain(real[x][1], add[x].c);
        }
        if(set[x].t != INF) {
            set_all(vson[x], set[x].t);
            set_all(virt[x][0], set[x].t);
            set_all(virt[x][1], set[x].t);
            set_tree(real[x][0], set[x].t);
            set_tree(real[x][1], set[x].t);
        }
        if(add[x].t) {
            add_all(vson[x], add[x].t);
            add_all(virt[x][0], add[x].t);
            add_all(virt[x][1], add[x].t);
            add_tree(real[x][0], add[x].t);
            add_tree(real[x][1], add[x].t);
        }
        set[x].c = set[x].t = INF;
        add[x].c = add[x].t = 0;
    }

    void push_par(int x) {
        if(par[x]) push_par(par[x]);
        push(x);
    }

    void push_par(int x, int k) {
        if(ptype(x) == k) push_par(par[x], k);
        push(x);
    }

    void splay_real(int x) {
        push_par(x, 1);
        for(int y = par[x]; ptype(x) == 1; rotate_real(x), y = par[x])
            if(ptype(y) == 1)
                rotate_real(cposr(x) == cposr(y) ? y : x);
    }

    void splay_virt(int x) {
        push_par(x, 2);
        for(int y = par[x]; ptype(x) == 2; rotate_virt(x), y = par[x])
            if(ptype(y) == 2)
                rotate_virt(cposv(x) == cposv(y) ? y : x);
    }

    int merge(int x, int y) {
        if(!x || !y) return x + y;
        push(x); push(y);
        if(sz[x].t < sz[y].t)
            std::swap(x, y);
        par[y] = x;
        if(sz[virt[x][0]].t < sz[virt[x][1]].t)
            virt[x][0] = merge(virt[x][0], y);
        else virt[x][1] = merge(virt[x][1], y);

        pull(x);
        return x;
    }

    void access(int x) {
        int t = 0;
        push_par(x);
        while(x) {
            splay_real(x);
            splay_virt(x);
            if(real[x][1]) {
                int y = real[x][1], z = vson[x];
                push(y);
                virt[y][0] = z;
                par[z] = y; par[y] = x;
                vson[x] = y;
                real[x][1] = 0;
                pull(y); pull(x);
            }
            int y = par[x];
            if(t) {
                real[x][1] = t; par[t] = x;
                pull(x);
            }
            int z = merge(virt[x][0], virt[x][1]);
            if(y) vson[y] = z;
            par[z] = y; par[x] = 0;
            virt[x][0] = virt[x][1] = 0;
            pull(y); t = x; x = y;
        }
    }

    void set_root_(int x) {
        if(root == x) return;
        access(x); splay_real(x);
        rev(x); root = x;
    }

    void check_root() {
        set_root_(true_root);
    }

    // x의 부모가 없어도 됨.
    void cut(int x) {
        check_root();
        access(x);
        splay_real(x);
        par[real[x][0]] = 0;
        real[x][0] = 0;
        pull(x);
    }

    void link(int parent, int child) {
        set_root_(child);
        access(parent);
        splay_real(parent);
        real[parent][1] = child;
        par[child] = parent;
        pull(parent);

        root = parent;
        while(real[root][0])
            root = real[root][0];
    }

    bool is_child(int parent, int child) {
        if(parent == child) return true;
        check_root();
        access(child); splay_real(child);
        int z = parent;
        while(ptype(z) == 1) z = par[z];
        return z == child;
    }

    int parent(int x) {
        check_root();
        access(x);
        if(!real[x][0]) return 0;
        x = real[x][0]; push(x);
        while(real[x][1]) x = real[x][1], push(x);
        splay_real(x);
        return x;
    }

    void cut(int x, int y) {
        if(parent(x) == y) cut(x);
        else assert(parent(y) == x), cut(y);
    }

    int lca(int x, int y) {
        check_root();
        access(x); access(y); splay_real(x);
        return par[x] ? par[x] : x;
    }

    int subtree(int x) {
        check_root();
        access(x); splay_real(x);
        return x;
    }

    int chain(int x, int y) {
        set_root_(x);
        access(y);
        splay_real(y);
        return y;
    }

    void reroot(int x) {
        true_root = x;
    }

}

namespace init {
    static constexpr int M = N * 2;
    int cnt = 1, tar[M]{}, nxt[M]{}, fst[N]{};

    void add_(int a, int b){
        tar[++cnt] = b, nxt[cnt] = fst[a], fst[a] = cnt;
    }

    void add_edge(int a, int b) {
        add_(a, b);
        add_(b, a);
    }

    T& val(int idx) {
        return AAA::val[idx];
    }

    void set_val(int idx, T value) {
        AAA::val[idx] = value;
    }

    void dfs(int x, int p) {
        using namespace AAA;
        int pre_son = 0;
        for(int i = fst[x]; i; i = nxt[i]) {
            int y = tar[i];
            if(y == p) continue;
            dfs(y, x);
            if(!pre_son) pre_son = y;
            else {
                par[pre_son] = y;
                virt[y][0] = pre_son;
                pre_son = y;
            }
            pull(y);
        }

        if(pre_son) {
            par[pre_son] = x;
            vson[x] = pre_son;
        }
        pull(x);
    }

    void reset() {
        using namespace AAA;
        for(int i = 0; i < N; i++) {
            par[i] = AAA::val[i] = add[i].c = add[i].t
                = sum[i].c = sum[i].t = sz[i].c = sz[i].t
                = real[i][0] = real[i][1]
                = virt[i][0] = virt[i][1] = vson[i] = 0;
            mx[i].t = mx[i].c = -INF;
            mn[i].t = mn[i].c = set[i].t = set[i].c = INF;
        }

        std::memset(tar, 0, sizeof tar);
        std::memset(nxt, 0, sizeof nxt);
        std::memset(fst, 0, sizeof fst);
        cnt = 1;
    }

    struct auto_reset_at_start_ {
        auto_reset_at_start_() {
            reset();
        }
    } aras_;

    void init(int node_count, int root) {
        assert(node_count < N);
        AAA::root = AAA::true_root = root;
        dfs(root, 0);
    }
}

namespace subtree {
    void add(int target, T value) {
        using namespace AAA;
        AAA::subtree(target);
        add_all(real[target][1], value);
        add_all(vson[target], value);
        val[target] += value;
        pull(target);
    }

    void set(int target, T value) {
        using namespace AAA;
        AAA::subtree(target);
        set_all(real[target][1], value);
        set_all(vson[target], value);
        val[target] = value;
        pull(target);
    }

    int size(int target) {
        using namespace AAA;
        AAA::subtree(target);
        return 1 + sza(real[target][1]) + sza(vson[target]);
    }

    T min(int target) {
        using namespace AAA;
        AAA::subtree(target);
        return std::min({val[target], mna(real[target][1]), mna(vson[target])});
    }

    T max(int target) {
        using namespace AAA;
        AAA::subtree(target);
        return std::max({val[target], mxa(real[target][1]), mxa(vson[target])});
    }

    T sum(int target) {
        using namespace AAA;
        AAA::subtree(target);
        return val[target] +
            (AAA::sum[real[target][1]].t + AAA::sum[real[target][1]].c) +
                (AAA::sum[vson[target]].t + AAA::sum[vson[target]].c);
    }
}

#undef mxa
#undef mna
#undef suma
#undef sza

namespace path {
    void add(int x, int y, T value) {
        AAA::add_chain(AAA::chain(x, y), value);
    }

    void set(int x, int y, T value) {
        AAA::set_chain(AAA::chain(x, y), value);
    }

    int size(int x, int y) {
        return AAA::sz[AAA::chain(x, y)].c;
    }

    T min(int x, int y) {
        return AAA::mn[AAA::chain(x, y)].c;
    }

    T max(int x, int y) {
        return AAA::mx[AAA::chain(x, y)].c;
    }

    T sum(int x, int y) {
        return AAA::sum[AAA::chain(x, y)].c;
    }
}

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m; cin >> n >> m;

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        init::add_edge(u, v);
    }

    for(int i = 1; i <= n; i++)
        cin >> init::val(i);

    int r; cin >> r;
    init::init(n, r);

    while(m--) {
        int q, x, y, z;
        cin >> q;
        if(q ==  0) cin >> x >> y,         subtree::set(x, y);
        if(q ==  1) cin >> r,              AAA::reroot(r);
        if(q ==  2) cin >> x >> y >> z,    path::set(x, y, z);
        if(q ==  3) cin >> x,      cout << subtree::min(x) << '\n';
        if(q ==  4) cin >> x,      cout << subtree::max(x) << '\n';
        if(q ==  5) cin >> x >> y,         subtree::add(x, y);
        if(q ==  6) cin >> x >> y >> z,    path::add(x, y, z);
        if(q ==  7) cin >> x >> y, cout << path::min(x, y) << '\n';
        if(q ==  8) cin >> x >> y, cout << path::max(x, y) << '\n';
        if(q == 10) cin >> x >> y, cout << path::sum(x, y) << '\n';
        if(q == 11) cin >> x,      cout << subtree::sum(x) << '\n';
        if(q ==  9) {
            cin >> x >> y;
            if(!AAA::is_child(x, y)) {
                AAA::cut(x);
                AAA::link(y, x);
            }
        }
    }
}
