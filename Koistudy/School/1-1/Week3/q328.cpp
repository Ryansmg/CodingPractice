#include <iostream>
#include <vector>
#include <algorithm>
#define pair pair<int, int>
using namespace std;
int main() {
    vector<pair> a;
    for(int i=1; i<=9; i++) {
        int b; cin >> b; a.emplace_back(b, i);
    }
    sort(a.begin(), a.end());
    cout << a[8].first << "\n" << a[8].second;
}
