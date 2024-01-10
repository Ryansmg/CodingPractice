#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int a, b;
    cin >> a >> b;
    int ans=1;
    while(b!=a) {
        if(a>b) {
            cout << -1; return 0;
        }
        if(b%10==1) {
            b/=10; ans++;
        } else if(b%2==0) {
            b/=2; ans++;
        } else {
            cout << -1; return 0;
        }
    }
    cout << ans;
}