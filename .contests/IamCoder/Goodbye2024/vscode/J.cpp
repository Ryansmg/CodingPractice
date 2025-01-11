#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n, c = 1;

int main() {

    cin >> n;
    cout << 2*n-1 << endl;
    for (int i = 1; i < n; i++) {

        cout << (i-1)*(n+1)+1 << ' ' << i*(n+1)-1 << ' ' << i << ' ' << '1' << endl;
        cout << i*(n+1) << ' ' << i*(n+1) << ' ' << n << ' ' << i+1 << endl;

    }
    cout << n*n << ' ' << n*n << ' ' << n << ' ' << 1 << endl;

}