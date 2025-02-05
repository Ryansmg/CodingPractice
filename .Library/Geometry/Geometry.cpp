/* Update : 2025-02-04 */

#include <bits/stdc++.h>

long double Gprecision = 1e-6;
bool Geq(const long double& a, const long double& b) { return abs(a-b) <= Gprecision; }

template <typename T = long long> class GPoint {
public:
    T x = T(), y = T();
    std::tuple<T, T> toTuple() { return {x, y}; }
    template <typename T2> explicit operator GPoint<T2>() const { return GPoint<T2>(static_cast<T2>(x), static_cast<T2>(y)); }
    T distSq(const GPoint& b) const { return sq_(x-b.x)+sq_(y-b.y); }
    long double dist(const GPoint& b) const { return sqrt(static_cast<long double>(distSq(b))); }
    bool operator<(const GPoint& b) const { return x == b.x ? y < b.y : x < b.x; }
    bool operator==(const GPoint& b) const {
        if constexpr(std::is_integral_v<T>) return x == b.x && y == b.y;
        else return Geq(static_cast<long double>(x), static_cast<long double>(b.x)) && Geq(static_cast<long double>(y), static_cast<long double>(b.y));
    }
    template <typename T2> requires (!std::is_same_v<T, T2>) bool operator==(const GPoint<T2>& b) const {
        return Geq(static_cast<long double>(x), static_cast<long double>(b.x)) && Geq(static_cast<long double>(y), static_cast<long double>(b.y));
    }
    static auto ccwCmp(const GPoint&);
};
template <typename T> __int128 product(const GPoint<T>& p1, const GPoint<T>& p2, const GPoint<T>& p3) { return __int128(p2.x-p1.x) * (p3.y-p1.y) - __int128(p3.x-p1.x) * (p2.y-p1.y); }
/// -1 : 시계, 0 : 직선, 1 : 반시계
template <typename T> signed ccw(const GPoint<T>& p1, const GPoint<T>& p2, const GPoint<T>& p3) { __int128 pd = product(p1, p2, p3); return pd == 0 ? 0 : ( pd < 0 ? -1 : 1 ); }

template <typename T> auto GPoint<T>::ccwCmp(const GPoint<T>& p) {
    return [&](const GPoint& a, const GPoint& b) -> bool {
        signed c = ccw(p, a, b);
        return c == 0 ? p.distSq(a) < p.distSq(b) : c > 0;
    };
}

