#include <iostream>
#define ull unsigned long long
using namespace std;

ull base[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

ull pow(ull a, ull b, ull mod) {
    ull ans = 1;
    while(b) {
        if(b&1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

bool _isPrime(ull n, ull a) {
    if(a % n == 0) return true;
    ull d = n - 1;
    while(true) {
        ull temp = pow(a, d, n);
        if(temp == n-1) return true;
        if(d%2 == 1) return (temp == 1 || temp == n-1);
        d /= 2;
    }
}

bool isPrime(ull n) {
    if(n==1) return false;
    for(ull a : base) 
        if(!_isPrime(n, a)) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ull n, ans = 0, t; cin >> n;
    for(ull i=1; i<=n; i++) {
        ans += isPrime(i) ? i : 0;
    }
    cout << ans;
}