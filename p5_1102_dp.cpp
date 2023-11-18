#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define ll long long

//hint : dfs 비슷 && arr=dp[작동 개수][bitmask]

bool contains(ll bitmask, int num)
{
    return (bitmask >> num) % 2;
}

ll addMask(ll bitmask, int num)
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
    vector<bool> on; //작동 여부
    int working = 0;
    for(char c : s) {
        on.push_back(c=='Y');
        if(c=='Y') working++;
    }
    int p; cin >> p; //최소 작동 발전소
    map<int, int> dp; //<bitmasking, 최소비용>
    while(working < p)
    {
        
    }
}