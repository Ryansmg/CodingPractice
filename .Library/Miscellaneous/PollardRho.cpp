/* Update : 2025-04-09 */

#include <bits/stdc++.h>

// replace __int128 with long long to use in Codeforces
namespace PollardRho {
    namespace itnl {
        template <typename T> inline T pw_(T a, T b, T mod) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
        std::vector<__int128>base={2,3,5,7,11,13,17,19,23,29,31,37,41};std::mt19937 gen=std::mt19937(std::random_device()());std::uniform_int_distribution<long long>dis;
        bool _isPrime(__int128 n,__int128 a){if(a%n==0){return true;}__int128 d=n-1;while(true){__int128 t=itnl::pw_(a,d,n);if(t==n-1){return true;}
                if(d%2==1){return(t==1||t==n-1);}d/= 2;}}
    }
    bool isPrime(__int128 n){if(n<=1)return false;for(const __int128&a:itnl::base){if(!itnl::_isPrime(n, a))return false;}return true;}
    __int128 factorize(__int128 n){assert(n>=2);if(n%2==0){return 2;}if(isPrime(n)){return n;}__int128 x=itnl::dis(itnl::gen)%(n-2)+2,y=x,
                c=itnl::dis(itnl::gen)%10+1,g=1;while(g==1){x=(x*x%n+c)%n;y=(y*y%n+c)%n;y=(y*y%n+c)%n;g=std::gcd(x-y>0?x-y:y-x,n);
            if(g==n)return factorize(n);}if(isPrime(g)){return g;}else return factorize(g);}
    std::vector<long long> getPrimes(__int128 n) { std::vector<long long> r; while(n != 1) { __int128 p = factorize(n); r.emplace_back(p); n /= p; } return r; }
}
using namespace PollardRho;

// Example : BOJ 4149. 큰 수 소인수분해
int main() {
    using namespace std;
    long long i = 0; cin >> i;
    auto ans = getPrimes(i);
    ranges::sort(ans);
    for(long long a : ans) cout << a << '\n';
}