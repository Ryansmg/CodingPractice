#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a;
    for(int i=0; i<n; i++) {
        int b; cin >> b; a.push_back(b);
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    for(int i=n; i>=1; i--) ans += i * a[n-i];
    cout << ans;
}