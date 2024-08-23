#include <iostream>
#define ll long long
using namespace std;
int main()
{
    ll x, y, n;
    cin >> x >> y >> n;
    ll a = n/x;
    //k = ax+y <= n
    a = a*x+y;
    if(a>n) a-=x;
    cout << a;
}