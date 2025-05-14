#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;

template <typename T> concept hasUpdFunc = requires(T& a, const T* l, const T* r) { a.update(l, r); };
template <typename T> concept hasPushFunc = requires(T& a, T* l, T* r) { a.push(l, r); };

/// can detect: void T.update(const T*, const T*)
/// and: void T.push(T*, T*)
/// 추가 기능을 구현하려면 내려갈 때 push 함수를 잘 호출해줘야 함
/// 0-based index
template <typename T> class Splay {
public:
    struct Node {
        Node *l = nullptr, *r = nullptr, *p = nullptr;
        T v = T(); int cnt = 1;
        Splay* sp = nullptr;
        ~Node() { delete l; delete r; }
        Node(const T& value, Splay* splay) : v(value), sp(splay) {}
        explicit Node(Splay* splay) : sp(splay) {}
        friend Splay;
        template <typename Callable> inline void forEach(const Callable& f) { Splay<T>::forEach(this, f); }
        template <typename Callable> inline void preorder(const Callable& f) { Splay<T>::preorder(this, f); }

        inline void upd() {
            if(l) l->push();
            if(r) r->push();
            if constexpr (hasUpdFunc<T>) v.update(l ? &l->v : nullptr, r ? &r->v : nullptr);
            if(sp->updFun) sp->updFun(*this);
            cnt = 1 + (l ? l->cnt : 0) + (r ? r->cnt : 0);
        }
        inline void push() {
            if constexpr(hasPushFunc<T>) v.push(l ? &l->v : nullptr, r ? &r->v : nullptr);
            if(sp->pushFun) sp->pushFun(*this);
        }
    };
protected:
    void (*updFun)(Node&) = nullptr;
    void (*pushFun)(Node&) = nullptr;

    int sz = 0;
    Node* tree = nullptr;
    void rotate(Node *x) {
        Node *p = x->p, *b;
        if(!p) return;
        p->push(); x->push();
        if(x == p->l) p->l = b = x->r, x->r = p;
        else p->r = b = x->l, x->l = p;
        x->p = p->p; p->p = x;
        if(b) b->p = p;
        (x->p ? p == x->p->l ? x->p->l : x->p->r : tree) = x;
        p->upd(); x->upd();
    }
public:
    void splay(Node* x, Node* g = nullptr) {
        while(x->p != g) {
            Node *p = x->p, *pp = p->p;
            if(pp == g) { rotate(x); break; }
            rotate((x == p->l) == (p == pp->l) ? p : x);
            rotate(x);
        }
    }
    void insert(Node* pos, bool left, const T& val) {
        sz++;
        if(left) {
            assert(pos->l == nullptr);
            pos->l = new Node(val, this);
            pos->l->p = pos;
        } else {
            assert(pos->r == nullptr);
            pos->r = new Node(val, this);
            pos->r->p = pos;
        }
        splay(pos);
    }
    void erase(Node* p) {
        sz--;
        splay(p);
        if(p->l) {
            if(p->r) {
                tree = p->l;
                tree->p = nullptr;
                Node* x = tree;
                while(x->r) x = x->r;
                x->r = p->r;
                p->r->p = x;
                splay(x);
                p->l = p->r = nullptr;
                delete p; return;
            }
            tree = p->l;
            tree->p = nullptr;
            p->l = p->r = nullptr;
            delete p; return;
        }
        if(p->r) {
            tree = p->r;
            tree->p = nullptr;
            p->l = p->r = nullptr;
            delete p; return;
        }
        delete p;
        tree = nullptr;
    }
    ~Splay() { delete tree; }
    Splay() = default;
    explicit Splay(int length, void (*updateFunc)(Node&) = nullptr, void (*pushFunc)(Node&) = nullptr) : sz(length), updFun(updateFunc), pushFun(pushFunc) {
        if(!length) return;
        Node* x = tree = new Node(this);
        for(long long i = 1; i < length; i++) {
            x->r = new Node(this);
            x->r->p = x;
            x = x->r;
        }
        while(x) x->upd(), x = x->p;
    }
    explicit Splay(const std::vector<T>& arr, void (*updateFunc)(Node&) = nullptr, void (*pushFunc)(Node&) = nullptr) : updFun(updateFunc), pushFun(pushFunc){
        long long length = static_cast<long long>(arr.size());
        sz = length;
        if(!length) return;
        Node* x = tree = new Node(arr[0], this);
        for(long long i = 1; i < length; i++) {
            x->r = new Node(arr[i], this);
            x->r->p = x;
            x = x->r;
        }
        while(x) x->upd(), x = x->p;
    }

    void setUpdFun(void (*updateFunc)(Node&)) { updFun = updateFunc; }
    void setPushFun(void (*pushFunc)(Node&)) { pushFun = pushFunc; }

    const Node* root() const { return tree; }
    Node* root() { return tree; }

    // k >= 0
    Node* kth(int k) {
        assert(0 <= k && k < sz);
        auto x = tree;
        x->push();
        while(true) {
            while(x->l && x->l->cnt > k) x = x->l, x->push();
            if(x->l) k -= x->l->cnt;
            if(!k--) break;
            x = x->r; x->push();
        }
        splay(x);
        return x;
    }

    // k >= 0
    inline T operator[](int k) { return *kth(k); }

    // 0-based index, s > 0, e < sz - 1
    Node* gather(int s, int e) {
        kth(e + 1);
        auto tmp = tree;
        kth(s - 1);
        splay(tmp, tree);
        tree->push(); tree->r->push(); tree->r->l->push();
        return tree->r->l;
    }

    // 0-based index
    void set(int k, const T& val) {
        kth(k);
        tree->v = val;
        tree->push();
        tree->upd();
    }

    void set(Node* x, const T& val) {
        x->v = val;
        x->push();
        x->upd();
        splay(x);
    }

    inline T operator()(int s, int e) { return gather(s, e)->v; }

    template <typename Callable>
    static void forEach(Node* i, const Callable& t) {
        i->push();
        if(i->l) forEach(i->l, t);
        t(*i);
        if(i->r) forEach(i->r, t);
    }

    template <typename Callable>
    inline void forEach(const Callable& f) { forEach(tree, f); }

    template <typename Callable>
    static void preorder(Node* i, const Callable& t) {
        i->push();
        t(*i);
        if(i->l) preorder(i->l, t);
        if(i->r) preorder(i->r, t);
    }

    template <typename Callable>
    inline void preorder(const Callable& f) { preorder(tree, f); }
};


