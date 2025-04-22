#include <queue>
#include <iostream>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int cur = 0;
    queue<int> q;
    for(int i = 1; i <= n; i++) q.push(i);
    while(!q.empty()) {
        int t = q.front(); q.pop();
        if(++cur == k) cout << t << " ", cur = 0;
        else q.push(t);
    }
}