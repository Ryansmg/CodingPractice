#pragma region macros
#define USE_MACROS true
#define USE_INT false
#define USE_INT128 true
#define USE_DOUBLE false
#define GCC_OPTIMIZE_ENABLE false
#if USE_MACROS
#include <bits/stdc++.h>
#if GCC_OPTIMIZE_ENABLE
// #pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif
#if !USE_INT
#define int long long // set USE_INT to true to disable
#endif
#if !USE_DOUBLE
#define double long double // set USE_DOUBLE to true to disable
#endif
#define llmax 9223372036854775807 // 2^63-1
#if USE_INT
#define intmax 2147483647
#else
#define intmax llmax
#endif
#define INF 1000000000000000000 // INF * INF > 2^63
#define inf 3000000000 // inf > 2^31, inf * inf < 2^63
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr) // enables fast input/output
#define filein freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/input.txt", "r", stdin) // stdin <- Coding/Baekjoon/input.txt
#define fileout freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/output.txt", "w", stdout) // stdout <- Coding/Baekjoon/output.txt
#define all(vec) (vec).begin(), (vec).end()
#define forn(name, val) for(int name = 0; name < val; name++)
#define forf(name, start, end) for(int name = start; name <= end; name++)
#define pass print("") // do nothing

using namespace std;
template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
template <typename T> using pq = priority_queue<T>;
using ii = array<int, 2>;
using iii = array<int, 3>;

#if USE_INT128
#define lint __int128 // to disable lint, set USE_INT128 to false
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
#endif

template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
template <typename T> T input() {T t; cin >> t; return t;} // explicit type, input<TYPE>()
int input() { int t; cin >> t; return t;} // default type : int
template <typename T> void print(const T &i, const string& end="") { cout << i << end; }
template <typename T> T pow_(T a, T b) { return pow_(a, b, intmax); }
template <typename T> T pow_(T a, T b, T mod) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }
#endif
#pragma endregion

// 19472. Array and Operations
// #lazyprop (세그비츠)

#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////
/*
 * Author : jinhan814
 * Date : 2021-05-06
 * Source : https://blog.naver.com/jinhan814/222266396476
 * Description : FastIO implementation for cin, cout.
 */
constexpr int SZ = 1 << 20;

