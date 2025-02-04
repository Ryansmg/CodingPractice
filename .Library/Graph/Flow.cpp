/* Update : 2025-02-04 */

#include <bits/stdc++.h>

class Flow {
public:
    long long maxFlow = 0, source = -1, sink = -1;
protected:
    long long maxNodeN = -1, edgeCount = -1;
    std::vector<long long> capacity, edgeFlow, revEdge;
    std::vector<std::array<long long, 3>> edges; std::vector<std::vector<long long>> con; std::vector<long long> visited;
public:
    Flow() = default;
    Flow(long long MaxNodeNum, long long Source, long long Sink) {
        maxNodeN = MaxNodeNum; source = Source; sink = Sink;
        con = std::vector<std::vector<long long>>(maxNodeN+10, std::vector<long long>());
        visited = std::vector<long long>(maxNodeN+10, -1);
        assert(Source <= MaxNodeNum && Sink <= MaxNodeNum);
    }
    void addEdge(long long start, long long end, long long Capacity, long long Dist = 0) {
        assert(start <= maxNodeN && end <= maxNodeN);
        assert(Capacity >= 0);
        edgeCount++; edges.push_back({start, end, Dist});
        capacity.push_back(Capacity); edgeFlow.push_back(0);
        revEdge.push_back(edgeCount+1); con[start].push_back(edgeCount);
        edgeCount++; edges.push_back({end, start, -Dist});
        capacity.push_back(0); edgeFlow.push_back(0);
        revEdge.push_back(edgeCount-1); con[end].push_back(edgeCount);
    }

    /// returns true if successes
    virtual bool run() {
        while(true) {
            for(long long &i : visited) i = -1;
            std::queue<long long> bfs; bfs.push(source);
            while (!bfs.empty()) {
                long long cur = bfs.front(); bfs.pop();
                for (long long edge: con[cur]) {
                    if (capacity[edge] - edgeFlow[edge] > 0 && visited[edges[edge][1]] == -1) {
                        bfs.push(edges[edge][1]);
                        visited[edges[edge][1]] = edge;
                        if (edges[edge][1] == sink) break;
                    }
                }
                if (visited[sink] != -1) break;
            }
            if (visited[sink] == -1) break;

            long long tempFlow = 9223372036854775807;
            for (long long i = sink; i != source; i = edges[visited[i]][0])
                tempFlow = std::min(tempFlow, capacity[visited[i]] - edgeFlow[visited[i]]);

            for (long long i = sink; i != source; i = edges[visited[i]][0]) {
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
    std::vector<long long> dist;
public:
    long long distSum = 0;
    Mcmf(long long MaxNodeNum, long long Source, long long Sink) : Flow(MaxNodeNum, Source, Sink) { dist = std::vector<long long>(MaxNodeNum+10); }
    /// returns true if succeeds
    bool run() override {
        while(true) {
            for(long long &i : visited) i = -1;
            for(long long &i : dist) i = 1000000000000000000;
            std::vector<bool> inQueue(maxNodeN+10, false);
            std::vector<long long> cycle(maxNodeN+10, 0);
            std::queue<int> spfa; spfa.push(source);
            dist[source] = 0;
            while (!spfa.empty()) {
                long long cur = spfa.front(); spfa.pop();
                inQueue[cur] = false;
                cycle[cur]++;
                if(cycle[cur] >= maxNodeN) return false;
                for (long long edge: con[cur]) {
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

            long long tempFlow = 9223372036854775807;
            for (long long i = sink; i != source; i = edges[visited[i]][0])
                tempFlow = std::min(tempFlow, capacity[visited[i]] - edgeFlow[visited[i]]);

            for (long long i = sink; i != source; i = edges[visited[i]][0]) {
                edgeFlow[visited[i]] += tempFlow;
                edgeFlow[revEdge[visited[i]]] -= tempFlow;
            }
            maxFlow += tempFlow;
            distSum += dist[sink] * tempFlow;
        }
        return true;
    }
};

// Example : BOJ 11408. 열혈강호 5
int main() {
    using namespace std;
    long long n, m; cin >> n >> m;
    Mcmf mcmf(n+m+1, 0, n+m+1);
    for(long long i = 1; i <= n; i++) {
        mcmf.addEdge(0, i, 1);
        long long t; cin >> t;
        for(long long j = 0; j < t; j++) {
            long long a, b; cin >> a >> b;
            mcmf.addEdge(i, a + n, 1, b);
        }
    }
    for(long long i = 1; i <= m; i++) mcmf.addEdge(i+n, n+m+1, 1);
    mcmf.run();
    cout << mcmf.maxFlow << '\n' << mcmf.distSum << '\n';
}
