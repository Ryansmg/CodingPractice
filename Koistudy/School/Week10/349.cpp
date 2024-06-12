#include <bits/stdc++.h>
#define int long long
using namespace std;

// 349. 벽장문의 이동

int dp[40000000];
vector<int> arr(1,-1);
int n, //벽장의 개수
a1, b1, //열려 있는 벽장의 번호
l; //사용할 벽장의 순서 개수

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> a1 >> b1 >> l;
    for(int i=0; i<39999999; i++) dp[i] = -1;
    for(int i=0; i<l; i++) {
        int t; cin >> t; arr.push_back(t);
    }
    queue<array<int, 4>> bfs;
    bfs.push({a1, b1, 0, 1});
    while(true) {
        auto fr = bfs.front(); bfs.pop();
        int a = fr[0], b = fr[1], cnt = fr[2], book = fr[3];
        int state = (1LL<<(a-1)) + (1LL<<(b-1));
        //cout << a << ' ' << b << ' ' << book << ' ' << cnt << ' ' << dp[state] << '\n';
        if(dp[state] >= book) continue;
        dp[state] = book;
        if(arr[book] == a || arr[book] == b) {
            if(book == l) {
                cout << cnt; return 0;
            }
            bfs.push({a, b, cnt, book+1});
        }
        if(a>1 && a-1!=b) bfs.push({a-1, b, cnt+1, book});
        if(a<n && a+1!=b) bfs.push({a+1, b, cnt+1, book});
        if(b>1 && a!=b-1) bfs.push({a, b-1, cnt+1, book});
        if(b<n && a!=b+1) bfs.push({a, b+1, cnt+1, book});
    }
}
