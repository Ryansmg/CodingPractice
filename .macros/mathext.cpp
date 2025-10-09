#pragma region
#include <bits/stdc++.h>

using std::cin, std::cout, std::cerr, std::clog, std::endl, std::istream, std::ostream, std::ifstream, std::ofstream;
using std::stringstream, std::istringstream, std::ostringstream;
using std::array, std::list, std::tuple, std::get, std::tie, std::initializer_list, std::bitset, std::ssize, std::span, std::string;
using std::complex, std::polar, std::popcount;
using std::max, std::min, std::gcd, std::lcm, std::swap, std::abs, std::sin, std::cos, std::tan, std::asin;
using std::acos, std::atan, std::floor, std::ceil, std::round, std::sinh, std::cosh, std::tanh, std::atan2, std::sqrt;
using std::less, std::greater, std::less_equal, std::greater_equal;
using std::iota, std::prev_permutation, std::next_permutation;
using std::is_integral_v, std::is_convertible_v, std::is_arithmetic_v, std::is_floating_point_v, std::is_same_v;

template <typename T = long long, typename Cmp = std::less<>> using set = std::set<T, Cmp>;
template <typename Key = long long, typename Value = long long, typename Cmp = std::less<>> using map = std::map<Key, Value, Cmp>;
template <typename T = long long, typename Cmp = std::less<>> using multiset = std::multiset<T, Cmp>;
template <typename Key = long long, typename Value = long long, typename Cmp = std::less<>> using multimap = std::multimap<Key, Value, Cmp>;
template <typename T = long long> using stack = std::stack<T, std::vector<T>>;
template <typename T = long long> using queue = std::queue<T, std::list<T>>;
template <typename T = long long> using deque = std::deque<T>;
template <typename T1 = long long, typename T2 = long long> using pair = std::pair<T1, T2>;

template <typename T = long long, typename Compare = std::less<>> using pq = std::priority_queue<T, std::vector<T>, Compare>;
template <typename T = long long, typename T2 = long long> using umap = std::unordered_map<T, T2>;
template <typename T = long long, typename T2 = long long> using ummap = std::unordered_multimap<T, T2>;
template <typename T = long long> using uset = std::unordered_set<T>;
template <typename T = long long> using umset = std::unordered_multiset<T>;
template <typename T = long long> using vector = std::vector<T>;

#define all(v_) (v_).begin(), (v_).end()
#define pb push_back
#define eb emplace_back

#define forn(name_, val_) for(long long name_ = 0; name_ < (val_); name_++)
#define forf(name_, start_, end_) for(long long name_ = (start_); name_ <= (end_); name_++)
#define forr(name_, start_, end_) for(long long name_ = (start_); name_ >= (end_); name_--)
/// foreach reverse
#define forer(...) for(__VA_ARGS__ | std::views::reverse)

#define CONCAT_INNER_(x, y) x##y
#define CONCAT_(x, y) CONCAT_INNER_(x, y)
#define repeat_(n, i) for(long long i = 0; i < n; i++)
#define rep(n) repeat_(n, CONCAT_(rep_var_, __COUNTER__))

long long iR_v_, iR_v2_, iR_v5_;
#define inRep() std::cin >> iR_v_; forn(iR_v3_, iR_v_)
#define inRep2() std::cin >> iR_v2_; forn(iR_v4_, iR_v2_)
#define tcRep() std::cin >> iR_v5_; forf(TCN, 1, iR_v5_)

