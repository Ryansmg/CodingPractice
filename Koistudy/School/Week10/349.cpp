#include <bits/stdc++.h>
#define int long long
using namespace std;

// 349. 벽장문의 이동
// min(a, b)는 a, b 중 최솟값을 반환한다.
// abs(a)는 a의 절댓값을 반환한다.

vector<int> arr;
int n, //벽장의 개수
a1, b1, //열려 있는 벽장의 번호
l; //사용할 벽장의 순서

signed main() {
    cin >> n >> a1 >> b1 >> l;
    for(int i=0; i<l; i++) {
        int t; cin >> t; arr.push_back(t);
    }
    queue<pair<int, int>> now;
    now.emplace(a1, b1);
    for(int i=0; i<l; i++) {
        queue<int> nxt;
        while(!now.empty()) {

        }
    }
}
