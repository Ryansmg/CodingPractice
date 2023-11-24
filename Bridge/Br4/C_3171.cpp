#include <iostream>
using namespace std;
#define ll long long

int main() {
    ll a, b, A, B;
    cin >> a >> b >> A >> B;
    ll s = A*a + B*b;
    if(s>=10000) s-=1000;
    cout << s;
}