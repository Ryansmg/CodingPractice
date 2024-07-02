#define USE_MACROS true
#define USE_INT128 false
#define GCC_OPTIMIZE_ENABLE false
#pragma region macros
#if USE_MACROS
#include <bits/stdc++.h>
#if GCC_OPTIMIZE_ENABLE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif
#define int long long
#define llmax 9223372036854775807
#define INF 1000000000000000000
#define inf 3000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define filein freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/input.txt", "r", stdin)
#define fileout freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/output.txt", "w", stdout)
#define all(vec) (vec).begin(), (vec).end()
#define forn(name, val) for(int name = 0; name < val; name++)

using namespace std;
template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
template <typename T> using pq = priority_queue<T>;
using ii = array<int, 2>;
using iii = array<int, 3>;

template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
template <typename T> T input() {T t; cin >> t; return t;}
int input() { int t=llmax; cin >> t; return t;}
template <typename T> void print(const T &i, const string& end="") { cout << i << end; }
#if USE_INT128
#define lint __int128
lint linput() { return (lint) input(); }
void print(const lint &i, const string& end="") { cout << (int)i << end;}
#endif
#endif
#pragma endregion

// 11408. 열혈강호 5
// #mcmf (최소 비용 최대 유량) #flow (#bellman_ford)
// http://boj.kr/11408

signed main() {
    fastio;
    int n, m; // 직원의 수, 일의 수
    cin >> n >> m;
    int source = 0, sink = 1410; //직원 1~400, 일 1001~1400
    v2<ii> edges(1420, v<ii>()); // [출발 노드] {도착 노드, 비용}
    v2<int> capacity(1420, v<int>(1420, 0)),
    flow(1420, v<int>(1420, 0));
    v<int> dist(1420), pre(1420);
    forn(i, m) {
        capacity[i+1001][sink] = 1;
        edges[i+1001].push_back({sink, 0});
        edges[sink].push_back({i + 1001, 0});
    }
    forn(i, n) {
        int workCnt = input();
        capacity[source][i+1] = 1;
        edges[source].push_back({i + 1, 0});
        edges[i+1].push_back({source, 0});
        forn(j, workCnt) {
            int a = input(), b = input();
            edges[i+1].push_back({a + 1000, b});
            edges[a+1000].push_back({i + 1, -b});
            capacity[i+1][a+1000] = 1;
        }
    }
    int maxFlow = 0; int distSum = 0;

    while(true) {
        fill(all(dist), INF);
        fill(all(pre), -1);
        bool inQueue[1420] = {false};
        int cycle[1420] = {0};
        queue<int> spfa;
        spfa.push(source);
        dist[source] = 0;
        while(!spfa.empty()) {
            int front = spfa.front(); spfa.pop();
            inQueue[front] = false;
            cycle[front]++;
            if(cycle[front] >= n+m+2)
                assert(false); // 음수 사이클이 존재
            for(auto edge : edges[front]) {
                if(capacity[front][edge[0]] - flow[front][edge[0]] > 0 &&
                    dist[edge[0]] > dist[front] + edge[1]) {
                    dist[edge[0]] = dist[front] + edge[1];
                    pre[edge[0]] = front;
                    if(!inQueue[edge[0]]) {
                        spfa.push(edge[0]);
                        inQueue[edge[0]] = true;
                    }
                }
            }
        }
        if(pre[sink] == -1) break;

        for(int i = sink; i != source; i = pre[i]) {
            flow[pre[i]][i]++;
            flow[i][pre[i]]--;
        }
        maxFlow++;
        distSum += dist[sink];
    }
    cout << maxFlow << '\n' << distSum;
}
