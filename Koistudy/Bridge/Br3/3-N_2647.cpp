#include <iostream>
using namespace std;
#define ll long long

ll max(ll a, ll b) {
    return a>b?a:b;
}
int main() {
    ll n;
    cin >> n;
    ll a, b, c;
    cin >> a >> b >> c;
    bool canMake = a+b>c;
    for(ll i=0; i<n-3; i++) {
        a=b; b=c; cin >> c;
        if(a+b>c) canMake = true;
        if(canMake) break;
    }
    if(canMake) cout << "No";
    else cout << "Yes";
}
