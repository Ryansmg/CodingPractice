#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;

//2473. 세 용액
//#two_pointers

int main()
{
    ll n; cin >> n;
    vector<ll> lq;
    for(int i=0; i<n; i++) {
        int a; cin >> a; lq.push_back(a);
    }
    sort(lq.begin(), lq.end());
    ll ans = 21480000000; vector<ll> ansv(3,3);
    for(int i=0; i<n-2; i++) {
        ll ind1 = i+1, ind2 = n-1;
        while(true){
            if(abs(ans) > abs(lq[i] + lq[ind1] + lq[ind2])) {
                ans = lq[i] + lq[ind1] + lq[ind2];
                ansv[0] = lq[i];
                ansv[1] = lq[ind1];
                ansv[2] = lq[ind2];
            }
            if(ind1 + 1 == ind2) break;
            if(lq[i] + lq[ind1] + lq[ind2] == 0) break;
            if(lq[i] + lq[ind1] + lq[ind2] > 0) ind2--;
            else ind1++;
        }
        if(ans==0) break;
    }
    sort(ansv.begin(), ansv.end());
    for(ll i : ansv) cout << i << " ";
}