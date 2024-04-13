#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long in;
    cin >> in;
    int m = 0, ans = 0;
    while(in) {
        if(in&1) ans = m;
        m++;
        in >>= 1;
    }
    cout << ans + 1;
}