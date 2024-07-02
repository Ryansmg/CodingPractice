#include <iostream>
#define ll long long
#define ld long double
using namespace std;

int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll c = (x2-x1) * (y3-y1) - (x3-x1) * (y2-y1);
    return c == 0 ? 0 : (c>0 ? 1 : -1);
}

pair<int, pair<ld, ld>> line_intersect(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
    pair<ld, ld> zero(0, 0);
    if(x1 > x2) { swap(x1, x2); swap(y1, y2); }
    if(x3 > x4) { swap(x3, x4); swap(y3, y4); }
    int ccw1 = ccw(x1, y1, x2, y2, x3, y3), ccw2 = ccw(x1, y1, x2, y2, x4, y4);
    int ccw3 = ccw(x3, y3, x4, y4, x1, y1), ccw4 = ccw(x3, y3, x4, y4, x2, y2);
    if(ccw1 * ccw2 < 0 && ccw3 * ccw4 < 0) goto onepoint;
    else if(ccw1 == 0 && ccw2 == 0){
        if(x1 == x2) {
            if(y1 > y2) swap(y1, y2);
            if(y3 > y4) swap(y3, y4);
            if(y1 == y4 && y3 < y1) return {2, {x1, y1} };
            else if(y2 == y3 && y1 < y3) return {2, {x2, y2} };
            else if(y1 <= y4 && y3 <= y2) return {1, zero};
        }
        else if(x1 <= x4 && x3 <= x2) {
            if(x1 == x4 && x3 < x1) return {2, {x1, y1} };
            if(x2 == x3 && x1 < x3) return {2, {x2, y2} };
            return {1, zero};
        }
    }
    else if((ccw1 * ccw2 == 0 && ccw3 * ccw4 <= 0) || (ccw1 * ccw2 <= 0 && ccw3 * ccw4 == 0)) goto onepoint;

    return {0, zero};

    onepoint:
    long double xd1 = x1, yd1 = y1, xd2 = x2, yd2 = y2, xd3 = x3, yd3 = y3, xd4 = x4, yd4 = y4;
        if((x1==x2 || y1==y2) && (x3==x4 || y3==y4)) {
            if(x1==x2) return {2, {x1, y3} };
            else return {2, {x3, y1} };
        } else if(x1 == x2) { 
            return {2, {x1, (y4-y3) * (x1-x3) / (x4-xd3) + y3} };
        } else if(x3 == x4) {
            return {2, {x3, (y2-y1) * (x3-x1) / (x2-xd1) + y1} }; 
        } else {
            long double a1 = (y2-y1) / (x2-xd1) - (y4-y3) / (x4-xd3);
            long double a2 = y3-y1+x1*(y2-y1)/(x2-xd1)-x3*(y4-y3)/(x4-xd3);
            long double ax = a2/a1;
            long double ay = (y2-y1) * (ax-x1) / (x2-x1) + y1;
            return {2, {ax, ay} };
        }
}

bool equals(pair<ll, ll> p1, pair<ld, ld> p2) {
    ld d = 0.000000001;
    bool b1 = p2.first - d <= p1.first && p1.first <= p2.first+d;
    bool b2 = p2.second - d <= p2.second && p2.second <= p2.second + d;
    return b1 && b2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for(int i=0; i<t; i++) 
    {
        ll xmin, ymin, xmax, ymax;
        bool b0=0, b1=0, b2=0, b3=0;
        //0 1
        //2 3
        ll ans = 0;
        ll x1, y1, x2, y2;
        cin >> xmin >> ymin >> xmax >> ymax >> x1 >> y1 >> x2 >> y2;
        ll line1[] = {xmin, xmin, xmax, xmax};
        ll line2[] = {ymin, ymax, ymin, ymax};
        ll line3[] = {xmax, xmin, xmax, xmin};
        ll line4[] = {ymin, ymin, ymax, ymax};
        for(int j=0; j<4; j++) {
            auto p = line_intersect(line1[j], line2[j], line3[j], line4[j], x1, y1, x2, y2);
            if(p.first == 1) {ans=4; break;}
            else if(p.first!=0) {
                if(equals({xmin, ymax} , p.second)) b0 = true;
                else if(equals({xmax, ymax} , p.second)) b1 = true;
                else if(equals({xmin, ymin} , p.second)) b2 = true;
                else if(equals({xmax, ymin} , p.second)) b3 = true;
                else ans++;
            }
        }
        cout << min(ans + b0 + b1 + b2 + b3, 4ll) << "\n";
    }
}