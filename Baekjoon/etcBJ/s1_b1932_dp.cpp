#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> pre(n, 0);
    vector<int> now(n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            int x; cin >> x;
            now[j] = x;
        }
        for(int j=0; j<=i; j++) {
            int maxn = 0;
            if(j>0) maxn = max(maxn, pre[j-1]);
            if(j<i) maxn = max(maxn, pre[j]);
            now[j] += maxn;
        }
        pre = now;
        vector<int> temp(n);
        now = temp;
    }
    int maxn = -1;
    for(int i : pre) {
        maxn = max(maxn, i);
    }
    cout << maxn;
}