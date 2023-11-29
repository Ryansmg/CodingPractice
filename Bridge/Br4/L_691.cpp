#include <iostream>
using namespace std;
#define ll long long

ll gcd(ll a, ll b)
{
    if(a>b) swap(a, b);

    while(a != 0)
    {
        b = b%a;
        swap(a, b);
    }

    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    int ans = 0;
    //k*(i^2-j^2), 2*k*i*j, k*(i^2+j^2)
    //i>j>0, k>0,

    char cnt[n/2+1] = {0};
    for(int i=2; i*i+i<=n; i++)
    {
        for(int j=i-1; j>0; j-=2)
        {
            if(gcd(i, j) != 1) continue;

            for(int k=1; 2*k*i*(i+j) <= n; k++) {
                int a = k*i*(i+j);
                cnt[a]++;
                if(cnt[a]==1) ans++;
                else if(cnt[a]==2) ans--;
            }
        }
    }

    cout << ans;
}