template <typename T> inline T pow_(T a, T b, T mod) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T modInv(T a, const T& m, bool chkGcd = true) { // by @kuhyaku
    T b = m, u = 1, v = 0; if(chkGcd) assert(std::gcd(a, m) == 1);
    while (b) { T t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }
    u %= m; if (u < 0) {u += m;} return u;
}
inline long long pow(long long a, long long b, long long mod) {return pow_(b < 0 ? modInv(a, mod) : a, std::abs(b), mod);}
inline long long pow(long long a, long long b) { long long ans=1;while(b){if(b&1)ans=ans*a;b>>=1;a=a*a;} return ans; }
template <typename T> requires (!is_same_v<T, long long> && !is_convertible_v<T, long long>)
inline T pow(T a, long long b) { if(!b){return a/a;} b--; T ans=a; while(b){if(b&1)ans=ans*a;b>>=1;a=a*a;} return ans; }
template <typename T, typename T2> requires (!is_same_v<T, long long> && !is_convertible_v<T, long long>)
inline T pow(T a, long long b, T2 mod) { if(!b){return a/a;} b--; T ans=a; while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> inline T pow(T a, T b) { T ans=1;while(b){if(b&1)ans=ans*a;b>>=1;a=a*a;} return ans; }

template <typename T> inline T gcd_(T a, T b) { if(a < b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }
template <typename T> inline T max(const std::vector<T>& v_) {
    T ret = v_.empty() ? std::numeric_limits<T>::min() : v_[0]; for(const T &t_ : v_) { ret = std::max(ret, t_); } return ret;
}
template <typename T> inline T min(const std::vector<T>& v_) {
    T ret = v_.empty() ? std::numeric_limits<T>::max() : v_[0]; for(const T &t_ : v_) { ret = std::min(ret, t_); } return ret;
}
inline long long max(long long a, long long b) { return a > b ? a : b; } inline long long min(long long a, long long b) { return a < b ? a : b; }
template <typename T> inline T lcm_(const T& a, const T& b) { return a / gcd_(a, b) * b; } template <typename T> inline T sq_(const T& i) { return i * i; }
template <typename T> inline T sum(const std::vector<T>& v_) { T s_ = T(); {for(const T& i_ : v_) s_ += i_;} return s_; }
template <typename T> inline T gcd(const std::initializer_list<T>& l_) { auto iter = l_.begin(); T ret = *iter; long long sz_ = l_.size();
    for(long long i_ = 1; i_ <= sz_-1; i_++) { ret = std::gcd(ret, *(++iter)); } return ret; }
template <typename T> inline T lcm(const std::initializer_list<T>& l_) { auto iter = l_.begin(); T ret = *iter / gcd(l_); long long sz_ = l_.size();
    for(long long i_ = 1; i_ <= sz_-1; i_++) { ret *= *(++iter); } return ret; }

namespace pRho {
    template <typename T> inline T pw_(T a, T b, T mod) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
    std::vector<__int128>base={2,3,5,7,11,13,17,19,23,29,31,37,41};std::mt19937 gen=std::mt19937(std::random_device()());std::uniform_int_distribution<long long>dis;
    bool _isPrime(__int128 n,__int128 a){if(a%n==0){return true;}__int128 d=n-1;while(true){__int128 t=pRho::pw_(a,d,n);if(t==n-1){return true;}
            if(d%2==1){return(t==1||t==n-1);}d/= 2;}}
    template <typename T> inline T gcd(T a,T b){if(a<b)swap(a,b);while(b){T r=a%b;a=b;b=r;}return a;}
}
bool isPrime(long long n){if(n<=1)return false;for(const __int128&a:pRho::base){if(!pRho::_isPrime(n, a))return false;}return true;}
long long factorize(long long n){assert(n>=2);if(n%2==0){return 2;}if(isPrime(n)){return n;}__int128 x=pRho::dis(pRho::gen)%(n-2)+2,y=x,
            c=pRho::dis(pRho::gen)%10+1,g=1;while(g==1){x=(x*x%n+c)%n;y=(y*y%n+c)%n;y=(y*y%n+c)%n;g=pRho::gcd(x-y>0?x-y:y-x,(__int128)n);
        if(g==n)return factorize(n);}if(isPrime((long long)g)){return (long long)g;} return factorize((long long)g);}
std::vector<long long> getPrimes(long long n) { std::vector<long long> r; while(n != 1) { long long p = factorize(n); r.emplace_back(p); n /= p; } return r; }

inline signed popcount(long long v) { return std::popcount((unsigned long long) v); }
inline auto clz(long long v) { return __builtin_clzll(v); } /// count leading zeros (000010 => 4)
inline signed lmb(long long v) { return 63 - clz(v); } /// left most bit (000100 => 2)

std::random_device mrdvce_; std::mt19937 m1gn_(mrdvce_());
std::uniform_int_distribution<long long> uni3i64_(0, 9223372036854775807);
#define rand rand_
inline long long randl() { return uni3i64_(m1gn_); }
inline long long rand_(long long l_, long long r_) { return randl() % (r_ - l_ + 1) + l_; } /// inclusive
inline long long rand_(long long n_) { return rand_(0, n_-1); }

template <typename Iter> void shuffle(Iter first, Iter last) {
    if (first == last) return;
    for (Iter i = first + 1; i != last; ++i)
        std::iter_swap(i, first + rand(int(i - first) + 1));
}
template <typename T> void shuffle(T& arr) { shuffle(arr.begin(), arr.end()); }

#pragma endregion

template <const long long mod = 1000000007>
struct ModInt {
    long long v = 0;
    ModInt() = default;
    // ReSharper disable once CppNonExplicitConvertingConstructor
    inline ModInt(long long val) : v(val % mod) { // NOLINT(*-explicit-constructor)
        if(v < 0) v += mod;
    }
    template <typename T> inline explicit operator T() requires std::is_integral_v<T> { return v; }
    inline ModInt& operator=(const ModInt& b) = default;
    inline ModInt operator-() const { return { -v }; }
    inline ModInt& operator++() { v = (v + 1) % mod; return *this; }
    inline ModInt operator++(signed) { ModInt ret = *this; v = (v + 1) % mod; return ret; }
    inline ModInt& operator--() { v = (v - 1 + mod) % mod; return *this; }
    inline ModInt operator--(signed) { ModInt ret = *this; v = (v - 1 + mod) % mod; return ret; }
    inline ModInt operator+(const ModInt& b) const { ModInt ret = *this; ret += b.v; return ret; }
    inline ModInt operator-(const ModInt& b) const { ModInt ret = *this; ret -= b.v; return ret; }
    inline ModInt operator*(const ModInt& b) const { return { v * b.v % mod }; }

    inline ModInt& operator+=(const ModInt& b) {
        v += b.v;
        if(v >= mod) v -= mod;
        return *this;
    }

    inline ModInt& operator+=(const ModInt&& b) {
        v += b.v;
        if(v >= mod) v -= mod;
        return *this;
    }

    inline ModInt& operator-=(const ModInt& b) {
        v -= b.v;
        if(v < 0) v += mod;
        return *this;
    }

    inline ModInt& operator-=(const ModInt&& b) {
        v -= b.v;
        if(v < 0) v += mod;
        return *this;
    }

    inline ModInt& operator*=(const ModInt& b) { v = v * b.v % mod; return *this; }
    inline friend std::istream& operator>>(std::istream& in, ModInt& t) {
        in >> t.v; t.v = t.v % mod;
        if(t.v < 0) t.v += mod;
        return in;
    }
    inline friend std::ostream& operator<<(std::ostream& out, const ModInt& t) { out << t.v; return out; }
    inline friend ModInt operator+(long long a, const ModInt& b) { a = (a % mod + mod) % mod; return {(b.v + a) % mod}; }
    inline friend ModInt operator-(long long a, const ModInt& b) { a = (a % mod + mod) % mod; return {(b.v - a + mod) % mod}; }
    inline friend ModInt operator*(long long a, const ModInt& b) { a = (a % mod + mod) % mod; return {(b.v * a) % mod}; }
};

class BigInt {
    constexpr static int BASE_DIGITS = 9;
    constexpr static int BASE = 1000000000;

    int sign;
    vector<int> a;

public:
    BigInt() : sign(1) {}

    explicit BigInt(long long v) : sign(1) { *this = v; }

    BigInt& operator=(long long v) {
        sign = 1;
        if (v < 0) { sign = -1; v = -v; }
        a.clear();
        for (; v > 0; v = v / BASE)
            a.push_back(v % BASE);
        return *this;
    }

    explicit BigInt(const string &s) : sign(1) { read(s); }

    explicit operator long long() const { // NOLINT(*-explicit-constructor)
        assert(*this <= BigInt(9223372036854775807));
        assert(BigInt(-9223372036854775807) <= *this);
        long long ret = 0, b = 1;
        for(long long i : a) ret += i * b, b *= BASE;
        return sign * ret;
    }

    void read(const string &s) {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int)s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for (int i = s.size() - 1; i >= pos; i -= BASE_DIGITS) {
            int x = 0;
            for (int j = max(pos, i - BASE_DIGITS + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }

    friend istream &operator>>(istream &stream, BigInt &v) {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }

    friend ostream &operator<<(ostream &stream, const BigInt &v) {
        if (v.sign == -1 && !v.isZero())
            stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int)v.a.size() - 2; i >= 0; --i)
            stream << std::setw(BASE_DIGITS) << std::setfill('0') << v.a[i];
        return stream;
    }

    explicit operator std::string() const {
        std::ostringstream stream;
        stream << *this;
        return stream.str();
    }

    bool operator<(const BigInt &v) const {
        if (sign != v.sign)
            return sign < v.sign;
        if (a.size() != v.a.size())
            return a.size() * sign < v.a.size() * v.sign;
        for (int i = int(a.size()) - 1; i >= 0; i--)
            if (a[i] != v.a[i])
                return a[i] * sign < v.a[i] * sign;
        return false;
    }

    bool operator>(const BigInt &v) const { return v < *this; }
    bool operator<=(const BigInt &v) const { return !(v < *this); }
    bool operator>=(const BigInt &v) const { return !(*this < v); }
    bool operator==(const BigInt &v) const {
        if(v.isZero()) return isZero();
        return !(*this < v) && !(v < *this);
    }
    bool operator!=(const BigInt &v) const { return *this < v || v < *this; }

    // Returns 0 if |x| == |y|, -1 if |x| < |y|, 1 if |x| > |y|
    friend int compare_abs(const BigInt &x, const BigInt &y) {
        if (x.a.size() != y.a.size())
            return x.a.size() < y.a.size() ? -1 : 1;

        for (int i = int(x.a.size()) - 1; i >= 0; --i) {
            if (x.a[i] != y.a[i])
                return x.a[i] < y.a[i] ? -1 : 1;
        }
        return 0;
    }

    BigInt operator-() const {
        BigInt res = *this;
        if (isZero())
            return res;

        res.sign = -sign;
        return res;
    }

    BigInt operator+() const {
        return *this;
    }

private:
    void internal_add(const BigInt &v) {
        if (a.size() < v.a.size()) {
            a.resize(v.a.size(), 0);
        }
        for (int i = 0, carry = 0; i < (int)max(a.size(), v.a.size()) || carry; ++i) {
            if (i == (int)a.size())
                a.push_back(0);

            a[i] += carry + (i < (int)v.a.size() ? v.a[i] : 0);
            carry = a[i] >= BASE;
            if (carry)
                a[i] -= BASE;
        }
    }

    void internal_sub(const BigInt &v) {
        for (int i = 0, carry = 0; i < (int)v.a.size() || carry; ++i) {
            a[i] -= carry + (i < (int)v.a.size() ? v.a[i] : 0);
            carry = a[i] < 0;
            if (carry) a[i] += BASE;
        }
        this->trim();
    }

public:
    BigInt& operator+=(const BigInt &v) {
        if (sign == v.sign) {
            internal_add(v);
        } else {
            if (compare_abs(*this, v) >= 0) {
                internal_sub(v);
            } else {
                BigInt vv = v;
                swap(*this, vv);
                internal_sub(vv);
            }
        }
        return *this;
    }

    BigInt& operator-=(const BigInt &v) {
        if (sign == v.sign) {
            if (compare_abs(*this, v) >= 0) {
                internal_sub(v);
            } else {
                BigInt vv = v;
                swap(*this, vv);
                internal_sub(vv);
                this->sign = -this->sign;
            }
        } else {
            internal_add(v);
        }
        return *this;
    }

    template <typename L, typename R>
    std::enable_if_t<std::is_convertible_v<L, BigInt> && std::is_convertible_v<R, BigInt> && std::is_lvalue_reference_v<R &&>, BigInt>
    friend operator+(L &&l, R &&r) {
        BigInt result(std::forward<L>(l));
        result += r;
        return result;
    }
    template <typename L, typename R>
    std::enable_if_t<std::is_convertible_v<L, BigInt> && std::is_convertible_v<R, BigInt> && std::is_rvalue_reference_v<R &&>, BigInt>
    friend operator+(L &&l, R &&r) {
        BigInt result(std::forward<R>(r));
        result += l;
        return result;
    }

    template <typename L, typename R>
    std::enable_if_t<std::is_convertible_v<L, BigInt> && std::is_convertible_v<R, BigInt>, BigInt>
    friend operator-(L &&l, R &&r) {
        BigInt result(std::forward<L>(l));
        result -= r;
        return result;
    }

    friend pair<BigInt, BigInt> divmod(const BigInt &a1, const BigInt &b1) {
        // assert(b1 > 0); // divmod not well-defined for b < 0.
        if(b1 < BigInt(0)) {
            auto [c, d] = divmod(-a1, -b1);
            return std::make_pair(c, -d);
        }

        long long norm = BASE / (b1.a.back() + 1);
        BigInt A = a1.abs() * BigInt(norm);
        BigInt B = b1.abs() * BigInt(norm);
        BigInt q = BigInt(0), r = BigInt(0);
        q.a.resize(A.a.size());

        for (int i = A.a.size() - 1; i >= 0; i--) {
            r *= BASE;
            r += BigInt(A.a[i]);
            long long s1 = r.a.size() <= B.a.size() ? 0 : r.a[B.a.size()];
            long long s2 = r.a.size() <= B.a.size() - 1 ? 0 : r.a[B.a.size() - 1];
            long long d = ((long long)BASE * s1 + s2) / B.a.back();
            r -= B * BigInt(d);
            while (r < BigInt(0)) {
                r += B, --d;
            }
            q.a[i] = d;
        }

        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim(); r.trim();
        auto res = std::make_pair(q, r / norm);
        if (res.second < BigInt(0))
            res.second += b1;
        return res;
    }
    BigInt operator/(const BigInt &v) const { return divmod(*this, v).first; }

    BigInt operator%(const BigInt &v) const { return divmod(*this, v).second; }

    BigInt& operator%=(const BigInt& v) { return *this = *this % v; }

    BigInt& operator/=(int v) {
        // assert(v > 0); // operator / not well-defined for v <= 0.
        if (llabs(v) >= BASE) {
            *this /= BigInt(v);
            return *this;
        }
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = (int)a.size() - 1, rem = 0; i >= 0; --i) {
            long long cur = a[i] + rem * (long long)BASE;
            a[i] = (int)(cur / v);
            rem = (int)(cur % v);
        }
        trim();
        return *this;
    }

    BigInt operator/(int v) const {
        // assert(v > 0); // operator / not well-defined for v <= 0.

        if (llabs(v) >= BASE) {
            return *this / BigInt(v);
        }
        BigInt res = *this;
        res /= v;
        return res;
    }
    BigInt& operator/=(const BigInt &v) { *this = *this / v; return *this; }

    long long operator%(long long v) const {
        // assert(v > 0); // operator / not well-defined for v <= 0.
        assert(v < BASE);
        int m = 0;
        for (int i = a.size() - 1; i >= 0; --i)
            m = (a[i] + m * (long long)BASE) % v;
        return m * sign;
    }

    BigInt& operator*=(int v) {
        if (llabs(v) >= BASE) {
            *this *= BigInt(v);
            return *this;
        }
        if (v < 0) sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < (int)a.size() || carry; ++i) {
            if (i == (int)a.size())
                a.push_back(0);
            long long cur = a[i] * (long long)v + carry;
            carry = (int)(cur / BASE);
            a[i] = (int)(cur % BASE);
        }
        trim();
        return *this;
    }

    BigInt operator*(int v) const {
        if (llabs(v) >= BASE) {
            return *this * BigInt(v);
        }
        BigInt res = *this;
        res *= v;
        return res;
    }
private:
    // Convert BASE 10^old --> 10^new.
    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int)p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int i : a) {
            cur += i * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back(cur % p[new_digits]);
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int)cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }

    using base = complex<double>;
    static void fft(vector<base> &a, bool inv) {
        int n = a.size(), j = 0;
        vector<base> roots(n / 2);
        for (int i = 1; i < n; i++) {
            int bit = n >> 1;
            while (j >= bit) {
                j -= bit;
                bit >>= 1;
            }
            j += bit;
            if (i < j)
                swap(a[i], a[j]);
        }
        double ang = 2 * acos(double(-1)) / n * (inv ? -1 : 1);
        for (int i = 0; i < n / 2; i++) {
            roots[i] = base(cos(ang * i), sin(ang * i));
        }
        for (int i = 2; i <= n; i <<= 1) {
            int step = n / i;
            for (int l = 0; l < n; l += i) {
                for (int k = 0; k < i / 2; k++) {
                    base u = a[l + k], v = a[l + k + i / 2] * roots[step * k];
                    a[l + k] = u + v;
                    a[l + k + i / 2] = u - v;
                }
            }
        }
        if (inv)
            for (int i = 0; i < n; i++)
                a[i] /= n;
    }

    static void multiply_fft(const vector<int> &a, const vector<int> &b, vector<int> &res) {
        vector<complex<double>> fa(a.begin(), a.end());
        vector<complex<double>> fb(b.begin(), b.end());
        int n = 1;
        while (n < (int)max(a.size(), b.size()))
            n <<= 1;
        n <<= 1;
        fa.resize(n);
        fb.resize(n);

        fft(fa, false);
        fft(fb, false);
        for (int i = 0; i < n; ++i)
            fa[i] *= fb[i];
        fft(fa, true);

        res.resize(n);
        long long carry = 0;
        for (int i = 0; i < n; ++i) {
            long long t = lround(fa[i].real()) + carry;
            carry = t / 1000;
            res[i] = t % 1000;
        }
    }

    BigInt mul_simple(const BigInt &v) const {
        BigInt res;
        res.sign = sign * v.sign;
        res.a.resize(a.size() + v.a.size());
        for (int i = 0; i < (int)a.size(); ++i)
            if (a[i])
                for (int j = 0, carry = 0; j < (int)v.a.size() || carry; ++j) {
                    long long cur = res.a[i + j] + (long long)a[i] * (j < (int)v.a.size() ? v.a[j] : 0) + carry;
                    carry = (int)(cur / BASE);
                    res.a[i + j] = (int)(cur % BASE);
                }
        res.trim();
        return res;
    }

    typedef vector<long long> vll;

    static vll karatsubaMultiply(const vll &a, const vll &b) {
        int n = a.size();
        vll res(n + n);
        if (n <= 32) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }

        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());

        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);

        for (int i = 0; i < k; i++) a2[i] += a1[i];
        for (int i = 0; i < k; i++) b2[i] += b1[i];

        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int)a1b1.size(); i++) r[i] -= a1b1[i];
        for (int i = 0; i < (int)a2b2.size(); i++) r[i] -= a2b2[i];

        for (int i = 0; i < (int)r.size(); i++) res[i + k] += r[i];
        for (int i = 0; i < (int)a1b1.size(); i++) res[i] += a1b1[i];
        for (int i = 0; i < (int)a2b2.size(); i++) res[i + n] += a2b2[i];
        return res;
    }

    BigInt mul_karatsuba(const BigInt &v) const {
        vector<int> a6 = convert_base(this->a, BASE_DIGITS, 6);
        vector<int> b6 = convert_base(v.a, BASE_DIGITS, 6);
        vll A(a6.begin(), a6.end());
        vll B(b6.begin(), b6.end());
        while (A.size() < B.size()) A.push_back(0);
        while (B.size() < A.size()) B.push_back(0);
        while (A.size() & (A.size() - 1)) A.push_back(0), B.push_back(0);
        vll c = karatsubaMultiply(A, B);
        BigInt res;
        res.sign = sign * v.sign;
        long long carry = 0;
        for (long long i : c) {
            long long cur = i + carry;
            res.a.push_back((int)(cur % 1000000));
            carry = cur / 1000000;
        }
        res.a = convert_base(res.a, 6, BASE_DIGITS);
        res.trim();
        return res;
    }

    BigInt mul_fft(const BigInt &v) const {
        BigInt res;
        res.sign = sign * v.sign;
        multiply_fft(convert_base(a, BASE_DIGITS, 3), convert_base(v.a, BASE_DIGITS, 3), res.a);
        res.a = convert_base(res.a, 3, BASE_DIGITS);
        res.trim();
        return res;
    }

