#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define llmax 9223372036854775807

int main()
{
    ll a, b;
    cin >> a >> b;
    ll an = 0, bn = 0;
    while(a>0) {
        an += a%10;
        a/=10;
    }
    while(b>0) {
        bn += b%10;
        b/=10;
    }
    cout << an*bn;
}