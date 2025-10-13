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
#define pb push_back
#define eb emplace_back
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

class Bitset {
    size_t l = 0, wl = 0; std::vector<unsigned __int128> m;
public:
    class ref {
        Bitset* p; size_t wi, bi;
    public:
        inline explicit ref(Bitset* p, size_t idx) : p(p), wi(idx >> 7), bi(idx & 127) {}
        inline ref& flip() { p->m[wi] ^= (__int128(1) << bi); return *this; }
        // ReSharper disable once CppNonExplicitConversionOperator
        inline operator bool() const { return p->m[wi] & (__int128(1) << bi); } // NOLINT(*-explicit-constructor)
        inline ref& operator=(bool b) {
            if(b) p->m[wi] |= (__int128(1) << bi);
            else p->m[wi] &= ~(__int128(1) << bi);
            return *this;
        }
        inline ref& operator=(const ref& b) { operator=(static_cast<bool>(b)); return *this; }
    };
    Bitset() = default;
    explicit Bitset(size_t sz) : l(sz), wl((sz + 127) >> 7), m((sz + 127) >> 7, 0) { }
    explicit Bitset(size_t sz, __int128 value) : Bitset(sz) { m[0] = value; }
    static Bitset of(__int128 value) { return Bitset(128, value); }
    static Bitset of(unsigned __int128 value) { return Bitset(128, value); }
    static Bitset of(long long value) { return Bitset(64, value); }
    static Bitset of(unsigned long long value) { return Bitset(64, value); }
    static Bitset of(signed value) { return Bitset(32, value); }
    static Bitset of(unsigned value) { return Bitset(32, value); }
    Bitset& flip() { for(auto& i : m) i = ~i; return *this; }
    inline Bitset& flip(size_t pos) { m[pos >> 7] ^= __int128(1) << (pos & 127); return *this; }
    inline bool operator[](size_t i) const { return !!(m[i >> 7] & (__int128(1) << (i & 127))); }
    inline ref operator[](size_t i) { return ref(this, i); }

    inline void reset() {
        for(size_t i = 0; i < wl; i++) m[i] = 0;
    }

    bool any() const {
        for(const auto& i : m) if(i) return true;
        return false;
    }

    inline long long size() const { return l; }
    inline long long length() const { return l; }

    long long count() const {
        long long r = 0; using ull = unsigned long long;
        for(size_t i = 0; i < wl; i++)
            r += __builtin_popcountll(static_cast<ull>(m[i]))
                 + __builtin_popcountll(static_cast<ull>(m[i] >> 64));
        return r;
    }

#define bs_op_(o) \
    Bitset& operator o (const Bitset& v) { \
        size_t ml = std::min(wl, v.wl);           \
        for(size_t i = 0; i < ml; i++) m[i] o v.m[i]; \
        return *this; \
    }
    bs_op_(&=) bs_op_(|=) bs_op_(^=)
#define bs_op_2_(o) \
    inline Bitset operator o (const Bitset& v) const { \
        Bitset r = *this; r o##= v; return r; \
    }

    Bitset operator~() const { Bitset r(*this); r.flip(); return r; }

    Bitset& operator+=(const Bitset& v) {
        size_t ml = std::min(wl, v.wl);
        bool carry = false;
        for (size_t i = 0; i < ml; i++) {
            unsigned __int128 t;
            bool of = __builtin_add_overflow(m[i], v.m[i], &t);
            if (carry) of |= __builtin_add_overflow(t, 1, &t);
            m[i] = t; carry = of;
        }
        return *this;
    }

    Bitset& operator-=(const Bitset& v) {
        size_t ml = std::min(wl, v.wl);
        bool br = false;
        for (size_t i = 0; i < ml; i++) {
            unsigned __int128 t;
            bool of = __builtin_sub_overflow(m[i], v.m[i], &t);
            if (br) of |= __builtin_sub_overflow(t, 1, &t);
            m[i] = t; br = of;
        }
        return *this;
    }

