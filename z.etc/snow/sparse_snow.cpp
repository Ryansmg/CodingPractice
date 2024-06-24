#pragma region macros
#define GCC_OPTIMIZE_ENABLE false

#include <bits/stdc++.h>
using namespace std;

#if GCC_OPTIMIZE_ENABLE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif

#define int lint
#define double long double
#define cint const int &
#define lf __float128

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

int range_sum(int a, int b) {
    if(a>b) return 0;
    return (a+b)*(b-a+1)/2;
}
bool printTime=true;

class sparseSeg {
public:
    class lpnd {
    public:
        lpnd *l = nullptr, *r = nullptr;
        int val = 0, lazy = 0;
        lpnd()=default;
        ~lpnd(){ delete l; delete r; }
    };
    explicit sparseSeg(int treeSize) : sparseSeg() { n = treeSize; }
    ~sparseSeg() { delete root; }
    void update(cint left, cint right, cint val) {
        assert(left <= right && left > 0);
        update(root, 1, n, left, right, val);
    }
    int query(cint left, cint right) {
        assert(left <= right && left > 0);
        return query(root, 1, n, left, right);
    }
private:
    explicit sparseSeg() { root = new lpnd(); }
    lpnd *root; int n = -1;
    static void push(lpnd *node, cint start, cint end) {
        node->val += (end-start+1) * node->lazy;
        if(start != end) {
            if(!node->l) node->l = new lpnd();
            node->l->lazy += node->lazy;
            if(!node->r) node->r = new lpnd();
            node->r->lazy += node->lazy;
        }
        node->lazy = 0;
    }
    void update(lpnd *node, int start, int end, cint left, cint right, cint val) {
        push(node, start, end);
        if(right < start || end < left) return;
        if(left <= start && end <= right) {
            node->lazy += val;
            push(node, start, end);
            return;
        }
        int mid = (start+end)/2;
        if(node->l || left <= mid) {
            if (!node->l) node->l = new lpnd();
            update(node->l, start, mid, left, right, val);
        }
        if(node->r || mid+1 <= right) {
            if (!node->r) node->r = new lpnd();
            update(node->r, mid + 1, end, left, right, val);
        }
        int lv = node->l ? node->l->val : 0;
        int rv = node->r ? node->r->val : 0;
        node->val = lv + rv;
    }
    int query(lpnd *node, int start, int end, cint left, cint right) {
        if(!node) return 0;
        if(right < start || end < left) return 0;
        push(node, start, end);
        if(left <= start && end <= right) return node->val;
        return query(node->l, start, (start+end)/2, left, right) +
               query(node->r, (start+end)/2+1, end, left, right);
    }
};
class sparseSeg2 {
public:
    class lpnd {
    public:
        lpnd *l = nullptr, *r = nullptr;
        int val = 0, lazy = 0;
        lpnd()=default;
        ~lpnd(){ delete l; delete r; }
    };
    explicit sparseSeg2(int treeSize) : sparseSeg2() { n = treeSize; }
    ~sparseSeg2() { delete root; }
    void update(cint left, cint right, cint val) {
        assert(left <= right && left > 0);
        update(root, 1, n, left, right, val);
    }
    int query(cint left, cint right) {
        assert(left <= right && left > 0);
        return query(root, 1, n, left, right);
    }
private:
    explicit sparseSeg2() { root = new lpnd(); }
    lpnd *root; int n = -1;
    static void push(lpnd *node, cint start, cint end) {
        node->val += range_sum(start, end) * node->lazy;
        if(start != end) {
            if(!node->l) node->l = new lpnd();
            node->l->lazy += node->lazy;
            if(!node->r) node->r = new lpnd();
            node->r->lazy += node->lazy;
        }
        node->lazy = 0;
    }
    void update(lpnd *node, int start, int end, cint left, cint right, cint val) {
        push(node, start, end);
        if(right < start || end < left) return;
        if(left <= start && end <= right) {
            node->lazy += val;
            push(node, start, end);
            return;
        }
        int mid = (start+end)/2;
        if(node->l || left <= mid) {
            if (!node->l) node->l = new lpnd();
            update(node->l, start, mid, left, right, val);
        }
        if(node->r || mid+1 <= right) {
            if (!node->r) node->r = new lpnd();
            update(node->r, mid + 1, end, left, right, val);
        }
        int lv = node->l ? node->l->val : 0;
        int rv = node->r ? node->r->val : 0;
        node->val = lv + rv;
    }
    int query(lpnd *node, int start, int end, cint left, cint right) {
        if(!node) return 0;
        if(right < start || end < left) return 0;
        push(node, start, end);
        if(left <= start && end <= right) return node->val;
        return query(node->l, start, (start+end)/2, left, right) +
               query(node->r, (start+end)/2+1, end, left, right);
    }
};

signed main() {
    fastio; cout.precision(8); cout << fixed;
    filein; fileout;
    auto startTime = clock();
    int l, n, m, a, b, k, t; cin >> l >> n >> m;
    vector<array<int, 5>> queries;
    for(int i=1; i<=n; i++) {
        cin >> a >> b >> k;
        queries.push_back({i, 1, a, b, k});
    }
    for(int i=1; i<=m; i++) {
        cin >> t >> a >> b;
        queries.push_back({t, 2, a, b, i-1});
    }
    sparseSeg sum(50000010); sparseSeg2 weight(50000010);
    sort(all(queries)); vector<lf> answers(m);
    for(auto &query : queries) {
        if(query[1] == 1) {
            sum.update(query[2], query[3], query[4]);
            weight.update(query[2], query[3], query[4]);
        } else {
            int s = sum.query(query[2], query[3]);
            int w = weight.query(query[2], query[3]);
            if(s==0) answers[query[4]] = -1;
            else answers[query[4]] = abs(((lf)w / ((lf) s)) - ((lf)(query[2]+query[3])/((lf)2)));
        }
    }
    for(const lf& i : answers) cout << (double)i << '\n'; // 정답 출력
    auto time = clock()-startTime;
    if(printTime) cout << endl << time;
}
