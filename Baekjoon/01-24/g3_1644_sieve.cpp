//소수의 연속합
//(에라토스테네스의 체)

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;
    vector<int> primes; int primeslen = 0;
    vector<int> pss;
    pss.push_back(0);
    int p = 2;
    while(true){
        while(p<n+1 && !isPrime[p]) p++;
        if(p==n+1) break;
        primes.push_back(p); primeslen++;
        if(primeslen<=1) pss.push_back(p);
        else pss.push_back(pss[primeslen-1] + p);
        for(int i=p*2; i<=n; i+=p) {
            isPrime[i] = false;
        }
        p++;
    }
    int ans=0;
    for(int i = 0; i <= primeslen-1; i++) {
        for(int j = i+1; j <= primeslen; j++) {
            if(pss[j]-pss[i]==n) {
                ans++;
            } else if(pss[j]-pss[i]>n) break;
        }
    }
    cout << ans;
}