struct T {
    int v = -1, mn = 0, sz = 0;
    bool flip = false;
};

void update(Splay<T>::Node& a) {
    a.v.mn = a.v.v;
    a.v.sz = a.v.v != -1;
    if(a.l) a.v.mn = min(a.v.mn, a.l->v.mn), a.v.sz += a.l->v.sz;
    if(a.r) a.v.mn = min(a.v.mn, a.r->v.mn), a.v.sz += a.r->v.sz;
}

void push(Splay<T>::Node& a) {
    if(!a.v.flip) return;
    swap(a.l, a.r);
    if(a.l) a.l->v.flip ^= 1;
    if(a.r) a.r->v.flip ^= 1;
    a.v.flip = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while(true) {
        int n; cin >> n;
        if(!n) break;
        vector<T> arr(n + 2); vector<int> in(n);
        for(int i = 1; i <= n; i++) cin >> in[i-1];
        vector<int> in2 = in;
        sort(in2.begin(), in2.end());
        for(int &i : in) i = lower_bound(in2.begin(), in2.end(), i) - in2.begin() + 1;
        map<int, int> m;
        for(int &i : in) {
            if(!m[i]) m[i] = i;
            else i = ++m[i];
        }

        for(int i = 0; i < n; i++) arr[i+1] = { in[i], in[i], 1 };

        Splay<T> splay(arr, update, push);

        for(int i = 1; i <= n; i++) {
            auto x = splay.gather(i, n);
            assert(x->v.mn == i);
            int idx = i;
            while(true) {
                x->push(); x->upd();
                if(x->v.v == i) {
                    idx += (x->l ? x->l->v.sz : 0);
                    break;
                }
                if(x->l && x->l->v.mn == i) x = x->l;
                else idx += (x->l ? x->l->v.sz : 0) + 1, x = x->r;
            }
            x = splay.gather(i, idx);
            splay.set(x, {x->v.v, x->v.mn, x->v.sz, true});
            cout << idx << " ";
        }
        cout << '\n';
    }
}
