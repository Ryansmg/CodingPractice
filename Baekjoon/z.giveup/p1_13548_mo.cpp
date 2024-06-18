#pragma region macros
#define GCC_OPTIMIZE_ENABLE true

#include <bits/stdc++.h>
using namespace std;

#if GCC_OPTIMIZE_ENABLE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif

#define cint const int &

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(name, val) for(int name = 0; name < val; name++)
#define forf(name, start, end) for(int name = start; name <= end; name++)

template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
template <typename T> using pq = priority_queue<T>;
using ii = array<int, 2>;
using iii = array<int, 3>;

int input() {int t; cin >> t; return t;}
#pragma endregion

// 13548. 수열과 쿼리 6
// #mo

struct query {
    int i, j, order;
    query()=default;
    query(int a, int b, int c) {
        i = a; j = b; order = c;
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
        tree[n+tar] += val;
        for(int i = n+tar; i>1; i>>=1)
            tree[i>>1] = max(tree[i], tree[i^1]);
    }
    /// [l, r)
    int query(int left, int right) {
        assert(0 <= left && right <= n);
        int l = n+left, r = n+right, ans = 0;
        for(; l<r; l>>=1, r>>=1) {
            if(l&1) ans = max(ans,tree[l++]);
            if(r&1) ans = max(tree[--r], ans);
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

int sqrtsize; //sqrt(쿼리의 개수)

bool cmp(query a, query b) {
    if(a.i/sqrtsize == b.i/sqrtsize) {
        return a.j < b.j;
    } else return a.i/sqrtsize < b.i/sqrtsize;
}

signed main() {
    fastio;
    int n; cin >> n;
    sqrtsize = (int) sqrt(n);
    vector<int> a(1,-1);
    forn(i, n) a.push_back(input());
    int m; cin >> m;
    vector<query> queries;
    for(int i=0; i<m; i++) {
        int b, c; cin >> b >> c;
        queries.emplace_back(b, c, i);
    }
    sort(queries.begin(), queries.end(), cmp);
    vector<int> ans(m);
    iterSeg seg(100001);
    int l = queries[0].i, r = queries[0].j;
    for(int i=l; i<=r; i++) seg.update(a[i], 1);
    ans[queries[0].order] = seg.query(0, 100001);
    for(int i=1; i<m; i++) {
        int nl = queries[i].i;
        int nr = queries[i].j;
        while(l < nl) seg.update(a[l++], -1);
        while(nl < l) seg.update(a[--l], 1);
        while(r < nr) seg.update(a[++r], 1);
        while(nr < r) seg.update(a[r--], -1);
        ans[queries[i].order] = seg.query(0, 100001);
    }
    for(int i : ans) cout << i << "\n";
}
