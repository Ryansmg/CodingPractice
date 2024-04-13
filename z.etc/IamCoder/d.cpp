#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 2147483600
using namespace std;

int ans = INF, e;
vector<pair<int, int>> in1; //original
vector<pair<int, int>> in;

void calc(int leftleft, int leftright, int depth, vector<int> used, int depthsetint)
{
    if(depth!=0) used[depth-1] = depthsetint;
    if(depth==2 && leftright>=e) {
        ans = min(in[used[0]].second - in[used[1]].first, ans);
        //cout << ans << ": " << used[0] << " " << used[1] << "\n";
    }
    if(depth==3 && leftright>=e) {
        int tempans = 0;
        tempans += in[used[0]].second - in[used[1]].first;
        tempans += in[used[1]].second - in[used[2]].first;
        tempans += max(0, in[used[0]].second - in[used[2]].first);
        ans = min(tempans, ans);
        //cout << ans << ": " << used[0] << " " << used[1] << " " << used[2] << "\n";
    }
    if(depth==3 && leftright < e) return;
    int idx=-1;
    for(auto p : in) {
        idx++;
        if(leftright < p.first || p.first < leftleft) continue;
        calc(p.first+1, p.second, depth+1, used, idx);
    }
}

int main()
{
    int n, s; //선분 개수, 시작점, 끝점
    cin >> n >> s >> e;
    vector<int> comp;
    int ta, tb;
    for(int i=0; i<n; i++) {
        cin >> ta >> tb;
        // comp.push_back(ta);
        // comp.push_back(tb);
        // in1.push_back({ta, tb});
        in.push_back({ta, tb});
        if(ta <= s && tb >= e) {
            cout << 0;
            return 0;
        }
    }
    // sort(comp.begin(), comp.end());
    // comp.erase(unique(comp.begin(), comp.end()), comp.end());
    // for(auto asdf : in1) {
    //     in.push_back({ (lower_bound(comp.begin(), comp.end(), asdf.first) - comp.begin()), 
    //     (lower_bound(comp.begin(), comp.end(), asdf.second) - comp.begin())});
    // }
    vector<int> temp(3, 3);
    calc(-1, s, 0, temp, 0);
    cout << (ans == INF ? -1 : ans);
}
