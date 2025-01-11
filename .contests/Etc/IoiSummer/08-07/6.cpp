#include <bits/stdc++.h>
using namespace std;
template <class t> using v = vector<t>;
template <class t> using v2 = v<v<t>>;
using i32 = int;
using i64 = long long;
#define all(vec) (vec).begin(), (vec).end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(i, j) for(i32 i=0; i<j; i++)
#define forf(i, j, k) for(i32 i=j; i<=k; i++)
template <class T=i64> T input() { T i; cin >> i; return i; }
template <typename T> v<T> inputArr(i64 sz) { v<T> a; forn(i,sz)a.push_back(input<T>()); return a; }

i64 min(i64 a, i64 b, i64 c) { return min(a, min(b, c)); }

struct point {
    i64 x, y;
    point(){}
    point(i64 a, i64 b) { x = a, y = b; }
    bool operator<(const point &b) const {
        if(x == b.x) return y < b.y;
        return x < b.x;
    }
};

istream& operator>>(istream &in, point &p) {
    i64 a, b; in >> a >> b; p = point(a, b); return in;
}

v<point> points;
i32 N;

i64 distance(const point &a, const point &b) {
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
i64 distance(const i32 &a, const i32 &b) {
    return distance(points[a], points[b]);
}
i64 distance2(const i32 &a, const i32 &b, const v<i32> &midPoints) {
    return distance(points[midPoints[a]], points[midPoints[b]]);
}

bool cmpByY(const i32 &a, const i32 &b) {
    if(points[a].y == points[b].y) return points[a].x < points[b].x;
    return points[a].y < points[b].y;
}

i64 solve(i32 l, i32 r) {
    int cnt = r - l + 1;
    if(cnt == 2) return distance(l, r);
    if(cnt == 3) return min(distance(l, r), distance(l, l+1), distance(r-1, r));
    i32 mid = (l+r)/2;
    i64 ans = min(solve(l, mid), solve(mid+1, r));
    i64 lineX = (points[mid].x + points[mid + 1].x) / 2;
    v<i32> midPoints;
    forf(i, l, r) if((points[i].x - lineX) * (points[i].x - lineX) < ans) midPoints.push_back(i);
    sort(all(midPoints), cmpByY);
    i32 sz = midPoints.size();
    forf(i, 0, sz-1) {
        forf(j, i+1, sz-1) {
            if((points[midPoints[i]].y - points[midPoints[j]].y)*(points[midPoints[i]].y - points[midPoints[j]].y) >= ans) break;
            ans = min(ans, distance2(i, j, midPoints));
        }
    }
    return ans;
}

i32 main() {
    fastio;
    cin >> N;
    forn(i, N) points.push_back(input<point>());
    sort(all(points));
    cout << solve(0, N-1);
}
