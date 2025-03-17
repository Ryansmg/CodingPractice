#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
ull pow(ull a, ull b, ull mod) {
    ull ans = 1;
    while(b) {
        if(b&1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
ll gcd(ll a, ll b) {
    if(a>b) swap(a, b);
    while(a) {
        b%=a;
        swap(a, b);
    }
    return b;
}
ll lcm(ll a, ll b) {
    return a/gcd(a, b)*b;
}
ll lcm(ll a, ll b, ll c) {
    return lcm(lcm(a, b),c);
}

// 소수면 1, 합성수면 0을 반환
int isPrime(int n) {
	if (n <= 1) return 0;
	int PrimeArray[n+1];

	for (int i = 2; i <= n; i++) {
		PrimeArray[i] = 1;
	}
	
	//모든 수에 대해서 체크
	for (int i = 2; i * i <= n; i++) {
		if (!PrimeArray[i]) continue;
		//i가 소수인 경우 모든 i의 배수에 표시한다.
		for (int j = i * i; j <= n; j += i) {
			PrimeArray[j] = 0;
		}
	}

	return PrimeArray[n];
}

int main()
{
    for(int i=2; i<=20; i++) {
        cout << i << ": " << isPrime(i) << endl;
    }
}
