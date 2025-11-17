// Update : 2025-11-04

#include <vector>
#include <cassert>
using std::vector, std::swap;
using ptr = signed;
constexpr ptr null = 0;

struct T {
    ptr p = null;
    long long val = 0, sum = 0;
};

struct Node {
    ptr l = null, r = null, p = null;
    signed sz = 1; bool flip = false;
    T val = T();
};

Node M[222222];

inline void reserve(int size) {
    assert(std::size(M) >= (unsigned) size);
}

inline bool isRoot(ptr nd) {
    return !M[nd].p || (nd != M[M[nd].p].l && nd != M[M[nd].p].r);
}

inline bool isLChild(ptr nd) {
    return M[nd].p && nd == M[M[nd].p].l;
}

inline bool isRChild(ptr nd) {
    return M[nd].p && nd == M[M[nd].p].r;
}

inline void push(ptr nd) {
    if(M[nd].flip) {
        swap(M[nd].l, M[nd].r);
        if(M[nd].l) M[M[nd].l].flip ^= 1;
        if(M[nd].r) M[M[nd].r].flip ^= 1;
        M[nd].flip = false;
    }

    // implement here
}

inline void pull(ptr nd) {
    if(M[nd].l) push(M[nd].l);
    if(M[nd].r) push(M[nd].r);
    M[nd].sz = 1 + (M[nd].l ? M[M[nd].l].sz : 0) + (M[nd].r ? M[M[nd].r].sz : 0);

    // implement here
    M[nd].val.sum = M[nd].val.val;
    if(M[nd].l) M[nd].val.sum += M[M[nd].l].val.sum;
    if(M[nd].r) M[nd].val.sum += M[M[nd].r].val.sum;
}

inline void rotate(ptr nd) {
    if(isLChild(nd)) {
        if(M[nd].r) M[M[nd].r].p = M[nd].p;
        M[M[nd].p].l = M[nd].r; M[nd].r = M[nd].p;
    } else {
        if(M[nd].l) M[M[nd].l].p = M[nd].p;
        M[M[nd].p].r = M[nd].l; M[nd].l = M[nd].p;
    }
    if(!isRoot(M[nd].p)) (isLChild(M[nd].p) ? M[M[M[nd].p].p].l : M[M[M[nd].p].p].r) = nd;
    ptr t = M[nd].p; M[nd].p = M[t].p; M[t].p = nd;
    pull(t); pull(nd);
}

signed sz = 0;

void splay(ptr x) {
    for(; !isRoot(x); rotate(x)) {
        if(!isRoot(M[x].p)) push(M[M[x].p].p);
        push(M[x].p); push(x);
        if(isRoot(M[x].p)) continue;
        if(isLChild(x) == isLChild(M[x].p)) rotate(M[x].p);
        else rotate(x);
    }
    push(x); pull(x);
}


ptr gen(const T& val) {
    ptr alloc = ++sz;
    M[alloc] = Node();
    M[alloc].val = val;
    return alloc;
}

template <typename... Args>
ptr gen(const Args&... args) {
    ptr alloc = ++sz;
    M[alloc] = Node();
    M[alloc].val = T(args...);
    return alloc;
}


void access(ptr x) {
    splay(x); M[x].r = null; pull(x);
    for(; M[x].p; splay(x)) {
        splay(M[x].p); M[M[x].p].r = x; pull(M[x].p);
    }
}

inline void setRoot(ptr x) {
    access(x); splay(x); M[x].flip ^= 1;
}

// child가 root일 때만 사용해야 함.
inline void link_(ptr parent, ptr child) {
    access(child); access(parent);
    M[child].l = parent; M[parent].p = child;
    pull(child);
}

inline void cut(ptr x) {
    access(x);
    M[M[x].l].p = null;
    M[x].l = null;
    pull(x);
}

inline ptr root(ptr x) {
    access(x); while(M[x].l) x = M[x].l, push(x);
    splay(x); return x;
}

inline bool connected(ptr u, ptr v) {
    return root(u) == root(v);
}

inline ptr lca(ptr x, ptr y) {
    access(x); access(y); splay(x);
    return M[x].p ? M[x].p : x;
}

/// @param x target node
/// @param f must be `void f(Node*)`
template <typename Callable>
void update(ptr x, const Callable& f) {
    splay(x); f(x); push(x); pull(x);
}

/// f는 x~y 경로를 나타내는 서브트리의 루트를 인자로 받아야 함.
/// 쿼리 / 업데이트 모두 가능
template <typename Callable>
void path(ptr x, ptr y, const Callable& f) {
    ptr rt = root(x);
    setRoot(x); access(y);
    splay(x);
    f(x); push(x); pull(x);
    setRoot(rt);
}

#include <iostream>
#include <set>
#include <map>
using namespace std;
using std::ios, std::cin, std::cout;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) gen();

    for(int i = 1; i <= n; i++) {
        int t; cin >> t;
        if(connected(t, i)) M[i].val.p = t;
        else link_(t, i);
    }

    for(int i = 1; i <= n; i++) {
        long long t; cin >> t;
        update(i, [&](ptr nd) { M[nd].val.val = t; });
    }

    while(q--) {
        long long t, i, j, x;
        cin >> t;
        if(t == 1) {
            cin >> i >> j;
            ptr rt = root(i);
            ptr lf = M[rt].val.p;
            ptr nx = lca(i, lf);
            if(nx == i) {
                M[rt].val.p = null;
                if(rt != lf && rt != nx) {
                    cut(nx);
                    assert(!connected(lf, rt));
                    link_(lf, rt);
                }
            } else cut(i);

            if(connected(i, j)) {
                M[i].val.p = j;
            } else link_(j, i);
        } else if(t == 2) {
            cin >> i >> x;
            update(i, [&](ptr nd) { M[nd].val.val = x; });
        } else {
            cin >> x;
            ptr rt = root(x);
            ptr lf = M[rt].val.p;
            ptr nx = lca(x, lf);
            long long ans = -M[nx].val.val;
            path(rt, x, [&](ptr nd) { ans += M[nd].val.sum; });
            path(nx, lf, [&](ptr nd) { ans += M[nd].val.sum; });
            cout << ans << '\n';
        }
    }
}
