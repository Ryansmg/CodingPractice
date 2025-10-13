// Update : 2025-10-13

#include <vector>
using std::vector, std::swap;

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
        inline bool isRoot() const { return !p || (this != p->l && this != p->r); }
        inline bool isLChild() const { return p && this == p->l; }
        inline bool isRChild() const { return p && this == p->r; }
        inline void push() {
            if(flip) {
                swap(l, r);
                if(l) l->flip ^= 1;
                if(r) r->flip ^= 1;
                flip = false;
            }
            for(auto f : lct->pushFunctions) f(this);
        }
        inline T& operator*() { return val; }
        inline const T& operator*() const { return val; }
        inline void upd() {
            if(l) l->push();
            if(r) r->push();
            sz = 1 + (l ? l->sz : 0) + (r ? r->sz : 0);
            for(auto f : lct->updFunctions) f(this);
        }
        inline void rotate() {
            if(isLChild()) {
                if(r) r->p = p;
                p->l = r; r = p;
            } else {
                if(l) l->p = p;
                p->r = l; l = p;
            }
            if (!p->isRoot()) (p->isLChild() ? p->p->l : p->p->r) = this;
            auto t = p; p = t->p; t->p = this;
            t->upd(); upd();
        }
    };
private:
    vector<void(*)(Node*)> updFunctions;
    vector<void(*)(Node*)> pushFunctions;
    int sz = 0;

public:
    LinkCutTree() = default;
    explicit LinkCutTree(void(*updateFunc)(Node*), void(*pushFunc)(Node*) = nullptr) {
        updFunctions.push_back(updateFunc);
        if(pushFunc) pushFunctions.push_back(pushFunc);
    }

    void addUpdFun(void (*updateFunc)(Node*)) { updFunctions.push_back(updateFunc); }
    void addPushFun(void (*pushFunc)(Node*)) { pushFunctions.push_back(pushFunc); }

    static void splay(Node* x) {
        for (; !x->isRoot(); x->rotate()) {
            if (!x->p->isRoot()) x->p->p->push();
            x->p->push(); x->push();
            if (x->p->isRoot()) continue;
            if (x->isLChild() == x->p->isLChild()) x->p->rotate();
            else x->rotate();
        }
        x->push(); x->upd();
    }

    /**
     * generates a new node that contains the value `val`.
     * storing and freeing the pointer should be done by the user.
     */
    Node* gen(const T& val) {
        sz++;
        Node* t = new Node(this);
        t->val = val;
        return t;
    }

    /**
     * generates a new node that contains the value `T(args...)`.
     * storing and freeing the pointer should be done by the user.
     */
    template <typename... Args>
    Node* gen(const Args&... args) {
        sz++;
        Node* t = new Node(this);
        t->val = T(args...);
        return t;
    }

    /// makes chain x the root of lct
    void access(Node* x) {
        splay(x); x->r = 0; x->upd();
        for (; x->p; splay(x)) {
            splay(x->p); x->p->r = x; x->p->upd();
        }
    }

    inline void link(Node* parent, Node* child) {
        setRoot(child);
        access(child); access(parent);
        child->l = parent; parent->p = child;
        child->upd();
    }

    /// cut x and x->p (at lct)
    inline void cut(Node* x) {
        access(x);
        x->l->p = nullptr;
        x->l = nullptr;
        x->upd();
    }

    /// a - b 간선이 있어야 함
    inline void cutEdge(Node* a, Node* b) {
        if(par(a) == b) cut(a);
        else assert(par(b) == a), cut(b);
    }

    inline bool hasEdge(Node* a, Node* b) {
        return par(a) == b || par(b) == a;
    }

    inline bool connected(Node* u, Node* v) {
        return root(u) == root(v);
    }

    inline Node* root(Node* x) {
        access(x); while(x->l) x = x->l, x->push();
        splay(x); return x;
    }

    /// 트리에서의 부모
    Node* par(Node* x) {
        access(x);
        if(!x->l) return nullptr;
        x = x->l; x->push();
        while(x->r) x = x->r, x->push();
        splay(x); return x;
    }

    inline Node* lca(Node* x, Node* y) {
        access(x); access(y); splay(x);
        return x->p ? x->p : x;
    }

    /// 트리에서의 부모까지 거리
    inline int depth(Node* x) {
        access(x); return x->l ? x->l->sz : 0;
    }

    /// @param x target node
    /// @param f must be `void f(Node*)`
    template <typename Callable>
    void update(Node* x, const Callable& f) {
        splay(x); f(x); splay(x); x->push(); x->upd();
    }

    inline void setRoot(Node* x) {
        access(x); splay(x); x->flip ^= 1;
    }

    /// f는 x~y 경로를 나타내는 서브트리의 루트를 인자로 받아야 함.
    /// 쿼리 / 업데이트 모두 가능
    template <typename Callable>
    void path(Node* x, Node* y, const Callable& f) {
        Node* rt = root(x);
        setRoot(x); access(y);
        splay(x);
        f(x); x->push(); x->upd();
        setRoot(rt);
    }
};

#include <iostream>
using std::ios_base, std::cin, std::cout;

// BOJ 13539. 트리와 쿼리 11
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    LinkCutTree<int> lct;
    vector<LinkCutTree<int>::Node*> a(n+1);
    for(int i = 1; i <= n; i++) a[i] = lct.gen(i);
    for(int i = 0; i < m; i++) {
        int op, u, v; cin >> op;
        if(op == 1) {
            cin >> u >> v;
            lct.link(a[v], a[u]);
        }
        if(op == 2) {
            cin >> v;
            lct.cut(a[v]);
        }
        if(op == 3) {
            cin >> u >> v;
            cout << **lct.lca(a[u], a[v]) << '\n';
        }
    }
}
