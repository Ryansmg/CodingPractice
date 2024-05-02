#include <bits/stdc++.h>
#define int long long
using namespace std;

struct line {
    int start, end;
    line(){}
    line(int a, int b) : start(a), end(b){};
};
struct cmp2 {
    bool operator()(line &b, line &a) {
        if(b.start==a.start) return b.end > a.end;
        return b.start > a.start;
    }
};
struct cmp {
    bool operator()(line &a, line &b) {
        if(a.end==b.end) return a.start>b.start;
        return a.end > b.end;
    }
};

signed main()
{
    int n; cin >> n;
    priority_queue<line, vector<line>, cmp2> out;
    priority_queue<line, vector<line>, cmp> in;
    for(int i=0; i<n; i++) {
        int a, b; cin >> a >> b;
        if(a>b) swap(a, b);
        out.emplace(a, b);
    }
    int d; cin >> d;
    int ans = 0, cur = 0;
    int startp = out.top().start;
    while(out.top().start <= startp+d) {
        in.push(out.top());
        out.pop();
        cur++;
    }
    while(in.top().end <= startp+d) {
        in.pop();
        cur--;
    }
    ans = cur;
    while(!in.empty() || !out.empty()) {
        
    }
    cout << ans;
}