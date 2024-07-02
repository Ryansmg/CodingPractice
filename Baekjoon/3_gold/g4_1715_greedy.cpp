#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;

//카드 정렬하기

struct cmp {
    bool operator() (ll a, ll b) {
        return a>b;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    priority_queue<ll, vector<ll>, cmp> pq;
    for(int i=0; i<n; i++) {
        ll a; cin >> a; pq.push(a);
    }
    ll sum = 0;
    while(pq.size() > 1) {
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        sum += a+b; pq.push(a+b);
    }
    cout << sum;
}
