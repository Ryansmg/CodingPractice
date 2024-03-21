#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> health;
    vector<int> joy;
    vector<int> ans(100, 0);
    int t;
    for(int i=0;i<n;i++){
        cin >> t;
        health.push_back(t);
    }
    for(int i=0;i<n;i++){
        cin >> t;
        joy.push_back(t);
    }
    for(int i=0; i<n; i++){
        for(int j=99; j>=0; j--){
            if(j - health[i] < 0) continue;
            ans[j] = max(ans[j-health[i]] + joy[i], ans[j]);
        }
    }
    cout << ans[99];
}