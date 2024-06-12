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

#define ll long long
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

template<bool useHash = true, typename hashType = int>
class graph {
public:
    class edge {
    public:
        int start{}, end{}, weight{};
        edge() = default;
        graph *par = nullptr;
        edge(int a, int b, int c) : start(a), end(b), weight(c) {}
        edge(int a, int b, int c, graph *par_graph) : start(a), end(b), weight(c), par(par_graph) {}
        static bool sort_less(const edge &l, const edge &r) {
            return l.start == r.start ? (l.end == r.end ? l.weight < r.weight : l.end < r.end) : l.start < r.start;
        }
    };

    map<hashType, int> hash;
    v<int> node_val; v<hashType> origin;
    v2<edge> con, par;
    v<edge> edges;
    int nodeCnt, vsz, maxNodeN;
    function<void(int, const graph &)> bfsFunc, dfsFunc;

    graph() : hash(::map<hashType, int>()), node_val(0), origin(0), con(0), par(0), edges(0), nodeCnt(0), vsz(0),
              maxNodeN(-1) {}

    explicit graph(int maxNodeNumber) : graph() {
        assert(!useHash);
        maxNodeN = maxNodeNumber;
        node_val = v<int>(maxNodeNumber + 10, {});
        con = par = v2<edge>(maxNodeNumber + 10, v<edge>());
        vsz = maxNodeNumber + 10;
    }
    void addUndirEdgeH(hashType start, hashType end, int weight = 1) {
        addUndirEdge(addHash(start), addHash(end), weight);
    }
    void addUndirEdge(int start, int end, int weight = 1) {
        addEdge(start, end, weight);
        addEdge(end, start, weight);
    }
    int addHash(hashType n) {
        assert(useHash);
        int h;
        auto ptr = hash.find(n);
        if(ptr == hash.end()) {
            hash.insert({n, nodeCnt});
            h = nodeCnt++;
            origin.push_back(n);
        } else h = ptr->second;
        chkVsz(h);
        return h;
    }
    void addEdgeH(hashType start, hashType end, int weight = 1) {
        assert(useHash);
        addEdge(addHash(start), addHash(end), weight);
    }
    void addEdge(int start, int end, int weight = 1) {
        if (!useHash) assert(start <= maxNodeN && end <= maxNodeN);
        int maxn = max(start, end);
        chkVsz(maxn);
        edge edge(start, end, weight, this);
        con[start].push_back(edge);
        par[end].push_back(edge);
        edges.push_back(edge);
    }
    void chkVsz(int maxn) {
        maxn++;
        if (vsz < maxn) {
            assert(useHash);
            con.resize(maxn, v<edge>());
            par.resize(maxn, v<edge>());
            node_val.resize(maxn, 0);
            vsz = maxn;
        }
    }

    static bool edge_sort_less_with_origin(const edge &l, const edge &r) {
        return l.par->origin[l.start] == r.par->origin[r.start] ?
               (l.par->origin[l.end] == r.par->origin[r.end] ? l.weight < r.weight : l.par->origin[l.end] <
                                                                                     r.par->origin[r.end])
                                                                : l.par->origin[l.start] < r.par->origin[r.start];
    }

    void sortEdges() {
        function<bool(const edge &, const edge &)> sort_origin_func = edge_sort_less_with_origin;
        if (useHash) for (v<edge> &v: con) sort(all(v), sort_origin_func);
        else for (v <edge> &v: con) sort(all(v), edge::sort_less);
    }

    void bfsH(hashType startNodeN) {
        assert(useHash);
        auto ptr = hash.find(startNodeN);
        assert(ptr != hash.end());
        bfs(ptr->second);
    }
    void bfs(int startNodeN) {
        queue<int> q;
        q.push(startNodeN);
        v<bool> vis(vsz + 5, false);
        vis[startNodeN] = true;
        while (!q.empty()) {
            int fr = q.front();
            q.pop();
            bfsFunc(fr, *this);
            for (edge e: con[fr]) {
                if (!vis[e.end]) {
                    q.push(e.end);
                    vis[e.end] = true;
                }
            }
        }
    }

    void dfsH(hashType startNodeN) {
        assert(useHash);
        auto ptr = hash.find(startNodeN);
        assert(ptr != hash.end());
        dfs(ptr->second);
    }
    void dfs(int startNodeN) {
        stack<int> st;
        st.push(startNodeN);
        v<bool> vis(vsz + 5, false);
        while (!st.empty()) {
            int fr = st.top();
            st.pop();
            if (vis[fr]) continue;
            vis[fr] = true;
            dfsFunc(fr, *this);
            for (auto e = con[fr].rbegin(); e != con[fr].rend(); e++) {
                if (!vis[e->end]) st.push(e->end);
            }
        }
    }
    map<hashType, int> dijkstraH(hashType startNodeN, int endNodeN = -inf) {
        auto v = dijkstraH_raw(startNodeN, endNodeN);
        map<hashType, int> ret;
        for(int i=0; i<nodeCnt; i++) ret.insert({origin[i], v[i]});
        return ret;
    }
    v<int> dijkstraH_raw(hashType startNodeN, int endNodeN = -inf) {
        assert(useHash);
        auto ptr = hash.find(startNodeN);
        assert(ptr != hash.end());
        return dijkstra(ptr->second, endNodeN);
    }
    v<int> dijkstra(int startNodeN, int endNodeN = -inf) {
        priority_queue<ii, v<ii>, greater<>> p;
        p.push({0, startNodeN});
        v<int> dist(vsz, INF);
        while(!p.empty()) {
            ii t = p.top(); p.pop();
            if(dist[t[1]] != INF) continue;
            dist[t[1]] = t[0];
            if(t[1] == endNodeN) break;
            for(edge c : con[t[1]]) p.push({t[0] + c.weight, c.end});
        }
        return dist;
    }
};

void pr(int i, const graph<false> &) { cout << i << ' '; }
void pr2(int i, const graph<true, string> &g) { cout << g.origin[i] << ' '; }

signed main() {
    fastio;
    int m, n; cin >> n >> m;
    graph<false> g(100000);
    forn(i, m) {
        int a, b, c; cin >> a >> b >> c;
        g.addEdge(a, b, c);
    }
    int a, b; cin >> a >> b;
    cout << g.dijkstra(a)[b];
}
