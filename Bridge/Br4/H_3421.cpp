#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll max(ll a, ll b) {
    return a>b?a:b;
}
int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << c+d-a-b;
}