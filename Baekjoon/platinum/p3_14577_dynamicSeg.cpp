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
template <typename T = int> T input() {T t; cin >> t; return t;}

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

#define all(vec) (vec).begin(), (vec).end()
template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }

template <typename T> T pow_(T a, T b) { return pow_(a, b, intmax); }
template <typename T> T pow_(T a, T b, T mod) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }
#pragma endregion

class pnd { // pointer_based_node
public:
    pnd *l = nullptr, *r = nullptr;
    int val = 0;
    pnd()=default;
    ~pnd(){ delete l; delete r; }
};
class dynamicSeg {
public:
    explicit dynamicSeg(int treeSize) : dynamicSeg() { n = treeSize; }
    ~dynamicSeg() { delete root; }
    void update(cint tar, cint val) {
        assert(tar>0);
        update(root, 1, n, tar, val);
    }
    int query(const int &left, const int &right) {
        assert(left <= right && left > 0);
        return query(root, 1, n, left, right);
    }
    int qidx(cint tar) {
        return qidx(root, 1, n, tar);
    }
private:
    explicit dynamicSeg() { root = new pnd(); }
    pnd *root; int n = -1;
    void update(pnd *node, int start, int end, cint tar, cint val) {
        if(tar < start || end < tar) return;
        if(start==end) {
            node->val += val; return;
        }
        if(tar <= (start+end)/2) {
            if (!node->l) node->l = new pnd();
            update(node->l, start, (start + end) / 2, tar, val);
        } else {
            if (!node->r) node->r = new pnd();
            update(node->r, (start + end) / 2 + 1, end, tar, val);
        }
        int lv = node->l ? node->l->val : 0;
        int rv = node->r ? node->r->val : 0;
        node->val = lv + rv;
    }
    int query(pnd *node, int start, int end, cint left, cint right) {
        if(!node) return 0;
        if(right < start || end < left) return 0;
        if(left <= start && end <= right) return node->val;
        return query(node->l, start, (start+end)/2, left, right) +
               query(node->r, (start+end)/2+1, end, left, right);
    }
    int qidx(pnd *node, int start, int end, cint tar) {
        //cout << "q " << start << " " << end << " " << tar << endl;
        //cout << (node->l ? node->l->val : 0) << " " << (node->r ? node->r->val : 0) << endl;
        if(start==end) {
            return start;
        }
        if(node->r && node->r->val >= tar)
            return qidx(node->r, (start+end)/2+1, end, tar);
        if(node->l && node->r) return qidx(node->l, start, (start+end)/2, tar - node->r->val);
        if(node->l) return qidx(node->l, start, (start+end)/2, tar);
//        if(node->r) return qidx(node->r, (start+end)/2+1, end, tar);
        assert(false);
    }
};

// 14577. 일기예보
// #segtree

signed main() {
    fastio;
    int n, m; cin >> n >> m;
    v<int> cnt(1, -1);
    forn(i, n) cnt.push_back(input());
    dynamicSeg ds(100000000000000);
    forf(i, 1, n) ds.update(cnt[i]+1, 1);
    forn(qi, m) {
        int t = input(), a, b;
        if(t==1) {
            cin >> a >> b;
            ds.update(cnt[a]+1, -1);
            cnt[a] += b;
            ds.update(cnt[a]+1, 1);
        }
        else if (t==2) {
            cin >> a >> b;
            ds.update(cnt[a]+1, -1);
            cnt[a] -= b;
            ds.update(cnt[a]+1, 1);
        }
        else if (t==3) {
            cin >> a >> b;
            cout << ds.query(a+1, b+1) << '\n';
        } else {
            cin >> a;
            cout << ds.qidx(a)-1 << '\n';
        }
    }
}
