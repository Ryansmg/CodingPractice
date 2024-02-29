#include <iostream>
#include <queue>
#include <vector>
#define pair pair<int, int>
using namespace std;

//11003. 최솟값 찾기
//#priority_queue
//(다른 풀이) #deque_trick #monotone_queue_optimization

struct paircmp {
    bool operator() (pair a, pair b) {
        if(a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, l;
    cin >> n >> l;
    priority_queue<pair, vector<pair>, paircmp> pq;
    pair minp = {2147000000, -2147000000};
    for(int i=1; i<=n; i++) {
        int a;
        cin >> a;
        pq.emplace(a, i);
        if(minp.second < i-l+1 || a <= minp.first) {
            while(!pq.empty() && pq.top().second < i-l+1) pq.pop();
            minp = pq.top();
        }
        cout << minp.first << " ";
    }
}
