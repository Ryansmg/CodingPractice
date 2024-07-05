#pragma region macros
#define GCC_OPTIMIZE_ENABLE false

#include <bits/stdc++.h>
using namespace std;

#if GCC_OPTIMIZE_ENABLE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif

#define int long long
#define uint unsigned int;
#define double long double
#define cint const int &

const long long llmax = 9223372036854775807; // 2^63-1
const long long INF = 1000000000000000000; // INF * INF > 2^63
const long long inf = 3000000000; // inf > 2^31, inf * inf < 2^63
const signed smax = 2147483647;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(name, val) for(int name = 0; name < val; name++)
#define forf(name, start, end) for(int name = start; name <= end; name++)

#define pass {cout << "";} // do nothing
#ifndef ONLINE_JUDGE
#define filein freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/input.txt", "r", stdin)
#define fileout freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/output.txt", "w", stdout)
#else
#define filein cout << ""
#define fileout filein
#endif
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
const lint LINTMAX = ((lint(1)<<126)-1)*2+1;
__int128 operator ""_I(const char* str, size_t len) {
    __int128 t = 0; int st=0, sign=1; if(*str == '-') sign=-1, st=1;
    for(int i=st; i < len; i++) { t *= 10; t += (*(str + i) - '0'); }
    return t*sign;
}
istream &operator>>(istream &in, __int128 &l) {
    string s; in >> s; size_t len = s.size(); int sign = 1, st = 0; l=0;
    if(s[0]=='-') sign=-1, st=1; for(int i=st; i<len; i++) { l *= 10; l += s[i]-'0'; }
    l*=sign; return in;
}
ostream &operator<<(ostream &out,const __int128 &i) {
    __int128 t = i<0?-i:i; if(!t) out << 0; if(i<0) out << '-';
    stack<char> st; while(t) { st.push((char)((t%10)+'0')); t/=10; }
    while(!st.empty()){out<<st.top();st.pop();} return out;
}
#pragma endregion

template <typename T = int> T input() {T t; cin >> t; return t;}

#define all(vec) (vec).begin(), (vec).end()
template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }

template <typename T> T pow_(T a, T b) { return pow_(a, b, intmax); }
template <typename T> T pow_(T a, T b, T mod) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }
#pragma endregion

signed main() {
    filein; fileout;
    int a, b;
    while(cin>>a) {
        cin>>b;
        cout << b/(a+1) << '\n';
    }
}
