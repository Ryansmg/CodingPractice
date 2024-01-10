#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//큰 수 만들기

struct cmp {
    bool operator() (string a, string b)
    {
        if(a.compare(b)==0) return false;
        string c = a+b, d= b+a;
        return stoull(c) < stoull(d);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    priority_queue<string, vector<string>, cmp> pq;
    int n; cin >> n; bool iszero=true;
    for(int i=0; i<n; i++)
    {
        string s; cin >> s; pq.push(s);
        if(iszero) {
            if(s.compare("0")!=0) iszero=false;
        }
    }
    if(iszero) {
        cout << 0; return 0;
    }
    while(!pq.empty()) {
        cout<<pq.top(); pq.pop();
    }
}
