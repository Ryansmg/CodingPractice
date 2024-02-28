#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

bool oper(int a, int b) {
    return a<b;
}

struct cmp {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k; cin >> n >> k;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> gems;
    for(int i=0; i<n; i++) {
        int a,b; cin>>a>>b; gems.emplace(a, b);
    }
    multiset<int> bags;
    for(int i=0; i<k; i++) {
        int a; cin >> a;
        bags.insert(a);
    }

    long long sum = 0;
    while(!bags.empty() && !gems.empty()) {
        pair<int, int> gtop = gems.top(); gems.pop();
        auto iter = bags.lower_bound(gtop.first);
        if(iter == bags.end()) continue;
        sum += gtop.second;
        bags.erase(iter);
    }

    cout << sum;
}
