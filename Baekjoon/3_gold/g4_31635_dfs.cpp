#include <iostream>
#include <vector>
using namespace std;

//신기한 미로의 가지
//#dfs

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, edgecnt = 1, prenode = 1, curnode;; 
    cin >> n;
    vector<int> temp, par(n+1, -1);
    vector<vector<int>> child(n+1, temp);
    vector<bool> complete(n+1, false);
    par[1] = 1;
    cout << "maze" << "\n";
    cout << flush;
    cin >> curnode;
    par[curnode] = prenode;
    child[prenode].push_back(curnode);
    while(edgecnt < n-1) {
        prenode = curnode;
        cout << "maze" << "\n";
        cout << flush;
        cin >> curnode;
        if(par[curnode] != -1) complete[prenode] = true;
        else {
            par[curnode] = prenode;
            child[prenode].push_back(curnode);
            edgecnt++;
        }
        if(edgecnt >= n-1) break;
        while(complete[curnode] && curnode != 1) {
            cout << "gaji " << par[curnode] << "\n";
            curnode = par[curnode];
            cout << flush;
            cin >> curnode;
        }
    }
    cout << "answer\n";
    for(int i=1; i<=n; i++) {
        for(int j : child[i]) {
            cout << i << " " << j << "\n";
        }
    }
    cout << flush;
    return 0;
}
