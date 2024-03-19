#include <iostream>
using namespace std;
#define ll long long

int main() {
    ll n, m;
    cin >> n >> m;
    if(n*m%2==0) cout << n*m/2;
    else cout << n*m/2 + 1;
}