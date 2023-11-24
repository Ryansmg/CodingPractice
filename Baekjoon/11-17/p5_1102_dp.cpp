#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define ll long long

bool contains(ll bitmask, int num) //num번째 발전소가 작동 중인지를 반환
{
    return (bitmask >> num) % 2;
}

ll addMask(ll bitmask, int num) //bitmask에 num번째 발전소가 작동함을 표시
{
    return bitmask | (1<<num);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; //발전소 개수
    cin >> n;
    vector<vector<int>> cost; //[이용하는발전소][고칠발전소] 비용
    for(int i=0; i<n; i++)
    {
        vector<int> temp;
        cost.push_back(temp);
        for(int j=0; j<n; j++){
            int a; cin >> a;
            cost[i].push_back(a);
        }
    }
    string s; cin >> s;
    int working = 0; //현재 작동 발전소 수
    ll beginMask = 0;
    int iii=0;
    for(char c : s) {
        if(c=='Y') {
            working++;
            beginMask = addMask(beginMask, iii);
        }
        iii++;
    }
    map<ll, int> pre; //<bitmasking, 최소비용>
    pre.insert({beginMask, 0});
    map<ll, int> now; //<bitmasking, 최소비용>
    int p; cin >> p; //최소 작동 발전소
    while(working < p)
    {
        for(auto & ptr : pre) {
            for(int i=0; i<n; i++) { //target
                if(contains( ptr.first, i )) continue;
                ll nowbm = addMask(ptr.first, i);

                for(int j=0; j<n; j++) { //base
                    if(!contains(ptr.first, j)) continue;
                    if(i==j) continue;
                    auto fptr = now.find(nowbm);
                    if(fptr == now.end()) now.insert({nowbm, ptr.second + cost[j][i] });
                    else {
                        fptr->second = min(fptr->second, ptr.second + cost[j][i]);
                    }
                }
            }
        }

        pre = now;
        map<ll, int> temp; now = temp;
        working++;
    }

    ll ans = -1;
    for(auto pair : pre) {
        if(ans == -1) ans = pair.second;
        else ans = min(ans, (ll) pair.second);
    }
    cout << ans;
}
