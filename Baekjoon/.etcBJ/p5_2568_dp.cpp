#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define int_max 2100000000
using namespace std;

//전깃줄 - 2

bool cmp(pair<int,int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; //전깃줄의 개수

    cin >> n;
    vector<pair<int, int>> lines;
    vector<int> lis, lis_ind(n), prev(n+1);
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        lines.emplace_back(a, b);
        lis.push_back(int_max);
    }

    sort(lines.begin(), lines.end(), cmp);

    for(int i=0; i<n; i++) {
        auto iter = lower_bound(lis.begin(), lis.end(), lines[i].second);
        int ind = iter - lis.begin();
        *iter = lines[i].second;
        lis_ind[ind] = i;
        if(ind == 0) prev[i] = -1;
        else prev[i] = lis_ind[ind-1];
    }

    int i = lower_bound(lis.begin(), lis.end(), int_max) - lis.begin();
    int ind = lis_ind[i-1];
    vector<int> ansInd(i);
    int curi = i-1;
    while(curi != -1){
        ansInd[curi] = ind;
        ind = prev[ind];
        curi--;
    }
    int ansnum = n - i;
    cout << ansnum << "\n";
    set<int> set;
    for(int j=0; j<i; j++) set.insert(lines[ansInd[j]].first);
    for(auto pair : lines) if(set.find(pair.first)==set.end()) cout << pair.first << "\n";
}