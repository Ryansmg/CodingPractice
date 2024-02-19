//1197 - 최소 스패닝 트리 (.z.base 확인)
//숏코딩용 (망)

#include <iostream>
#include <vector>
#include <queue>
#define l long long
using namespace std;
struct edge{l parent,target,weight;edge(l a,l b,l c){parent=a;target=b;weight=c;}edge(){}bool operator()(edge x, edge y){return x.weight>y.weight;}};
int main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
l v,e;cin>>v>>e;vector<edge> p;vector<vector<edge>> s(v+1,p);for(l i=0;i<e;i++) {l a,b,c;cin>>a>>b>>c;edge x(a,b,c),y(b,a,c);s[a].push_back(x);s[b].push_back(y);}priority_queue<edge,vector<edge>,edge> j;vector<bool> t(v+1,0);t[1]=1;for(edge e:s[1])j.push(e);l c=0,u=0;while(c<v-1){edge o=j.top();j.pop();if(t[o.target])continue;t[o.target]=1;u+=o.weight;c++;for(edge e:s[o.target]){if(!t[e.target])j.push(e);}}cout << u;}