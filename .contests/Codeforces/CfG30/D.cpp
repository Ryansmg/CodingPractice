#pragma region optimize
#if 0
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,bmi,bmi2,lzcnt,popcnt")
#endif
#pragma endregion

#pragma region

#include <bits/stdc++.h>
using namespace std;
using i64 = long long; using i32 = signed;
using f64 = long double; using f32 = double;
#define all(v_) (v_).begin(), (v_).end()
#define forn(name_, val_) for(long long name_ = 0; name_ < (val_); name_++)
#define forf(name_, start_, end_) for(long long name_ = (start_); name_ <= (end_); name_++)
#define forr(name_, start_, end_) for(long long name_ = (start_); name_ >= (end_); name_--)
#define CONCAT_INNER_(x, y) x##y
#define CONCAT_(x, y) CONCAT_INNER_(x, y)
#define repeat_(n, i) for(long long i = 0; i < n; i++)
#define rep(n) repeat_(n, CONCAT_(rep_var_, __COUNTER__))
long long iR_v_, iR_v5_;
#define inRep() cin>>iR_v_; forn(iR_v3_, iR_v_)
#define tcRep() cin>>iR_v5_; forf(TCN, 1, iR_v5_)
template <typename T, typename Compare> inline T pop(priority_queue<T, vector<T>, Compare> &pq_) { T t_ = pq_.top(); pq_.pop(); return t_; }
template <typename T> inline T pop(stack<T> &st_) { T t_ = st_.top(); st_.pop(); return t_; }
template <typename T> inline T pop(stack<T, vector<T>> &st_) { T t_ = st_.top(); st_.pop(); return t_; }
template <typename T> inline T pop(queue<T> &q_) { T t_ = q_.front(); q_.pop(); return t_; }
template <typename T> inline T pop(queue<T, list<T>> &q_) { T t_ = q_.front(); q_.pop(); return t_; }
template <typename T> inline T pop(vector<T> &arr_) { T t_ = arr_.back(); arr_.pop_back(); return t_; }
template <typename T> inline void reverse(T& v_) { reverse(v_.begin(), v_.end()); }
template <typename T> inline void sort(T& v_) { sort(v_.begin(), v_.end()); }
template <typename T, typename Cmp> inline void sort(T& v_, const Cmp& cmp) { sort(v_.begin(), v_.end(), cmp); }
template <typename T> inline void compress(T &v_, const bool& autosort = true) { if(autosort) sort(v_.begin(), v_.end()); v_.erase(unique(v_.begin(), v_.end()), v_.end()); }
template <typename T> inline long long cidx(const T &val, const vector<T> &compressed) { return lower_bound(compressed.begin(), compressed.end(), val) - compressed.begin(); }
template <typename T> inline vector<T> merge(const vector<T>&a, const vector<T>&b) {
    vector<T> ret(a.size()+b.size()); std::merge(a.begin(), a.end(), b.begin(), b.end(), ret.begin()); return ret;
}
template <typename T, typename Cmp> inline vector<T> merge(const vector<T>&a, const vector<T>&b, const Cmp& cmp) {
    vector<T> ret(a.size()+b.size()); std::merge(a.begin(), a.end(), b.begin(), b.end(), ret.begin(), cmp); return ret;
}
template <typename T> inline T pow_(T a, T b, T mod) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T modInv(T a, const T& m, bool chkGcd = true) { // by @kuhyaku
    T b = m, u = 1, v = 0; if(chkGcd) assert(gcd(a, m) == 1);
    while (b) { T t = a / b; a -= t * b; swap(a, b); u -= t * v; swap(u, v); }
    u %= m; if (u < 0) {u += m;} return u;
}
inline long long pow(long long a, long long b, long long mod) {return pow_(b < 0 ? modInv(a, mod) : a, abs(b), mod);}
inline long long pow(long long a, long long b) { long long ans=1;while(b){if(b&1)ans=ans*a;b>>=1;a=a*a;} return ans; }
template <typename T> inline T max(const vector<T>& v_) { T ret = v_.empty() ? numeric_limits<T>::min() : v_[0]; for(const T &t_ : v_) { ret = max(ret, t_); } return ret; }
template <typename T> inline T min(const vector<T>& v_) { T ret = v_.empty() ? numeric_limits<T>::max() : v_[0]; for(const T &t_ : v_) { ret = min(ret, t_); } return ret; }
inline long long max(long long a, long long b) { return a > b ? a : b; } inline long long min(long long a, long long b) { return a < b ? a : b; }
template <typename T> inline T sum(const vector<T>& v_) { T s_ = T(); {for(const T& i_ : v_) s_ += i_;} return s_; }
template <typename T> inline T gcd_(T a, T b) { if(a < b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }
inline signed popcount(long long v) { return __builtin_popcountll(*reinterpret_cast<unsigned long long*>(&v)); }
/// count leading zeros (000010 => 4)
inline auto clz(long long v) { return __builtin_clzll(v); }
/// left most bit (000100 => 2)
inline signed lmb(long long v) { return 63 - clz(v); }
mt19937 m1gn_(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<long long> uni3i64_(0, 9223372036854775807);
#define rand rand_
inline long long randl() { return uni3i64_(m1gn_); }
/// inclusive
inline long long rand_(long long l_, long long r_) { return randl() % (r_ - l_ + 1) + l_; }
inline long long rand_(long long n_) { return rand_(0, n_-1); }

template <typename Iter> void shuffle(Iter first, Iter last) {
    if (first == last) return;
    for (Iter i = first + 1; i != last; ++i)
        iter_swap(i, first + rand(int(i - first) + 1));
}
template <typename T> void shuffle(T& arr) { shuffle(arr.begin(), arr.end()); }

#define ci64 const i64 &
#define ci32 const i32 &

template <typename T = long long> inline T get() { T t; cin >> t; return t; }
template <typename ...T> inline void get(T&... a_) { (cin >> ... >> a_); }
inline void put() {}
template <typename ...T> inline void put(const T&... a_) { (cout << ... << a_); }
inline void ln() { cout << '\n'; }
template <typename ...T> inline void ln(const T&... a_) { (cout << ... << a_) << '\n'; }

#define in64(...) long long __VA_ARGS__; get(__VA_ARGS__)
#define instr(...) string __VA_ARGS__; get<string>(__VA_ARGS__)
inline string inStr() { string t; cin >> t; return t; }

inline string readline() {
    char c = '\n'; while(c == '\n') cin.get(c);
    string s; getline(cin, s);
    s = c + s; return s;
}

struct enable_fastio_ {
    enable_fastio_() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
} efio_;

#pragma endregion

#pragma region ext

/// requirements: (T + T), add -> (T += AddType)
/// 1-based index (for default)
template <typename T = long long, typename AddType = T>
struct segtree {
    std::vector<T> tree; signed n = -1; signed offset = 1;
    explicit segtree(const std::vector<T> &arr) {
        n = signed(arr.size()); tree = std::vector<T>(2 * n, T());
        for(signed i = n, j = 0; i < 2 * n; i++, j++) tree[i] = arr[j];
        for(signed i = n - 1; i > 0; i--) tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
    segtree() = default;
    explicit segtree(signed i) { tree = std::vector<T>(i * 2, T()); n = i; }
    segtree(signed lBound, signed rBound) {
        n = rBound - lBound + 1; offset = lBound;
        tree = std::vector<T>(n * 2, T());
    }
    void add(signed tar, const AddType& val) { tar -= offset;
        tree[n + tar] += val;
        for(signed i = (n + tar) >> 1; i; i >>= 1) tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
    void set(signed tar, const T &val) { tar -= offset;
        tree[n + tar] = val;
        for(signed i = (n + tar) >> 1; i; i >>= 1) tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
    template <typename T2> requires (!std::is_convertible_v<T2, T>)
    inline void set(signed tar, const T2& val) { set(tar, T(val)); }
    template <typename T2, typename... T3> requires (sizeof...(T3) > 0)
    inline void set(signed tar, const T2& val, const T3&... arr) { set(tar, T(val, arr...)); }
    T query(signed left, signed right) { left -= offset; right -= offset;
        signed l = n + left, r = n + right + 1;
        T ansL, ansR;
        bool lSet = false, rSet = false;
        for(; l < r; l >>= 1, r >>= 1) {
            if(l & 1) {
                if(!lSet) lSet = true, ansL = tree[l++];
                else ansL = ansL + tree[l++];
            }
            if(r & 1) {
                if(!rSet) rSet = true, ansR = tree[--r];
                else ansR = tree[--r] + ansR;
            }
        }
        if(!lSet) return ansR;
        if(!rSet) return ansL;
        return ansL + ansR;
    }
    inline T query(signed tar) { return tree[n + tar - offset]; }
#ifdef __cpp_lib_span
    std::span<T> getLeafs() { return std::span<T>(tree.begin() + n, tree.begin() + 2 * n); }
#endif
};

#pragma endregion

struct seg {
    struct T {
        i64 monCnt = 0;
        i64 cmax = -1;
        i64 cmaxIdx = -1;
        multiset<i64> mons;

        T operator+(const T& b) const {
            if(cmax > b.cmax) return {monCnt + b.monCnt, cmax, cmaxIdx};
            return {monCnt + b.monCnt, b.cmax, b.cmaxIdx};
        }
    };

    vector<T> M;

    i64 len = 0;

    seg() = default;

    void init(i64 L) {
        M = vector<T>(4 * L);
        len = L;
    }

    void add(i64 p, i64 s, i64 e, i64 t, i64 v) {
        if(s == e) {
            M[p].monCnt++;
            M[p].cmax = max(M[p].cmax, v);
            M[p].mons.insert(v);
            M[p].cmaxIdx = t;
            return;
        }
        i64 m = (s + e) / 2;
        if(t <= m) add(p*2, s, m, t, v);
        else add(p*2+1, m+1, e, t, v);
        M[p] = M[p*2] + M[p*2+1];
    }

    T query(i64 p, i64 s, i64 e, i64 l, i64 r) {
        if(l <= s && e <= r) return M[p];
        if(e < l || r < s) return {};
        i64 m = (s + e) / 2;
        return query(p*2, s, m, l, r) + query(p*2+1, m+1, e, l, r);
    }

    void remove(i64 p, i64 s, i64 e, i64 t) {
        if(s == e) {
            M[p].monCnt--;
            M[p].mons.erase(prev(M[p].mons.end()));
            M[p].cmax = M[p].mons.empty() ? 0 : *M[p].mons.rbegin();
            M[p].cmaxIdx = t;
            return;
        }
        i64 m = (s + e) / 2;
        if(t <= m) remove(p*2, s, m, t);
        else remove(p*2+1, m+1, e, t);
        M[p] = M[p*2] + M[p*2+1];
    }
};

i32 main() {
    tcRep() {
        in64(n, k);
        instr(s);
        instr(t);
        i64 ok = n;
        while(ok && s[ok-1] == t[ok-1]) ok--;
        auto cur = s;
        vector<string> ans;
        bool possible = true;
        while(ok && possible) {
            if(ans.size() > k) break;
            i64 avail = ok - 1;
            forr(i, ok-1, 0) {
                if(avail > i) avail = i;
                while(avail && cur[avail] != t[i]) avail--;
                if(cur[avail] != t[i]) {
                    possible = false; break;
                }
                if(avail < i) cur[avail+1] = cur[avail];
            }
            ans.push_back(cur);
            while(ok && cur[ok-1] == t[ok-1]) ok--;
        }
        if(ans.size() > k || !possible) ln(-1);
        else {
            ln(ans.size());
            for(const auto& i : ans) ln(i);
        }
    }
}
