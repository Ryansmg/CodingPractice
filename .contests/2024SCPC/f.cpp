#define USE_MACROS true
#define USE_INT128 false
#define GCC_OPTIMIZE_ENABLE false
#pragma region macros
#if USE_MACROS
#include <bits/stdc++.h>
#if GCC_OPTIMIZE_ENABLE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif
#define int long long
#define llmax 9223372036854775807
#define INF 1000000000000000000
#define inf 3000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define filein freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/input.txt", "r", stdin)
#define fileout freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/output.txt", "w", stdout)
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
int input() { int t=llmax; cin >> t; return t;}
template <typename T> void print(const T &i, const string& end="") { cout << i << end; }
template <typename T> T pow_(T a, T b) { return pow_(a, b, llmax); }
template <typename T> T pow_(T a, T b, T mod) { a %= mod; T ans = 1; while(b) { if(b&1) ans = ans * a % mod; b >>= 1; a = a * a % mod; } return ans; }
template <typename T> T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }
#if USE_INT128
#define lint __int128
lint linput() { return (lint) input(); }
void print(const lint &i, const string& end="") { cout << (int)i << end;}
#endif
#endif
#pragma endregion

// f
// #tags

signed main() {
    int n, m;
    cin >> n >> m;
    v2<int> con(n+2, v<int>());
    v<array<int, 4>> edges; // 출발노드, 도착노드, 가중치, 이용여부
    forn(i, m) edges.push_back({input(), input(), input(), 0});

    //dijkstra
}
