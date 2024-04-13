#include <iostream>
using namespace std;
#define ll long long

int main()
{
    ll n, m;
    cin >> n >> m;
    if(n >= m) {
        cout << 0;
        return 0;
    }
    ll ans = 1;
    for(ll i = 1; i <= n; i++) {
        ans *= i;
        ans %= m;
    }
    cout << ans;
}