template <typename T = long long> class GLine {
public:
    GLine()=default;
    GLine(const GPoint<T>& point1, const GPoint<T>& point2) : p1(point1), p2(point2) {
        if(p1.x > p2.x) std::swap(p1, p2);
        else if(p1.x == p2.x && p1.y > p2.y) std::swap(p1, p2);
    }
    GLine(const T& x1, const T& y1, const T& x2, const T& y2) : GLine(GPoint(x1, y1), GPoint(x2, y2)) {}
    GPoint<T> p1, p2;
    bool intersects(const GLine& l) const {
        if(p1 == p2 && l.p1 == l.p2) return p1 == l.p2;
        else if(p1 == p2) return l.contains(p1);
        else if(l.p1 == l.p2) return contains(l.p1);
        signed ccw1 = ccw(p1, p2, l.p1), ccw2 = ccw(p1, p2, l.p2),
                ccw3 = ccw(l.p1, l.p2, p1), ccw4 = ccw(l.p1, l.p2, p2);
        if(ccw1 * ccw2 < 0 && ccw3 * ccw4 < 0) return true;
        else if(ccw1 == 0 && ccw2 == 0) {
            if(p1.x == p2.x) return p1.y <= l.p2.y && l.p1.y <= p2.y;
            else return p1.x <= l.p2.x && l.p1.x <= p2.x;
        }
        return (ccw1 * ccw2 == 0 && ccw3 * ccw4 <= 0) || (ccw1 * ccw2 <= 0 && ccw3 * ccw4 == 0);
    }
    //pair.first => 0 : 교차하지 않음, 1 : 한 점에서 교차, 2 : 무수히 많은 점에서 교차
    //pair.second => 교점이 하나라면 교점의 좌표, 아니면 0,0
    std::pair<signed, GPoint<long double>> intersection(const GLine& l) const {
        signed ccw1 = ccw(p1, p2, l.p1), ccw2 = ccw(p1, p2, l.p2),
                ccw3 = ccw(l.p1, l.p2, p1), ccw4 = ccw(l.p1, l.p2, p2);
        if(ccw1 * ccw2 < 0 && ccw3 * ccw4 < 0) return { 1, intersection_checked(l) };
        if(!ccw1 && !ccw2) {
            if(p1.x == p2.x) {
                if(p1.y == l.p2.y && l.p1.y < p1.y) return { 1, static_cast<GPoint<long double>>(p1) };
                if(p2.y == l.p1.y && p1.y < l.p1.y) return { 1, static_cast<GPoint<long double>>(p2) };
                if(p1.y <= l.p2.y && l.p1.y <= p2.y) return { 2, {0, 0} };
            }
            else if(p1.x <= l.p2.x && l.p1.x <= p2.x) {
                if(p1.x == l.p2.x && l.p1.x < p1.x) return { 1, static_cast<GPoint<long double>>(p1) };
                if(p2.x == l.p1.x && p1.x < l.p1.x) return { 1,  static_cast<GPoint<long double>>(p2) };
                return { 2, {0, 0} };
            }
        }
        else if(p1 == l.p1 || p1 == l.p2) return {1, static_cast<GPoint<long double>>(p1)};
        else if(p2 == l.p2 || p2 == l.p1) return {1, static_cast<GPoint<long double>>(p2)};
        else if((ccw1 * ccw2 == 0 && ccw3 * ccw4 <= 0) || (ccw1 * ccw2 <= 0 && ccw3 * ccw4 == 0))
        return {1, intersection_checked(l)};
        return { 0, {0, 0} };
    }
    bool contains(const GPoint<T>& p) const {
        if(ccw(p1, p2, p)) return false;
        if(p1.x == p2.x) return p1.y <= p.y && p.y <= p2.y;
        return p1.x <= p.x && p.x <= p2.x;
    }
    bool parallel(const GLine& b) const {
        return (p1.y-p2.y) * (b.p1.x-b.p2.x) == (p1.x-p2.x) * (b.p1.y-b.p2.y);
    }
private:
    GPoint<long double> intersection_checked(const GLine& l) const {
        if((p1.x == p2.x || p1.y == p2.y) && (l.p1.x == l.p2.x || l.p1.y == l.p2.y)) {
            if(p1.x == p2.x) return {(long double)p1.x, (long double)l.p1.y};
            return {(long double)l.p1.x, (long double)p1.y};
        }
        if(p1.x == p2.x) return {(long double)p1.x, ((long double)(l.p2.y-l.p1.y)) * (p1.x-l.p1.x) / ((long double)(l.p2.x-l.p1.x)) + l.p1.y};
        if(l.p1.x == l.p2.x) return {(long double)l.p1.x, ((long double)(p2.y-p1.y)) * (l.p1.x-p1.x) / ((long double)(p2.x-p1.x)) + p1.y};
        long double a1 = (p2.y-p1.y) / ((long double)(p2.x-p1.x)) - (l.p2.y-l.p1.y) / ((long double)(l.p2.x-l.p1.x));
        long double a2 = l.p1.y-p1.y+p1.x*(p2.y-p1.y)/((long double)(p2.x-p1.x))-l.p1.x*(l.p2.y-l.p1.y)/((long double)(l.p2.x-l.p1.x));
        long double ax = a2/a1, ay = (p2.y-p1.y) * (ax-p1.x) / ((long double)(p2.x-p1.x)) + p1.y;
        return {ax, ay};
    }
};

template <typename T> concept isGPoint = requires(const T& t) { { T::ccwCmp(t) }; };

