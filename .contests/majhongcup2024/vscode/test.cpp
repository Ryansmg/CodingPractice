#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
int n, c[10], ans;
vector<int> t;
int cr[5][10];
string ss[16]= {"111", "222", "333", "444", "555", "666", "777", "888", "999", "123", "234", "345", "456", "567", "678", "789"};

set<vector<int>> sts;
int a;

void rec(vector<int> ar, int cnt) {

    if (cnt == 4) {

        if (sts.find(ar) != sts.end()) return;
        sts.insert(ar);
        int tmp = 1;
        for (int i = 1; i <= 9; i++) tmp *= cr[c[i]][ar[i]];
        ans += tmp;
        return;
    }

    vector<int> art = ar;
    for (int i = 0; i < 16; i++) {

        art = ar;
        bool can = true;
        for (char cc : ss[i]) {
            art[cc-'0']++;
            if (c[cc-'0']-art[cc-'0'] < 0) {can = false; break;}
        }
        if (can) rec(art, cnt + 1);

    }

}
#define ll long long

signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); 

    for (int i = 0; i <= 10; i++) t.pb(0);
    cr[4][0] = 1; cr[4][1] = 4; cr[4][2] = 6; cr[4][3] = 4; cr[4][4] = 1;
    cr[3][0] = 1; cr[3][1] = 3; cr[3][2] = 3; cr[3][3] = 1;
    cr[2][0] = 1; cr[2][1] = 2; cr[2][2] = 1;
    cr[1][0] = cr[1][1] = 1;
    cr[0][0] = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {

        cin >> a;
        c[a]++;

    }
    for (int i = 1; i <= 9;i++) {
        t.clear();
        t.resize(10, 0);
        t[i] += 2;
        if (c[i]-t[i] < 0) continue;
        rec(t, 0);
    }

    int A[10];
    memset(A, 0, sizeof(A));
    for (A[1] = 1;A[1]<=9;A[1]++) {
        for ( A[2] = 1;A[2]<=9;A[2]++) {
            for ( A[3] = 1;A[3]<=9;A[3]++) {
                for ( A[4] = 1;A[4]<=9;A[4]++) {
                    for ( A[5] = 1;A[5]<=9;A[5]++) {
                        for ( A[6] = 1;A[6]<=9;A[6]++) {
                            for (A[7] = 1;A[7]<=9;A[7]++) {
                                bool CAN = false;
                                for (ll k = 1;k<9;k++) {
                                    if (A[k] >= A[k+1]) {
                                        CAN = true;
                                        break;
                                    }
                                }
                                if (CAN) continue;
                                
                                vector<int> lst(10, 0);
                                for (ll k = 1;k<=9;k++)lst[A[k]] += 2;

                                if (sts.find(lst) != sts.end()) continue;

                                sts.insert(lst);
                                int tmp = 1;
                                for (int i = 1; i <= 9; i++) tmp *= cr[c[i]][lst[i]];
                                ans += tmp;
                            }
                        }
                    }
                }
            }  
        }
    }


    cout << ans;
    return 0;    
}

