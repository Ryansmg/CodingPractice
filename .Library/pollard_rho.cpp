#include <iostream>
#include <vector>
#include <algorithm>
#define i128 __int128
using namespace std;

// 4149. 큰 수 소인수분해
// #miller_rabin #pollard_rho

i128 base[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

i128 pow_(i128 a, i128 b, i128 mod) {
    a %= mod;
    i128 ans = 1;
    while(b) {
        if(b&1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

bool _isPrime(i128 n, i128 a) {
    if(a % n == 0) return true;
    i128 d = n - 1;
    while(true) {
        i128 temp = pow_(a, d, n);
        if(temp == n-1) return true;
        if(d%2 == 1) return (temp == 1 || temp == n-1);
        d /= 2;
    }
}

bool isPrime(i128 n) {
    for(i128 a : base) 
        if(!_isPrime(n, a)) return false;
    return true;
}

i128 gcd_(i128 a, i128 b) {
    if(a<b) swap(a, b);
    while(b!=0) {
        i128 r = a % b;
        a = b; b = r;
    }
    return a;
}

i128 factorize(i128 n) {
    if(n%2 == 0) return 2;
    if(isPrime(n)) return n;
    i128 x = rand()%(n-2) + 2, y = x, c = rand()%10 + 1, g = 1;
    while(g==1) {
        x = (x*x%n+c)%n;
        y = (y*y%n+c)%n;
        y = (y*y%n+c)%n;
        g = gcd_(x-y>0?x-y:y-x, n);
        if(g==n) return factorize(n);
    }
    if(isPrime(g)) return g;
    else return factorize(g);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    unsigned long long n; cin >> n;
    vector<i128> ans;
    while(n > 1) {
        i128 div = factorize(n);
        ans.push_back(div);
        n /= div;
    }
    sort(ans.begin(), ans.end());
    for(unsigned long long i : ans) cout << i << "\n";
}
