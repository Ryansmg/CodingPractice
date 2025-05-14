// 최신 버전은 cmm.cpp 참고

#include <vector>
#include <cassert>
#include <cmath>
using std::max, std::swap, std::vector;

template <typename T> concept hasUpdFunc = requires(T& a, const T* l, const T* r) { a.update(l, r); };
template <typename T> concept hasPushFunc = requires(T& a, T* l, T* r) { a.push(l, r); };
template <typename T> concept hasFlip = requires(T a) { a.flip; };

/// can detect: void T.update(const T*, const T*)
///             void T.push(T*, T*)
///             bool T.flip
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
            for(auto f : sp->updFunctions) f(*this);
            cnt = 1 + (l ? l->cnt : 0) + (r ? r->cnt : 0);
        }
        inline void push() {
            if constexpr(hasPushFunc<T>) v.push(l ? &l->v : nullptr, r ? &r->v : nullptr);
            for(auto f : sp->pushFunctions) f(*this);
        }
    };
protected:
    vector<void(*)(Node&)> updFunctions;
    vector<void(*)(Node&)> pushFunctions;

    int sz = 0;
    int size() const { return sz; }
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
            pos = pos->l;
        } else {
            assert(pos->r == nullptr);
            pos->r = new Node(val, this);
            pos->r->p = pos;
            pos = pos->r;
        }
        splay(pos);
    }
    void insertPrev(Node* pos, const T& val) {
        pos->push();
        if(pos->l) {
            pos = pos->l, pos->push();
            while(pos->r) pos = pos->r, pos->push();
            insert(pos, false, val);
        } else insert(pos, true, val);
    }
    void insertNext(Node* pos, const T& val) {
        pos->push();
        if(pos->r) {
            pos = pos->r, pos->push();
            while(pos->l) pos = pos->l, pos->push();
            insert(pos, true, val);
        } else insert(pos, false, val);
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
    explicit Splay(int length, void (*updateFunc)(Node&) = nullptr, void (*pushFunc)(Node&) = nullptr) : sz(length) {
        if(updateFunc) updFunctions.push_back(updateFunc);
        if(pushFunc) pushFunctions.push_back(pushFunc);
        if(!length) return;
        Node* x = tree = new Node(this);
        for(long long i = 1; i < length; i++) {
            x->r = new Node(this);
            x->r->p = x;
            x = x->r;
        }
        while(x) x->upd(), x = x->p;
    }
    explicit Splay(const std::vector<T>& arr, void (*updateFunc)(Node&) = nullptr, void (*pushFunc)(Node&) = nullptr) {
        long long length = static_cast<long long>(arr.size());
        sz = length;
        if(updateFunc) updFunctions.push_back(updateFunc);
        if(pushFunc) pushFunctions.push_back(pushFunc);
        if(!length) return;
        Node* x = tree = new Node(arr[0], this);
        for(long long i = 1; i < length; i++) {
            x->r = new Node(arr[i], this);
            x->r->p = x;
            x = x->r;
        }
        while(x) x->upd(), x = x->p;
    }

    void addUpdFun(void (*updateFunc)(Node&)) { updFunctions.push_back(updateFunc); }
    void addPushFun(void (*pushFunc)(Node&)) { pushFunctions.push_back(pushFunc); }

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
    inline T operator[](int k) { return kth(k)->v; }

    // 0-based index, s > 0, e < sz - 1
    Node* gather(int s, int e) {
        kth(e + 1);
        auto tmp = tree;
        kth(s - 1);
        splay(tmp, tree);
        return tree->r->l;
    }

    // 0-based index
    void set(int k, const T& val) {
        kth(k);
        tree->v = val;
    }

    void set(Node* x, const T& val) {
        x->v = val;
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

    static void push_flip(Splay<T>::Node& a) requires hasFlip<T> {
        if(!a.v.flip) return;
        swap(a.l, a.r);
        if(a.l) a.l->v.flip ^= 1;
        if(a.r) a.r->v.flip ^= 1;
        a.v.flip = false;
    }

    /// 1 <= l <= r <= size - 2
    void flip(int l, int r) requires hasFlip<T> {
        auto x = gather(l, r);
        T t = x->v; t.flip = true;
        set(x, t);
    }

    /// 1 <= s <= e <= size - 2
    void shift(int s, int e, int k) requires hasFlip<T> {
        if(k >= 0) {
            k %= e - s + 1; if(!k) return;
            flip(s, e); flip(s, s+k-1); flip(s+k, e);
        } else {
            k *= -1; k %= e - s + 1; if(!k) return;
            flip(s, e); flip(s, e-k); flip(e-k+1, e);
        }
    }
};

struct GoldMine {
    long long v = 0, mx = 0, l = 0, r = 0, s = 0;
    bool flip = false;
    void merge(const GoldMine& b) {
        mx = max(max(mx, b.mx), r + b.l);
        l = max(l, s + b.l);
        r = max(b.r, r + b.s);
        s += b.s;
    }
};

void update(Splay<GoldMine>::Node& a) {
    a.v.mx = a.v.l = a.v.r = max(0LL, a.v.v);
    a.v.s = a.v.v;
    if(a.l) {
        GoldMine t = a.l->v;
        t.merge(a.v);
        long long v = a.v.v;
        a.v = t; a.v.v = v;
    }
    if(a.r) a.v.merge(a.r->v);
}


// BOJ 17607. 수열과 쿼리 31
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<GoldMine> arr(n + 2);
    for(int i = 1; i <= n; i++) {
        int t; cin >> t;
        if(t) arr[i] = {1, 1, 1, 1, 1};
        else arr[i] = {-15571557, -15571557, -15571557, -15571557, -15571557};
    }
    Splay<GoldMine> splay(arr, update, Splay<GoldMine>::push_flip);

    int m; cin >> m;
    while(m--) {
        long long op, a, b; cin >> op >> a >> b;
        if(op == 1) splay.flip(a, b);
        else cout << splay(a, b).mx << '\n';
    }
}
