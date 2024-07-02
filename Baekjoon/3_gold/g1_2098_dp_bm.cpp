#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long

//외판원 순회

bool contains(ll bitmask, int num)
{
    return (bitmask >> num) % 2;
}

ll addMask(ll bitmask, int num)
{
    return bitmask | (1<<num);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int a;
    cin >> a;
    vector<vector<int>> cost;
    for(int i=0; i<a; i++)
    {
        vector<int> temp;
        cost.push_back(temp);
        for(int j=0; j<a; j++)
        {
            int b;
            cin >> b;
            cost[i].push_back(b);
        }
    }

    vector<map<ll, ll>> pre(a); //pre[도시번호-1] -> map<bitmasking, 최소비용>
    vector<map<ll, ll>> now(a);
    pre[0].insert({0,0});
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<a; j++) //dep
        {
            for(int k=0; k<a; k++) //dest
            {
                if(cost[j][k]==0) continue;
                for(auto a : pre[j]){
                    if(contains(a.first, k)) continue;
                    ll mask = addMask(a.first, k);
                    auto nowPtr = now[k].find(mask);
                    if(nowPtr==now[k].end()) now[k].insert({mask, a.second + cost[j][k]});
                    else nowPtr->second = min(nowPtr->second, a.second + cost[j][k]);
                }
            }
        }
        
        pre = now;
        vector<map<ll,ll>> temp(a);
        now = temp;
    }

    ll bm = (1<<a) - 1;
    cout << pre[0].find(bm)->second;
}
