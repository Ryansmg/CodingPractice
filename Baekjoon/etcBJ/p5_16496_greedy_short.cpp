#include <iostream>
#include <vector>
#include <queue>
using namespace std;struct cmp{bool operator()(string a, string b){if(a.compare(b)==0)return false;string c=a+b,d=b+a;return stoull(c)<stoull(d);}};int main(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);priority_queue<string,vector<string>,cmp> q;int n;cin>>n;bool z=1;for(int i=0;i<n;i++){string s;cin>>s;q.push(s);if(z&&s.compare("0")!=0)z=false;}if(z){cout<<0;return 0;}while(!q.empty()){cout<<q.top();q.pop();}}