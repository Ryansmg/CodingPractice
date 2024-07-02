#pragma region macros
#include <bits/stdc++.h>
#define int long long
#define double long double
#define llmax 9223372036854775807
#define INF 1000000000000000000
#define inf 3000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define all(vec) (vec).begin(), (vec).end()
#define forn(name, val) for(int name = 0; name < val; name++)
#define forf(name, start, end) for(int name = start; name <= end; name++)
using namespace std;
template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
template <typename T> using pq = priority_queue<T>;
using ii = array<int, 2>;
using iii = array<int, 3>;

template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
template <typename T> T input() {T t; cin >> t; return t;}
int input() { int t; cin >> t; return t;}
#pragma endregion

template <typename T = int>
class segtree {
protected:
    vector<T> tree;
    int n;
public:
    explicit segtree(int treeSize) {
        tree = v<T>(4*treeSize, INF);
        n = treeSize;
    }
    segtree(const v<T> &a, int treeSize) : segtree(treeSize) {
        assert(a.size() == treeSize);
        init(a, 1, 1, n);
    }
    void update(int tar, T diff) { update(tar, tar, diff); }
    T query(int tar) { return query(tar, tar); }
    T query(int left, int right) { return query(1, left, right, 1, n); }
protected:
    void update(int left, int right, T diff) { update(1, left, right, 1, n, diff); }
    void init(const v<T> &a, int node, int start, int end) {
        if(start==end) {
            tree[node] = a[start-1];
        } else {
            init(a, node*2, start, (start+end)/2);
            init(a, node*2+1, (start+end)/2+1, end);
            tree[node] = min(tree[node*2], tree[node*2+1]);
        }
    }
    void update(int node, int left, int right, int start, int end, T diff) {
        if(end<left || right < start) return;
        if(left <= start && end <= right) {
            tree[node] = diff;
            return;
        }
        update(node*2, left, right, start, (start+end)/2, diff);
        update(node*2+1, left, right, (start+end)/2+1, end, diff);
        tree[node] = min(tree[node*2], tree[node*2+1]);
    }
    T query(int node, int left, int right, int start, int end) {
        if(right < start || end < left) return INF;
        if(left <= start && end <= right) return tree[node];
        return min(query(node*2, left, right, start, (start+end)/2),
               query(node*2+1, left, right, (start+end)/2+1, end));
    }
};

signed main() {
    fastio;
    int n, q; cin >> n;
    v<int> arr;
    forn(i, n) arr.push_back(input());
    segtree st(arr, n);
    cin >> q;
    forn(i, q) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a==2) {
            if(b>c) swap(b, c);
            cout << st.query(b, c) << '\n';
        } else {
            st.update(b, c);
        }
    }
}
