#define cc(a, b) a##b
#include <bits/stdc++.h>
using namespace std;

#define ff(i, a, b) cc(fo,r)(int i=a; i<=b; i++)

int main() {
    __int128 ans = 1; long long n, k;
    cin >> n >> k; n--; k--;
    ff(i, n-k+1, n) ans *= i;
    ff(i, 1, k) ans /= i;
    cout << static_cast<long long>(ans);
}
