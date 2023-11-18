#include <iostream>
using namespace std;
#define ll long long

ll max(ll a, ll b) {
    return a>b?a:b;
}
int main() {
    ll n, first; bool same = true;
    cin >> n;
    cin >> first;
    for(int i=0; i<n-1; i++) {
        int a; cin >> a;
        if(first != a) same = false;
    }
    if(same) cout << n;
    else cout << 1;
}
