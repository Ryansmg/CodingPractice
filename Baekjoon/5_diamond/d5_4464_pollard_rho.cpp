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

#define uint unsigned long long
class pollard_rho {
public:
    explicit pollard_rho() {
        base = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
        gen = mt19937(random_device()());
    }
    bool isPrime(lint n) {
        if(n<=1) return false;
        for(const lint &a: base) if (!_isPrime(n, a)) return false;
        return true;
    }
    lint factorize(const lint &n) {
        if (n % 2 == 0) return 2;
        if (isPrime(n)) return n;
        lint x = dis(gen) % (n - 2) + 2, y = x, c = dis(gen) % 10 + 1, g = 1;
        while (g == 1) {
            x = (x * x % n + c) % n;
            y = (y * y % n + c) % n;
            y = (y * y % n + c) % n;
            g = gcd(x - y > 0 ? x - y : y - x, n);
            if (g == n) return factorize(n);
        }
        if (isPrime(g)) return g;
        else return factorize(g);
    }
    static lint pow(lint a, lint b) {
        return pow(a, b, LINTMAX);
    }
    static lint pow(lint a, lint b, lint mod) {
        a %= mod;
        lint ans = 1;
        while (b) {
            if (b & 1) ans = ans * a % mod;
            b >>= 1;
            a = a * a % mod;
        }
        return ans;
    }
    static lint gcd(lint a, lint b) {
        if (a < b) swap(a, b);
        while (b != 0) {
            lint r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
private:
    v<lint> base;
    mt19937 gen;
    uniform_int_distribution<lint> dis;
    static bool _isPrime(lint n, lint a) {
        if (a % n == 0) return true;
        lint d = n - 1;
        while (true) {
            lint temp = pow(a, d, n);
            if (temp == n - 1) return true;
            if (d % 2 == 1) return (temp == 1 || temp == n - 1);
            d /= 2;
        }
    }
};

// 4464. Pride and Prejudice and Zombies
// #pollard_rho #miller_rabin

signed main() {
    fastio;
    pollard_rho pr;
    while(true) {
        int in = input();
        if(!in) break;
        cout << in << ": ";
        if(pr.isPrime(in)) { cout << "no\n"; continue; }
        string instr = to_string(in);
        uint len = instr.length();
        string sortStr = instr;
        sort(all(sortStr));
        if(len&1) { cout << "no\n"; continue; }
        v<int> arr; v<bool> bo;
        int a = in;
        while(a!=1) {
            int b = (int) pr.factorize(a);
            arr.push_back(b); a/=b;
        }
        
        set<int> fac; fac.insert(1);
        for(auto i : arr) {
            set<int> nxt = fac;
            for(auto j : fac) nxt.insert(i * j);
            fac = nxt;
        }
        
        for(int i : fac) {
            int j = in/i;
            string is = to_string(i), js = to_string(j);
            string s = is+js; sort(all(s));
            bool ichk, jchk; ichk=jchk=false;
            for(char c : is) {
                if(c!='0') ichk=false;
                else if(!ichk) ichk=true;
                else goto nxtdw;
            }
            for(char c : js) {
                if(c!='0') jchk=false;
                else if(!jchk) jchk=true;
                else goto nxtdw;
            }
            if(!(is.length()==len/2 && js.length()==len/2)) { continue; }
            if(s!=sortStr) { continue; }
            cout << "yes\n"; goto nxt;
            nxtdw:
            cout << "";
        }
        cout << "no\n";
        nxt:
        cout << "";
    }
}
