#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//멀티탭 스케줄링

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> used(n,0);
    vector<int> in(k);
    int ans = 0;
    for(int i=0; i<k; i++) cin >> in[i];
    int found = 0;
    for(int i=0; i<=k; i++) {
        if(i==k) {
            cout << 0;
            return 0;
        }
        if(find(used.begin(), used.end(), in[i]) == used.end()){
            used[found] = in[i]; found++;
        }
        if(found==n) break;
    }
    for(int i=n; i<k; i++)
    {
        if(find(used.begin(), used.end(), in[i]) != used.end()) continue;
        vector<bool> appeared(n, false);
        for(int j=i+1; j<k; j++)
        {
            auto ptr = find(used.begin(), used.end(), in[j]);
            if(ptr!=used.end()) *(ptr-used.begin()+appeared.begin()) = true;
            int check = 0;
            for(int m=0; m<n; m++) if(appeared[m]) check++;
            if(check==n-1) break;
        }
        int l;
        for(l=0; l<n; l++) if(!appeared[l]) break;
        if(l==n) l=n-1;
        used[l] = in[i];
        ans++;
    }
    cout << ans;
    return 0;
}
