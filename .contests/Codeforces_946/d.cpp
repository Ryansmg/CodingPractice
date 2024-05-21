#include <bits/stdc++.h>
#define int long long
using namespace std; int input() { int t=0; cin >> t; return t;}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = input();
    for(int asdf=0; asdf<t; asdf++) {
        int n = input(), dx=0, dy=0, no = -1, so = -1, wo = -1, eo = -1, h = 0;
        string s; cin >> s; string ans = s;
        for(const char &c : s) {
            if(c=='N') dy++;
            if(c=='S') dy--;
            if(c=='W') dx--;
            if(c=='E') dx++;
        }
        if(abs(dx)&1 || abs(dy)&1) {
            cout << "NO\n"; continue;
        }
        int rx=0, ry=0, hx=0, hy=0;
        for(int i = 0; i < n; i++)
            switch(s[i]) {
                case 'N':
                    if(hy>=ry) {ry++; ans[i]='R';}
                    else {h = 1; hy++; ans[i] = 'H';}
                    no = i; break;
                case 'S':
                    if(hy<=ry) {ry--; ans[i]='R';}
                    else {h = 1; hy--; ans[i] = 'H';}
                    so = i; break;
                case 'W':
                    if(hx<=rx) {rx--; ans[i]='R';}
                    else {h = 1; hx--; ans[i] = 'H';}
                    wo = i; break;
                case 'E':
                    if(hx>=rx) {rx++; ans[i]='R';}
                    else {h = 1; hx++; ans[i] = 'H';}
                    eo = i; break;
            }
        if(!h) {
            if(no != -1 && so != -1 && n>2) {
                ans[no] = ans[so] = 'H';
            } else if (wo != -1 && eo != -1 && n>2) {
                ans[wo] = ans[eo] = 'H';
            } else {
                cout << "NO\n"; continue;
            }
        }
        cout << ans << "\n";
    }
}
