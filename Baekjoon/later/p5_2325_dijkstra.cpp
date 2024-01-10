#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int nodeN, edgeN; cin >> nodeN >> edgeN;
    vector<vector<pair<int, int>>> child(nodeN+1); //nodeN -> {childNodeN, weight}
    for(int i=0; i<edgeN; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        child[x].emplace_back(y, z);
        child[y].emplace_back(x, z);
    }

}