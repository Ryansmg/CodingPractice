#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long x, y, a, b;
    cin >> x >> y >> a >> b;
    if(a*2<b || a*b<0) {
        cout << (abs(x) + abs(y)) * a;
        return 0;
    }
    long long m = min(x, y);
    cout << m*b + abs(y-x)*a;
}