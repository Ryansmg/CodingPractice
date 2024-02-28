#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

//9527. 1의 개수 세기
//#bitmask #prefix_sum

//10010 => (0~10000) + 10 + ans(10) (모든 숫자는 이진법)
ll ans(vector<ll> &s, ll tar) {
    if(tar==1) return 1;
    if(tar<=0) return 0;
    //ll logcal = 1, log=0;
    //while(logcal <= tar) {log++; logcal <<= 1;}
    //log--; logcal >>= 1;
    //ll a = s[log-1] + (tar - logcal + 1) + ans(s, tar - logcal);
    ll l2 = log2(tar);
    ll a = s[l2-1] + (tar - (1ll << l2) + 1) + ans(s, tar - (1ll<<l2));
    return a;
}

int main()
{
    ll a, b;
    cin >> a >> b;
    vector<ll> s(1, 1); //s[n] = (0~2^(n+1)-1)에서 1의 개수
    ll j=1;
    for(int i=1; i<60; i++) {
        s.push_back(2*j + s.back()*2);
        j <<= 1;
    }
    cout << ans(s, b) - ans(s, a-1);
}
