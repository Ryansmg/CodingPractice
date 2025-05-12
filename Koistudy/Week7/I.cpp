#include <iostream>
#include <vector>
using namespace std;

long long fac[300001];
long long edge_count[300001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int w, h, s1, s2, g1, g2;
    cin >> w >> h >> s1 >> s2 >> g1 >> g2;
    vector<vector<long long>> arr(h + 1, vector<long long>(w + 1, 0));
    arr[s2][s1] = 1;
    for(int r = 1; r <= h; r++) {
        int cw = r%2 ? w : w-1;
        for(int c = 1; c <= cw; c++) {
            if(c < cw) arr[r][c+1] += arr[r][c];
            if(r == h) continue;

            if(r%2) arr[r+1][c-1] += arr[r][c];
            else arr[r+1][c+1] += arr[r][c];
            arr[r+1][c] += arr[r][c];
        }
    }
    cout << arr[g2][g1] << '\n';
}