public:
    BigInt& operator*=(const BigInt &v) { *this = *this * v; return *this; }
    BigInt operator*(const BigInt &v) const {
        if (a.size() < 32 || v.a.size() < 32)
            return mul_simple(v);
        if (a.size() > 100111 || v.a.size() > 100111)
            return mul_fft(v);
        return mul_karatsuba(v);
    }

    BigInt abs() const {
        BigInt res = *this;
        res.sign *= res.sign;
        return res;
    }
    friend BigInt abs(const BigInt& A) { return A.abs(); }

    void trim() {
        while (!a.empty() && !a.back())
            a.pop_back();
        if (a.empty()) sign = 1;
    }

    bool isZero() const { return a.empty() || (a.size() == 1 && !a[0]); }

    friend BigInt gcd(const BigInt &A, const BigInt &B) { return B.isZero() ? A : gcd(B, A % B); }
    friend BigInt lcm(const BigInt &A, const BigInt &b) { return A / gcd(A, b) * b; }

    friend BigInt sqrt(const BigInt &a1) {
        BigInt A = a1;
        while (A.a.empty() || A.a.size() % 2 == 1)
            A.a.push_back(0);

        int n = A.a.size();

        int firstDigit = (int)sqrt((double)A.a[n - 1] * BASE + A.a[n - 2]);
        int norm = BASE / (firstDigit + 1);
        A *= norm; A *= norm;
        while (A.a.empty() || A.a.size() % 2 == 1)
            A.a.push_back(0);

        BigInt r = BigInt((long long)A.a[n - 1] * BASE + A.a[n - 2]);
        firstDigit = (int)sqrt((double)A.a[n - 1] * BASE + A.a[n - 2]);
        int q = firstDigit;
        BigInt res;

        for (int j = n / 2 - 1; j >= 0; j--) {
            for (;; --q) {
                BigInt r1 = (r - (res * 2 * BigInt(BASE) + BigInt(q)) * q) * BigInt(BASE) * BigInt(BASE) + BigInt(j > 0 ? (long long)A.a[2 * j - 1] * BASE + A.a[2 * j - 2] : 0);
                if (r1 >= BigInt(0)) {
                    r = r1; break;
                }
            }
            res *= BASE;
            res += BigInt(q);

            if (j > 0) {
                int d1 = res.a.size() + 2 < r.a.size() ? r.a[res.a.size() + 2] : 0;
                int d2 = res.a.size() + 1 < r.a.size() ? r.a[res.a.size() + 1] : 0;
                int d3 = res.a.size() < r.a.size() ? r.a[res.a.size()] : 0;
                q = ((long long)d1 * BASE * BASE + (long long)d2 * BASE + d3) / (firstDigit * 2);
            }
        }

        res.trim();
        return res / norm;
    }
};

