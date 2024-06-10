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

// b
// #tags

bool cmp(const iii &a, const iii &b) {
    return a[0]<b[0];
}

signed main() {
    int n, m, k;
    cin >> n >> m >> k;
    v<bool> infected(n+1, false);
    v<int> infects;
    forn(i, k) {
        int t = input();
        infected[t] = true;
        infects.push_back(t);
    }
    v<iii> logs;
    int time = INF, answer = -1;
    forn(i, m) logs.push_back({input(), input(), input()});
    sort(all(logs), cmp);
    for(int i : infects) {
        cout << "i: " << i << endl;
        v<bool> curinf(n+1);
        int t = 0;
        while(true) {
            fill(all(curinf), false);
            curinf[i] = true;
            while (logs[t][1] != i && t < m) t++;
            if(t>=m) break;
            bool g = false;
            cout << "t: " << t << endl;
            for (int j = t; j < m; j++) {
                iii log = logs[j];
                if (curinf[log[1]] && !curinf[log[2]] && infected[log[2]]) {
                    cout << log[1] << "->" << log[2] << endl;
                    curinf[log[2]] = true;
                } else if (curinf[log[1]] && !curinf[log[2]] && !infected[log[2]]) {
                    cout << log[1] << "-\\>" << log[2] << endl;
                    t++;
                    g = true; break;
                }
            }
            if(g) continue;
            break;
        }
        bool ans = t<m;
        for(int j : infects)
            if(!curinf[j]) ans = false;
        cout << "ans: " << ans << endl;
        if(ans) {
            assert(answer == -1);
            if(time > t) {
                time = t;
                answer = i;
            }
        }
    }
    cout << answer;
}
