#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define ll long long

//트리와 쿼리

vector<ll> parent; //union-find에 사용됨.

ll findRoot(ll n) {
    if(parent[n] == n) return parent[n];
    return parent[n] = findRoot(parent[n]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 
    ll n; cin >> n; //정점의 개수
    vector<ll> temp;
    vector<vector<ll>> child(n+1, temp);
    for(ll i=0; i<n-1; i++)
    {
        ll u, v; cin >> u >> v;
        child[u].push_back(v);
        child[v].push_back(u);
    }

    vector<ll> s_parent(n+1); //트리의 방향을 나타냄.
    
    //root node = 1로 두고 트리 방향 정하기
    s_parent[1] = 1;
    vector<bool> visp(n+1, false);
    stack<ll> quep;
    quep.push(1);
    while(!quep.empty()) {
        ll fr = quep.top(); quep.pop();
        for(ll as : child[fr]) {
            if(visp[as]) continue;
            visp[as] = true;
            s_parent[as] = fr;
            quep.push(as);
        }
    }

    parent.resize(n+1);
    vector<ll> count(n+1);

    ll q; cin >> q; //질의의 개수
    for(ll i=0; i<q; i++) {
        vector<bool> selected(n+1, false);
        vector<ll> sels;
        ll k; cin >> k;
        for(ll j=0; j<k; j++) {
            ll asdf; cin >> asdf;
            selected[asdf] = true;
            sels.push_back(asdf);

            parent[asdf] = asdf;
            count[asdf] = 1;
        }

        for(ll j : sels)
        {
            if(selected[s_parent[j]]) {

                parent[j] = findRoot(j);
                parent[s_parent[j]] = findRoot(s_parent[j]);

                if(parent[j] == parent[s_parent[j]]) continue;
                
                parent[j] = parent[s_parent[j]];
                count[parent[j]] += count[j];
            }
        }

        ll ans = 0;

        for(ll j : sels)
            if(parent[j] == j) ans += count[j] * (count[j]-1) / 2;

        cout << ans << "\n";
    }
}
