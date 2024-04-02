#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ll a, b, c, n;
    cin >> a >> b >> c >> n;
    for(ll ci = n/c; ci>=0; ci--) {
    for(ll bi = (n-n*ci*c)/b; bi>=0; bi--) {
        if((n-n*ci*c-n*bi*b)%a==0) {
            cout << 1;
            return 0;
        }
    }
    }
    cout << 0;
}
