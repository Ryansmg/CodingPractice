#include <bits/stdc++.h>
using namespace std;

int n, m;;

int main() {

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= m; j++) {

            cout << (i+j*2)%5+1 << ' ';

        }
        cout << '\n';

    }

}