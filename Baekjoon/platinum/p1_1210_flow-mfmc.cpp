#pragma region macros
#include <bits/stdc++.h>
#define int long long
#define double long double
#define llmax 9223372036854775807
#define INF 1000000000000000000
#define inf 3000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define all(vec) (vec).begin(), (vec).end()
#define forn(name, val) for(int name = 0; name < val; name++)
#define forf(name, start, end) for(int name = start; name <= end; name++)

using namespace std;
template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
using ii = array<int, 2>;
using iii = array<int, 3>;

template <typename T> T input() {T t; cin >> t; return t;}
int input() { int t; cin >> t; return t;}
#pragma endregion

class Flow {
public:
    int maxFlow = 0;
    int source, sink;
protected:
    int maxNodeN;
    int edgeCount = -1;
public:
    v<int> capacity = v<int>(), edgeFlow = v<int>(), revEdge = v<int>();
    v<iii> edges = v<iii>();
    v2<int> con = v2<int>();
    v<int> visited = v<int>();
    Flow(int MaxNodeN, int Source, int Sink) {
        maxNodeN = MaxNodeN;
        source = Source;
        sink = Sink;
        con=v2<int>(maxNodeN+10, v<int>());
        visited = v<int>(maxNodeN+10, -1);
        assert(Source <= MaxNodeN && Sink <= MaxNodeN);
    }
    int addEdge(int start, int end, int Capacity, int Dist = 0) {
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
        return edgeCount-1;
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

signed main() {
    // source = 0
    // sink = 401
    // 톨게이트 in = 1~200
    // 톨게이트 out = 201~400
    int n, m; cin >> n >> m;
    Flow flow(402,0,401);
    int start, end; cin >> start >> end;
    flow.addEdge(0, start, INF);
    flow.addEdge(end+200, 401, INF);
    v<int> tolEdges;
    forf(i, 1, n) tolEdges.push_back(flow.addEdge(i, i+200, input()));
    forn(i, m) {
        int a, b; cin >> a >> b;
        flow.addEdge(a+200, b, INF);
        flow.addEdge(b+200, a, INF);
    }
    flow.run();

    // 분할된 정점들 기준 in에 도달 가능, out에 도달 불가능 => 막는다.
    v<bool> vis(410, false);
    queue<int> bfs; bfs.push(0); vis[0]=true;
    while(!bfs.empty()) {
        int t = bfs.front(); bfs.pop();
        for(int e : flow.con[t]) {
            if(flow.capacity[e] - flow.edgeFlow[e] > 0 &&
                !vis[flow.edges[e][1]]) {
                vis[flow.edges[e][1]]=true;
                bfs.push(flow.edges[e][1]);
            }
        }
    }
    v<int> ans;
    forf(i, 1, 200) if(vis[i]&&!vis[i+200]) ans.push_back(i);
    sort(all(ans)); for(int i : ans) cout << i << ' ';
}
