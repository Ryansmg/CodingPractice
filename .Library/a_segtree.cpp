#pragma region macros
#define GCC_OPTIMIZE_ENABLE false

#include <bits/stdc++.h>
using namespace std;

#if GCC_OPTIMIZE_ENABLE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif

#define int long long
#define double long double
#define cint const int &

#define llmax 9223372036854775807 // 2^63-1
#define INF 1000000000000000000 // INF * INF > 2^63
#define inf 3000000000 // inf > 2^31, inf * inf < 2^63
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(name, val) for(int name = 0; name < val; name++)
#define forf(name, start, end) for(int name = start; name <= end; name++)

#define pass {cout << "";} // do nothing
#define filein freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/input.txt", "r", stdin)
#define fileout freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/output.txt", "w", stdout)

template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
template <typename T> using pq = priority_queue<T>;
using ii = array<int, 2>;
using iii = array<int, 3>;

#ifndef int
#define intmax 2147483647
#else
#define intmax llmax
#endif

#pragma region lint
#define lint __int128
#define ll long long
lint LINTMAX = ((lint(1)<<126)-1)*2+1;
string lint2str(const lint &i) {string ret,bs;if(i==-LINTMAX-1)return lint2str(i/10)+"8";if(!i)return "0";if(i<0)return "-"+lint2str(-i);
    lint t=1; forn(as, 18)t*=10;lint a=i/(t*t);if(a){ret += to_string((ll) a);bs = to_string((ll) (i / t % (t * 10) + t));
        forn(j, 18) ret += bs[j + 1];bs = to_string((ll) ((i % t) + t));forn(j, 18) ret += bs[j + 1];
    } else {lint b = i / t % (t * 10);if (b) {ret += to_string((ll) b);bs = to_string((ll) ((i % t) + t));
            forn(j, 18) ret += bs[j + 1];} else { ret += to_string((ll) (i % t)); }}return ret;}
istream &operator>>(istream &in, lint &l) {string s;in>>s;lint t=l=0,size=s.size(),k=1;if(s[0]=='-')t=1;
    for(lint i=size-1;i>=t;i--){if(!t)l+=(s[i]-'0')*k;else l-=(s[i]-'0')*k;k*=10;}return in;}
ostream &operator<<(ostream &out,const lint &i){ out << lint2str(i); return out; }
#pragma endregion

template <typename T = int> T input() {T t; cin >> t; return t;}

#define all(vec) (vec).begin(), (vec).end()
template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }

template <typename T> T pow_(T a, T b) { return pow_(a, b, intmax); }
template <typename T> T pow_(T a, T b, T mod) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }
#pragma endregion

