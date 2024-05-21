#define USE_INT128 false
#define GCC_OPTIMIZE_ENABLE false
#include <bits/stdc++.h>
#if GCC_OPTIMIZE_ENABLE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif
#define int long long
#define llmax 9223372036854775807
#define inf 3000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define filein freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/input.txt", "r", stdin)
#define fileout freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/output.txt", "w", stdout)
#define all(vec) (vec).begin(), (vec).end()

using namespace std;
template <typename T> using v = vector<T>;
template <typename T> using pq = priority_queue<T>;
using ii = array<int, 2>;
using iii = array<int, 3>;

template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(v.unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
int input() { int t=llmax; cin >> t; return t;}
template <typename T> void print(const T &i, const string& end="") { cout << i << end; }
#if USE_INT128
#define lint __int128
lint linput() { return (lint) input(); }
void print(const lint &i, const string& end="") { cout << (int)i << end;}
#endif
template <typename T> T temp() { T t; return t; }

// a

signed main()
{
    fastio;
    int tc = input();
    // 한 화면 3x5
    // .....
    // .....
    // .....
    for(int tci = 0; tci < tc; tci++) {
        int x, y; cin >> x >> y; //1x1, 2x2
        int yscreen = (y+1)/2;
        int guarx = yscreen*7;
        if(y%2) guarx += 4;
        x -= guarx;
        int xsc = x<=0 ? 0 : (x+14)/15;
        cout << yscreen + xsc << '\n';
    }
}