template <int precision = 32>
class BigDecimal {
    BigInt data; BigInt div;
public:
    template <int a, int b>
    struct greater { constexpr static int value = a > b ? a : b; };
    template <int a, int b>
    static constexpr int greater_v = greater<a, b>::value;

    void setData(const BigInt& data_) { data = data_; }

    BigDecimal() : data(0), div(pow(BigInt(10), precision)) { }

    BigDecimal(const BigDecimal& bd) = default;

    explicit BigDecimal(long double d) : data(0), div(pow(BigInt(10), precision)) {
        data = (long long) d;
        data *= div;
        d -= (long long) d;
        string s;
        for(int i = 0; i < precision; i++)
            d *= 10, s += char('0' + (long long) d), d -= (long long) d;
        data += BigInt(s);
    }

    template <int other_precision>
    BigDecimal<other_precision> convert_precision() const {
        if constexpr(other_precision == precision) {
            // assert(false); // should not be used in class (remove later)
        }
        if constexpr(other_precision >= precision) {
            BigInt nData = data;
            nData *= pow(BigInt(10), other_precision - precision);
            BigDecimal<other_precision> ret; ret.setData(nData);
            return ret;
        }
        // assert(false); // should not be used in class (remove later)
        BigInt nData = data + BigInt(5) * pow(BigInt(10), precision - other_precision - 1);
        nData /= pow(BigInt(10), precision - other_precision);
        BigDecimal<other_precision> ret; ret.setData(nData);
        return ret;
    }

