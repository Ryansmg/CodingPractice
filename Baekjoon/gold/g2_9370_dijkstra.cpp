#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#define inf 2147483640
using namespace std;

//미확인 도착지

struct TRI {
    int node, distance; 
    bool passed; //g~h를 지남
    TRI(int a, int b, bool c) {
        node = a; distance = b; passed = c;
    }
    TRI(){}
} typedef tri;

struct cmp {
    bool operator() (tri a, tri b) {
        return a.distance > b.distance;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int caseN; cin >> caseN;
    for(int curtc = 0; curtc < caseN; curtc++) 
    {
        //input

        int nodeN, //노드 개수
        edgeN, //간선 개수
        destN, //목적지 후보 개수
        start, //시작 노드
        conf1, conf2; //확정 노드
        cin >> nodeN >> edgeN >> destN >> start >> conf1 >> conf2;
        
        vector<vector<pair<int, int>>> child(nodeN+1); //노드 번호 -> { 자식 노드 번호, 가중치 }
        set<int> dests; //목적지 후보

        for(int i=0; i<edgeN; i++){
            int a, b, c;
            cin >> a >> b >> c;
            child[a].push_back({b, c});
            child[b].push_back({a, c});
        }
        for(int i=0; i<destN; i++){
            int a; cin >> a; dests.insert(a);
        }

        //dijkstra

        vector<int> dist(nodeN+1, inf); //노드 번호 -> 최단 거리
        vector<int> passed(nodeN+1, false);
        priority_queue<tri, vector<tri>, cmp> pq;
        dist[start] = 0;
        for(auto pair : child[start]) // 자식 노드 번호, 가중치
            pq.emplace(pair.first, pair.second, (start == conf1 && pair.first == conf2) || 
                (start == conf2 && pair.first == conf1));
        
        while(!pq.empty())
        {
            tri top = pq.top(); pq.pop();
            if(dist[top.node] != inf && passed[top.node]) continue;
            if(dist[top.node] == inf || dist[top.node] == top.distance){
                dist[top.node] = top.distance;
                passed[top.node] = passed[top.node] || top.passed;
            }

            for(auto pair : child[top.node]) {
                if(dist[pair.first] < top.distance + pair.second) continue;
                pq.emplace(pair.first, top.distance + pair.second, top.passed || 
                (top.node == conf1 && pair.first == conf2) || 
                (top.node == conf2 && pair.first == conf1));
            }
        }
        vector<int> ansvec;

        for(int i : dests) 
            if(passed[i]) ansvec.push_back(i);
        sort(ansvec.begin(), ansvec.end());
        for(int i : ansvec)
            cout << i << " ";

        cout << "\n";
    }
}
