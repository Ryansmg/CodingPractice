#include <iostream>
#include <stack>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    stack<pair<ll, ll>> st;
    ll ans = 0;
    for(ll i=0; i<n; i++) {
        ll a; cin >> a;
        ll weight = 1;
        while(!st.empty() && st.top().first <= a) {
            if(st.top().first == a) {
                weight += st.top().second;
            }
            ans+=st.top().second; st.pop();
        }
        if(!st.empty()) ans++;
        st.push({a, weight});
    }
    cout << ans;
}