    Bitset& operator<<=(long long shift) {
        if(shift < 0) {
            *this >>= -shift;
            return *this;
        }
        if (shift == 0) return *this;
        long long ws = shift >> 7, bs = shift & 127;
        if (ws >= static_cast<long long>(wl)) { std::fill(m.begin(), m.end(), 0); return *this; }
        for (long long i = wl - 1; i >= ws; --i) {
            m[i] = m[i - ws] << bs;
            if (i > ws && bs) m[i] |= m[i - ws - 1] >> (128 - bs);
        }
        std::fill_n(m.begin(), ws, 0);
        return *this;
    }

    Bitset& operator>>=(long long shift) {
        if(shift < 0) {
            *this <<= -shift;
            return *this;
        }
        if (shift == 0) return *this;
        long long ws = shift >> 7, bs = shift & 127;
        if (ws >= static_cast<long long>(wl)) { std::fill(m.begin(), m.end(), 0); return *this; }
        for (long long i = 0; i < static_cast<long long>(wl - ws); ++i) {
            m[i] = m[i + ws] >> bs;
            if (i + ws + 1 < static_cast<long long>(wl) && bs) m[i] |= m[i + ws + 1] << (128 - bs);
        }
        std::fill(m.end() - ws, m.end(), 0);
        return *this;
    }

    bs_op_2_(&) bs_op_2_(|) bs_op_2_(^) bs_op_2_(+) bs_op_2_(-)

    inline Bitset operator<<(size_t shift) const { Bitset r(*this); r <<= shift; return r; }
    inline Bitset operator>>(size_t shift) const { Bitset r(*this); r >>= shift; return r; }

    friend std::ostream& operator<<(std::ostream& out, const Bitset& v) {
        for(long long i=v.l-1; i>=0; i--) out << ((v.m[i >> 7] & (__int128(1) << (i & 127))) ? 1 : 0);
        return out;
    }

    std::string toDecimal() const { // GPT
        if (l == 0) return "0";
        std::vector<uint32_t> decimal; decimal.push_back(0);
        for (ssize_t i = l - 1; i >= 0; i--) {
            uint32_t carry = (*this)[i];
            for (unsigned int & j : decimal) {
                uint64_t cur = static_cast<uint64_t>(j) * 2 + carry;
                j = cur % 1000000000;
                carry = cur / 1000000000;
            }
            if (carry) decimal.push_back(carry);
        }
        std::string result = std::to_string(decimal.back());
        for (ssize_t i = decimal.size() - 2; i >= 0; i--) {
            std::string part = std::to_string(decimal[i]);
            result += std::string(9 - part.size(), '0') + part;
        }
        return result;
    }

    static Bitset fromDecimal(const std::string& s, long long sz = -1) { // GPT
        if (s == "0") return Bitset(1);
        std::vector<uint32_t> dec;
        int len = s.size(), firstDigits = len % 9;
        if (firstDigits == 0) firstDigits = 9;
        dec.push_back(std::stoul(s.substr(0, firstDigits)));
        for (int i = firstDigits; i < len; i += 9)
            dec.push_back(std::stoul(s.substr(i, 9)));
        std::vector<bool> bits;
        constexpr uint64_t base = 1000000000;
        while (!dec.empty()) {
            uint64_t carry = 0;
            for (unsigned int & i : dec) {
                uint64_t cur = carry * base + i;
                i = static_cast<uint32_t>(cur >> 1);
                carry = cur & 1;
            }
            bits.push_back(carry);
            while (!dec.empty() && dec[0] == 0) dec.erase(dec.begin());
        }
        Bitset result(sz == -1 ? bits.size() : sz);
        for (size_t i = 0; i < bits.size(); i++) result[i] = bits[i];
        return result;
    }
};

#pragma endregion

int main() {
    tcRep() {
        in64(n);
        vector<i64> arr(n);
        forn(i, n) get(arr[i]);
        sort(arr);
        i64 ans = 0, prv = -243879;
        for(int i : arr) {
            if(prv < i) ans++, prv = i;
        }
        ln(ans);
    }
}
