#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void f(int depth, vector<int> s, int n, int &maxn) {
    for(int i=0; i<n; i++) {
        if(s[i] != -1) continue;
        s[i] = depth;
        if(depth == n) {
            int ans = 0;
            for(int i=0; i<n; i++) {
                int l = 0, r=0;
                for(int j=0; j<i; j++) {
                    l += max(0, s[j]-s[i]);
                }
                for(int j=i+1; j<n; j++) {
                    r += max(0, s[j]-s[i]);
                }
                if(l<r) ans += 2*l+1;
                else ans += 2*r;
            }
            if(ans > maxn) {
            for(int i : s) cout << i << " ";
            cout << endl;
                maxn = ans;
                cout << maxn << endl;
            }
        } else {
            f(depth+1, s, n, maxn);
        }
        s[i] = -1;
    }
}

int main()
{
    int n; cin >> n;
    int maxn = -1;
    vector<int> s(n, -1);
    f(1, s, n, maxn);
}