#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
};

int main()
{
    int n, m;
    cin >> n >> m; //n: 섬, m: 다리
    vector<pair<int, int>> childd;
    vector<vector<pair<int, int>>> child(n+1, childd); //<노드, 가중치>
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        child[a].push_back({b, c});
        child[b].push_back({a, c});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
}