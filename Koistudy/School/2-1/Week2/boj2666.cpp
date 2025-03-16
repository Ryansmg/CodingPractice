#include <bits/stdc++.h>
using namespace std;

struct state {
    int open0, open1, targetIdx;
    int hash() {
        assert(open0 != open1);
        return (1<<open0) | (1<<open1);
    }
};

int main() {
    int n, q, a, b;
    cin >> n >> a >> b >> q;
    vector<int> targets(q);
    for(int i=0; i<q; i++) cin >> targets[i];
    queue<state, list<state>> search;
    search.emplace_back(a, b, 0);
    while(!search.empty()) {

    }
}