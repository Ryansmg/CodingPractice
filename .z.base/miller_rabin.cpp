#include <iostream>
#define ull unsigned long long
using namespace std;

// 5615. 아파트 임대
// #miller_rabin

// A=2xy+x+y
// 2A+1 = (2x+1)(2y+1) => 2A+1 != prime

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
    while(!d&1) {
        if (pow(a, d, n) == n-1) return true;
        d >>= 2;
    }
    ull temp = pow(a, d, n);
    return temp == 1 || temp == n-1;
}

bool isPrime(ull n) {
    for(ull a : base) 
        if(!_isPrime(n, a)) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ull n, ans = 0, t; cin >> n;
    for(ull i=0; i<n; i++) {
        cin >> t;
        ans += isPrime(2*t+1) ? 1 : 0;
    }
    cout << ans;
}