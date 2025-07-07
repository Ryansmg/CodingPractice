// Update : 2025-05-19

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class LinkCutTree {
public:
    struct Node {
        Node *l = nullptr, *r = nullptr, *p = nullptr;
        int sz = 1; bool flip = false;
        LinkCutTree *lct;
        T val = T();
        explicit Node(LinkCutTree* ptr) : lct(ptr) {}
        /// @returns whether this is the root of the splay tree
        bool isRoot() const { return !p || (this != p->l && this != p->r); }
        bool isLChild() const { return p && this == p->l; }
        bool isRChild() const { return p && this == p->r; }
        void push() {
            for(auto f : lct->pushFunctions) f(this);
            if(flip) {
                swap(l, r);
                if(l) l->flip ^= 1;
                if(r) r->flip ^= 1;
                flip = false;
            }
        }
        T& operator*() { return val; }
        const T& operator*() const { return val; }
        void upd() {
            if(l) l->push();
            if(r) r->push();
            sz = 1 + (l ? l->sz : 0) + (r ? r->sz : 0);
            for(auto f : lct->updFunctions) f(this);
        }
    };
private:
    vector<void(*)(Node*)> updFunctions;
    vector<void(*)(Node*)> pushFunctions;
    int sz = 0;

    void rotate(Node *x) {
        if(x->p->p) x->p->p->push(), x->p->p->upd();
        x->p->push(), x->p->upd(); x->push(); x->upd();
        if(x->isLChild()) {
            if(x->r) x->r->p = x->p;
            x->p->l = x->r; x->r = x->p;
        } else {
            if(x->l) x->l->p = x->p;
            x->p->r = x->l; x->l = x->p;
        }
        if(!x->p->isRoot()) (x->p->isLChild() ? x->p->p->l : x->p->p->r) = x;
        auto t = x->p; x->p = t->p; t->p = x;
        t->upd(); x->upd();
    }
public:
    LinkCutTree() = default;
    explicit LinkCutTree(void(*updateFunc)(Node*), void(*pushFunc)(Node*) = nullptr) {
        updFunctions.push_back(updateFunc);
        if(pushFunc) pushFunctions.push_back(pushFunc);
    }

    void addUpdFun(void (*updateFunc)(Node*)) { updFunctions.push_back(updateFunc); }
    void addPushFun(void (*pushFunc)(Node*)) { pushFunctions.push_back(pushFunc); }

    void splay(Node* x) {
        while(!x->isRoot()) {
            Node *p = x->p, *pp = p->p;
            if(!x->p->isRoot()) x->p->p->push(), x->p->p->upd();
            p->push(); x->push(); p->upd(); x->upd();
            if(p->isRoot()) { rotate(x); break; }
            rotate((x == p->l) == (p == pp->l) ? p : x);
            rotate(x);
        }
        x->push(); x->upd();
    }

    Node* gen(const T& val) {
        sz++;
        Node* t = new Node(this);
        t->val = val;
        return t;
    }

    template <typename... Args>
    Node* gen(const Args&... args) {
        sz++;
        Node* t = new Node(this);
        t->val = T(args...);
        return t;
    }

    /// makes chain x the root of lct
    void access(Node* x) {
        splay(x); x->r = nullptr; x->upd();
        while(x->p) splay(x->p), x->p->r = x, splay(x);
    }

    void link(Node* parent, Node* child) {
        setRoot(child);
        access(child); access(parent);
        child->l = parent; parent->p = child;
        splay(parent);
    }

    /// cut x and x->p (at lct)
    void cut(Node* x) {
        access(x);
        x->l->p = nullptr;
        x->l = nullptr;
        x->upd();
    }

    // a - b 간선이 있어야 함
    void cutEdge(Node* a, Node* b) {
        if(par(a) == b) cut(a);
        else assert(par(b) == a), cut(b);
    }

    Node* root(Node* x) {
        access(x); x->push();
        while(x->l) x = x->l, x->push();
        splay(x); return x;
    }

    /// 트리에서의 부모
    Node* par(Node* x) {
        access(x); x->push();
        if(!x->l) return nullptr;
        x = x->l, x->push(); while(x->r) x = x->r, x->push();
        splay(x); return x;
    }

    Node* lca(Node* x, Node* y) {
        access(x); access(y); splay(x);
        return x->p ? x->p : x;
    }

    /// 트리에서의 부모까지 거리
    int depth(Node* x) {
        access(x); return x->l ? x->l.push(), x->l->sz : 0;
    }

    /// @param x must be `void f(Node*)`
    template <typename Callable>
    void update(Node* x, const Callable& f) {
        splay(x); f(x); splay(x); x->push(); x->upd();
    }

    void setRoot(Node* x) {
        access(x); splay(x); x->flip ^= 1;
    }

    /// f는 x~y 경로를 나타내는 서브트리의 루트를 인자로 받아야 함.
    /// 쿼리 / 업데이트 모두 가능
    template <typename Callable>
    void path(Node* x, Node* y, const Callable& f) {
        Node* rt = root(x);
        setRoot(x); access(y); splay(x);
        f(x); splay(x);
        setRoot(rt);
    }
};

struct T;
using LCT = LinkCutTree<T>;
using Nd = LCT::Node*;
using i64 = long long;

struct T {
    Nd l = nullptr, r = nullptr;
    i64 c = -1, cmx = -1; Nd mx = nullptr;
    int id = -1;
};

void upd(Nd t) {
    t->val.cmx = t->val.c, t->val.mx = t;
    if(t->l && t->l->val.cmx > t->val.cmx) t->val.cmx = t->l->val.cmx, t->val.mx = t->l->val.mx;
    if(t->r && t->r->val.cmx > t->val.cmx) t->val.cmx = t->r->val.cmx, t->val.mx = t->r->val.mx;
}


#define forf(i, a, b) for(i64 i = a; i <= b; i++)
#define forn(i, n) for(i64 i = 0; i < n; i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        LCT lct(upd);
        int n, m; cin >> n >> m;
        vector<Nd> nds(n), ends;
        i64 cans = 0, ans = 0;
        forn(i, n) nds[i] = lct.gen(), nds[i]->val.mx = nds[i], nds[i]->val.id = i;
        forn(i, n - 1) {
            i64 a = i + 1, b, c; cin >> b >> c;
            cans += c;
            Nd x = lct.gen({nds[a], nds[b], c, c});
            ends.push_back(x);
            x->val.mx = x;
            lct.link(x, nds[a]);
            lct.link(x, nds[b]);
        }
        forn(j, m) {
            i64 u, v, c; cin >> u >> v >> c;
            if(u == v) {
                ans ^= cans; continue;
            }
            T pathv;
            lct.path(nds[u], nds[v], [&](Nd x) {
                pathv = x->val;
            });
            if(pathv.cmx > c) {
                cans += c - pathv.cmx;
                lct.cutEdge(pathv.mx, pathv.mx->val.l);
                lct.cutEdge(pathv.mx, pathv.mx->val.r);
                pathv.mx->val.c = pathv.mx->val.cmx = c;
                pathv.mx->val.mx = pathv.mx;
                lct.link(pathv.mx, nds[u]);
                lct.link(pathv.mx, nds[v]);
                pathv.mx->val.l = nds[u];
                pathv.mx->val.r = nds[v];
            }
            ans ^= cans;
        }
        cout << ans << '\n';
        for(auto x : nds) delete x;
        for(auto x : ends) delete x;
    }
}
