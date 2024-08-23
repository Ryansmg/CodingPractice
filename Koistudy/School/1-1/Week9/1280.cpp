#include <bits/stdc++.h>
using namespace std;

int f(int i) {
    int t = 1;
    int t2 = 1;
    int ans = 0;
    while(t<=i) t *= 10;
    t /= 10;
    while(t>=1) {
        ans += (i%(t*10))/t*t2;
        t /= 10;
        t2 *= 10;
    }
    return ans;
}

bool is_Pal(int i) {
    return i == f(i);
}

int main()
{
    int t; cin >> t; cout << f(t);
}