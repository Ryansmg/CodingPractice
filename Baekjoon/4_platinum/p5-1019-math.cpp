#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans[10] = {0};
int t = 1;
void add(int i) {
    while(i>0){
        ans[i%10]+=t;
        i/=10;
    }
}
signed main()
{
    int m=1, n; cin >> n;
    while(true) {
        while(m%10!=0 && m<=n) {
            add(m); m++;
        }
        if(m==n && m==10) add(m);
        if(m>=n) break;
        while((n%10)!=9) {
            add(n); n--;
        }
        int ii = (n/10)-(m/10)+1;
        for(int i=0; i<=9; i++) ans[i] += ii*t;
        n/=10;
        m/=10;
        t*=10;
    }
    for(int i=0; i<=9; i++) cout << ans[i] << " ";
}