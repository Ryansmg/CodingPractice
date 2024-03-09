#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 18870. 좌표 압축
// #coordinate_compression

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    queue<int> inputs;
    vector<int> comp;
    for(int i=0; i<n; i++) {
        int a; cin >> a;
        inputs.emplace(a);
        comp.push_back(a);
    }

    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
 
    while(!inputs.empty()) {
        int in = inputs.front(); inputs.pop();
        int ans = lower_bound(comp.begin(), comp.end(), in) - comp.begin();
        cout << ans << " ";
    }
}