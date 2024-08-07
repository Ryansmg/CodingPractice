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

class Flow {
public:
    int maxFlow = 0;
    int source, sink;
protected:
    int maxNodeN;
    int edgeCount = -1;
    v<int> capacity = v<int>(), edgeFlow = v<int>(), revEdge = v<int>();
    v<iii> edges = v<iii>();
    v2<int> con = v2<int>();
    v<int> visited = v<int>();
public:
    Flow(int MaxNodeN, int Source, int Sink) {
        maxNodeN = MaxNodeN;
        source = Source;
        sink = Sink;
        con=v2<int>(maxNodeN+10, v<int>());
        visited = v<int>(maxNodeN+10, -1);
        assert(Source <= MaxNodeN && Sink <= MaxNodeN);
    }
    void addEdge(int start, int end, int Capacity, int Dist = 0) {
        assert(start <= maxNodeN && end <= maxNodeN);
        assert(Capacity >= 0);
        edgeCount++;
        edges.push_back({start, end, Dist});
        capacity.push_back(Capacity);
        edgeFlow.push_back(0);
        revEdge.push_back(edgeCount+1);
        con[start].push_back(edgeCount);
        edgeCount++;
        edges.push_back({end, start, -Dist});
        capacity.push_back(0);
        edgeFlow.push_back(0);
        con[end].push_back(edgeCount);
        revEdge.push_back(edgeCount-1);
    }

    /// returns true if successes
    virtual bool run() {
        while(true) {
            fill(all(visited), -1);
            queue<int> bfs;
            bfs.push(source);
            while (!bfs.empty()) {
                int cur = bfs.front(); bfs.pop();
                for (int edge: con[cur]) {
                    if (capacity[edge] - edgeFlow[edge] > 0 && visited[edges[edge][1]] == -1) {
                        bfs.push(edges[edge][1]);
                        visited[edges[edge][1]] = edge;
                        if (edges[edge][1] == sink) break;
                    }
                }
                if (visited[sink] != -1) break;
            }
            if (visited[sink] == -1) break;

            int tempFlow = llmax;
            for (int i = sink; i != source; i = edges[visited[i]][0])
                tempFlow = min(tempFlow, capacity[visited[i]] - edgeFlow[visited[i]]);

            for (int i = sink; i != source; i = edges[visited[i]][0]) {
                edgeFlow[visited[i]] += tempFlow;
                edgeFlow[revEdge[visited[i]]] -= tempFlow;
            }
            maxFlow += tempFlow;
        }
        return true;
    }
};

string s; v<string> arr;
void solve() {
    // source : 0, nodesin:1~900, nodesout: 901~1800, sink:1818
    Flow flow(1818, 0, 1818);
    int rcnt = arr.size(), ccnt = arr[0].size();
    const int dr[] = {1, -1, 0, 0};
    const int dc[] = {0, 0, 1, -1};
    forn(r, rcnt) {
        forn(c, ccnt) {
            flow.addEdge(r*ccnt+c+1, r*ccnt+c+900+1, 1);
            if(arr[r][c]=='N') flow.addEdge(r*ccnt+c+900+1, 1818, 1);
            if(arr[r][c]=='I') {
                forn(i, 4) {
                    int nr = r+dr[i], nc = c+dc[i];
                    if(nr<0||nc<0||nr>=rcnt||nc>=ccnt) continue;
                    if(arr[nr][nc]=='N') flow.addEdge(r*ccnt+c+900+1, nr*ccnt+nc+1, 1);
                }
            }
            if(arr[r][c]=='W') {
                flow.addEdge(0, r*ccnt+c+1, 1);
                forn(i, 4) {
                    int nr = r+dr[i], nc = c+dc[i];
                    if(nr<0||nc<0||nr>=rcnt||nc>=ccnt) continue;
                    if(arr[nr][nc]=='I') flow.addEdge(r*ccnt+c+900+1, nr*ccnt+nc+1, 1);
                }
            }
        }
    }
    flow.run();
    cout << flow.maxFlow << '\n';
    arr.clear();
}

signed main() {
    fastio;
    while(getline(cin, s)) {
        if(s.empty()) solve();
        else arr.push_back(s);
    }
    assert(!arr.empty());
    solve();
}
