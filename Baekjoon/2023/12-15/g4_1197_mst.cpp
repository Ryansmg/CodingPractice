//최소 스패닝 트리 (Minimum Spanning Tree)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge {
    int nodeA, nodeB, weight;
    edge(){}
    edge(int a, int b, int c) {
        nodeA = a; nodeB = b; weight = c;
    }
};

struct edgecmp {
    bool operator() (edge a, edge b) {
        return a.weight > b.weight;
    }
};

vector<int> s_parent;

int findRoot(int x) {
    if(s_parent[x] == x) return x;
    return s_parent[x] = findRoot(s_parent[x]);
}

int main()
{
    int v, e; cin >> v >> e;
    vector<int> temp(v+1); s_parent = temp;
    for(int i=1; i<=v; i++) s_parent[i]=i;
    vector<int> wsum(v+1, 0);

    priority_queue<edge, vector<edge>, edgecmp> pq;
    for(int i=0; i<e; i++) {
        int a, b, c; cin >> a >> b >> c;
        pq.emplace(a, b, c);
    }
    int findn = 0;
    while(findn<v-1) {
        auto top = pq.top(); pq.pop();
        if(findRoot(top.nodeA) == findRoot(top.nodeB)) continue;
        wsum[findRoot(top.nodeB)] += wsum[findRoot(top.nodeA)] + top.weight;
        s_parent[findRoot(top.nodeA)] = findRoot(top.nodeB);
        findn++;
    }
    cout << wsum[findRoot(1)];
}