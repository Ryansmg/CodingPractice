#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

struct point {
    int x, y;
    point(){}
    point(int a, int b) { x=a; y=b; }
};

struct line {
    point a, b;
    line(){}
    line(point x, point y) { a=x; b=y; }
    line(int c, int d, int e, int f) {
        point g(c,d), h(e,f);
        a=g; b=h;
    }
};

int findRoot(vector<int> &parent, int n) {
    if(parent[n] == n) return n;
    return parent[n] = findRoot(parent, parent[n]);
}

int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll c = (x2-x1) * (y3-y1) - (x3-x1) * (y2-y1);
    return c == 0 ? 0 : (c > 0 ? 1 : -1);
}

bool line_intersect(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
    if(x1 > x2) { swap(x1, x2); swap(y1, y2); }
    if(x3 > x4) { swap(x3, x4); swap(y3, y4); }
    int ccw1 = ccw(x1, y1, x2, y2, x3, y3), ccw2 = ccw(x1, y1, x2, y2, x4, y4);
    int ccw3 = ccw(x3, y3, x4, y4, x1, y1), ccw4 = ccw(x3, y3, x4, y4, x2, y2);
    if(ccw1 * ccw2 < 0 && ccw3 * ccw4 < 0) { return true; }
    else if(ccw1 == 0 && ccw2 == 0){
        if(x1 == x2) {
            if(y1 > y2) swap(y1, y2); if(y3 > y4) swap(y3, y4);
            if(y1 <= y4 && y3 <= y2) return true;
        }
        else if(x1 <= x4 && x3 <= x2) return true;
    }
    else if((ccw1 * ccw2 == 0 && ccw3 * ccw4 <= 0) || (ccw1 * ccw2 <= 0 && ccw3 * ccw4 == 0)) return true;
    return false;
}

bool intersect(line a, line b) {
    return line_intersect(a.a.x, a.a.y, a.b.x, a.b.y, b.a.x, b.a.y, b.b.x, b.b.y);
}

int main()
{
    int n; cin >> n;
    vector<int> parent;
    vector<int> cnt;
    int groups = n;
    vector<line> lines;
    for(int i=0; i<n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        lines.emplace_back(a, b, c, d);
        parent.push_back(i);
        cnt.push_back(1);
    }
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(findRoot(parent, i) == findRoot(parent, j)) continue;
            if(intersect(lines[i], lines[j])) {
                groups--;
                cnt[findRoot(parent, i)] += cnt[findRoot(parent, j)];
                parent[findRoot(parent, j)] = findRoot(parent, i);
            }
        }
    }

    cout << groups << "\n";
    int m = -1;
    for(int i : cnt) m = max(i, m);
    cout << m;
}
