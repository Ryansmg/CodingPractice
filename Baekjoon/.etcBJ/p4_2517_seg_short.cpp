#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool oper(pair<int,int> a,pair<int,int> b) {return a.first<b.first;}
int main() {
    int n; cin >> n;
    vector<int> tree(2*n);
    for(int i=0; i<n; i++) cin >> tree[i+n];
    vector<int> ansvec(n);
    vector<pair<int, int>> indvec;
    for(int i=0; i<n; i++) indvec.push_back({tree[i+n], i});
    sort(indvec.begin(), indvec.end(), oper);
    int curlimit = 0;
    for(int i=0; i<n; i++) tree[i+n] = tree[i+n]==0?0:1;
    for(int i=n-1; i>0; i--) tree[i] = tree[i<<1] + tree[i<<1|1];
    for(auto p : indvec) {
        if(curlimit<p.first) {
            pair<int, int> tp = {curlimit, 0};
            for(int i = lower_bound(indvec.begin(), indvec.end(), tp, oper) - indvec.begin();
            indvec[i].first<p.first; i++) {
                int ind = indvec[i].second;
                for(tree[ind+=n]=0; ind>1; ind>>=1) tree[ind>>1] = tree[ind] + tree[ind^1];
            }
            curlimit = p.first;
        }
        int sum = 0;
        for(int start=n, end=n+p.second; start<end; start>>=1, end>>=1) {
            if(start&1) sum += tree[start++];
            if(end&1) sum += tree[--end];
        }
        ansvec[p.second] = sum;
    }
    for(int i : ansvec) cout << i+1 << "\n";
}