class INPUT {
private:
    char read_buf[SZ];
    int read_idx, next_idx;
    bool __END_FLAG__, __GETLINE_FLAG__;
public:
    explicit operator bool() { return !__END_FLAG__; }
    static bool IsBlank(char c) { return c == ' ' || c == '\n'; }
    static bool IsEnd(char c) { return c == '\0'; }
    char _ReadChar() {
        if (read_idx == next_idx) {
            next_idx = fread(read_buf, sizeof(char), SZ, stdin);
            if (next_idx == 0) return 0;
            read_idx = 0;
        }
        return read_buf[read_idx++];
    }
    char ReadChar() {
        char ret = _ReadChar();
        for (; IsBlank(ret); ret = _ReadChar());
        return ret;
    }
    template<typename T> T ReadInt() {
        T ret = 0; char cur = _ReadChar(); bool flag = false;
        for (; IsBlank(cur); cur = _ReadChar());
        if (cur == '-') flag = true, cur = _ReadChar();
        for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret = 10 * ret + (cur & 15);
        if (IsEnd(cur)) __END_FLAG__ = true;
        return flag ? -ret : ret;
    }
    string ReadString() {
        string ret; char cur = _ReadChar();
        for (; IsBlank(cur); cur = _ReadChar());
        for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
        if (IsEnd(cur)) __END_FLAG__ = true;
        return ret;
    }
    double ReadDouble() {
        string ret = ReadString();
        return stod(ret);
    }
    string getline() {
        string ret; char cur = _ReadChar();
        for (; cur != '\n' && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
        if (__GETLINE_FLAG__) __END_FLAG__ = 1;
        if (IsEnd(cur)) __GETLINE_FLAG__ = 1;
        return ret;
    }
    friend INPUT& getline(INPUT& in, string& s) { s = in.getline(); return in; }
} _in;

class OUTPUT {
private:
    char write_buf[SZ];
    int write_idx;
public:
    ~OUTPUT() { Flush(); }
    explicit operator bool() { return true; }
    void Flush() {
        fwrite(write_buf, sizeof(char), write_idx, stdout);
        write_idx = 0;
    }
    void WriteChar(char c) {
        if (write_idx == SZ) Flush();
        write_buf[write_idx++] = c;
    }
    template<typename T> int GetSize(T n) {
        int ret = 1;
        for (n = n >= 0 ? n : -n; n >= 10; n /= 10) ret++;
        return ret;
    }
    template<typename T> void WriteInt(T n) {
        int sz = GetSize(n);
        if (write_idx + sz >= SZ) Flush();
        if (n < 0) write_buf[write_idx++] = '-', n = -n;
        for (int i = sz; i-- > 0; n /= 10) write_buf[write_idx + i] = n % 10 | 48;
        write_idx += sz;
    }
    void WriteString(const string& s) { for (auto& c : s) WriteChar(c); }
    void WriteDouble(double d) { WriteString(to_string(d)); }
} _out;

/* operators */
INPUT& operator>> (INPUT& in, char& i) { i = in.ReadChar(); return in; }
INPUT& operator>> (INPUT& in, string& i) { i = in.ReadString(); return in; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
INPUT& operator>> (INPUT& in, T& i) {
    if constexpr (is_floating_point_v<T>) i = in.ReadDouble();
    else if constexpr (is_integral_v<T>) i = in.ReadInt<T>(); return in; }

OUTPUT& operator<< (OUTPUT& out, char i) { out.WriteChar(i); return out; }
OUTPUT& operator<< (OUTPUT& out, const string& i) { out.WriteString(i); return out; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
OUTPUT& operator<< (OUTPUT& out, T i) {
    if constexpr (is_floating_point_v<T>) out.WriteDouble(i);
    else if constexpr (is_integral_v<T>) out.WriteInt<T>(i); return out; }

/* macros */
#undef fastio
#define fastio 1
#define cin _in
#define cout _out
#define istream INPUT
#define ostream OUTPUT
struct Node {
    int mn, mx, sum;
    Node()=default;
    Node(int a, int b, int d) : mn(a), mx(b), sum(d){};
};
class segbeats {
public:
    explicit segbeats(int treeSize) {
        tree = v<Node>(4*treeSize);
        lazy_add = v<int>(4*treeSize, 0);
        lazy_div = v<int>(4*treeSize, -inf);
        n = treeSize;
    }
    explicit segbeats(const v<int> &a) : segbeats((int)a.size()) {
        init(a, 1, 1, n);
    }
    segbeats(const v<int> &a, int treeSize) : segbeats(treeSize) {
        init(a, 1, 1, n);
        assert(a.size() == treeSize);
    }
    void add(const int &left, const int &right, const int &diff) { add(1, left, right, 1, n, diff); }
    void div(int left, int right) { div(1, left, right, 1, n); }
    Node query(int left, int right) { return query(1, left, right, 1, n); }
    int query_sum(int left, int right) { return query_sum(1, left, right, 1, n); }
    int query_max(int left, int right) { return query_max(1, left, right, 1, n); }
    int query_min(int left, int right) { return query_min(1, left, right, 1, n); }

protected:
    v<Node> tree; v<int> lazy_add, lazy_div;
    int n;
    void update_lazy(int node, int start, int end) {
        if(lazy_div[node] <= -inf) {
            tree[node].mx += lazy_add[node];
            tree[node].mn += lazy_add[node];
            tree[node].sum += (end-start+1) * lazy_add[node];
            if(start != end) {
                lazy_add[node*2] += lazy_add[node];
                lazy_add[node*2+1] += lazy_add[node];
            }
        } else {
            tree[node].mx = tree[node].mn = lazy_div[node] + lazy_add[node];
            tree[node].sum = (end-start+1)*tree[node].mx;
            if(start != end) {
                lazy_add[node*2] = lazy_add[node*2+1] = lazy_add[node];
                lazy_div[node*2] = lazy_div[node*2+1] = lazy_div[node];
            }
        }
        lazy_add[node] = 0;
        lazy_div[node] = -inf;
    }
    static Node merge_node(const Node &a, const Node &b) {
        return {min(a.mn, b.mn), max(a.mx, b.mx), a.sum+b.sum};
    }
    void init(const v<int> &a, int node, int start, int end) {
        if(start==end) {
            tree[node] = {a[start-1], a[start-1], a[start-1]};
        } else {
            init(a, node*2, start, (start+end)/2);
            init(a, node*2+1, (start+end)/2+1, end);
            tree[node] = merge_node(tree[node*2], tree[node*2+1]);
        }
    }
    void add(int node, const int &left, const int &right, int start, int end, const int &diff) {
        update_lazy(node, start, end);
        if(right < start || end < left) return;
        if(left <= start && end <= right) {
            lazy_add[node] = diff;
            update_lazy(node, start, end);
            return;
        }
        add(node*2, left, right, start, (start+end)/2, diff);
        add(node*2+1, left, right, (start+end)/2+1, end, diff);
        tree[node] = merge_node(tree[node*2], tree[node*2+1]);
    }
    void div(int node, int left, int right, int start, int end) {
        update_lazy(node, start, end);
        if(end < left || right < start) return;
        if(left <= start && end <= right) {
            if(floor(sqrt(tree[node].mn)) == floor(sqrt(tree[node].mx))) {
                lazy_div[node] = floor(sqrt(tree[node].mn));
                update_lazy(node, start, end);
                return;
            }
            if(tree[node].mn + 1 == tree[node].mx) {
                lazy_add[node] = ((int)(floor(sqrt(tree[node].mn)))) - tree[node].mn;
                update_lazy(node, start, end);
                return;
            }
        }
        div(node*2, left, right, start, (start+end)/2);
        div(node*2+1, left, right, (start+end)/2+1, end);
        tree[node] = merge_node(tree[node*2], tree[node*2+1]);
    }
    Node query(int node, int left, int right, int start, int end) {
        update_lazy(node, start, end);
        if(right < start || end < left) return {inf, -inf, 0};
        if(left <= start && end <= right) return tree[node];
        return merge_node(query(node*2, left, right, start, (start+end)/2),
               query(node*2+1, left, right, (start+end)/2+1, end));
    }
    int query_sum(int node, int left, int right, int start, int end) {
        update_lazy(node, start, end);
        if(right < start || end < left) return 0;
        if(left <= start && end <= right) return tree[node].sum;
        return query_sum(node*2, left, right, start, (start+end)/2) +
                          query_sum(node*2+1, left, right, (start+end)/2+1, end);
    }
    int query_max(int node, int left, int right, int start, int end) {
        update_lazy(node, start, end);
        if(right < start || end < left) return -inf;
        if(left <= start && end <= right) return tree[node].mx;
        return max(query_max(node*2, left, right, start, (start+end)/2),
               query_max(node*2+1, left, right, (start+end)/2+1, end));
    }
    int query_min(int node, int left, int right, int start, int end) {
        update_lazy(node, start, end);
        if(right < start || end < left) return inf;
        if(left <= start && end <= right) return tree[node].mn;
        return min(query_min(node*2, left, right, start, (start+end)/2),
                   query_min(node*2+1, left, right, (start+end)/2+1, end));
    }
};

signed main() {
    fastio;
    int T = 1;
    forn(iasdf, T) {
        int n, q; cin >> n >> q;
        v<int> a;
        int temp;
        forn(i, n) {
            cin >> temp;
            a.push_back(temp);
        }
        segbeats lp(a, n);
        forn(m, q) {
            int t, l, r;
            cin >> t >> l >> r;
            if (t == 1) {
                cin >> temp;
                lp.add(l, r, temp);
            }
            else if (t == 2) lp.div(l, r);
            else cout << lp.query_sum(l, r) << '\n';
        }
    }
    cout.Flush();
}
