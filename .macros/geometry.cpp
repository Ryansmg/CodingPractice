#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define ssize(v) ((i64)v.size())

constexpr long double EPS = 1e-9;
constexpr long double PI = 3.1415926535897932384626433832795L;
constexpr long double INF = std::numeric_limits<long double>::max();

struct auto_fastio_ {
    auto_fastio_() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
} a_f_;

struct double_ {
    long double value = 0;
    double_() = default;
    double_(long double _) : value(_) {}

#define op0(op) double_ operator op (const double_& b) const { return {value op b.value}; }\
                double_ operator op (double_&& b) const { return {value op b.value}; }
#define op1(op) double_& operator op (const double_& b) { value op b.value; return *this; }\
                double_& operator op (double_&& b) { value op b.value; return *this; }
    op0(+) op0(-) op0(*) op0(/)
    op1(+=) op1(-=) op1(*=) op1(/=)

    double_ operator-() const { return {-value}; }

    bool operator==(const double_& b) const { return b.value - EPS <= value && value <= b.value + EPS; }
    bool operator!=(const double_& b) const { return !(*this == b); }
    bool operator<(const double_& b) const { return *this != b && value < b.value; }
    bool operator>(const double_& b) const { return *this != b && value > b.value; }
    bool operator<=(const double_& b) const { return *this == b || value < b.value; }
    bool operator>=(const double_& b) const { return *this == b || value > b.value; }

    friend double_ sqrt(const double_& a) { return {std::sqrt(a.value)}; }
    friend double_ abs(const double_& a) { return {std::abs(a.value)}; }

    friend istream& operator>>(istream& in, double_& b) { return in >> b.value; }
    friend ostream& operator<<(ostream& out, const double_& b) { return out << std::setprecision(9) << std::fixed << b.value; }

    friend long long round(const double_& d) { return llroundl(d.value); }
};

#define double double_

struct point {
    double x = 0, y = 0;
    double len() const { return sqrt(x * x + y * y); }
    double dist(const point& b) const { return point{x-b.x, y-b.y}.len(); }

    bool operator==(const point& b) const { return x == b.x && y == b.y; }
    bool operator!=(const point& b) const { return !(*this == b); }
    bool operator<(const point& b) const { return x == b.x ? y < b.y : x < b.x; }

    friend istream& operator>>(istream& in, point& p) { return in >> p.x >> p.y; }
    friend ostream& operator<<(ostream& out, const point& p) { return out << p.x << " " << p.y; }
};

using vec = point;


double product(const point& p1, const point& p2, const point& p3) {
    return (p2.x-p1.x) * (p3.y-p1.y) - (p3.x-p1.x) * (p2.y-p1.y);
}

int ccw(const point& p1, const point& p2, const point& p3) {
    auto pd = product(p1, p2, p3);
    return pd == 0 ? 0 : ( pd < 0 ? -1 : 1 );
}

struct line {
    point p1{}, p2{};
    line() = default;
    line(const point& P1, const point& P2) : p1(P1), p2(P2) {
        if(p1.x > p2.x || (p1.x == p2.x && p1.y > p2.y)) std::swap(p1, p2);
    }

    /// 직선
    point intersection(const line& b) const {
        double vx1 = p2.x - p1.x, vy1 = p2.y - p1.y,
               vx2 = b.p2.x - b.p1.x, vy2 = b.p2.y - b.p1.y,
               det = vx1 * (-vy2) - (-vx2) * vy1;
        if(det == 0) return {INF, INF};
        auto s = ((b.p1.x - p1.x) * (-vy2) + (b.p1.y - p1.y) * vx2) / det;
        return {p1.x + vx1 * s, p1.y + vy1 * s};
    }
    bool contains(const point& p) const {
        if(ccw(p1, p2, p)) return false;
        if(p1.x == p2.x) return p1.y <= p.y && p.y <= p2.y;
        return p1.x <= p.x && p.x <= p2.x;
    }
    bool parallel(const line& b) const {
        return (p1.y-p2.y) * (b.p1.x-b.p2.x) == (p1.x-p2.x) * (b.p1.y-b.p2.y);
    }
};

