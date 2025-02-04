/* Update : 2025-02-04 */

#include <bits/stdc++.h>

/// Persistent Li Chao Tree
class Plct {
public:
    struct Line { long long a = 0, b = 9223372036854775807; long long operator[](long long x) const { return a*x+b; } };
private:
    std::vector<Line> tr; std::vector<signed> l, r; long long ln, rn; long long mode = 1;
public:
    Plct(long long leftBound, long long rightBound, bool useMaxQuery = false) : ln(leftBound), rn(rightBound) {
        for(signed i=0; i<2; i++) tr.emplace_back(), l.emplace_back(0), r.emplace_back(0);
        if(useMaxQuery) mode = -1;
    }
    struct Root {
        signed pos = 0, prvPos = 0; Plct* ptr = nullptr;
        Root next() const {
            Root ret; ret.pos = ssize(ptr->tr); ret.prvPos = pos; ret.ptr = ptr;
            ptr->tr.emplace_back(ptr->tr[pos]); ptr->l.emplace_back(ptr->l[pos]); ptr->r.emplace_back(ptr->r[pos]);
            return ret;
        }
        /// @returns self
        Root& add(long long a, long long b) { ptr->update({a*ptr->mode, b*ptr->mode}, prvPos, pos, ptr->ln, ptr->rn); return *this; }
        /// @returns self
        Root& add(const Line& line) { add(line.a, line.b); return *this; }
        /// @returns self
        Root& addAt(long long left, long long right, long long a, long long b) { ptr->updateAt(left, right, prvPos, pos, ptr->ln, ptr->rn, {a*ptr->mode, b*ptr->mode}); return *this; }
        long long query(long long x) const { return ptr->mode * ptr->query(x, pos, ptr->ln, ptr->rn); }
    };
    friend Root; Root root() { return { 1, 0, this }; }
private:
    void updateAt(long long ul, long long ur, long long pp, long long p, long long s, long long e, const Line& line) {
        if(ur < s || e < ul) return;
        if(ul <= s && e <= ur) { update(line, pp, p, s, e); return; }
        if(!l[p] || l[p] == l[pp]) l[p] = std::ssize(tr), tr.emplace_back(tr[l[pp]]), l.emplace_back(l[r[pp]]), r.emplace_back(r[r[pp]]);
        if(!r[p] || r[p] == r[pp]) r[p] = std::ssize(tr), tr.emplace_back(tr[r[pp]]), l.emplace_back(l[l[pp]]), r.emplace_back(r[l[pp]]);
        updateAt(ul, ur, l[pp], l[p], s, (s+e)/2, line);
        updateAt(ul, ur, r[pp], r[p], (s+e)/2+1, e, line);
    }
    void update(const Line& line, long long pp, long long p, long long s, long long e) {
        long long m = (s + e) >> 1; Line low = tr[p], high = line;
        if(low[s] > high[s]) std::swap(low, high);
        if(low[e] <= high[e]) { tr[p] = low; return; }
        if(low[m] < high[m]) {
            tr[p] = low;
            if(!l[p]) l[p] = l[pp];
            if(!r[p] || r[p] == r[pp]) r[p] = std::ssize(tr), tr.emplace_back(tr[r[pp]]), l.emplace_back(l[r[pp]]), r.emplace_back(r[r[pp]]);
            update(high, r[pp], r[p], m+1, e);
        } else {
            tr[p] = high;
            if(!l[p] || l[p] == l[pp]) l[p] = std::ssize(tr), tr.emplace_back(tr[l[pp]]), l.emplace_back(l[l[pp]]), r.emplace_back(r[l[pp]]);
            if(!r[p]) r[p] = r[pp];
            update(low, l[pp], l[p], s, m);
        }
    }
    long long query(long long x, long long p, long long s, long long e) const {
        if(!p) { return 9223372036854775807; } long long m = (s + e) >> 1;
        if(x <= m) return std::min(tr[p][x], query(x, l[p], s, m));
        return std::min(tr[p][x], query(x, r[p], m+1, e));
    }
};
using PlctRoot = Plct::Root;

