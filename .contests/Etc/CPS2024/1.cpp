#include <bits/stdc++.h>
using namespace std;

int n = 0;

int solve(short cur, int used, vector<short> arr) {
    if(cur != 16) {
        if(cur == 4 && arr[0] + arr[1] - arr[2] - arr[3] != 5) return 0;
        if(cur == 8 && arr[4] + arr[5] + arr[6] - arr[7] != 10) return 0;
        if(cur == 12 && arr[8] - arr[9] + arr[10] + arr[11] != 9) return 0;

        if(cur == 13 && arr[0] + arr[4] + arr[8] - arr[12] != 17) return 0;
        if(cur == 14 && arr[1] + arr[5] - arr[9] - arr[13] != 8) return 0;
        if(cur == 15 && arr[2] - arr[6] - arr[10] + arr[14] != 11) return 0;

        if(cur == 2 && arr[0] + arr[1] <= 7) return 0;
        if(cur == 3 && arr[0] + arr[1] - arr[2] < 6) return 0;
        if(cur == 6 && arr[1] + arr[5] <= 10) return 0;
        if(cur == 7 && arr[4] + arr[5] + arr[6] <= 10) return 0;
        if(cur == 8 && arr[3] + arr[7] <= 16) return 0;
        if(cur == 9 && arr[0] + arr[4] + arr[8] <= 17) return 0;
        if(cur == 12 && arr[3] + arr[7] + arr[11] < 32) return 0;

        int ans = 0;
        for(int i=1; i<=16; i++) {
            if(~used&(1<<i)) {
                vector<short> t = arr;
                t.push_back(i);
                ans += solve(cur+1, used|(1<<i), t);
            }
        }
        return ans;
    }
    if(arr[12] - arr[13] + arr[14] - arr[15] != 0) return 0;
    if(arr[3] + arr[7] + arr[11] + arr[15] != 48) return 0;
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++)
            printf("%2d ", arr[i*4+j]);
    }
    printf("\n");
    n++;
    return 1;
}

int main() {
    solve(0, 0, vector<short>());
    printf("%d", n);
}