    explicit BigDecimal(const std::string &s) : data(0), div(pow(BigInt(10), precision)) { read(s); }
    void read(const std::string &s) {
        int dotCount = 0, dotPos = -1;
        for(int i = 0; i < int(s.size()); i++) {
            if(s[i] == '.') {
                dotCount++;
                dotPos = i;
            }
        }
        assert(dotCount <= 1);
        if(!dotCount) {
            data.read(s);
            data *= div;
            return;
        }
        string first = dotPos ? s.substr(0, dotPos) : "0";
        string second = dotPos != int(s.size()) - 1 ? s.substr(dotPos + 1) : "0";
        while(second.size() > precision) second.pop_back();
        while(second.size() < precision) second.push_back('0');
        data.read(first);
        data *= div;
        data += BigInt(second);
    }

    explicit operator std::string() const {
        string s(data);
        bool flag = false;
        if(s[0] == '-') {
            flag = true;
            s.erase(s.begin());
        }
        if(s.size() < precision + 1) {
            s = string(precision + 1 - s.size(), '0') + s;
        }
        int sz = int(s.size());
        string first = s.substr(0, sz - precision);
        string second = s.substr(sz - precision);
        first.push_back('.');
        first.append(second);
        if(flag) return "-" + first;
        return first;
    }

    explicit operator BigInt() const {
        return data / div;
    }

    friend istream& operator>>(istream& in, BigDecimal& b) {
        string s; in >> s;
        b.read(s); return in;
    }
    friend ostream& operator<<(ostream& out, const BigDecimal& b) {
        out << std::string(b);
        return out;
    }

    // arithmetic operators
    template <int o>
    BigDecimal& operator+=(const BigDecimal<o>& a) {
        if constexpr(precision == o) {
            data += a.data;
            return *this;
        }
        data += a.template convert_precision<precision>().data;
        return *this;
    }

    template <int o>
    BigDecimal<greater_v<precision, o>> operator+(const BigDecimal<o>& a) const {
        if constexpr(precision >= o) {
            BigDecimal<greater_v<precision, o>> ret = *this;
            ret += a; return ret;
        }
        BigDecimal<greater_v<precision, o>> ret = a;
        ret += *this; return ret;
    }

    template <int o>
    BigDecimal& operator-=(const BigDecimal<o>& a) {
        if constexpr(precision == o) {
            data -= a.data;
            return *this;
        }
        data -= a.template convert_precision<precision>().data;
        return *this;
    }

    template <int o>
    BigDecimal<greater_v<precision, o>> operator-(const BigDecimal<o>& a) const {
        if constexpr(precision >= o) {
            BigDecimal<greater_v<precision, o>> ret = *this;
            ret -= a;
            return ret;
        }
        BigDecimal<greater_v<precision, o>> ret = a;
        ret -= *this;
        return ret;
    }

