#include <iostream>
using namespace std;
#define ll long long

ll max(ll a, ll b) {
    return a>b?a:b;
}
int main() {
    ll n;
    cin >> n;
    if(n%4==0) cout << "YES";
    else cout << "NO";
}
