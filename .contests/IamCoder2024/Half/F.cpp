#pragma region macros
#include <bits/stdc++.h>
using namespace std;
using i32 = int; using i64 = long long; using i128 = __int128;
using u32 = unsigned; using u64 = unsigned long long;
using f32 = float; using f64 = double; using f128 = __float128;
#define ci64 const i64 &
#define ci32 const i32 &
const long long llmax =  9223372036854775807, INF = 1000000000000000000, inf = 3000000000;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(i, a) for(i64 i=0; i<a; i++)
#define forf(a, b, c) for(i64 a = b; a <= c; a++)
#define all(vec) (vec).begin(), (vec).end()
template <class T> using v = vector<T>;
template <class T> using v2 = v<v<T>>;
using vl = v<i64>; using v2l = v2<i64>;
template <class T, class T2, class T3> using pq = priority_queue<T, T2, T3>;
template <class T> using lim = std::numeric_limits<T>;
template <class T = i64> T input() { T t; cin >> t; return t; }
template <class T> typename T::value_type fpop(T &que) {
    auto t = que.front(); que.pop(); return t;
}
template <class T> typename T::value_type tpop(T &st) {
    auto t = st.top(); st.pop(); return t;
}
template <class T> void compress(v<T> &v, const bool &autosort=true) {
    if(autosort) sort(v); v.erase(unique(all(v)), v.end());
}
template <class T> T idx(const T &val, const v<T> &compressed) {
    return lower_bound(all(compressed), val) - compressed.begin();
}
template <typename T> void inputArr(v<T> &arr, i64 sz) {
    arr.clear(); forn(i, sz) arr.emplace_back(input<T>());
}
template <typename T> void println(T a) {
    cout << a << '\n';
}
#pragma endregion

struct lecture {
    i64 s, e, i;
    lecture(i64 l, i64 r, i64 I) : s(l), e(r), i(I) {}
    bool operator<(const lecture &other) const {
        if(other.e != e) return e < other.e;
        return s < other.s;
    }
};

i32 main() {
    i64 n, m; cin >> n >> m;
    v<lecture> ls;
    forn(i, n) {
        i64 a, b; cin >> a >> b;
        ls.emplace_back(a, b, i);
    }
    i64 maxs = -1, li = 0;
    for(auto l = ls.begin(); l != ls.end(); l++, li++) {
        if(l->s <= maxs) continue;
        auto l2 = l; i64 l2i = li;
        while(l2 != ls.begin())
            if(l2->e >= l->s) { l2--; l2i--; }

    }
}