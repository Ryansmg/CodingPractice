#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int have50 = 0;
    int have25 = 0;
    for(int i=0; i<n; i++) {
        int a; cin >> a;
        if(a==25) have25++;
        if(a==50) {
            if(!have25) {
                cout << "NO";
                return 0;
            }
            have50++;
            have25--;
        }
        if(a==100) {
            if(have50&&have25) {
                have50--; have25--;
            }
            else if(have25>=3) {
                have25-=3;
            }
            else {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}