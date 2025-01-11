#pragma region macros
#include <bits/stdc++.h>
using namespace std;
using i32 = int; using i64 = long long; using i128 = __int128;
using f32 = float; using f64 = double;
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
template <class T> void sort(T &v) { sort(all(v)); }
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

int main() {
    fastio;
    i64 h, n, q;
    cin >> h >> n >> q;
    vl d; inputArr(d, n);
    sort(all(d), greater<>());
    i64 ans = 0; i64 temp = 0;
    pq<i64, vl, greater<>> pq;
    while(h > 0 && temp < n) { h -= d[temp]; ans++; pq.push(d[temp++]); }
    println(h > 0 ? -1 : ans);
    forn(asdf, q) {
        i64 x = input();
        if(h > 0) {
            pq.push(x); h -= x; ans++;
            println(h > 0 ? -1 : ans);
            continue;
        }
        if(pq.top() >= x) { println(ans); continue; }
        pq.push(x); h -= x; ans++;
        while(h + pq.top() <= 0) {
            h += tpop(pq); ans--;
        }
        println(ans);
    }
}