    template <int o>
    BigDecimal& operator*=(const BigDecimal<o>& a) {
        data *= a.data;
        data /= a.div;
        return *this;
    }

    template <int o>
    BigDecimal& operator/=(const BigDecimal<o>& a) {
        data *= a.div;
        data /= a.data;
        return *this;
    }

    template <int o>
    BigDecimal operator*(const BigDecimal<o>& a) const {
        if constexpr(precision >= o) {
            BigDecimal ret = *this;
            ret *= a;
            return ret;
        }
        BigDecimal<o> ret = a;
        ret *= *this;
        return ret;
    }

    template <int o>
    BigDecimal operator/(const BigDecimal<o>& a) const {
        if constexpr(precision >= o) {
            BigDecimal ret = *this;
            ret /= a;
            return ret;
        }
        BigDecimal<o> ret = a;
        ret /= *this;
        return ret;
    }

    template <int o>
    bool operator==(const BigDecimal<o>& a) const {
        if constexpr(precision == o) {
            return data == a.data;
        }
        if constexpr(precision > o)
            return data == a.template convert_precision<precision>().data;
        return a.data == convert_precision<o>().data;
    }


    template <int o>
    auto operator<=>(const BigDecimal<o>& a) const {
        if constexpr(precision == o) {
            return data <=> a.data;
        }
        if constexpr(precision > o)
            return data <=> a.template convert_precision<precision>().data;
        return a.data <=> convert_precision<o>().data;
    }

    friend BigDecimal floor(const BigDecimal& a) {
        BigDecimal ret = a;
        ret.data = ret.data / ret.div * ret.div;
        return ret;
    }

    friend BigDecimal ceil(const BigDecimal& a) {
        BigDecimal k("1");
        k.data -= BigInt(1);
        k += a;
        return floor(k);
    }

    friend BigDecimal round(const BigDecimal& a) {
        BigDecimal ret = a;
        ret += BigDecimal("0.5");
        return floor(ret);
    }
};

template <typename T>
class Frac {
    inline void reduction() {
        if(denominator < T(0)) numerator *= -1, denominator *= -1;
        T g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
    }
    inline void checkDivZ() const { if(denominator == T(0)) { std::cerr << "Cannot divide by zero!\n"; exit(1); } }
    inline void checkDivZ(const Frac& a) const { checkDivZ(); a.checkDivZ(); }
public:
    T numerator = T(0); // 분자
    T denominator = T(1); // 분모 (항상 >= 0, 0인 경우 abs(분자) == 1)
    Frac() = default;
    explicit Frac(T i) : numerator(std::move(i)), denominator(1) {}
    Frac(T Numerator, T Denominator) : numerator(std::move(Numerator)), denominator(std::move(Denominator)) {
        if(denominator < T(0)) numerator *= -1, denominator *= -1;
        reduction();
    }
    explicit operator bool() const { return numerator != T(0); }
    template <typename T2> requires (!is_same_v<T2, bool>)
    explicit operator T2() { return static_cast<T2>(numerator) / static_cast<T2>(denominator); }
    inline Frac& operator+=(const Frac& b) { checkDivZ(b);
        T l = lcm(denominator, b.denominator);
        numerator *= l / denominator; numerator += b.numerator * (l / b.denominator);
        denominator = l; reduction(); return *this;
    }
    inline Frac& operator+=(const T& i) { checkDivZ(); numerator += i * denominator; return *this; }
    inline Frac operator+(const Frac& b) const { checkDivZ(b); Frac ret = *this; ret += b; return ret; }
    inline Frac operator+(const T& i) const { checkDivZ(); Frac ret = *this; ret += i; return ret; }
    inline Frac& operator-=(const Frac& b) {checkDivZ(b);
        T l = lcm(denominator, b.denominator);
        numerator *= l / denominator; numerator -= b.numerator * (l / b.denominator);
        denominator = l; reduction(); return *this;
    }
    inline Frac& operator-=(const T& i) { checkDivZ(); numerator -= i * denominator; return *this; }
    inline Frac operator-(const Frac& b) const { checkDivZ(b);  Frac ret = *this; ret -= b; return ret; }
    inline Frac operator-(const T& i) const { checkDivZ(); Frac ret = *this; ret -= i; return ret; }
    inline Frac& operator*=(const Frac& b) { checkDivZ(b);
        numerator *= b.numerator; denominator *= b.denominator;
        reduction(); return *this;
    }
    inline Frac& operator*=(const T& i) { checkDivZ(); numerator *= i; reduction(); return *this; }
    inline Frac operator*(const Frac& b) const { checkDivZ(b); Frac ret = *this; ret *= b; return ret; }
    inline Frac operator*(const T& i) const { checkDivZ(); Frac ret = *this; ret *= i; return ret; }
    inline Frac& operator/=(const Frac& b) { checkDivZ(b);
        assert(b.numerator != T(0)); // cannot divide by 0
        numerator *= b.denominator; denominator *= b.numerator;
        reduction(); return *this;
    }
    inline Frac& operator/=(const T& i) { checkDivZ();
        assert(i != T(0)); // cannot divide by 0
        denominator *= i; reduction(); return *this;
    }
    inline Frac operator/(const Frac& b) const { checkDivZ(b); Frac ret = *this; ret /= b; return ret; }
    inline Frac operator/(const T& i) const { checkDivZ(); Frac ret = *this; ret /= i; return ret; }
    inline bool operator==(const Frac& b) const { return numerator == b.numerator && denominator == b.denominator; }
    inline bool operator!=(const Frac& b) const { return numerator != b.numerator || denominator != b.denominator; }
    inline bool operator<(const Frac& b) const {
        if(!denominator && !b.denominator) return numerator < b.numerator;
        return numerator * b.denominator < b.numerator * denominator;
    }
    inline bool operator<=(const Frac& b) const {
        if(!denominator && !b.denominator) return numerator <= b.numerator;
        return numerator * b.denominator <= b.numerator * denominator;
    }
    inline bool operator>(const Frac& b) const {
        if(!denominator && !b.denominator) return numerator > b.numerator;
        return numerator * b.denominator > b.numerator * denominator;
    }
    inline bool operator>=(const Frac& b) const {
        if(!denominator && !b.denominator) return numerator >= b.numerator;
        return numerator * b.denominator >= b.numerator * denominator;
    }