/// 선분
struct segment : line {
    using line::line;
    bool intersects(const segment& l) const {
        if(p1 == p2 && l.p1 == l.p2) return p1 == l.p2;
        if(p1 == p2) return l.contains(p1);
        if(l.p1 == l.p2) return contains(l.p1);
        int ccw1 = ccw(p1, p2, l.p1), ccw2 = ccw(p1, p2, l.p2),
            ccw3 = ccw(l.p1, l.p2, p1), ccw4 = ccw(l.p1, l.p2, p2);
        if(ccw1 * ccw2 < 0 && ccw3 * ccw4 < 0) return true;
        if(ccw1 == 0 && ccw2 == 0) {
            if(p1.x == p2.x) return p1.y <= l.p2.y && l.p1.y <= p2.y;
            return p1.x <= l.p2.x && l.p1.x <= p2.x;
        }
        return (ccw1 * ccw2 == 0 && ccw3 * ccw4 <= 0) || (ccw1 * ccw2 <= 0 && ccw3 * ccw4 == 0);
    }

    point intersection(const segment& l) const {
        int ccw1 = ccw(p1, p2, l.p1), ccw2 = ccw(p1, p2, l.p2),
            ccw3 = ccw(l.p1, l.p2, p1), ccw4 = ccw(l.p1, l.p2, p2);
        if(ccw1 * ccw2 < 0 && ccw3 * ccw4 < 0) return line::intersection(l);
        if(!ccw1 && !ccw2) {
            if(p1.x == p2.x) {
                if(p1.y == l.p2.y && l.p1.y < p1.y) return p1;
                if(p2.y == l.p1.y && p1.y < l.p1.y) return p2;
                if(p1.y <= l.p2.y && l.p1.y <= p2.y) return {INF, INF};
            }
            else if(p1.x <= l.p2.x && l.p1.x <= p2.x) {
                if(p1.x == l.p2.x && l.p1.x < p1.x) return p1;
                if(p2.x == l.p1.x && p1.x < l.p1.x) return p2;
                return {INF, INF};
            }
        }
        else if((ccw1 * ccw2 == 0 && ccw3 * ccw4 <= 0) || (ccw1 * ccw2 <= 0 && ccw3 * ccw4 == 0))
            return line::intersection(l);
        return {INF, INF};
    }
};

/// O(NlogN)
/// @returns { upper hull, lower hull }
pair<vector<point>, vector<point>> monotone_chain(const vector<point>& points_, bool allowStraightPoints = false) {
    auto points = points_;
    vector<point> up, down; sort(points.begin(), points.end());
    for(const point& p : points) {
        while(ssize(up) >= 2 && ccw(up[ssize(up)-2], up.back(), p) >= 0 + allowStraightPoints) up.pop_back();
        while(ssize(down) >= 2 && ccw(down[ssize(down)-2], down.back(), p) <= 0 - allowStraightPoints) down.pop_back();
        up.push_back(p); down.push_back(p);
    }
    return { up, down };
}

/// O(NlogN) (counter-clockwise)
vector<point> convex_hull(const vector<point>& points, bool allowStraightPoints = false) {
    auto temp = monotone_chain(points, allowStraightPoints);
    auto up = std::move(temp.first), down = std::move(temp.second);
    while(allowStraightPoints && !up.empty() && up.back() != down.back()) up.pop_back();
    if(ssize(up) >= 2) down.insert(down.end(), up.rbegin()+1, up.rend()-1);
    return down;
}

int main() {
    point a, b, c, d;
    cin >> a >> b >> c >> d;
    segment l1(a, b), l2(c, d);
    auto p = l1.intersection(l2);
    auto i = l1.intersects(l2);
    cout << i << "\n";
    if(i && p.x != INF) cout << p;
}
