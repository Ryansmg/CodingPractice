#pragma region macros
#include <bits/stdc++.h>
using namespace std;
using i32 = int; using i64 = long long; using i128 = __int128;
using f32 = float; using f64 = double;
#define ci64 const i64 &
#define ci32 const i32 &
const long long llmax =  9223372036854775807, INF = 1000000000000000000, inf = 3000000000;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define forn(i, a) for(i64 i=0; i<a; i++)
#define forf(a, b, c) for(i64 a = b; a <= c; a++)
#define all(vec) (vec).begin(), (vec).end()
template <class T> using v = vector<T>;
template <class T> using v2 = v<v<T>>;
using vl = v<i64>; using v2l = v2<i64>;
template <class T> using lim = std::numeric_limits<T>;
template <class T = i64> T input() { T t; cin >> t; return t; }
template <class T> void sort(T &v) { sort(all(v)); }
#pragma endregion

int main() {
    i64 n, h;
    cin >> n >> h;
    forn(i, n) {
        i64 a; cin >> a; h -= a;
        if(h<=0) {
            cout << i+1;
            exit(0);
        }
    }
    cout << -1;
}