    inline bool operator==(const T& b) const { return numerator == b && denominator == 1; }
    inline bool operator!=(const T& b) const { return numerator != b || denominator != 1; }
    inline bool operator<(const T& b) const { return !denominator ? numerator < 0 : numerator < b * denominator; }
    inline bool operator<=(const T& b) const { return denominator && numerator <= b * denominator; }
    inline bool operator>(const T& b) const { return !denominator ? numerator > 0 : numerator > b * denominator; }
    inline bool operator>=(const T& b) const { return denominator && numerator >= b * denominator; }
    friend inline Frac operator+(const T& a, const Frac& b) { Frac ret(a); ret += b; return ret; }
    friend inline Frac operator-(const T& a, const Frac& b) { Frac ret(a); ret -= b; return ret; }
    friend inline Frac operator*(const T& a, const Frac& b) { Frac ret(a); ret *= b; return ret; }
    friend inline Frac operator/(const T& a, const Frac& b) { Frac ret(a); ret /= b; return ret; }
    friend inline bool operator==(const T &a, const Frac& b) { return b.numerator == a && b.denominator == 1; }
    friend inline bool operator!=(const T &a, const Frac& b) { return b.numerator != a || b.denominator != 1; }
    friend inline bool operator<(const T &a, const Frac& b) { return !b.denominator ? 0 < b.numerator : a * b.denominator < b.numerator; }
    friend inline bool operator<=(const T &a, const Frac& b) { return b.denominator && a * b.denominator <= b.numerator; }
    friend inline bool operator>(const T &a, const Frac& b) { return !b.denominator ? 0 > b.numerator : a * b.denominator > b.numerator; }
    friend inline bool operator>=(const T &a, const Frac& b) { return b.denominator && a * b.denominator >= b.numerator; }

    friend ostream& operator<<(ostream& out, const Frac& b) {
        if(b.denominator == T(1)) out << b.numerator;
        else out << b.numerator << "/" << b.denominator;
        return out;
    }

    friend istream& operator>>(istream& in, Frac& b) {
        string s; in >> s;

        int slash_idx = -1;
        for(int i = 0; i < int(s.size()); i++) {
            if(s[i] == '/') {
                slash_idx = i; break;
            }
        }

        if(slash_idx == -1) {
            istringstream stream(s);
            T t; stream >> t;
            b = Frac(t);
            return in;
        }

        string f = s.substr(0, slash_idx);
        string g = s.substr(slash_idx + 1);
        T num, den;
        istringstream(f) >> num;
        istringstream(g) >> den;
        b = Frac(num, den);
        return in;
    }
};

template <typename T>
struct Matrix {
    signed r = 0, c = 0;
    std::vector<std::vector<T>> m;
    Matrix() = default;
    Matrix(signed row, signed column, T value) : r(row), c(column), m(row, std::vector<T>(column, value)) {}
    explicit Matrix(std::vector<std::vector<T>> arr) : r(arr.size()), c(arr.empty() ? 0 : arr[0].size()), m(std::move(arr)) {}
    inline auto& operator[](signed index) { return m[index]; }
    inline const auto& operator[](signed index) const { return m[index]; }

    Matrix& operator+=(const Matrix& other) {
        assert(r == other.r && c == other.c);
        for(signed i = 0; i < r; i++)
            for(signed j = 0; j < c; j++)
                m[r][c] += other[r][c];
        return *this;
    }

    Matrix operator+(const Matrix& other) const {
        Matrix ret = *this;
        ret += other;
        return ret;
    }

    Matrix& operator-=(const Matrix& other) {
        assert(r == other.r && c == other.c);
        for(signed i = 0; i < r; i++)
            for(signed j = 0; j < c; j++)
                m[r][c] -= other[r][c];
        return *this;
    }

    Matrix operator-(const Matrix& other) const {
        Matrix ret = *this;
        ret -= other;
        return ret;
    }

    Matrix operator-() const {
        Matrix ret = *this;
        for(signed i = 0; i < r; i++)
            for(signed j = 0; j < c; j++)
                ret.m[r][c] = -ret.m[r][c];
        return ret;
    }

    Matrix operator*(const Matrix& other) const {
        assert(c == other.r);
        Matrix ret(r, other.c, T());
        for(signed lr = 0; lr < r; lr++)
            // ReSharper disable once CppDFANotInitializedField
            for(signed rc = 0; rc < other.c; rc++)
                for(signed i = 0; i < c; i++)
                    ret[lr][rc] += m[lr][i] * other[i][rc];
        return ret;
    }
    Matrix& operator*=(const Matrix& other) { return *this = *this * other; }

    Matrix& operator*=(const T& val) {
        for(signed i = 0; i < r; i++)
            for(signed j = 0; j < c; j++)
                m[i][j] *= val;
        return *this;
    }

    Matrix operator*(const T& val) const {
        Matrix ret = *this; ret *= val; return ret;
    }

    Matrix& naive_mul(const Matrix& other) {
        assert(r == other.r && c == other.c);
        for(signed i = 0; i < r; i++)
            for(signed j = 0; j < c; j++)
                m[i][j] *= other.m[i][j];
        return *this;
    }

    friend Matrix naive_mul(const Matrix& a, const Matrix& b) {
        auto ret = a;
        ret *= b;
        return ret;
    }

    Matrix& operator/=(const T& val) {
        for(signed i = 0; i < r; i++)
            for(signed j = 0; j < c; j++)
                m[i][j] /= val;
        return *this;
    }

    Matrix operator/(const T& val) const {
        Matrix ret = *this; ret /= val; return ret;
    }


    Matrix& operator/=(const Matrix& other) {
        assert(r == other.r && c == other.c);
        for(signed i = 0; i < r; i++)
            for(signed j = 0; j < c; j++)
                m[r][c] /= other[r][c];
        return *this;
    }

    Matrix operator/(const Matrix& other) const {
        Matrix ret = *this;
        ret /= other;
        return ret;
    }

    Matrix& operator%=(const T& val) {
        for(signed i = 0; i < r; i++)
            for(signed j = 0; j < c; j++)
                m[i][j] %= val;
        return *this;
    }

    Matrix operator%(const T& val) const {
        Matrix ret = *this; ret %= val; return ret;
    }

    friend istream& operator>>(istream& in, Matrix& mat) {
        for(signed i = 0; i < mat.r; i++)
            for(signed j = 0; j < mat.c; j++)
                in >> mat.m[i][j];
        return in;
    }

