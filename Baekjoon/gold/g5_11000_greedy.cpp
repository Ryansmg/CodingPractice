#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pair pair<int, int>
using namespace std;

//강의실 배정

struct cmp {
    bool operator() (int a, int b) {
        return a>b;
    }
};

struct cmp2 {
    bool operator() (pair a, pair b) {
        return a.first > b.first;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    priority_queue<pair, vector<pair>, cmp2> pqin;
    for(int i=0; i<n; i++) {
        int a, b; cin >> a >> b;
        pqin.emplace(a, b);
    }
    priority_queue<int, vector<int>, cmp> pq;
    size_t ans = 0;
    while(!pqin.empty()) {
        int a = pqin.top().first, b = pqin.top().second;
        pqin.pop();
        if(pq.empty()) { pq.push(b); }
        else {
            if(pq.top() <= a) pq.pop();
            pq.push(b);
        }
        ans = max(ans, pq.size());
    }
    cout << ans;
}
