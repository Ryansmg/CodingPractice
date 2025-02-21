#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
using ll = long long int;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vl>;

void solve()
{
    ll N;
    scanf("%lld", &N);
    ll sq = (ll)sqrt(N);
    vl A(N);
    for(ll i = 0; i < N; i++) scanf("%lld", &A[i]);
    vvl bucket(N, vl{});
    vl group(N);
    for(ll i = 0; i < N; i++) group[i] = i / sq;

    function<void()> init = [&]()
    {
        for(ll i = 0; i < N; i++)
        {
            bucket[group[i]].push_back(A[i]);
        }

        for(ll i = group[0]; i <= group[N - 1]; i++)
        {
            sort(all(bucket[i]));
        }
    };

    function<void(ll, ll)> update = [&](ll i, ll x)
    {
        ll g = group[i];

        ll index = lower_bound(all(bucket[g]), A[i]) - bucket[g].begin();

        A[i] = x;
        bucket[g][index] = x;

        sort(all(bucket[g]));
    };

    function<ll(vl&, ll)> G = [&](vl& v, ll x)
    {
        ll n = v.size();

        return n - (upper_bound(all(v), x) - v.begin());
    };

    function<ll(ll, ll, ll)> query = [&](ll l, ll r, ll x)
    {
        ll ret = 0;

        while(l <= r && l % sq) ret += (A[l++] > x);
        while(l <= r && (r + 1) % sq) ret += (A[r--] > x);
        for(ll i = group[l]; i <= group[r]; i++) ret += G(bucket[i], x);

        return ret;
    };

    init();

    ll Q;
    scanf("%lld", &Q);

    for(ll q = 1; q <= Q; q++)
    {
        ll com;
        scanf("%lld", &com);

        if(com == 1)
        {
            ll l, r, x;
            scanf("%lld %lld %lld", &l, &r, &x); l--; r--;
            printf("%lld\n", query(l, r, x));
        }
        else if(com == 2)
        {
            ll i, x;
            scanf("%lld %lld", &i, &x); i--;
            update(i, x);
        }
    }
}

int main()
{
    solve();

    return 0;
}