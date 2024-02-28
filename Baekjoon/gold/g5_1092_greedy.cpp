#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main()
{
    multiset<int, greater<>> ms;
    vector<int> cranes;
    int cn, a, b; cin >> cn;
    for(int i=0; i<cn; i++) {
        cin >> b; cranes.push_back(b);
    }
    sort(cranes.begin(), cranes.end(), cmp);
    cin >> a;
    for(int i=0; i<a; i++) {
        cin >> b; ms.insert(b);
    }
    int ans = 0;
    while(!ms.empty()) {
        ans++;
        int curcrane = 0;
        vector<std::multiset<int, std::greater<void>>::iterator> iters;
        if(*ms.begin() > cranes[0]) {
            cout << -1; return 0;
        }
        for(auto i = ms.begin(); i != ms.end(); i++) {
            if(*i <= cranes[curcrane]) {
                iters.push_back(i); curcrane++;
            }
            if(curcrane == cn) break;
        }
        for(auto mi : iters) {
            ms.erase(mi);
        }
    }
    cout << ans;
}