#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> v(n, 1);
    v.erase(unique(v.begin(), v.end()), v.end());
    int a[100];
    sort(a, a+99);
    sort(v.begin(), v.end()); 
}
