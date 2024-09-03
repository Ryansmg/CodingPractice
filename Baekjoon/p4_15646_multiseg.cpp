#pragma region macros
//@formatter:off
#define GCC_OPTIMIZE_ENABLE false

#include <bits/stdc++.h>
using namespace std;
#if GCC_OPTIMIZE_ENABLE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif
#ifdef LOCAL
#define DEBUG_PRINT_ if(c==cdbg) cerr << t; else cout << t;
#define lfastio print()
#else
#define DEBUG_PRINT_
#define lfastio fastio
#endif
using i16 = short; using i32 = signed; using i64 = long long; using i128 = __int128;
using u16 = unsigned short; using u32 = unsigned; using u64 = unsigned long long; using u128 = unsigned __int128;
using f32 = float; using f64 = double; using f128 = long double;
using str = string;
#define int i64
#define uint u64
#define ci64 const i64 &
#define cint ci64
#define ci32 const i32 &
const long long llmax = 9223372036854775807, INF = 1000000000000000000, inf = 3000000000;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(name, val) for(i64 name = 0; name < val; name++)
#define forf(name, start, end) for(i64 name = start; name <= end; name++)
#define forr(name, start, end) for(i64 name = start; name >= end; name--)
#define all(vec) (vec).begin(), (vec).end()
template <typename T> using v = vector<T>; template <typename T> using v2 = v<v<T>>;
using vl = v<i64>; using v2l = v2<i64>;
template <typename T, typename T2=v<T>, typename T3=less<>> using pq = priority_queue<T, T2, T3>;
using ii = array<i64, 2>; using iii = array<i64, 3>;
template <typename T> using lim = std::numeric_limits<T>;

template <typename T = i64> T input() {T t; cin >> t; return t;}
template <typename T> T::value_type fpop(T &que) { auto t = que.front(); que.pop(); return t; }
template <typename T> T::value_type tpop(T &st) { auto t = st.top(); st.pop(); return t; }
template <typename T> void sort(v<T> &v) { sort(all(v)); }
template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
template <typename T> T pow_(T a, T b, T mod=lim<T>::max()) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }
template <typename T = i64> v<T> inputArr(i64 sz) { v<T> a; forn(i,sz) a.push_back(input<T>()); return a; }
template <typename T> void inputArr(v<T> &arr, i64 sz, bool clear = true) { if(clear) arr.clear(); forn(i,sz) arr.push_back(input<T>()); }
template <typename T> v<T> sorted_copy(v<T> arr) { sort(all(arr)); return arr; }
template <typename T> v<T> compressed_copy(v<T> arr, const bool &autosort=true) { compress(arr, autosort); return arr; }
template <typename T> T min(T a, T b, T c) { return min(a, min(b, c)); }
template <typename T> T min(T a, T b, T c, T d, T e=lim<T>::max(), T f=lim<T>::max()) { return min(min(a, b), min(c, d), min(e, f)); }
template <typename T> T max(T a, T b, T c) { return max(a, max(b, c)); }
template <typename T> T max(T a, T b, T c, T d, T e=lim<T>::min(), T f=lim<T>::min()) { return max(max(a, b), max(c, d), max(e, f)); }

enum Null_{} nl_; enum cdbg_{ useCerr, useCout } cdbg=useCerr, cloc=useCout;
istream& operator>>(istream& i, const Null_&) { return i; } ostream& operator<<(ostream& i, const Null_&) { return i; }
template <typename T> cdbg_& operator<<(cdbg_& c, const T& t) {
    DEBUG_PRINT_
    return c;
}

template <class A, class B=Null_, class C=Null_, class D=Null_, class E=Null_, class F=Null_, class G=Null_>
void input(A &a, B &b=nl_, C &c=nl_, D &d=nl_, E &e=nl_, F &f=nl_, G &g=nl_) {
    cin >> a >> b >> c >> d >> e >> f >> g;
}
template <class A=Null_, class B=Null_, class C=Null_, class D=Null_, class E=Null_, class F=Null_, class G=Null_, class H=Null_, class I=Null_, class J=Null_>
void print(A a=nl_, B b=nl_, C c=nl_, D d=nl_, E e=nl_, F f=nl_, G g=nl_, H h=nl_, I i=nl_, J j=nl_) {
    cout << a << b << c << d << e << f << g << h << i << j;
}
template <class A=Null_, class B=Null_, class C=Null_, class D=Null_, class E=Null_, class F=Null_, class G=Null_, class H=Null_, class I=Null_, class J=Null_>
void println(A a=nl_, B b=nl_, C c=nl_, D d=nl_, E e=nl_, F f=nl_, G g=nl_, H h=nl_, I i=nl_, J j=nl_) {
    print(a, b, c, d, e, f, g, h, i, j); cout << '\n';
}
template <typename T>
void printArr(const v<T> &v, const string &sep = " ", const string &end = "\n") {
    for(T i : v) cout << i << sep; cout << end;
}
//@formatter:on
#pragma endregion

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

// 15646. 농부 후안은 바리스타입니다
// #multi_segtree

i32 main() {
    i64 n, m, q; cin >> n >> m >> q;
    vl yc, xc;
    queue<array<i32, 6>> queries;
    forn(qi, q) {
        array<i32, 6> i{};
        i[0] = input();
        if(i[0] == 1) {
            input(i[1], i[2], i[3], i[4], i[5]);
            xc.push_back(i[1]); xc.push_back(i[3]);
            yc.push_back(i[2]); yc.push_back(i[4]);
        }
        else {
            input(i[1], i[2]);
            xc.push_back(i[1]);
            yc.push_back(i[2]);
        }
        queries.emplace(i);
    }
    compress(xc); compress(yc);
    seg2d seg(yc.size()+2, xc.size()+2);
    forn(qi, q) {
        array<i32, 6> i = fpop(queries);
        i64 t = i[0];
        if(t == 1) {
            i64 x1, y1, x2, y2, d;
            x1 = i[1], y1 = i[2], x2 = i[3], y2 = i[4], d = i[5];
            x1 = idx(x1, xc) + 1;
            x2 = idx(x2, xc) + 1;
            y1 = idx(y1, yc) + 1;
            y2 = idx(y2, yc) + 1;
            seg.update(x1, y1, d);
            seg.update(x2+1, y2+1, -d);
        } else {
            i64 x = i[1], y = i[2];
            x = idx(x, xc) + 1;
            y = idx(y, yc) + 1;
            println(seg.query(1, x, 1, y));
        }
    }
}
