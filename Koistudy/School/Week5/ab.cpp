#include <iostream>
#define ll long long
#define ull unsigned ll
#define prb << ' '
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
    if(n==1) return false;
    for(ull a : base) 
        if(!_isPrime(n, a)) return false;
    return true;
}

ll gcd(ll a, ll b)
{
    if(a>b) swap(a, b);

    while(a != 0)
    {
        b = b%a;
        swap(a, b);
    }

    return b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int i = 1;
    cout << to_string(i);

}