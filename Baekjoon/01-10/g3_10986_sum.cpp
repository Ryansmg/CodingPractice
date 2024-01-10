#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> sum(n+1);
    vector<ll> ans(m, 0);
    sum[0] = 0;
    ans[0] = 1;
    for(int i=1; i<=n; i++) {
        int a; cin >> a;
        sum[i] = sum[i-1] + a;
        sum[i] %= m;
        ans[sum[i]]++;
    }
    ll answer=0;
    for(ll l : ans) {
        answer += l*(l-1)/2;
    }
    cout << answer;
}
