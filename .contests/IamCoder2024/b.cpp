#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2147483647
#define ll long long
using namespace std;

ll n, m, k, t, p;
    //세로, 가로, 모기수, 체력, 전기장 //좌표 : (세로, 가로)

struct point {
    ll y, x;
    point(){}
    point(ll a, ll b) {
        y=a; x=b;
    }
};

ll dist(point p1, point p2) {
    return abs(p1.x-p2.x) + abs(p1.y-p2.y);
}

ll ans1 = 1;
vector<pair<point, ll>> mosq;
void calc1(ll vis, point pre, ll premax, ll hp, int preind) {
    vis = vis | (1<<preind);
    for(int i=0; i<k; i++) {
        if((vis>>i)&1) continue;
        ll d = dist(mosq[i].first, pre);
        if(d > hp) continue;
        ans1 = max(ans1, premax+1);
        calc1(vis, mosq[i].first, premax+1, hp - d, i);
    }
}

int main()
{
    cin >> n >> m >> k >> t >> p;
    ll a, b, c;
    for(int i=0; i<k; i++) {
        cin >> a >> b >> c;
        mosq.push_back({{a, b}, c});
    }
    int ind = 0;
    for(auto mqs : mosq) 
        calc1(1<<ind, mqs.first, 1, t, ind++);
    
    ll ansp = 1;
    for(int y = 1; y <= n; y++) {
        for(int x=1; x<=m; x++) {
            ll ansptemp = 0;
            point src(y, x);
            for(auto ms : mosq) {
                point msp(ms.first.y, ms.first.x);
                if(dist(msp, src)==0) ansptemp++;
                else if(ms.second <= p / dist(msp, src)) ansptemp++;
            }
            ansp = max(ansp, ansptemp);
        }
    }

    cout << ans1 << " " << ansp;
}