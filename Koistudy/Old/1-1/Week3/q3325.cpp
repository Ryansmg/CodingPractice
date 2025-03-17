#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int ansd; cin >> ansd;
    int ans = 0;
    for(int i=0; i<=719; i+=2) {
        int a = (i*6)%360;
        int b = (i/2)%360;
        int d = abs(a-b);
        if(d>180) d = 360-d;
        if(d==ansd) ans++;
    }
    cout << ans << "\n";
    for(int i=0; i<=719; i+=2) {
        int a = (i*6)%360;
        int b = (i/2)%360;
        int d = abs(a-b);
        if(d>180) d = 360-d;
        if(d==ansd) {
            printf("%02d:%02d\n", i/60, i%60);
        }
    }
}