    friend ostream& operator<<(ostream& out, const Matrix& mat) {
        for(signed i = 0; i < mat.r; i++) {
            for(signed j = 0; j < mat.c; j++)
                out << mat.m[i][j] << ' ';
            if(i < mat.r - 1) out << '\n';
        }
        return out;
    }

    struct Row {
        std::vector<std::vector<T>>* p;
        int index;
        auto begin() { return (*p)[index].begin(); }
        auto end() { return (*p)[index].end(); }
        void operator+=(const T& val) { for(T& i : (*p)[index]) i += val; }
        void operator-=(const T& val) { for(T& i : (*p)[index]) i -= val; }
        void operator*=(const T& val) { for(T& i : (*p)[index]) i *= val; }
        void operator/=(const T& val) {
            for(T& i : (*p)[index]) i /= val;
        }
        void operator%=(const T& val) { for(T& i : (*p)[index]) i %= val; }

        void operator+=(const Row& R) {
            for(int i = 0; i < int((*p)[0].size()); i++)
                (*p)[index][i] += (*R->p)[R.index][i];
        }

        void operator-=(const Row& R) {
            for(int i = 0; i < int((*p)[0].size()); i++)
                (*p)[index][i] -= (*R->p)[R.index][i];
        }
        std::vector<T>& operator*() { return (*p)[index]; }
    };

    struct Col {
        std::vector<std::vector<T>>* p;
        int index;
        void operator+=(const T& val) { for(int i = 0; i < p->size(); i++) (*p)[i][index] += val; }
        void operator-=(const T& val) { for(int i = 0; i < p->size(); i++) (*p)[i][index] -= val; }
        void operator*=(const T& val) { for(int i = 0; i < p->size(); i++) (*p)[i][index] *= val; }
        void operator/=(const T& val) { for(int i = 0; i < p->size(); i++) (*p)[i][index] /= val; }
        void operator%=(const T& val) { for(int i = 0; i < p->size(); i++) (*p)[i][index] %= val; }
        struct iter {
            std::vector<std::vector<T>>* p;
            int R, C;
            T& operator*() { return p[R][C]; }
            const T& operator*() const { return p[R][C]; }
            iter operator++() const { return {p, R+1, C}; }
            iter operator--() const { return {p, R-1, C}; }
            iter& operator++(int) { return *this = operator++(); }
            iter& operator--(int) { return *this = operator--(); }
            auto operator<=>(const iter& b) const { return R <=> b.R; }
            bool operator==(const iter& b) const { return R == b.R; }
        };
        iter begin() { return {p, 0, index}; }
        iter end() { return {p, p->size(), index}; }

        struct col_vec_ref {
            Col* p;
            friend void swap(col_vec_ref a, col_vec_ref b) {
                int ai = a.p->index, bi = b.p->index;
                for(int i = 0; i < int(a.p->p->size()); i++) {
                    std::swap((*a.p->p)[i][ai], (*a.p->p)[i][bi]);
                }
            }
        };
        col_vec_ref operator*() { return {this}; }
    };

    template <typename T2>
    Row row(T2 index) { return Row(&m, (long long) index); }

    template <typename T2>
    Col col(T2 index) { return Col(&m, (long long) index); }

    Matrix RREF() const {
        Matrix ret = *this;
        int cnt = 0;
        for(int i = 0; i < c && cnt < r; i++) {
            int select = -1;
            for(int j = cnt; j < r; j++) {
                if(ret[j][i] != T(0)) {
                    select = j;
                    break;
                }
            }
            if(select == -1) continue;
            std::swap(ret[cnt], ret[select]);
            T temp = ret[cnt][i];
            ret.row(cnt) /= temp; ret[cnt][i] = T(1);
            for(int j = 0; j < r; j++) {
                if(j == cnt) continue;
                T t = ret[j][i];
                if(t == T(0)) continue;
                for(int k = i; k < c; k++) {
                    ret[j][k] -= t * ret[cnt][k];
                }
                ret[j][i] = T(0);
            }
            cnt++;
        }
        return ret;
    }

    struct Block {
        Matrix* p = nullptr;
        int sr = 0, er = 0, sc = 0, ec = 0;
        static Block whole(Matrix* ptr) { return {ptr, 0, ptr->r - 1, 0, ptr->c - 1}; }
    };

    T cofactor(int row, int col) const {
        vector<vector<T>> nxt;
        forn(i, r) {
            if(i == row) continue;
            nxt.emplace_back();
            forn(j, c) {
                if(j == col) continue;
                nxt.back().push_back(m[i][j]);
            }
        }
        if((row + col) % 2) return Matrix(nxt).determinant() * T(-1);
        return Matrix(nxt).determinant();
    }

    T determinant() const {
        assert(r == c);
        if(r == 1) return m[0][0];
        T res = T(0);
        forn(i, c) res += cofactor(0, i) * m[0][i];
        return res;
    }

    Matrix transpose() const {
        vector<vector<T>> nxt(c, vector<T>(r));
        forn(i, r) forn(j, c) nxt[j][i] = m[i][j];
        return Matrix(nxt);
    }

    Matrix adjoint() const {
        assert(r == c);
        vector<vector<T>> res(r, vector<T>(r));
        forn(i, r) forn(j, c) res[i][j] = cofactor(i, j);
        return Matrix(res).transpose();
    }

    Matrix inverse() const {
        return inverse_with_existence().first;
    }

    pair<Matrix, bool> inverse_with_existence() const {
        assert(r == c);
        vector<vector<T>> nxt(r, vector<T>(r * 2));
        forn(i, r) forn(j, c) nxt[i][j] = m[i][j];
        forn(i, r) nxt[i][i + c] = T(1);
        Matrix R = Matrix(nxt).RREF();
        forn(i, r) forn(j, c) {
            if(i == j && R[i][j] != T(1)) return std::make_pair(Matrix(), false);
            if(i != j && R[i][j] != T(0)) return std::make_pair(Matrix(), false);
        }
        vector<vector<T>> res(r, vector<T>(r));
        forn(i, r) forn(j, c) res[i][j] = R[i][j + c];
        return std::make_pair(Matrix(res), true);
    }
};

using i64 = long long;
using f64 = long double;

signed main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cout << Matrix(vector<vector<f64>>{
        {2, 1, -4},
        {-4, -1, 6},
        {-2, 2, -2}
    }).inverse();
}
