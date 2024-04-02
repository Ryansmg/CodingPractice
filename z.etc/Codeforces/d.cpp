#include <iostream>
#include <vector>
using namespace std;

int pow(int a, int b) {
    if(b==1) return a;
    if(b==0) return 1;
    return a*pow(a, b-1);
}

int getBin(int i) {
    int bin=0;
    for (int j = 6; j >= 0; j--) {
        int temp = (i >> j) & 1;
        bin += pow(10, j) * temp;
    }
    return bin;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for(int ti=0; ti<t; ti++) {
        int n; cin >> n;
        for(int i=32; i>=2; i--) {
            int bin = getBin(i);
            //cout << bin << "\n";
            while(n%bin==0) n/=bin;
            if(n==1) {
                cout << "YES\n";
                break;
            }
            if(i==2) {
                cout << "NO\n";
            }
        }
    }
}
