#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr i64 llmax = 9223372036854775807;

// upper hull
struct LCLine {
    mutable i64 a, b, p;
    bool operator<(const LCLine& i) const { return a < i.a; }
    bool operator<(i64 x) const { return p < x; }
};
struct LineContainer : multiset<LCLine, less<>> {
    // for double, use INF = 1/.0, Div(a, b) = a/b
    static constexpr i64 infin = llmax;
    static i64 Div(i64 a, i64 b) { return a / b - ((a ^ b) < 0 && a % b != 0); }
    bool Cross(iterator x, iterator y) {
        if (y == end()) return x->p = infin, 0;
        if (x->a == y->a) x->p = x->b > y->b ? infin : -infin;
        else x->p = Div(y->b - x->b, x->a - y->a);
        return x->p >= y->p;
    }
    void Insert(i64 a, i64 b) { // y = ax + b
        auto z = insert({ a, b, 0 }), y = z++, x = y;
        while (Cross(y, z)) z = erase(z);
        if (x != begin() && Cross(--x, y)) Cross(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p) Cross(x, erase(y));
    }
    i64 Query(i64 x) {
        auto l = *lower_bound(x);
        return l.a * x + l.b;
    }
};

struct CHLine {
    i64 x, y;
    CHLine(const i64 x = 0, const i64 y = 0) : x(x), y(y) {} // NOLINT(*-explicit-constructor)
    bool operator<= (const CHLine& i) const { return 1. * x / y <= 1. * i.x / i.y; }
};
struct ConvexHull {
private:
    static i64 F(const CHLine& i, const i64 x) { return i.x * x + i.y; }
    static CHLine C(const CHLine& a, const CHLine& b) { return { a.y - b.y, b.x - a.x }; }
    vector<CHLine> S;
public:
    void Insert(const i64 a, const i64 b) {
        while (S.size() > 1 && C(S.back(), CHLine(a, b)) <= C(S[S.size() - 2], S.back())) S.pop_back();
        S.emplace_back(a, b);
    }
    i64 Query(const i64 x) const {
        int lo = 0, hi = S.size();
        while (lo + 1 < hi) {
            const int mid = (lo + hi) >> 1;
            if (C(S[mid - 1], S[mid]) <= CHLine(x, 1)) lo = mid;
            else hi = mid;
        }
        return F(S[lo], x);
    }
};

// O(N), 쿼리 x좌표가 단조증가
struct CHNLine {
    i64 x, y;
    CHNLine(const i64 x = 0, const i64 y = 0) : x(x), y(y) {} // NOLINT(*-explicit-constructor)
    bool operator<= (const CHNLine& i) const { return 1. * x / y <= 1. * i.x / i.y; }
};
struct ConvexHullN {
private:
    static i64 F(const CHNLine& i, const i64 x) { return i.x * x + i.y; }
    static CHNLine C(const CHNLine& a, const CHNLine& b) { return { a.y - b.y, b.x - a.x }; }
    deque<CHNLine> S;
public:
    void Insert(const i64 a, const i64 b) {
        while (S.size() > 1 && C(S.back(), CHNLine(a, b)) <= C(S[S.size() - 2], S.back())) S.pop_back();
        S.emplace_back(a, b);
    }
    i64 Query(const i64 x) {
        // 최솟값 => <=를 >=로 수정
        while (S.size() > 1 && F(S[0], x) <= F(S[1], x)) S.pop_front();
        return F(S[0], x);
    }
};

