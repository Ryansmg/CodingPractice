#include <iostream>
using namespace std;
#define ll long long

ll pow(ll a, ll b) {
    if(b==1) return a;
    ll mid = pow(a, b/2);
    if(b%2==0) return mid*mid;
    return mid*mid*a;
}

int main()
{
    ll p, q, r;
    cin >> p >> q >> r;
    ll pw = pow(p, q);
    ll cnt = 0;
    for(ll i=1; i<pw; i++) {
        ll a = i;
        while(1) {
            if(a%p==0) {
                if(a/p==r) cnt++;
                break;
            } else {
                ll temp=0;
                if((a%p)*2 >= p) temp=1;
                a = a/p+temp;
            }
        }
    }
    cout << cnt;
}