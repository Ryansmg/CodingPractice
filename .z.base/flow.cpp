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
template <typename T> T temp() { T t; return t; }
#endif
#pragma endregion

// 2367. 파티
// #flow (최대 유량)

signed main() {
    fastio;
    int n, k, d; cin >> n >> k >> d;
    // source : 0, sink = 999
    // 사람 : 1 ~ 200
    // 음식 : 501 ~ 600

    //입력 받기
    v<v<int>> con(1010, temp<v<int>>());
    v<int> temp(1010, 0), visited(1010);
    v<v<int>> capacity(1010, temp); // 최대 유량
    v<v<int>> flow(1010, temp); // 현재 유량
    forn(i, d) {
        capacity[i + 501][999] = input();
        con[i+501].push_back(999);
        con[999].push_back(i+501); // 유령 간선도 push_back
    }
    forn(i, n) {
        int z = input();
        capacity[0][i+1] = k;
        con[0].push_back(i+1);
        con[i+1].push_back(0);
        forn(j, z) {
            int t = input();
            capacity[i+1][t+500] = 1;
            con[i+1].push_back(t+500);
            con[t+500].push_back(i+1);
        }
    }

    int maxFlow = 0, source = 0, sink = 999;
    // 모든 증가 경로 구하기
    while(true) {
        fill(all(visited), -1);
        queue<int> bfs;
        bfs.push(source);
        while(!bfs.empty()) {
            int cur = bfs.front(); bfs.pop();
            for(int i : con[cur]) {
                if(capacity[cur][i] - flow[cur][i] > 0 && visited[i] == -1) {
                    bfs.push(i);
                    visited[i] = cur;
                    if(i == sink) break;
                }
            }
            if(visited[sink] != -1) break;
        }
        // 모든 증가 경로를 찾은 경우
        if(visited[sink] == -1) break;

        // 백트래킹으로 최대 유량 확인
        int tempFlow = INF;
        for(int i = sink; i != source; i = visited[i])
            tempFlow = min(tempFlow, capacity[visited[i]][i] - flow[visited[i]][i]);

        // 유량 증가 & 유령 간선 만들기
        for(int i = sink; i != source; i = visited[i]) {
            flow[visited[i]][i] += tempFlow;
            flow[i][visited[i]] -= tempFlow;
        }

        maxFlow += tempFlow;
    }
    cout << maxFlow;
}
