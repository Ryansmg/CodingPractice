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

lint snow[50000010];
signed main() {
    filein;
    int l, n, m, a, b, k, t; cin >> l >> n >> m;
    // 쿼리들을 저장하는 배열
    // [0] : 쿼리의 순서, [1] : 쿼리의 종류 (1 또는 2)
    // 쿼리 1인 경우 a, b, k / 쿼리 2인 경우 a, b, 주어진 순서(0~m-1)
    // (a, b는 압축되지 않은 값)
    vector<array<int, 5>> queries;
    // 쿼리 1 입력
    for(int i=1; i<=n; i++) {
        a = input(); b = input(); k = input();
        queries.push_back({i, 1, a, b, k});
    }
    // 쿼리 2 입력
    for(int i=1; i<=m; i++) {
        t = input(); a = input(); b = input();
        queries.push_back({t, 2, a, b, i-1});
    }
    sort(queries.begin(), queries.end());
    v<__float128> answer(m);
    int cnt = 0;
    for(const auto &q : queries) {
        cout << ++cnt << "/" << n+m << endl;
        if(q[1] == 1) {
            forf(qi, q[2], q[3]) snow[qi] += q[4];
        } else {
            lint sum = 0, wsum = 0;
            forf(q2, q[2], q[3]) {
                sum += snow[q2];
                wsum += snow[q2] * q2;
            }
            if(sum==0) answer[q[4]] = -1;
            else answer[q[4]] = abs((__float128)wsum / (__float128) sum - (q[2]+q[3])/2.0Q);
        }
    }
    fileout; fastio;
    cout.precision(8); cout << fixed;
    for(const __float128 &i : answer) cout << (double) i << '\n';
}
