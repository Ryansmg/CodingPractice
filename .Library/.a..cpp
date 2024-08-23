#pragma region macros

#include <bits/stdc++.h>

using namespace std;
using i16 = short;
using i32 = signed;
using i64 = long long;
using i128 = __int128;
using u16 = unsigned short;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
using f32 = float;
using f64 = double;
using f128 = long double;
#define ci64 const i64 &
#define ci32 const i32 &
const long long llmax = 9223372036854775807, INF = 1000000000000000000, inf = 3000000000;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(name, val) for(i64 name = 0; name < val; name++)
#define forf(name, start, end) for(i64 name = start; name <= end; name++)
#define all(vec) (vec).begin(), (vec).end()
template<typename T> using v = vector<T>;
template<typename T> using v2 = v<v<T>>;
using vl = v<i64>;
using v2l = v2<i64>;
template<typename T, typename T2=v<T>, typename T3=less<>> using pq = priority_queue<T, T2, T3>;
using ii = array<i64, 2>;
using iii = array<i64, 3>;
template<typename T> using lim = std::numeric_limits<T>;

template<typename T = i64>
T input() {
    T t;
    cin >> t;
    return t;
}
template<typename T>
T::value_type fpop(T &que) {
    auto t = que.front();
    que.pop();
    return t;
}
template<typename T>
T::value_type tpop(T &st) {
    auto t = st.top();
    st.pop();
    return t;
}
template<typename T>
void sort(v<T> &v) { sort(all(v)); }
template<typename T>
void compress(v<T> &v, const bool &autosort = true) {
    if (autosort) sort(all(v));
    v.erase(unique(all(v)), v.end());
}
template<typename T>
T idx(const T &val, const v<T> &compressed) {
    return lower_bound(all(compressed), val) - compressed.begin();
}
template<typename T>
T pow_(T a, T b, T mod = lim<T>::max()) {
    a %= mod;
    T ans = 1;
    while (b) {
        if (b & 1)ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
template<typename T>
T gcd_(T a, T b) {
    if (a < b) swap(a, b);
    while (b) {
        T r = a % b;
        a = b;
        b = r;
    }
    return a;
}
template<typename T>
v<T> inputArr(i64 sz) {
    v<T> a;
    forn(i, sz) a.push_back(input<T>());
    return a;
}
template<typename T>
void inputArr(v<T> &arr, i64 sz) { forn(i, sz) arr.push_back(input<T>()); }
#pragma endregion
using lint = i128;
namespace Euclid {
    i128 gcd(i128 x, i128 y) { return y ? gcd(y, x % y) : x; }
    i128 mod(i128 a, i128 b) { return ((a % b) + b) % b; }

    // returns g = gcd(a, b); finds x, y such that g = ax + by
    i128 ext_gcd(i128 a, i128 b, i128 &x, i128 &y) {
        i128 xx = y = 0;
        i128 yy = x = 1;
        while (b) {
            i128 q = a / b;
            i128 t = b; b = a % b; a = t;
            t = xx; xx = x - q * xx; x = t;
            t = yy; yy = y - q * yy; y = t;
        }
        return a;
    }

    // computes b such that ab = 1 (mod n), returns -1 on failure
    i128 mod_inverse(i128 a, i128 n) {
        i128 x, y;
        i128 g = ext_gcd(a, n, x, y);
        if (g > 1) return -1;
        return mod(x, n);
    }

    // Chinese remainder theorem: find z such that
    // z % m1 = r1, z % m2 = r2. Here, z is unique modulo M = lcm(m1, m2).
    // Return (z, M). On failure, M =-1.
    pair<i128, i128> CRT(i128 m1, i128 r1, i128 m2, i128 r2) {
        i128 s, t;
        i128 g = ext_gcd(m1, m2, s, t);
        if (r1 % g != r2 % g) return make_pair(0, -1);
        s = mod(s * r2, m2);
        t = mod(t * r1, m1);
        return make_pair(mod(s * (m1 / g) + t * (m2 / g), m1 * (m2 / g)), m1 * (m2 / g));
    }
}