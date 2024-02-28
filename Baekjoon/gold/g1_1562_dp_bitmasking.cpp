#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define ll long long

//계단 수

int addMask(int base, int i)
{
    return base | 1<<i;
}

ll stairNum(int length)
{
    vector<map<int, int>> pre; //pre[마지막 자리 수] -> map {bitmask, count}
    vector<map<int, int>> now;
    for(int i=0; i<10; i++) { map<int,int> temp2; pre.push_back(temp2);}
    for(int i=0; i<10; i++) { map<int,int> temp2; now.push_back(temp2);}
    for(int i=1; i<=9; i++) pre[i].insert({addMask(0,i), 1});
    
    for(int i=2; i<=length; i++)
    {
        for(int j=0; j<=9; j++)
        {
            if(j>0) {
                for(auto k : pre[j-1]) {
                    int base = addMask(k.first, j);
                    auto it = now[j].find(base);
                    if (it == now[j].end()) now[j].insert({base, k.second});
                    else {it->second += k.second; it->second %= 1000000000;}
                }
            }
            if(j<9) {
                for(auto k : pre[j+1]) {
                    int base = addMask(k.first, j);
                    auto it = now[j].find(base);
                    if (it == now[j].end()) now[j].insert({base, k.second});
                    else {it->second += k.second; it->second %= 1000000000;}
                }
            }
        }
        
        pre = now;
        
        vector<map<int, int>> temp;
        for(int l=0; l<10; l++) { map<int, int> temp2; temp.push_back(temp2);}
        now = temp;
    }
    ll a = 0;
    for( auto v : pre ){
        auto it = v.find(1023);
        if(it != v.end()) {
            a += (it->second % 1000000000);
            a %= 1000000000;
        }
    }
    return a % 1000000000;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int length;
    cin >> length;

    cout << stairNum(length);
}
