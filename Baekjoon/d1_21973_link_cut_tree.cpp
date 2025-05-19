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
        splay(x); x->r = nullptr;
        while(x->p) splay(x->p), x->p->r = x, splay(x);
    }

    void link(Node* parent, Node* child) {
        setRoot(child);
        access(child); access(parent);
        child->l = parent; parent->p = child;
    }

    /// cut x and x->p (at lct)
    void cut(Node* x) {
        access(x);
        x->l->p = nullptr;
        x->l = nullptr;
    }

    Node* getRoot(Node* x) {
        access(x); while(x->l) x = x->l;
        splay(x); return x;
    }

    /// 트리에서의 부모
    Node* getPar(Node* x) {
        access(x);
        if(!x->l) return nullptr;
        x = x->l; while(x->r) x = x->r;
        splay(x); return x;
    }

    Node* lca(Node* x, Node* y) {
        access(x); access(y); splay(x);
        return x->p ? x->p : x;
    }

    /// 트리에서의 부모까지 거리
    int getDepth(Node* x) {
        access(x); return x->l ? x->l->sz : 0;
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
        Node* root = getRoot(x);
        setRoot(x); access(y); splay(x);
        f(x); splay(x); x->push(); x->upd();
        setRoot(root);
    }
};

struct T {
    long long val, sum;
};
using LCT = LinkCutTree<T>;
using Nd = LCT::Node*;

void update(Nd a) {
    a->val.sum = a->val.val + (a->l ? a->l->val.sum : 0) + (a->r ? a->r->val.sum : 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, q, x, a, b; cin >> n;
    string s;
    LCT lct(update);
    vector<Nd> r(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> x;
        r[i] = lct.gen(x, x);
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> s >> a >> b;
        if(s == "bridge") {
            if(lct.getRoot(r[a]) == lct.getRoot(r[b]))
                cout << "no" << endl;
            else {
                cout << "yes" << endl;
                lct.link(r[a], r[b]);
            }
        }
        if(s == "penguins") {
            lct.update(r[a], [&](Nd k) {
                k->val.val = b;
            });
        }
        if(s == "excursion") {
            if(lct.getRoot(r[a]) != lct.getRoot(r[b])) cout << "impossible" << endl;
            else lct.path(r[a], r[b], [](Nd k) {
                cout << k->val.sum << endl;
            });
        }
    }
}
