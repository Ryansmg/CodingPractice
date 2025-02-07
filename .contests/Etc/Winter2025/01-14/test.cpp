#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define N 300000

int main() {
    fastio;
    int n, k; cin >> n >> k;
    vector<vector<bitset<N>>> bs(3, vector<bitset<N>>(k, bitset<N>()));
    vector<vector<int>> arr(n, vector<int>(k));
    for (int i = 0; i < n; i++) for (int j = 0; j < k; j++) cin >> arr[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            bs[0][j][i] = bs[1][j][i] = bs[2][j][i] = true;
            bs[arr[i][j] - 1][j][i] = false;
        }
    }

    int mn = 2147481557, mx = 0;

    if (k == 9) {
        for (int i1 = 0; i1 < 3; i1++) {
            for (int i2 = 0; i2 < 3; i2++) {
                for (int i3 = 0; i3 < 3; i3++) {
                    for (int i4 = 0; i4 < 3; i4++) {
                        for (int i5 = 0; i5 < 3; i5++) {
                            for (int i6 = 0; i6 < 3; i6++) {
                                for (int i7 = 0; i7 < 3; i7++) {
                                    for (int i8 = 0; i8 < 3; i8++) {
                                        for (int i9 = 0; i9 < 3; i9++) {
                                            int c = (bs[i1][0] & bs[i2][1] & bs[i3][2] & bs[i4][3] & bs[i5][4] &
                                                     bs[i6][5] & bs[i7][6] & bs[i8][7] & bs[i9][8]).count();
                                            mn = min(mn, c);
                                            mx = max(mx, c);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        for (int i1 = 0; i1 < 3; i1++) {
            for (int i2 = 0; i2 < 3; i2++) {
                for (int i3 = 0; i3 < 3; i3++) {
                    for (int i4 = 0; i4 < 3; i4++) {
                        for (int i5 = 0; i5 < 3; i5++) {
                            for (int i6 = 0; i6 < 3; i6++) {
                                for (int i7 = 0; i7 < 3; i7++) {
                                    int c = (bs[i1][0] & bs[i2][1] & bs[i3][2] & bs[i4][3] & bs[i5][4] &
                                             bs[i6][5] & bs[i7][6]).count();
                                    mn = min(mn, c);
                                    mx = max(mx, c);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << mn << ' ' << mx << '\n';
}
