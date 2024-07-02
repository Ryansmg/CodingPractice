#include <iostream>
#include <vector>
using namespace std;

//20040. 사이클 게임
//#union_find

int findRoot(vector<int> &parent, int n) {
    if(parent[n] == n) return n;
    return parent[n] = findRoot(parent, parent[n]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> parent;
    for(int i=0; i<n; i++) parent.push_back(i);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        if(findRoot(parent, a) == findRoot(parent, b)) {
            cout << i+1;
            return 0;
        }
        parent[findRoot(parent,b)] = findRoot(parent, a);
    }
    cout << 0;
}
