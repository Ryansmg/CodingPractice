#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#define INF 2000000000
using namespace std;

//2812 - 크게 만들기

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k, maxv = -1;
    cin >> n >> k;
    vector<int> v;
    stack<int> s;
    for(int i=0; i<n; i++) {
        char c; cin >> c;
        v.push_back(c - '0');
        maxv = max(maxv, c - '0');
    }
    for(auto i = v.rbegin(); i!=v.rend(); i++) s.push(*i);
    int voff = 0, kleft = k;
    while(!s.empty()) {
        int target = -INF;
        if(n-voff == kleft) return 0;
        for(int i=voff; i<=voff+kleft; i++) {
            target = max(target, v[i]);
            if(target == maxv) break;
        }
        while(true) {
            voff++;
            if(s.top() != target) {
                kleft--; s.pop();
            } else {
                cout << s.top();
                s.pop();
                break;
            }
        }
        if(kleft == 0) {
            while(!s.empty()) {
                cout << s.top();
                s.pop();
            }
        }
    }
}