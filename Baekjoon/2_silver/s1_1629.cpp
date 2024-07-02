#include <iostream>
#define ll long long
using namespace std;

ll divpow(ll base, ll exp, ll div) {
    if(exp == 1) return base % div;
    ll x = divpow(base, exp/2, div);
    if(exp%2==0) return (x * x) % div;
    else return x * x % div * base % div;
}

int main()
{
    ll base, exp, div;
    cin >> base >> exp >> div;
    cout << divpow(base, exp, div);
}