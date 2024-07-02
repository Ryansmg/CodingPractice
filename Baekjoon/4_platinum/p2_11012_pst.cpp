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

class pst {
    class pnd {
    public:
        pnd *l = nullptr, *r = nullptr;
        bool deleteL = false, deleteR = false;
        int val = 0;
        pnd()=default;
        pnd(bool ldel, bool rdel) : deleteL(ldel), deleteR(rdel) {}
        ~pnd(){ if(deleteL) delete l; if(deleteR) delete r; }
    };
public:
    explicit pst(cint treeSize) : pst() {
        n = treeSize;
        init(cur, 1, n);
        end_update();
    }
    pst(cint treeSize, const v<int> &arr) : pst() {
        n = treeSize;
        assert(arr.size() == treeSize);
        init(cur, 1, n, arr);
        end_update();
    }
    ~pst() { for(auto &p : root) delete p; }
    void update(cint tar, cint val) {
        assert(tar>0);
        update(pre, cur, 1, n, tar, val);
    }
    void singleUpdate(cint tar, cint val) { update(tar, val); end_update(); }
    void end_update() {
        if(!cur->l) { cur->l = pre->l; cur->deleteL = false; cur->val += cur->l->val; }
        if(!cur->r) { cur->r = pre->r; cur->deleteR = false; cur->val += cur->r->val; }
        pre = cur; cur = new pnd();
        root.push_back(cur); treeCnt++;
    }
    int query(cint rootN, cint left, cint right) {
        assert(0<=rootN && rootN<treeCnt); assert(left <= right && left > 0);
        return query(root[rootN], 1, n, left, right);
    }
private:
    explicit pst() {
        root.push_back(new pnd());
        pre = nullptr; cur = root[0];
    }
    v<pnd*> root; int n = -1, treeCnt = 0;
    pnd *pre, *cur;
    void init(pnd *node, int start, int end, const v<int> &arr) {
        if(start == end) { node->val = arr[start-1]; return; }
        node->l = new pnd(); node->r = new pnd();
        node->deleteL = true; node->deleteR = true;
        init(node->l, start, (start+end)/2, arr);
        init(node->r, (start+end)/2+1, end, arr);
        node->val = node->l->val + node->r->val;
    }
    void init(pnd *node, int start, int end) {
        if(start == end) { node->val = 0; return; }
        node->l = new pnd(); node->r = new pnd();
        node->deleteL = true; node->deleteR = true;
        init(node->l, start, (start+end)/2);
        init(node->r, (start+end)/2+1, end);
        node->val = node->l->val + node->r->val;
    }
    void update(pnd *prev, pnd *now, int start, int end, cint tar, cint val) {
        if(start==end) { now->val += val; return; }
        if(tar <= (start+end)/2) {
            if(!now->l || now->l == prev->l) {
                now->l = new pnd();
                now->l->val = prev->l->val;
            }
            if(!now->r) now->r = prev->r;
            now->deleteL = true;
            update(prev->l, now->l, start, (start+end)/2, tar, val);
        } else {
            if(!now->l) now->l = prev->l;
            if(!now->r || now->r == prev->r) {
                now->r = new pnd();
                now->r->val = prev->r->val;
            }
            now->deleteR = true;
            update(prev->r, now->r, (start+end)/2+1, end, tar, val);
        }
        now->val = now->l->val + now->r->val;
    }
    int query(pnd *node, int start, int end, cint left, cint right) {
        if(right < start || end < left) return 0;
        if(left <= start && end <= right) return node->val;
        return query(node->l, start, (start+end)/2, left, right) +
               query(node->r, (start+end)/2+1, end, left, right);
    }
};

// 11012. Egg
// #pst (퍼시스턴트 세그먼트 트리)

v2<int> queries = v2<int>(100010, v<int>());

signed main() {
    fastio;
    int T = input();
    forn(tci, T) {
        for(auto &q : queries) q.clear();
        int n, m, a, b; cin >> n >> m;
        forn(i, n) {
            cin >> a >> b;
            queries[b].push_back(a+1);
        }
        pst ps(100010);
        forn(i, 100003) {
            for(int j : queries[i]) ps.update(j, 1);
            ps.end_update();
        }
        int ans = 0;
        forn(i, m) {
            int l, r, t;
            cin >> l >> r >> b >> t; l++; r++; b++; t++;
            ans += ps.query(t, l, r) - ps.query(b-1, l, r);
        }
        cout << ans << '\n';
    }
}
