#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define endl '\n'


vector<int>graph[1005];
vector<int>visited(1005);



void dfs(int a){
    int i,j,k;

    int x=graph[a].size();

    for(i=0;i<x;i++){
        if(visited[graph[a][i]]==0){
            cout << graph[a][i] << ' ';
            visited[graph[a][i]]=1;
            dfs(graph[a][i]);
        }
    }
}

void bfs(int a){
    int i,j,k;
    vector<int>temp;


    int x=graph[a].size();

    for(i=0;i<x;i++){
        if(visited[graph[a][i]]==0){
            visited[graph[a][i]]=1;
            cout << graph[a][i] << ' ';
            temp.PB(graph[a][i]);
        }
    }
    int y=temp.size();
    for(i=0;i<y;i++){
        bfs(temp[i]);
    }


}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i,j,k;

    int n,m,v;

    cin >> n >> m >> v;

    while(m){
        int a,b;
        m--;
        cin >> a >> b;
        graph[a].PB(b);
        graph[b].PB(a);
    }

    for(i=1;i<=n;i++){
        int x=graph[i].size();
        sort(&graph[i][0],&graph[i][x]);
    }

    visited[v]=1;
    cout << v << ' ';
    dfs(v);
    cout << endl;
    fill(visited.begin(),visited.end(),0);
    visited[v]=1;
    cout << v << ' ';
    bfs(v);



    return 0;
}