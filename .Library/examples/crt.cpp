#pragma region macros
#define GCC_OPTIMIZE_ENABLE false

#include <bits/stdc++.h>
using namespace std;

#if GCC_OPTIMIZE_ENABLE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif

#define int long long
#define double long double
#define cint const int &

#define llmax 9223372036854775807 // 2^63-1
#define INF 1000000000000000000 // INF * INF > 2^63
#define inf 3000000000 // inf > 2^31, inf * inf < 2^63
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(name, val) for(int name = 0; name < val; name++)
#define forf(name, start, end) for(int name = start; name <= end; name++)

#define pass {cout << "";} // do nothing
#define filein freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/input.txt", "r", stdin)
#define fileout freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/output.txt", "w", stdout)

template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
template <typename T> using pq = priority_queue<T>;
using ii = array<int, 2>;
using iii = array<int, 3>;

#ifndef int
#define intmax 2147483647
#else
#define intmax llmax
#endif

#pragma region lint
#define lint __int128
#define ll long long
lint LINTMAX = ((lint(1)<<126)-1)*2+1;
string lint2str(const lint &i) {string ret,bs;if(i==-LINTMAX-1)return lint2str(i/10)+"8";if(!i)return "0";if(i<0)return "-"+lint2str(-i);
	lint t=1; forn(as, 18)t*=10;lint a=i/(t*t);if(a){ret += to_string((ll) a);bs = to_string((ll) (i / t % (t * 10) + t));
		forn(j, 18) ret += bs[j + 1];bs = to_string((ll) ((i % t) + t));forn(j, 18) ret += bs[j + 1];
	} else {lint b = i / t % (t * 10);if (b) {ret += to_string((ll) b);bs = to_string((ll) ((i % t) + t));
			forn(j, 18) ret += bs[j + 1];} else { ret += to_string((ll) (i % t)); }}return ret;}
istream &operator>>(istream &in, lint &l) {string s;in>>s;lint t=l=0,size=s.size(),k=1;if(s[0]=='-')t=1;
	for(lint i=size-1;i>=t;i--){if(!t)l+=(s[i]-'0')*k;else l-=(s[i]-'0')*k;k*=10;}return in;}
ostream &operator<<(ostream &out,const lint &i){ out << lint2str(i); return out; }
#pragma endregion

template <typename T = int> T input() {T t; cin >> t; return t;}

#define all(vec) (vec).begin(), (vec).end()
template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }

template <typename T> T pow_(T a, T b) { return pow_(a, b, intmax); }
template <typename T> T pow_(T a, T b, T mod) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }
#pragma endregion

// 14858. GCD 테이블과 연속 부분 수열
// #crt

lint lcm_(lint a, lint b) {
    return a / gcd_(a, b) * b;
}

pair<lint, pair<lint, lint>> choi(lint a, lint b) {
    if (b == 0) return {a, {1, 0}};
    pair<lint, pair<lint, lint>> ret = choi(b, a % b);
    lint g, x, y;
    g = ret.first;
    tie(x, y) = ret.second;
    return {g, {y, x - (a / b) * y}};
}
#define NO_ {cout << "NO"; return 0;}
#define YES_ {cout << "YES"; return 0;}
pair<lint, lint> CRT(v<lint> &A, v<lint> &B) {
    if (A.size() != B.size()) return {-1, -1};

    lint a1 = A[0], m1 = B[0];

    for (lint i = 1; i < A.size(); i++) {
        lint a2 = A[i], m2 = B[i];
        a2 %= m2;
        lint g = gcd(m1, m2);
        if (a1 % g != a2 % g) {
            cout << "NO";
            exit(0);
        }

        lint p, q;
        auto res = choi(m1 / g, m2 / g);
        tie(p, q) = res.second;

        lint mod = m1 / g * m2;
        a1 = (a1 * (m2 / g) % mod) * q % mod + (a2 * (m1 / g) % mod) * p % mod;
        a1 = (a1 + mod) % mod;
        m1 = mod;
    }

    return { a1, m1 };
}


signed main() {
    lint n, m, k; cin >> n >> m >> k;
    lint l = 1;
    v<lint> arr, arr2;
    forn(i, k) arr.push_back(input());
    forn(i, k) arr2.push_back((-i-1-((-i-1)/arr[i]*arr[i])+arr[i])%arr[i]);
    forn(i, k) {
        l = lcm_(l, arr[i]);
        if(l>n) NO_
    }
    auto p = CRT(arr2, arr);
    if(p.first+k > m || p.first <= -1) NO_
    forn(i, k) if(gcd_(p.second, p.first+i+1) != arr[i]) NO_
    YES_
}
