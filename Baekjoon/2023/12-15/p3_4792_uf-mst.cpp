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

struct edgecmp2 {
    bool operator() (edge a, edge b) {
        return a.weight < b.weight;
    }
};

vector<int> s_parent;

int findRoot(int x) {
    if(s_parent[x] == x) return x;
    return s_parent[x] = findRoot(s_parent[x]);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    while(true) {
        int nodeN, edgeN, k; cin >> nodeN >> edgeN >> k;
        if(nodeN + edgeN + k == 0) break;
        vector<int> wsum(nodeN+1);
        priority_queue<edge, vector<edge>, edgecmp2> pq;
        priority_queue<edge, vector<edge>, edgecmp> pq2;
        vector<int> temp(nodeN+1); s_parent = temp;
        for(int i=1; i<=nodeN; i++) s_parent[i]=i;
        for(int i=0; i<edgeN; i++) 
        {
            char c; int f, t; cin >> c >> f >> t;
            pq.emplace(f, t, c=='B');
            pq2.emplace(f, t, c=='B');
        }
        
        int findn = 0;
        while(findn<nodeN-1) {
            auto top = pq.top(); pq.pop();
            if(findRoot(top.nodeA) == findRoot(top.nodeB)) continue;
            wsum[findRoot(top.nodeB)] += wsum[findRoot(top.nodeA)] + top.weight;
            s_parent[findRoot(top.nodeA)] = findRoot(top.nodeB);
            findn++;
        }
        int max = wsum[findRoot(1)];

        vector<int> temp3(nodeN+1); wsum = temp3;
        vector<int> temp2(nodeN+1); s_parent = temp2;
        for(int i=1; i<=nodeN; i++) s_parent[i]=i;
        findn = 0;
        while(findn<nodeN-1) {
            auto top = pq2.top(); pq2.pop();
            if(findRoot(top.nodeA) == findRoot(top.nodeB)) continue;
            wsum[findRoot(top.nodeB)] += wsum[findRoot(top.nodeA)] + top.weight;
            s_parent[findRoot(top.nodeA)] = findRoot(top.nodeB);
            findn++;
        }
        int min = wsum[findRoot(1)];

        cout << (min<=k && k<=max) << "\n";
    }
}
