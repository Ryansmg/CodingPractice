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

using namespace std;
template <typename T> using v = vector<T>;
template <typename T> using pq = priority_queue<T>;
using ii = array<int, 2>;
using iii = array<int, 3>;

template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
template <typename T> T input() {T t; cin >> t; return t;}
int input() { int t=llmax; cin >> t; return t;}
template <typename T> void print(const T &i, const string& end="") { cout << i << end; }
#if USE_INT128
#define lint __int128
lint linput() { return (lint) input(); }
void print(const lint &i, const string& end="") { cout << (int)i << end;}
#endif
template <typename T> T temp() { T t; return t; }
#endif
#pragma endregion

// 11049. 행렬 곱셈 순서
// #dp
// 범위 dp 대표 문제
// http://boj.kr/11049

signed main()
{
    fastio;
    int n = input();
    v<ii> arr;
    for(int i=0; i<n; i++)
        arr.push_back({input(), input()});
    v<int> temp(n,inf);
    v<v<int>> dp(n, temp);
    for(int i=0; i<n-1; i++) {
        dp[i][i] = 0;
        dp[i][i + 1] = arr[i][0] * arr[i][1] * arr[i + 1][1];
    }
    dp[n-1][n-1]=0;

    for(int len=2; len<n; len++)
        for(int i=0; i+len<n; i++)
            for(int l = 0; l < len; l++)
                dp[i][i+len] = min(dp[i][i+len],
                                   dp[i][i+l] + dp[i+l+1][i+len] + arr[i][0] * arr[i+l][1] * arr[i+len][1]);

    cout << dp[0][n-1];
}
