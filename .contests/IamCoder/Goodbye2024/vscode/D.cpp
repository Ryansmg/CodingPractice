#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
int n, c = 1;
vector<pair<int, int>> vpii;

signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    int m = n/2;
    if (n%2) {

        cout << m*(m+1) << endl;
        if (m*(m+1) > 1000000) return 0;
        for (int i = 1; i < n; i++) {

            for (int j = 1; j <= min(i, n-i); j++) {

                vpii.clear();
                for (int k = j; k+i <= n; k+=i) vpii.push_back({k, k+i});
                cout << vpii.size() << ' ';
                for (pair<int, int> pii : vpii) cout << pii.first << ' ' << pii.second << ' ';
                cout << endl;

            }

        }

    }
    else {

        cout << m*m << endl;
        if (m*m > 1000000) return 0;
        for (int i = 1; i < n; i++) {

            for (int j = 1; j <= min(i, n-i); j++) {

                vpii.clear();
                for (int k = j; k+i <= n; k+=i) vpii.push_back({k, k+i});
                cout << vpii.size() << ' ';
                for (pair<int, int> pii : vpii) cout << pii.first << ' ' << pii.second << ' ';
                cout << endl;

            }

        }

    }

}