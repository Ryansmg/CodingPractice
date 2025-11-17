#include "hack.h"
#include <bits/stdc++.h>

using i64 = long long;
using namespace std;
#define forf(i, a, b) for(i64 i = a; i <= b; i++)
#define forr(i, a, b) for(i64 i = b; i >= a; i--)
#define all(x) (x).begin(), (x).end()

std::random_device mrdvce_; std::mt19937 m1gn_(mrdvce_());
std::uniform_int_distribution<long long> uni3i64_(0, 9223372036854775807);
#define rand rand_
inline long long randl() { return uni3i64_(m1gn_); }
inline long long rand_(long long l_, long long r_) { return randl() % (r_ - l_ + 1) + l_; } /// inclusive
inline long long rand_(long long n_) { return rand_(0, n_-1); }

template <typename Iter> void shuffle(Iter first, Iter last) {
    if (first == last) return;
    for (Iter i = first + 1; i != last; ++i)
        std::iter_swap(i, first + rand(int(i - first) + 1));
}
template <typename T> void shuffle(T& arr) { shuffle(arr.begin(), arr.end()); }


namespace pRho {
    template <typename T> inline T pw_(T a, T b, T mod) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
    std::vector<__int128>base={2,3,5,7,11,13,17,19,23,29,31,37,41};std::mt19937 gen=std::mt19937(std::random_device()());std::uniform_int_distribution<long long>dis;
    bool _isPrime(__int128 n,__int128 a){if(a%n==0){return true;}__int128 d=n-1;while(true){__int128 t=pRho::pw_(a,d,n);if(t==n-1){return true;}
        if(d%2==1){return(t==1||t==n-1);}d/= 2;}}
    template <typename T> inline T gcd(T a,T b){if(a<b)swap(a,b);while(b){T r=a%b;a=b;b=r;}return a;}
}
bool isPrime(long long n){if(n<=1)return false;for(const __int128&a:pRho::base){if(!pRho::_isPrime(n, a))return false;}return true;}
long long factorize(long long n){assert(n>=2);if(n%2==0){return 2;}if(isPrime(n)){return n;}__int128 x=pRho::dis(pRho::gen)%(n-2)+2,y=x,
            c=pRho::dis(pRho::gen)%10+1,g=1;while(g==1){x=(x*x%n+c)%n;y=(y*y%n+c)%n;y=(y*y%n+c)%n;g=pRho::gcd(x-y>0?x-y:y-x,(__int128)n);
                if(g==n)return factorize(n);}if(isPrime(g)){return g;}else return factorize(g);}
std::vector<long long> getPrimes(long long n) { std::vector<long long> r; while(n != 1) { long long p = factorize(n); r.emplace_back(p); n /= p; } return r; }


i64 a, b;

vector<i64> concat(const vector<i64>& a, const vector<i64>& b) {
    vector<i64> ret(a.size() + b.size());
    forf(i, 0, i64(a.size())-1) ret[i] = a[i];
    forf(i, 0, i64(b.size())-1) ret[i+a.size()] = b[i];
    return ret;
}

void findTwo(vector<i64> l, vector<i64> r) {
    while(l.size() > 1 || r.size() > 1) {
        if(l.size() > r.size()) {
            i64 lsz = l.size();
            vector<i64> ll(lsz/2), lr(lsz - lsz/2);
            forf(i, 0, lsz/2-1) ll[i] = l[i];
            forf(i, lsz/2, lsz-1) lr[i-lsz/2] = l[i];
            if(collisions(concat(lr, r))) l = lr;
            else l = ll;
        }
        else {
            i64 rsz = r.size();
            vector<i64> rl(rsz/2), rr(rsz - rsz/2);
            forf(i, 0, rsz/2-1) rl[i] = r[i];
            forf(i, rsz/2, rsz-1) rr[i-rsz/2] = r[i];
            if(collisions(concat(l, rl))) r = rl;
            else r = rr;
        }
    }
    a = l[0]; b = r[0];
}

#ifdef LOCAL
#define lprintf printf
#else
#define lprintf(...)
#endif

vector<i64> L, R;

int hack(){
    if(L.empty()) {
        forf(i, 1, 26000) L.push_back(i);
        for(i64 i = 26000 * (500'000'000 / 2 / 26000); i <= 1'000'026'000; i += 26000)
            R.push_back(i);
    }

    findTwo(L, R);

    i64 n = abs(a - b);
    map<i64, i64> ps;
    for(const i64& i : getPrimes(n)) ps[i]++;

    i64 ans = n;
    for(const auto& [p, c] : ps) {
        while(ans % p == 0 && collisions({1, 1 + ans/p})) ans /= p;
    }
    return ans;
}