class segtree {
#define MID ((start+end)/2)
public:
    class T {
    public:
        int val = 0;
        T()=default;
        explicit T(int v) : val(v) {}
        T operator+(const T &t2) const { return T(val + t2.val); }
        T operator+(const int &i) const { return T(val + i); }
        void operator+=(const T &i) { val += i.val; }
        void operator+=(const int &i) { val += i; }
        T& operator=(cint i) { val = i; return *this; }
        T& operator=(const T &i) = default;
    };
    vector<T> tree;
    int n;
    explicit segtree(int treeSize, bool inputInit = false) {
        n = treeSize;
        tree = v<T>(4*treeSize, T());
        if(inputInit) {
            v<int> a;
            forn(i, treeSize) a.push_back(input());
            init(a, 1, 1, n);
        }
    }
    explicit segtree(const v<int> &a) : segtree((int) a.size()) {
        init(a, 1, 1, n);
    }
    segtree(const v<int> &a, int treeSize) : segtree(treeSize) {
        init(a, 1, 1, n);
        assert(a.size() == treeSize);
    }
    void update(int tar, int diff) { update(tar, tar, diff); }
    T query_node(int tar) { return query(tar, tar); }
    int query(int tar) { return query(tar, tar).val; }
    T query(int left, int right) { return query(1, left, right, 1, n); }
protected:
    void update(int left, int right, int diff) { update(1, left, right, 1, n, diff); }
    T init(const v<int> &a, int node, int start, int end) {
        if (start == end) return tree[node] = a[start - 1];
        return tree[node] = init(a, node * 2, start, MID) +
        init(a, node * 2 + 1, MID + 1, end);
    }
    void update(int node, int left, int right, int start, int end, int diff) {
        if(end<left || right < start) return;
        if(left <= start && end <= right) { tree[node] += diff; return; }
        update(node*2, left, right, start, MID, diff);
        update(node*2+1, left, right, MID+1, end, diff);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    T query(int node, int left, int right, int start, int end) {
        if(right < start || end < left) return {};
        if(left <= start && end <= right) return tree[node];
        return query(node*2, left, right, start, MID) +
               query(node*2+1, left, right, MID+1, end);
    }
};

class iterSeg {
public:
    v<int> tree; int n;
    explicit iterSeg(const v<int> &arr) { n = (int) arr.size(); init(arr); }
    explicit iterSeg(cint i) { tree = v<int>(i*4, 0); n = i; }
    void inputInit() {
        tree = v<int>(4*n, 0);
        forf(i, n, 2*n-1) cin >> tree[i];
        init();
    }
    /// 0 <= tar < n
    void update(int tar, int val) {
        assert(0 <= tar && tar < n);
        tree[n+tar] = val;
        for(int i = n+tar; i>1; i>>=1)
            tree[i>>1] = tree[i] + tree[i^1];
    }
    /// [l, r)
    int query(int left, int right) {
        assert(0 <= left && right <= n);
        int l = n+left, r = n+right, ans = 0;
        for(; l<r; l>>=1, r>>=1) {
            if(l&1) ans += tree[l++];
            if(r&1) ans += tree[--r];
        }
        return ans;
    }
private:
    void init() { for(int i=n-1; i>0; i--) tree[i] = tree[i<<1] + tree[i<<1|1]; }
    void init(const v<int> &arr) {
        tree = v<int>(4*n, 0);
        for(int i=n, j=0; i<2*n; i++, j++) tree[i] = arr[j];
        init();
    }
};

class lazyprop {
public:
    class T {
    public:
        int val = 0;
        T()=default;
        explicit T(int v) : val(v) {}
        T operator+(const T &t2) const { return T(val + t2.val); }
        T operator+(const int &i) const { return T(val + i); }
        void operator+=(const T &i) { val += i.val; }
        void operator+=(const int &i) { val += i; }
        T& operator=(cint i) { val = i; return *this; }
        T& operator=(const T &i) = default;
    };
protected:
    v<T> tree; v<int> lazy;
    int n;
    void update_lazy(int node, int start, int end) {
        tree[node] += lazy[node] * (end-start+1);
        if(start!=end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = {};
    }
public:
    explicit lazyprop(int treeSize, bool inputInit = false) {
        lazy = v<int>(4*treeSize, 0);
        tree = v<T>(4*treeSize, T());
        n = treeSize;
        if(inputInit) {
            v<int> a; forn(i, n) a.push_back(input());
            init(a, 1, 1, n);
        }
    }
    explicit lazyprop(const v<int> &a) : lazyprop((int) a.size()) {
        init(a, 1, 1, n);
    }
    lazyprop(const v<int> &a, int treeSize) : lazyprop(treeSize) {
        init(a, 1, 1, n);
        assert(a.size() == treeSize);
    }
    void update(int tar, int diff) { update(tar, tar, diff); }
    void update(int left, int right, int diff) { update(1, left, right, 1, n, diff); }
    T query(int tar) { return query(tar, tar); }
    T query(int left, int right) { return query(1, left, right, 1, n); }
protected:
    void init(const v<int> &a, int node, int start, int end) {
        if(start==end) {
            tree[node] = a[start-1];
        } else {
            init(a, node*2, start, (start+end)/2);
            init(a, node*2+1, (start+end)/2+1, end);
            tree[node] = tree[node*2] + tree[node*2+1];
        }
    }
    void update(int node, int left, int right, int start, int end, int diff) {
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
    T query(int node, int left, int right, int start, int end) {
        update_lazy(node, start, end);
        if(right < start || end < left) return {};
        if(left <= start && end <= right) return tree[node];
        return query(node*2, left, right, start, (start+end)/2) +
               query(node*2+1, left, right, (start+end)/2+1, end);
    }
};

class goldmineSeg {
public:
    class nd {
    public:
        int lval, rval, val, allval;
        nd(int a, int b, int c, int d) : lval(a), rval(b), val(c), allval(d){}
    };
private:
    vector<nd> tree;
    int n;
public:
    explicit goldmineSeg(const int &treeSize) {
        tree = v<nd>(4*treeSize, {0, 0, 0, 0});
        n = treeSize;
    }
    explicit goldmineSeg(const v<int> &a) : goldmineSeg((int) a.size()) {
        init(a, 1, 1, n);
    }
    goldmineSeg(const v<int> &a, const int &treeSize) : goldmineSeg(treeSize) {
        assert(a.size() == treeSize);
        init(a, 1, 1, n);
    }
    void update(const int &tar, const int &val) { update(1, 1, n, tar, val); }
    nd query(const int &left, const int &right) { return query(1, 1, n, left, right); }
protected:
    void init(const vector<int> &a, int node, int start, int end) {
        if(start==end) {
            tree[node] = {a[start-1], a[start-1], a[start-1], a[start-1]};
        } else {
            init(a, node*2, start, (start+end)/2);
            init(a, node*2+1, (start+end)/2+1, end);
            tree[node] = {0,0,0,0};
            tree[node].lval = max(tree[node*2].lval, tree[node*2].allval + tree[node*2+1].lval);
            tree[node].rval = max(tree[node*2+1].rval, tree[node*2+1].allval + tree[node*2].rval);
            tree[node].val = max(max(tree[node*2].val, tree[node*2+1].val), tree[node*2].rval + tree[node*2+1].lval);
            tree[node].allval = tree[node*2].allval + tree[node*2+1].allval;
        }
    }
    void update(int node, int start, int end, const int &index, const int &val) {
        if(index<start || end<index) return;
        if(start==end) {
            tree[node] = {val, val, val, val};
        } else {
            update(node*2, start, (start+end)/2, index, val);
            update(node*2+1, (start+end)/2+1, end, index, val);
            tree[node] = {0,0,0,0};
            tree[node].lval = max(tree[node*2].lval, tree[node*2].allval + tree[node*2+1].lval);
            tree[node].rval = max(tree[node*2+1].rval, tree[node*2+1].allval + tree[node*2].rval);
            tree[node].val = max(max(tree[node*2].val, tree[node*2+1].val), tree[node*2].rval + tree[node*2+1].lval);
            tree[node].allval = tree[node*2].allval + tree[node*2+1].allval;
        }
    }
    nd query(int node, int start, int end, const int &left, const int &right) {
        if(end < left || right < start) return {0, -inf, -inf, -inf};
        if(left <= start && end <= right) return tree[node];
        nd f = query(node*2, start, (start+end)/2, left, right);
        nd s = query(node*2+1, (start+end)/2+1, end, left, right);
        nd c = {0, 0, 0, 0};
        c.lval = max(f.lval, f.allval + s.lval);
        c.rval = max(s.rval, s.allval + f.rval);
        c.val = max(max(f.val, s.val), f.rval + s.lval);
        c.allval = f.allval + s.allval;
        return c;
    }

};

class seg2d {
public:
    class seg1d {
    public:
        vector<int> tree;
        int n;
        explicit seg1d(int treeSize) {
            tree = v<int>(4*treeSize, 0);
            n = treeSize;
        }
        explicit seg1d(const v<int> &a) : seg1d((int) a.size()) {
            init(a, 1, 1, n);
        }
        seg1d(const v<int> &a, int treeSize) : seg1d(treeSize) {
            init(a, 1, 1, n);
            assert(a.size() == treeSize);
        }
        void update(int tar, int diff) { update(tar, tar, diff); }
        static int findNode(int start, int end, cint tar, int node) {
            if(start==end) { return node; }
            if(tar<=(start+end)/2) return findNode(start, (start+end)/2, tar, node*2);
            return findNode((start+end)/2+1, end, tar, node*2+1);
        }
        int query(int tar) { return query(tar, tar); }
        int query(int left, int right) { return query(1, left, right, 1, n); }
    protected:
        void update(int left, int right, int diff) { update(1, left, right, 1, n, diff); }
        void init(const v<int> &a, int node, int start, int end) {
            if(start==end) {
                tree[node] = a[start-1];
            } else {
                init(a, node*2, start, (start+end)/2);
                init(a, node*2+1, (start+end)/2+1, end);
                tree[node] = tree[node*2] + tree[node*2+1];
            }
        }
        void update(int node, int left, int right, int start, int end, int diff) {
            if(end<left || right < start) return;
            if(left <= start && end <= right) {
                tree[node] = diff;
                return;
            }
            update(node*2, left, right, start, (start+end)/2, diff);
            update(node*2+1, left, right, (start+end)/2+1, end, diff);
            tree[node] = tree[node*2] + tree[node*2+1];
        }
        int query(int node, int left, int right, int start, int end) {
            if(right < start || end < left) return {};
            if(left <= start && end <= right) return tree[node];
            return query(node*2, left, right, start, (start+end)/2) +
                   query(node*2+1, left, right, (start+end)/2+1, end);
        }
    };
    v<seg1d> trees; int yn, xn;
    //Cnt : y, Size : x
    seg2d(cint treeCnt, cint treeSize) {
        trees = v<seg1d>(treeCnt*4, seg1d(treeSize));
        yn = treeCnt, xn = treeSize;
    }
    seg2d(cint treeCnt, cint treeSize, const v2<int> &arr) {
        trees = v<seg1d>(treeCnt*4, seg1d(treeSize));
        yn = treeCnt, xn = treeSize;
        init(1, 1, yn, arr, (int) arr[0].size());
    }
    /// 1<=x1<=treeSize, 1<=y1<=treeCnt
    void update(cint x, cint y, cint val) {
        update(1, 1, yn, x, y, val, seg1d::findNode(1, xn, x, 1));
    }
    /// 1<=x1<=treeSize, 1<=y1<=treeCnt
    int query(cint x1, cint x2, cint y1, cint y2) {
        return query(1, 1, yn, x1, x2, y1, y2);
    }
    seg1d* query_tree(int y) {
        return query_tree(1, 1, yn, y);
    }
private:
    seg1d* query_tree(int node, int start, int end, cint y) {
        if(start==end) return &trees[node];
        if(y<=(start+end)/2) return query_tree(node*2, start, (start+end)/2, y);
        else return query_tree(node*2+1, (start+end)/2+1, end, y);
    }
    void init(int node, int start, int end, const v2<int> &arr, cint sz) {
        if(start==end) {
            trees[node] = seg1d(arr[start-1], sz);
            return;
        }
        init(node*2, start, (start+end)/2, arr, sz);
        init(node*2+1, (start+end)/2+1, end, arr, sz);
        int ts = (int) trees[node].tree.size();
        forn(i, ts) trees[node].tree[i] = trees[node*2].tree[i] + trees[node*2+1].tree[i];
    }
    void update(int node, int start, int end, cint x, cint y, cint val, cint t) {
        if(y < start || end < y) return;
        if(start==end) {
            trees[node].update(x, val);
            return;
        }
        update(node*2, start, (start+end)/2, x, y, val, t);
        update(node*2+1, (start+end)/2+1, end, x, y, val, t);
        trees[node].update(x, trees[node*2].tree[t] + trees[node*2+1].tree[t]);
    }
    int query(int node, cint start, cint end, cint x1, cint x2, cint y1, cint y2) {
        if(end<y1 || y2<start) return 0;
        if(y1 <= start && end <= y2) return trees[node].query(x1, x2);
        return query(node*2, start, (start+end)/2, x1, x2, y1, y2) +
               query(node*2+1, (start+end)/2+1, end, x1, x2, y1, y2);
    }
};

class pst {
    class pnd {
    public:
        pnd *l = nullptr, *r = nullptr;
        bool deleteL = false, deleteR = false;
        int val = 0;
        pnd()=default;
        pnd(bool ldel, bool rdel) : deleteL(ldel), deleteR(rdel) {}
        ~pnd(){ if(deleteL) delete l; if(deleteR) delete r; }
    };
public:
    explicit pst(cint treeSize) : pst() {
        n = treeSize;
        init(cur, 1, n);
        end_update();
    }
    pst(cint treeSize, const v<int> &arr) : pst() {
        n = treeSize;
        assert(arr.size() == treeSize);
        init(cur, 1, n, arr);
        end_update();
    }
    ~pst() { for(auto &p : root) delete p; }
    void update(cint tar, cint val) {
        assert(tar>0);
        update(pre, cur, 1, n, tar, val);
    }
    void singleUpdate(cint tar, cint val) { update(tar, val); end_update(); }
    void end_update() {
        if(!cur->l) { cur->l = pre->l; cur->deleteL = false; cur->val += cur->l->val; }
        if(!cur->r) { cur->r = pre->r; cur->deleteR = false; cur->val += cur->r->val; }
        pre = cur; cur = new pnd();
        root.push_back(cur); treeCnt++;
    }
    int query(cint rootN, cint left, cint right) {
        assert(0<=rootN && rootN<treeCnt); assert(left <= right && left > 0);
        return query(root[rootN], 1, n, left, right);
    }
private:
    explicit pst() {
        root.push_back(new pnd());
        pre = nullptr; cur = root[0];
    }
    v<pnd*> root; int n = -1, treeCnt = 0;
    pnd *pre, *cur;
    void init(pnd *node, int start, int end, const v<int> &arr) {
        if(start == end) { node->val = arr[start-1]; return; }
        node->l = new pnd(); node->r = new pnd();
        node->deleteL = true; node->deleteR = true;
        init(node->l, start, (start+end)/2, arr);
        init(node->r, (start+end)/2+1, end, arr);
        node->val = node->l->val + node->r->val;
    }
    void init(pnd *node, int start, int end) {
        if(start == end) { node->val = 0; return; }
        node->l = new pnd(); node->r = new pnd();
        node->deleteL = true; node->deleteR = true;
        init(node->l, start, (start+end)/2);
        init(node->r, (start+end)/2+1, end);
        node->val = node->l->val + node->r->val;
    }
    void update(pnd *prev, pnd *now, int start, int end, cint tar, cint val) {
        if(start==end) { now->val += val; return; }
        if(tar <= (start+end)/2) {
            if(!now->l || now->l == prev->l) {
                now->l = new pnd();
                now->l->val = prev->l->val;
            }
            if(!now->r) now->r = prev->r;
            now->deleteL = true;
            update(prev->l, now->l, start, (start+end)/2, tar, val);
        } else {
            if(!now->l) now->l = prev->l;
            if(!now->r || now->r == prev->r) {
                now->r = new pnd();
                now->r->val = prev->r->val;
            }
            now->deleteR = true;
            update(prev->r, now->r, (start+end)/2+1, end, tar, val);
        }
        now->val = now->l->val + now->r->val;
    }
    int query(pnd *node, int start, int end, cint left, cint right) {
        if(right < start || end < left) return 0;
        if(left <= start && end <= right) return node->val;
        return query(node->l, start, (start+end)/2, left, right) +
               query(node->r, (start+end)/2+1, end, left, right);
    }
};

class segbeats {
public:
    struct Node {
        int mx, mx2, mxcnt, sum;
        Node()=default;
        Node(int a, int b, int c, int d) : mx(a), mx2(b), mxcnt(c), sum(d){};
        Node operator+(const Node &a) const {
            return merge_node(*this, a);
        }
        static Node merge_node(const Node &a, const Node &b) {
            Node ret(a.mx, a.mx2, a.mxcnt, a.sum + b.sum);
            if(ret.mx == b.mx) ret.mxcnt += b.mxcnt;
            for(const int &i : {b.mx, b.mx2}) {
                if(ret.mx < i) {
                    ret.mx2 = ret.mx;
                    ret.mx = i;
                    ret.mxcnt = b.mxcnt;
                } else if (ret.mx > i && ret.mx2 < i) {
                    ret.mx2 = i;
                }
            }
            return ret;
        }
    };
    explicit segbeats(int treeSize) {
        lazy = tree = v<Node>(4*treeSize);
        n = treeSize;
    }
    explicit segbeats(const v<int> &a) : segbeats((int)a.size()) {
        init(a, 1, 1, n);
    }
    segbeats(const v<int> &a, int treeSize) : segbeats(treeSize) {
        init(a, 1, 1, n);
        assert(a.size() == treeSize);
    }
    void update(int tar, int diff) { update(tar, tar, diff); }
    void update(int left, int right, int diff) { update(1, left, right, 1, n, diff); }
    Node query(int left, int right) { return query(1, left, right, 1, n); }
protected:
    vector<Node> tree, lazy;
    int n;
    void update_lazy(int node, int start, int end) {
        if(start==end) return;
        for(int i : {node*2, node*2+1}) {
            if(tree[node].mx < tree[i].mx) {
                tree[i].sum -= tree[i].mxcnt * (tree[i].mx - tree[node].mx);
                tree[i].mx = tree[node].mx;
            }
        }
    }
    void init(const v<int> &a, int node, int start, int end) {
        if(start==end) {
            tree[node] = {a[start-1], -1, 1, a[start-1]};
        } else {
            init(a, node*2, start, (start+end)/2);
            init(a, node*2+1, (start+end)/2+1, end);
            tree[node] = tree[node*2] + tree[node*2+1];
        }
    }
    void update(int node, int left, int right, int start, int end, int diff) {
        update_lazy(node, start, end);
        if((end<left || right < start) || tree[node].mx <= diff) return; //break condition
        if(left <= start && end <= right && tree[node].mx2 < diff) { // tag condition
            tree[node].sum -= tree[node].mxcnt * (tree[node].mx - diff);
            tree[node].mx = diff;
            update_lazy(node, start, end);
            return;
        }
        update(node*2, left, right, start, (start+end)/2, diff);
        update(node*2+1, left, right, (start+end)/2+1, end, diff);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    Node query(int node, int left, int right, int start, int end) {
        update_lazy(node, start, end);
        if(right < start || end < left) return {-1, -1, -1, 0};
        if(left <= start && end <= right) return tree[node];
        return query(node*2, left, right, start, (start+end)/2) +
                          query(node*2+1, left, right, (start+end)/2+1, end);
    }
};

class dynamicSeg {
    class pnd { // pointer_based_node
    public:
        pnd *l = nullptr, *r = nullptr;
        int val = 0;
        pnd()=default;
        ~pnd(){ delete l; delete r; }
    };
public:
    explicit dynamicSeg(int treeSize) : dynamicSeg() { n = treeSize; }
    ~dynamicSeg() { delete root; }
    void update(cint tar, cint val) {
        assert(tar>0);
        update(root, 1, n, tar, val);
    }
    int query(const int &left, const int &right) {
        assert(left <= right && left > 0);
        return query(root, 1, n, left, right);
    }
private:
    explicit dynamicSeg() { root = new pnd(); }
    pnd *root; int n = -1;
    void update(pnd *node, int start, int end, cint tar, cint val) {
        if(start==end) {
            node->val = val; return;
        }
        if(tar <= (start+end)/2) {
            if(!node->l) node->l = new pnd();
            update(node->l, start, (start+end)/2, tar, val);
        } else {
            if(!node->r) node->r = new pnd();
            update(node->r, (start+end)/2+1, end, tar, val);
        }
        int lv = node->l ? node->l->val : 0;
        int rv = node->r ? node->r->val : 0;
        node->val = lv + rv;
    }
    int query(pnd *node, int start, int end, cint left, cint right) {
        if(!node) return 0;
        if(right < start || end < left) return 0;
        if(left <= start && end <= right) return node->val;
        return query(node->l, start, (start+end)/2, left, right) +
               query(node->r, (start+end)/2+1, end, left, right);
    }
};

class sparseSeg {
public:
    class lpnd {
    public:
        lpnd *l = nullptr, *r = nullptr;
        int val = 0, lazy = 0;
        lpnd()=default;
        ~lpnd(){ delete l; delete r; }
    };
    explicit sparseSeg(int treeSize) : sparseSeg() { n = treeSize; }
    ~sparseSeg() { delete root; }
    void update(cint left, cint right, cint val) {
        assert(left <= right && left > 0);
        update(root, 1, n, left, right, val);
    }
    int query(cint left, cint right) {
        assert(left <= right && left > 0);
        return query(root, 1, n, left, right);
    }
private:
    explicit sparseSeg() { root = new lpnd(); }
    lpnd *root; int n = -1;
    static void push(lpnd *node, cint start, cint end) {
        node->val += (end-start+1) * node->lazy;
        if(start != end) {
            if(!node->l) node->l = new lpnd();
            node->l->lazy += node->lazy;
            if(!node->r) node->r = new lpnd();
            node->r->lazy += node->lazy;
        }
        node->lazy = 0;
    }
    void update(lpnd *node, int start, int end, cint left, cint right, cint val) {
        push(node, start, end);
        if(right < start || end < left) return;
        if(left <= start && end <= right) {
            node->lazy += val;
            push(node, start, end);
            return;
        }
        int mid = (start+end)/2;
        if(node->l || left <= mid) {
            if (!node->l) node->l = new lpnd();
            update(node->l, start, mid, left, right, val);
        }
        if(node->r || mid+1 <= right) {
            if (!node->r) node->r = new lpnd();
            update(node->r, mid + 1, end, left, right, val);
        }
        int lv = node->l ? node->l->val : 0;
        int rv = node->r ? node->r->val : 0;
        node->val = lv + rv;
    }
    int query(lpnd *node, int start, int end, cint left, cint right) {
        if(!node) return 0;
        if(right < start || end < left) return 0;
        push(node, start, end);
        if(left <= start && end <= right) return node->val;
        return query(node->l, start, (start+end)/2, left, right) +
               query(node->r, (start+end)/2+1, end, left, right);
    }
};
