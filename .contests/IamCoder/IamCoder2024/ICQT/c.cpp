#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;

void calc1(vector<ll> &imp, vector<ll> &par, vector<vector<ll>> &child, ll n) {
    for(ll ch : child[n]) {
        if(ch == par[n]) continue;
        calc1(imp, par, child, ch);
    }
    if(n!=1) imp[par[n]] += imp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> temp;
    vector<vector<ll>> child(n+1, temp);
    vector<ll> par(n+1, -1);
    vector<ll> imp(n+1);
    ll ta, tb;
    ll impsum = 0;
    for(ll i=0; i<n-1; i++) {
        cin >> ta >> tb;
        child[ta].push_back(tb);
        child[tb].push_back(ta);
    }
    for(ll i=1; i<=n; i++) {
        cin >> ta;
        imp[i] = ta;
        impsum += ta;
    }
    queue<ll> bfs;
    queue<ll> bfs2;
    bfs.push(1);
    par[1] = 1;
    while(!bfs.empty()) {
        ll fr = bfs.front(); bfs.pop();
        bool hasChild = false;
        for(ll ch : child[fr]) {
            if(par[ch] != -1) continue;
            hasChild = true;
            par[ch] = fr;
            bfs.push(ch);
        }
        if(!hasChild) bfs2.push(fr);
    }
    calc1(imp, par, child, 1);
    ll sumans = 21474836400;       
    ll ans1, ans2;
    for(ll i=2; i<=n; i++) {
        if(abs(impsum - sumans*2) > abs(impsum - imp[i]*2)) {
            sumans = imp[i];
            ans1 = i;
            ans2 = par[i];
        }
    }
    cout << abs(impsum - 2*sumans) << "\n";
    cout << ans1 << " " << ans2;
}
