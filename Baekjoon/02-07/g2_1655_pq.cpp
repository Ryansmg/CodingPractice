#include <queue>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

void print(priority_queue<int> l, priority_queue<int, vector<int>, greater<>> r) {
    deque<int> q;
    while(!l.empty()){
        q.push_front(l.top());
        l.pop();
    }
    while(!r.empty()){
        q.push_back(r.top());
        r.pop();
    }
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop_front();
    }
    cout << "\n";
}

//1655 - 가운데를 말해요

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    priority_queue<int> left; // min, ..., 중간값 (top)
    priority_queue<int, vector<int>, greater<> > right; // (top) 중간값, ..., max
    int leftn = 0, rightn = 0;
    int n; cin >> n;
    for(int i=0; i<n; i++) 
    {
        int a; cin >> a;
        if(leftn == rightn) {
            if(!left.empty() && a <= left.top()) {
                left.push(a);
                right.push(left.top());
                left.pop();
                rightn++;
            } else {
                right.push(a);
                rightn++;
            }
            //print(left, right);
            cout << right.top() << "\n";
        } else {
            if(left.empty()){
                int b = a, c = right.top();
                if(b>c) swap(b,c);
                right.pop();
                left.push(b);
                right.push(c);
                leftn++;
            }
            else if(a <= left.top()) {
                left.push(a);
                leftn++;
            } else {
                right.push(a);
                left.push(right.top());
                right.pop();
                leftn++;
            }
            //print(left, right);
            cout << left.top() << "\n";
        }
    }
}