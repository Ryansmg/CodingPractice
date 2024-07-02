#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findP(vector<int> &parent, int n) {
    if(parent[n] == n) return n;
    return parent[n] = findP(parent, parent[n]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, k, a;
    cin >> n >> m >> k;
    vector<int> parent;
    vector<int> in;
    for(int i=0; i<m; i++) {
        cin >> a;
        parent.push_back(i);
        in.push_back(a);
    }
    sort(in.begin(), in.end());
    for(int i=0; i<k; i++) {
        cin >> a;
        int ind = upper_bound(in.begin(), in.end(), a) - in.begin();
        cout << in[findP(parent, parent[ind])] << "\n";
        parent[findP(parent, parent[ind])] = findP(parent, parent[ind]) + 1;
    }
}
