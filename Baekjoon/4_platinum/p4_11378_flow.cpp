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
    }
    void addEdge(int start, int end, int Capacity, int Dist = 0) {
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

signed main() {
    fastio;
    int n, m, k; cin >> n >> m >> k;
    //source : 0
    //직원 : 1~1000
    //일 : 1001~2000
    //벌점계산 : 2001
    //sink : 2002
    Flow flow(2002, 0, 2002);
    forf(i, 1, n) flow.addEdge(0, i, 1);
    forf(i, 1, n) flow.addEdge(2001, i, INF);
    forf(i, 1, m) flow.addEdge(i+1000, 2002, 1);
    flow.addEdge(0, 2001, k);
    forf(i, 1, n) {
        int z = input();
        forn(j, z) {
            int t = input();
            flow.addEdge(i, t+1000, 1);
        }
    }
    flow.run();
    cout << flow.maxFlow;
}
