#include <stdio.h>
#define ll long long
#define isprime 0
#define isnotprime 1

int main()
{
    ll n; scanf("%lld", &n);
    ll f = n;
    ll len = 0;
    while(len*len<=n) len++;
    ll isPrime[len+100] = {0};
    for(ll i=2; i<=len+99; i++) 
    {
        if(isPrime[i] == isnotprime) continue;
        for(ll j = i+i; j<=len+99; j+=i) isPrime[j] = isnotprime;
        while(f%i==0) {
            f /= i;
            printf("%lld ", i);
        }
        if(f==1) break;
    }
    if(f!=1) printf("%lld", f);
}
