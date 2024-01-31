#include <iostream>
#include <vector>
#define ll long long
#define arrlen 1000001
using namespace std;

//약수의 합
//누적 합 + 에라토스테네스의 체

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll t; cin >> t;
    ll ssp[arrlen] = {0};
    for(ll i=1; i<arrlen; i++) {
        for(ll j=i; j<arrlen; j+=i) {
            ssp[j] += i;
        }
    }
    ll ss[arrlen] = {0};
    for(ll i=1; i<arrlen; i++) ss[i] = ss[i-1] + ssp[i];
    for(ll wgb=0; wgb<t; wgb++)
    {
        ll n; cin >> n;
        cout << ss[n] << "\n";
    }
}
