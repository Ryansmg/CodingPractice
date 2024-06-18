#pragma region macros
#include <bits/stdc++.h>

#include <utility>
#define int long long
#define double long double
#define cint const int &
#define llmax 9223372036854775807
#define INF 1000000000000000000
#define inf 3000000000
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define forn(name, val) for(int name = 0; name < val; name++)
#define forf(name, start, end) for(int name = start; name <= end; name++)
#define pass {cout << "";}
using namespace std;
template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
template <typename T> using pq = priority_queue<T>;
using ii = array<int, 2>;
using iii = array<int, 3>;
#define all(vec) (vec).begin(), (vec).end()
template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
template <typename T=int> T input() {T t; cin >> t; return t;}
#pragma endregion

class sqrtArray {
    int n, sq;
    v<int> arr, bucket;
public:
    explicit sqrtArray(int size) :
        n(size), sq((int)sqrt(size)){
        arr = v<int>(n+1,0);
        bucket = v<int>(n/sq+2,0);
    }
    explicit sqrtArray(const v<int>& vec) :
        n((int)vec.size()), sq((int)sqrt(n)){
        arr = v<int>(n+1, 0);
        bucket = v<int>(n/sq+2, 0);
        forn(i, n) set(i, vec[i]);
    }
    void set(int pos, int val) {
        bucket[pos/sq] += val - arr[pos];
        arr[pos] = val;
    }
    int query(int l, int r) {
        int ret = 0;
        for(; l%sq && l<=r; l++) ret += arr[l];
        for(; (r+1)%sq && l<=r; r--) ret += arr[r];
        for(; l<=r; l += sq) ret += bucket[l/sq];
        return ret;
    }
};

class sa {
    struct san {
        int val, pos=-1; sa &s;
        san(int v, sa &S) : val(v), s(S) {}
        san& operator=(int v) {
            s.set(pos, v);
            return *this;
        }
        int operator[](int r) {
            assert(pos<=r);
            return s.query(pos, r);
        }
    };
    int n, sq;
    v<san> arr; v<int> bucket;
public:
    explicit sa(int size) :
            n(size), sq((int)sqrt(size)){
        arr = v<san>(n+1,san(0, *this));
        bucket = v<int>(n/sq+2,0);
    }
    explicit sa(const v<int>& vec) :
            n((int)vec.size()), sq((int)sqrt(n)){
        arr = v<san>(n+1,san(0, *this));
        bucket = v<int>(n/sq+2, 0);
        forn(i, n) set(i, vec[i]);
    }
    san& operator[](int pos) {
        assert(0<=pos && pos<n);
        arr[pos].pos=pos;
        return arr[pos];
    }
private:
    void set(int pos, int val) {
        bucket[pos/sq] += val - arr[pos].val;
        arr[pos].val = val;
    }
    int query(int l, int r) {
        int ret = 0;
        for(; l%sq && l<=r; l++) ret += arr[l].val;
        for(; (r+1)%sq && l<=r; r--) ret += arr[r].val;
        for(; l<=r; l += sq) ret += bucket[l/sq];
        return ret;
    }
};

signed main() {
    fastio; // 구간 합 구하기
    int n, m; cin >> n >> m; m+=input();
    v<int> in;
    forn(i, n) in.push_back(input());
    sa arr(in);
    forn(i, m) {
        int a, b, c; cin >> a >> b >> c;
        if(a==1) arr[b-1] = c;
        else cout << arr[b-1][c-1] << '\n';
    }
}
