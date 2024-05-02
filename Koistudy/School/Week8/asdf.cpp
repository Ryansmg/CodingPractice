#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n; cin >> n;
    vector<int> a;
    for(int i=0; i<n; i++) {
        int t; cin >> t; a.push_back(t);
    }
    vector<int> arr;
    arr.push_back(a[0]);
    for(int i=1; i<n; i++) arr.push_back(arr[i-1] + a[i]);
    int ans = arr[0], small = 0, presmall = 0;
    for(int i=0; i<n; i++) {
        if(small > arr[i]) {
            presmall = small;
            small = arr[i];
            ans = max(ans, arr[i]-presmall);
        } else {
            ans = max(ans, arr[i]-small);
        }
    }
    cout << ans;
}
