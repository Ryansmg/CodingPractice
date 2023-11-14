#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//회의실 배정

bool cmp(pair<int,int> a, pair<int, int> b)
{
    if(a.second < b.second) return true;
    else if(a.first < b.first && a.second == b.second) return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> times(n);
    for(int i=0; i<n; i++) cin >> times[i].first >> times[i].second;
    sort(times.begin(), times.end(), cmp);
    int ans = 1;
    int endTime = times[0].second;
    for(int i=1; i<n; i++)
    {
        if(endTime > times[i].first) continue;
        endTime = times[i].second;
        ans++;
    }
    cout << ans;
}