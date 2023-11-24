#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define inf 2147000000

//네트워크 복구

struct TRI { 
    int node, //정점 번호
    dist; //최단 거리
    vector<int> preNodes; //이전 노드
    TRI(int a, int b, vector<int> c) {
        node = a; dist = b; preNodes = c;
    }
    TRI(){}
} typedef tri;

struct NP {
    int node, //정점 번호
    weight; //가중치
    NP(int a, int b) {
        node = a; weight = b;
    }
    NP(){}
} typedef npair;

struct cmp {
    bool operator() (tri a, tri b){
        return a.dist>b.dist;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; //컴퓨터의 개수
    int m; //회선의 개수
    cin >> n >> m;
    vector<vector<npair>> child(n+1); //[컴퓨터 번호] -> {<자식 번호, 가중치>}
    for(int i=0; i<m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        child[a].emplace_back(b, c);
        child[b].emplace_back(a, c);
    }

    set<string> recovered;
    vector<int> onevec; onevec.push_back(1);

    for(int dest = 1; dest<=n; dest++)
    {
        priority_queue<tri, vector<tri>, cmp> pq;
        vector<int> dist(n+1, inf);
        dist[1] = 0;
        for(auto pair : child[1]) {
            pq.emplace(pair.node, pair.weight, onevec);
        }

        tri t;
        bool tset = false;
        int tnum = 0;

        while(!pq.empty()) 
        {
            tri top = pq.top(); pq.pop();
            if(dist[top.node] != inf) continue;
            dist[top.node] = top.dist;
            if(dest == top.node) {
                if(!tset) {
                    tset=true; t = top;
                    int len = t.preNodes.size();
                    for(int i=0; i<len-1; i++)
                    {
                        string s = to_string(t.preNodes[i]) + " " + to_string(t.preNodes[i+1]);
                        if(recovered.find(s)==recovered.end()) tnum++;
                    }
                } else {
                    int len = top.preNodes.size();
                    int tnum2 = 0;
                    for(int i=0; i<len-1; i++)
                    {
                        string s = to_string(top.preNodes[i]) + " " + to_string(top.preNodes[i+1]);
                        if(recovered.find(s)==recovered.end()) tnum2++;
                    }
                    if(tnum2 < tnum) t = top;
                }
            }
            for(auto pair : child[top.node]) 
            {
                if(dist[pair.node] <= top.dist + pair.weight) continue;
                vector nvec = top.preNodes;
                nvec.push_back(top.node);
                pq.emplace(pair.node, top.dist + pair.weight, nvec);
            }
        }

        //cout << "1->" << dest << ": " << dist[dest] << '\n';
        t.preNodes.push_back(dest);
        int len = t.preNodes.size();
        for(int i=0; i<len-1; i++)
        {
            string s = to_string(t.preNodes[i]) + " " + to_string(t.preNodes[i+1]);
            if(recovered.find(s)==recovered.end()) recovered.insert(s);
        }
    }

    cout << recovered.size() << "\n";
    for(string s : recovered) cout << s << "\n";
}
