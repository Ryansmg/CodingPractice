#include <iostream>
using namespace std;
#define ll long long

int main() {
    ll n, m;
    cin >> n >> m;
    if(n<m) n *= 2;
    else m *= 2;
    cout << (n>m?n:m) * (n>m?n:m);
}