#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);int n;cin>>n
#define lint __int128
using namespace std;lint LINTMAX = ((lint(1)<<126)-1)*2+1;template <typename T>
using v = vector<T>;void e(int i){cout<<i;exit(0);}
#define all(vec) (vec).begin(), (vec).end()

class pollard_rho {
public:
    explicit pollard_rho() {
        base = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
        gen = mt19937(random_device()());
    }
    bool isPrime(lint n) {
        if(n<=1) return false;
        for(const lint &a: base) if (!_isPrime(n, a)) return false;
        return true;
    }
    lint factorize(const lint &n) {
        if (n % 2 == 0) return 2;
        if (isPrime(n)) return n;
        lint x = dis(gen) % (n - 2) + 2, y = x, c = dis(gen) % 10 + 1, g = 1;
        while (g == 1) {
            x = (x * x % n + c) % n;
            y = (y * y % n + c) % n;
            y = (y * y % n + c) % n;
            g = gcd(x - y > 0 ? x - y : y - x, n);
            if (g == n) return factorize(n);
        }
        if (isPrime(g)) return g;
        else return factorize(g);
    }
    static lint pow(lint a, lint b, lint mod) {
        a %= mod;
        lint ans = 1;
        while (b) {
            if (b & 1) ans = ans * a % mod;
            b >>= 1;
            a = a * a % mod;
        }
        return ans;
    }
    static lint gcd(lint a, lint b) {
        if (a < b) swap(a, b);
        while (b != 0) {
            lint r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
private:
    v<lint> base;
    mt19937 gen;
    uniform_int_distribution<lint> dis;
    static bool _isPrime(lint n, lint a) {
        if (a % n == 0) return true;
        lint d = n - 1;
        while (true) {
            lint temp = pow(a, d, n);
            if (temp == n - 1) return true;
            if (d % 2 == 1) return (temp == 1 || temp == n - 1);
            d /= 2;
        }
    }
};

// 17633. 제곱수의 합 (More Huge)
// #pollard_rho #miller_rabin #math

// 라그랑주의 네 제곱수 정리
//   모든 자연수는 4개 이하의 제곱수의 합으로 나타낼 수 있다.
// 르장드르의 세 제곱수 정리
//   4^a(8b+7) 꼴이 아닌 모든 자연수는 3개 이하의 제곱수의 합으로 나타낼 수 있다.
// 페르마의 두 제곱수 정리
//   어떤 자연수가 두 제곱수의 합으로 나타내어지려면 소인수분해한 항 중 p^k가 없어야 함.
//   이때 p는 4n+3 꼴의 소수, k는 홀수

signed main() {
    fastio;
    while (n % 4 == 0)n /= 4;
    if ((int) sqrt(n) * (int) sqrt(n) == n)e(1);
    if (n % 8 == 7)e(4);
    int a = n;
    v<int> r;
    pollard_rho p;
    set<int> s;
    while (a != 1) {
        int i = (int) p.factorize(a);
        if (s.find(i) != s.end())
            s.erase(i);
        else s.insert(i);
        a /= i;
    }
    for (int i: s)if (i % 4 == 3)e(3);
    e(2);
}
