// 11689. GCD(n, k) = 1
// #math #number_theory #euler_phi
// https://namu.wiki/w/오일러%20피%20함수
//phi(n) = n * ∏{p∣n} (1-1/p)

#include <iostream>
#define ll long long
using namespace std;

ll phi(ll n) {
    ll euler = n;
    for(ll i=2; i*i<=n; i++) {
        if(n%i==0) euler -= euler / i;
        while(n%i==0) n /= i;
    }
    //n이 소수인 경우
    if(n!=1) euler -= euler / n;
    return euler;
}

int main()
{
    ll n;
    cin >> n;
    cout << phi(n);
}