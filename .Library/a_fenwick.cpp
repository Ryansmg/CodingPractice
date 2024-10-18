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

class fenwick {
public:
    v<int> tree; int n;
    explicit fenwick(int treeSize) {
        n = treeSize;
        tree = v<int>(treeSize+10, 0);
    }
    fenwick(const v<int>& arr, int treeSize) : fenwick(treeSize){
        forn(i, n) update(i+1, arr[i]);
    }
    void update(int tar, cint val) {
        assert(tar>0);
        while(tar < n) {
            tree[tar] += val; tar += (tar & -tar);
        }
    }
    void update(cint left, cint right, cint val) {
        if(rq) { cout << "\nCannot use range_update and range_query at the same time.\n"; assert(false); }
        ru = true;
        assert(0<left && left<=right);
        update(left, val); update(right+1, -val);
    }
    int query(int left, int right) {
        if(ru) { cout << "\nCannot use range_update and range_query at the same time.\n"; assert(false); }
        rq = true;
        assert(0<left && left<=right);
        if(left==1) return query(right);
        return query(right) - query(left-1);
    }
    int query(int tar) {
        int ans = 0;
        while(tar > 0) {
            ans += tree[tar]; tar -= (tar & -tar);
        }
        return ans;
    }
private:
    bool ru = false, rq = false;
};
struct Fenwick {
    v<int> tree; int n;
    explicit Fenwick(int treeSize) { n = treeSize; tree = v<int>(treeSize+10, 0); }
    void update(int tar, cint val) { assert(tar>0); while(tar < n) tree[tar] += val, tar += (tar & -tar); }
    int query(int left, int right) { assert(0<left && left<=right); if(left==1) return query(right); return query(right) - query(left-1); }
    int query(int tar) { int ans = 0; while(tar > 0) ans += tree[tar], tar -= (tar & -tar);  return ans; }
};

/*
2d fenwick
int tree[5050][5050];

void update(int x, int y, int v){
    for(x++; x<5050; x+=x&-x) for(int yy=y+1; yy<5050; yy+=yy&-yy) tree[x][yy] += v;
}
int query(int x, int y){
    int ret = 0;
    for(x++; x; x-=x&-x) for(int yy=y+1; yy; yy-=yy&-yy) ret += tree[x][yy];
    return ret;
}

 */

signed main() {

}