/// the order of the stored GPoints are not preserved.
template <isGPoint T = GPoint<long long>> class GPoints {
public:
    std::vector<T> points;
    T& operator[](long long i) { return points[i]; }
    long long size() const { return std::ssize(points); }
    void push_back(const T& p) { points.pb(p); } auto begin() { return points.begin(); } auto end() { return points.end(); }
    template <typename... Args> void emplace_back(const Args&... args) { points.eb(args...); }
    [[deprecated]] std::vector<T> grahamScan() { sort(points, T::ccwCmp(min(points)));
        std::vector<T> ret; for(const T& p : points) { while(std::ssize(ret) >= 2 && ccw(ret[std::ssize(ret)-2], ret.back(), p) <= 0) { pop(ret); } ret.pb(p); } return ret; }
    /// O(NlogN)
    /// @returns { upper hull, lower hull }
    std::pair<std::vector<T>, std::vector<T>> monotoneChain(bool allowStraightPoints = false) {
        std::vector<T> up, down; sort(points);
        for(const T& p : points) {
            while(std::ssize(up) >= 2 && ccw(up[std::ssize(up)-2], up.back(), p) >= 0 + allowStraightPoints) pop(up);
            while(std::ssize(down) >= 2 && ccw(down[std::ssize(down)-2], down.back(), p) <= 0 - allowStraightPoints) pop(down);
            up.pb(p); down.pb(p);
        }
        return { up, down };
    }
    /// O(NlogN), uses monotone chain
    /// counter clockwise
    std::vector<T> convexHull(bool allowStraightPoints = false) {
        auto [up, down] = monotoneChain(allowStraightPoints);
        while(allowStraightPoints && !up.empty() && up.back() != down.back()) pop(up);
        if(std::ssize(up) >= 2) down.insert(down.end(), up.rbegin()+1, up.rend()-1);
        return down;
    }
    /// O(N)
    bool isPoint() { for(long long i = 0; i < std::ssize(points)-1; i++) {if(points[i] == points[i+1]) {return true;}} return std::ssize(points)==1; }
    /// O(N)
    bool isLine() { if(std::ssize(points)<=1) { return false; } if(std::ssize(points)==2) return true;
        for(long long i = 0; i < std::ssize(points)-2; i++) {if(ccw(points[i], points[i+1], points[i+2])) {return false;} } return true;}
};

template <typename T> struct GPointValueType_;
template <typename T> struct GPointValueType_<GPoint<T>> { using type = T; };

template <isGPoint T = GPoint<long long>> class ConvexPolygon {
public:
    using MT = GPointValueType_<T>::type;
    std::vector<T> up, down; MT mnX, mxX, mnY, mxY;
    explicit ConvexPolygon(GPoints<T>& points, bool asp_ = false) : mnX(std::numeric_limits<MT>::max()), 
        mxX(std::numeric_limits<MT>::min()), mnY(std::numeric_limits<MT>::max()), mxY(std::numeric_limits<MT>::min()) {
        tie(up, down) = points.monotoneChain(asp_);
        for(const auto& p : up) setMin(mnX, p.x), setMin(mnY, p.y), setMax(mxX, p.x), setMax(mxY, p.y);
        for(const auto& p : down) setMin(mnX, p.x), setMin(mnY, p.y), setMax(mxX, p.x), setMax(mxY, p.y);
    }
    /// O(N)
    std::vector<T> arr() { std::vector<T> ret = down; ret.insert(ret.end(), up.rbegin()+1, up.rend()-1); return ret; }
    /// O(logN)
    bool contains(const T& p) const {
        if(p.x < mnX || mxX < p.x || p.y < mnY || mxY < p.y) return false;
        long long idx = ub(up, p) - up.begin();
        if(ccw(up[idx-1], up[idx], p) > 0) return false;
        idx = ub(down, p) - down.begin();
        return ccw(down[idx-1], down[idx], p) >= 0;
    }
};
