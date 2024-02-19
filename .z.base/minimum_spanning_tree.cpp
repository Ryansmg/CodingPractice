//Minimum spanning tree : 최소 스패닝 트리

/* 문제 #1197: 그래프가 주어졌을 때, 그 그래프의 최소 스패닝 트리를 구하는 프로그램을 작성하시오.
최소 스패닝 트리는 주어진 그래프의 모든 정점들을 연결하는 부분 그래프인 스패닝 트리 중에서 그 가중치의 합이 최소인 트리를 말한다.

입력:
첫째 줄에 정점의 개수 V와 간선의 개수 E가 주어진다.
다음 E개의 줄에는 각 간선에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다. 
이는 A번 정점과 B번 정점이 가중치 C인 간선으로 연결되어 있다는 의미이다.
그래프의 정점은 1번부터 V번까지 번호가 매겨져 있고, 임의의 두 정점 사이에 경로가 있다.

출력: 첫째 줄에 최소 스패닝 트리의 가중치를 출력한다. */

//kruskal / prim 알고리즘이 존재한다. 시간복잡도는 둘 모두 O(ElogV)
#define USE_KRUSKAL false
#define USE_PRIM false
#define USE_RANDOM !USE_KRUSKAL && !USE_PRIM

#include <iostream>
#include <vector>
#include <queue>
#include <random>
#define ll long long
using namespace std;

struct edge {
    ll parent; //간선 시작점
    ll target; //간선 도착점
    ll weight; //가중치
    edge(ll a, ll b, ll c) {
        parent = a; target = b; weight = c;
    }
    edge(){}
    bool operator() (edge x, edge y) {
        return x.weight > y.weight;
    }
};

//kruskal -> union_find
ll findRoot(vector<ll> &parent, ll n) {
    if(parent[n] == n) return n;
    return parent[n] = findRoot(parent, parent[n]);
}

// 가중치가 적은 간선부터 선택한다.
int kruskal(ll v, ll e, priority_queue<edge, vector<edge>, edge> &pq) {
    vector<ll> parent(v+1); //union_find
    for(ll i=1; i<=v; i++) parent[i] = i;
    ll edgecount = 0; //찾은 간선 개수
    ll weightsum = 0;
    while(edgecount < v-1) { //v-1이 mst의 간선 개수
        edge minedge = pq.top(); pq.pop();

        //tree는 loop를 형성하지 않아야 한다.
        if(findRoot(parent, minedge.parent) == findRoot(parent, minedge.target)) continue;

        //union find
        parent[findRoot(parent, minedge.target)] = findRoot(parent, minedge.parent);

        edgecount++;
        weightsum += minedge.weight;
    }
    cout << weightsum;
    return 0;
}

// 가중치가 적은 순으로 그래프 탐색
int prim(int v, int e, vector<vector<edge>> &edges) {
    //현재 정점들에 연결된 간선을 저장
    priority_queue<edge, vector<edge>, edge> pq;
    //loop 형성 방지
    vector<bool> visited(v+1, false);

    //탐색은 1번 정점에서 시작 (임의로 설정)
    visited[1] = true;
    for(edge e : edges[1]) pq.push(e); 

    //현재 정점들에 연결된 간선 중 가장 가중치가 작은 것을 선택해서 연결한다.
    ll edgecount = 0; //찾은 간선 개수
    ll weightsum = 0;
    while(edgecount < v-1) { //v-1이 mst의 간선 개수
        edge top = pq.top(); pq.pop();
        if(visited[top.target]) continue;
        visited[top.target] = true;
        weightsum += top.weight;
        edgecount++;
        for(edge e : edges[top.target]) {
            if(!visited[e.target])  
                pq.push(e);
        }
    }
    cout << weightsum;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    //입력 저장
    ll v, e; cin >> v >> e; //v:정점, e:간선의 개수
    vector<edge> temp;
    vector<vector<edge>> edges(v+1, temp); //prim
    priority_queue<edge, vector<edge>, edge> pq; //kruskal
    for(ll i=0; i<e; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        edge e1(a, b, c), e2(b, a, c);
        edges[a].push_back(e1);
        edges[b].push_back(e2);
        pq.push(e1);
    }
    if(USE_KRUSKAL) return kruskal(v, e, pq);
    if(USE_PRIM) return prim(v, e, edges);
    if(USE_RANDOM) {
        random_device rd; mt19937 gen(rd());
        uniform_int_distribution dis(0, 1);
        if(dis(gen)) return kruskal(v, e, pq);
        else return prim(v, e, edges);
    }
}