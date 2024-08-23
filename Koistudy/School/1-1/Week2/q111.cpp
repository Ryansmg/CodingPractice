#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <set>
using namespace std;
bool cmp2(int a, int b) {
    return a > b;
}
struct cmp {
    bool operator()(int a, int b) {
        vector<int> c;
        c.push_back(a);
        c.push_back(b);
        vector<int> d = c;
        sort(c.begin(), c.end(), cmp2);
        return !(c[0]==d[0]&&c[1]==d[1]);
    }
};
int main()
{
    priority_queue<int, vector<int>, cmp> pq;
    set<int> s;
    int a;
    for(int i=0; i<3; i++) {
        cin >> a;
        if(s.find(a) != s.end()) {
            cout << "Impossible";
            return 0;
        } else {
            s.insert(a);
            pq.push(a);
        }
    }
    stack<int> dq;
    while(!pq.empty()) {
        dq.emplace(pq.top());
        pq.pop();
    }
    while(!dq.empty()) {
        cout << dq.top() << ' ';
        dq.pop();
    }
}