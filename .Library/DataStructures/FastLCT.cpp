// Update : 2025-11-04
// 그리 빠르진 않음

#include <vector>
#include <cassert>
using std::vector, std::swap;
using ptr = signed;
constexpr ptr null = 0;

struct T {
    ptr l = null, r = null;
    long long val = 155715571557, edgeIdx = -1;
    long long mn = 155715571557, mnEdgeIdx = -1;
};

struct Node {
    ptr l = null, r = null, p = null;
    signed sz = 1; bool flip = false;
    T val = T();
};

Node M[666666];

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
    M[nd].val.mn = M[nd].val.val; M[nd].val.mnEdgeIdx = M[nd].val.edgeIdx;
    if(M[nd].l && M[M[nd].l].val.mn < M[nd].val.mn)
        M[nd].val.mn = M[M[nd].l].val.mn, M[nd].val.mnEdgeIdx = M[M[nd].l].val.mnEdgeIdx;
    if(M[nd].r && M[M[nd].r].val.mn < M[nd].val.mn)
        M[nd].val.mn = M[M[nd].r].val.mn, M[nd].val.mnEdgeIdx = M[M[nd].r].val.mnEdgeIdx;
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

inline void link(ptr parent, ptr child) {
    setRoot(child);
    link_(parent, child);
}

inline void cut(ptr x) {
    access(x);
    M[M[x].l].p = null;
    M[x].l = null;
    pull(x);
}

ptr par(ptr x) {
    access(x);
    if(!M[x].l) return null;
    x = M[x].l; push(x);
    while(M[x].r) x = M[x].r, push(x);
    splay(x); return x;
}

inline void cutEdge(ptr a, ptr b) {
    if(par(a) == b) cut(a);
    else assert(par(b) == a), cut(b);
}

inline bool hasEdge(ptr a, ptr b) {
    return par(a) == b || par(b) == a;
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

inline int depth(ptr x) {
    access(x); return M[x].l ? M[M[x].l].sz : 0;
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
    vector<ptr> nodes(n+1), edges(n-1);
    set<int> free;
    set<pair<long long, int>> used;
    for(int i = 1; i <= n; i++) nodes[i] = gen();
    for(int i = 0; i < n - 1; i++) {
        edges[i] = gen();
        M[edges[i]].val.edgeIdx = M[edges[i]].val.mnEdgeIdx = i;
        free.insert(i);
    }
    reserve(n + n - 1);
    while(q--) {
        long long t, i, j, d, x;
        cin >> t;
        if(t == 1) {
            cin >> i >> j >> d;
            bool ok = !connected(nodes[i], nodes[j]);
            if(!ok) {
                T res;
                path(nodes[i], nodes[j], [&](const ptr nd) {
                    res = M[nd].val;
                });
                if(res.mn < d) {
                    int dealloc = res.mnEdgeIdx;
                    ptr tarEdge = edges[dealloc];
                    cutEdge(tarEdge, M[tarEdge].val.l);
                    cutEdge(tarEdge, M[tarEdge].val.r);
                    used.erase(used.find({M[tarEdge].val.val, M[tarEdge].val.edgeIdx}));
                    free.insert(dealloc);
                    ok = true;
                }
            }

            if(ok) {
                int alloc = *free.begin(); free.erase(alloc);
                M[edges[alloc]].val.val = d;
                M[edges[alloc]].val.l = nodes[i];
                M[edges[alloc]].val.r = nodes[j];
                link(edges[alloc], nodes[i]);
                link(edges[alloc], nodes[j]);
                used.insert({d, alloc});
            }

        }
        else if(t == 2) {
            cin >> x;
            while(!used.empty() && used.begin()->first < x) {
                int dealloc = used.begin()->second;
                ptr tarEdge = edges[dealloc];
                cutEdge(tarEdge, M[tarEdge].val.l);
                cutEdge(tarEdge, M[tarEdge].val.r);
                used.erase(used.begin());
                free.insert(dealloc);
            }
        }
        else {
            cin >> i >> j;
            if(connected(nodes[i], nodes[j])) {
                path(nodes[i], nodes[j], [](const ptr nd) {
                    cout << M[nd].val.mn << '\n';
                });
            } else {
                cout << "0\n";
            }
        }
    }
}
