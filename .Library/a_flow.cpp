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

class Mcmf : public Flow {
protected:
    v<int> dist = v<int>();
public:
    int distSum = 0;
    Mcmf(int MaxNodeN, int Source, int Sink) : Flow(MaxNodeN, Source, Sink) {
        dist = v<int>(MaxNodeN+10);
    }
    /// returns true if succeeds
    bool run() override {
        while(true) {
            fill(all(visited), -1);
            fill(all(dist), INF);
            v<bool> inQueue(maxNodeN+10, false);
            v<int> cycle(maxNodeN+10, 0);
            queue<int> spfa;
            spfa.push(source);
            dist[source] = 0;
            while (!spfa.empty()) {
                int cur = spfa.front(); spfa.pop();
                inQueue[cur] = false;
                cycle[cur]++;
                if(cycle[cur] >= maxNodeN) return false;
                for (int edge: con[cur]) {
                    if (capacity[edge] - edgeFlow[edge] > 0 &&
                    dist[edges[edge][1]] > dist[cur] + edges[edge][2]) {
                        dist[edges[edge][1]] = dist[cur] + edges[edge][2];
                        visited[edges[edge][1]] = edge;
                        if(!inQueue[edges[edge][1]]) {
                            spfa.push(edges[edge][1]);
                            inQueue[edges[edge][1]] = true;
                        }
                    }
                }
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
            distSum += dist[sink] * tempFlow;
        }
        return true;
    }
};

#pragma region examples
void solve2367() {
    fastio;
    int n, k, d; cin >> n >> k >> d;
    Flow flow(999, 0, 999);
    forn(i, d) flow.addEdge(i+501, 999, input());
    forn(i, n) {
        flow.addEdge(0, i+1, k);
        int z = input();
        forn(j, z) flow.addEdge(i+1, input()+500, 1);
    }
    flow.run();
    cout << flow.maxFlow;
}
void solve11408() {
    Mcmf mcmf(1410, 0, 1410);
    int n, m; cin >> n >> m;
    forn(i, m) mcmf.addEdge(i+1001, mcmf.sink, 1, 0);
    forn(i, n) {
        int z = input();
        mcmf.addEdge(mcmf.source, i+1, 1, 0);
        forn(j, z) {
            int a, b; cin >> a >> b;
            mcmf.addEdge(i+1, a+1000, 1, b);
        }
    }
    mcmf.run();
    cout << mcmf.maxFlow << '\n' << mcmf.distSum;
}
#pragma endregion

signed main() {

}
