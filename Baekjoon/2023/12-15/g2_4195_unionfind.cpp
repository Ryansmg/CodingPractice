//친구 네트워크 (분리 집합, Union-Find)

#include <iostream>
#include <vector>
#include <map>
#define ll long long
using namespace std;

map<string, pair<string, int>> parent;

map<string, pair<string, int>>::iterator findRoot(string name){
    auto par = parent.find(name);
    if(name.compare(par->second.first)==0) return par;
    auto a = findRoot(par->second.first);
    parent.find(name)->second.first = a->second.first;
    return a;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll testcaseN; cin >> testcaseN;

    for(int tcn=0; tcn< testcaseN; tcn++)
    {
        map<string, pair<string, int>> temp;
        parent = temp;
        int edgeN; cin >> edgeN;
        for(int i=0; i<edgeN; i++)
        {
            string a, b;
            cin >> a >> b;
            if(parent.find(a)==parent.end()) parent.insert({ a, {a, 1} });
            if(parent.find(b)==parent.end()) parent.insert({ b, {b, 1} });
            auto pra = findRoot(a), prb = findRoot(b);
            if(pra->second.first.compare(prb->second.first) != 0) {
                parent.find(prb->second.first)->second.first = pra->second.first;
                pra->second.second += prb->second.second;
            }
            cout << pra->second.second << "\n";
        }
    }
}
