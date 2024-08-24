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

i64 n;
vl par, // 부모 노드
maxdep, // 서브트리 최대 깊이
maxdepn, // 서브트리 최대 깊이 << 이어지는 노드 번호
uplen, // 부모 노드 쪽으로 갈 수 있는 최대 길이
maxdep2, // 서브트리 2번째 최대 깊이
sublen, // 서브트리의 지름
ans; // 정답
v2l child;

void dfs(i64 v = 1, i64 dep = 1) {
    maxdep[v] = maxdep2[v] = dep; maxdepn[v] = v;
    for(ci64 c : child[v]) {
        dfs(c, dep + 1);
        sublen[v] = max(sublen[c], sublen[v]);
        if(maxdep[v] < maxdep[c]) {
            maxdep2[v] = maxdep[v];
            maxdep[v] = maxdep[c];
            maxdepn[v] = c;
        } else if(maxdep2[v] < maxdep[c]) {
            maxdep2[v] = maxdep[c];
        }
    }
    sublen[v] = max(sublen[v], maxdep[v] - dep + maxdep2[v] - dep);
}

void solve(i64 v = 1, i64 dep = 1) {
    for(ci64 c : child[v]) {
        i64 md = maxdepn[v] == c ? maxdep2[v] : maxdep[v];
        uplen[c] = max(uplen[v]+1, md-dep+1);
        solve(c, dep + 1);
        ans[c] = max(ans[c], uplen[c] + sublen[c]);
    }
}

i32 main() {
    fastio;
    cin >> n;
    par.resize(n+1);
    sublen.resize(n+1, 0);
    maxdep.resize(n+1, -INF);
    maxdepn.resize(n+1);
    uplen.resize(n+1, 0);
    maxdep2.resize(n+1, -INF);
    child.resize(n+1, vl());
    forf(i, 2, n) child[par[i] = input()].emplace_back(i);
    dfs();
    ans.resize(n+1, sublen[1]);
    solve();
    forf(i, 2, n) cout << ans[i] << '\n';
}
