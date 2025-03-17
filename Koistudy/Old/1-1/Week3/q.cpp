#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ll a, b;
    cin >> a >> b;
    ll ans = b-a+1;
    for(ll i = 1; i*i <= b; i++) {
        if(i*i < a) continue;
        ans--;
    }
    cout << ans;
}