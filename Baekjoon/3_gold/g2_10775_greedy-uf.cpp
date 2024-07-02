#include <iostream>
#include <vector>
using namespace std;

int findRoot(vector<int> &parent, int n) {
    if(parent[n] == n) return n;
    return parent[n] = findRoot(parent, parent[n]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int g, p;
    cin >> g >> p;
    vector<int> parent(g+1);
    for(int i=0; i<g+1; i++) parent[i] = i;
    int i;
    for(i=0; i<=p; i++) {
        if(i==p) break;
        int a; cin >> a;
        if(findRoot(parent, a) == 0) break;
        parent[findRoot(parent, a)] = findRoot(parent, findRoot(parent, a)-1);
    }
    cout << i;
}