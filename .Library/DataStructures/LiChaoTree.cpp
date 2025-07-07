/* Update : 2025-02-11 */

#include <vector>

class LiChaoTree {
    static inline long long m(long long s, long long e) { return s + (e - s) / 2; }
public:
    struct Line { long long a = 0, b = 9223372036854775807; long long operator[](long long x) const { return a*x+b; } };
    LiChaoTree() : left(0), right(0) {}
    LiChaoTree(long long l, long long r, bool useMaxQuery = false) : left(l), right(r) { tr.emplace_back(); if(useMaxQuery) mode = -1; }
    void update(const Line& line) { update({mode*line.a, mode*line.b}, 0, left, right); }
    void update(long long a, long long b) { update({mode*a, mode*b}, 0, left, right); }
    void updateAt(long long l, long long r, const Line& line) { updateAt(l, r, 0, left, right, {mode*line.a, mode*line.b}); }
    long long query(long long x) const { return mode*query(x, 0, left, right); }
    long long operator[](long long x) const { return mode*query(x, 0, left, right); }
private:
    struct Node { signed l = -1, r = -1; Line line = Line(); };
    std::vector<Node> tr; long long left, right; long long mode = 1;
    void updateAt(long long l, long long r, long long p, long long s, long long e, const Line& line) {
        if(r < s || e < l) return;
        if(l <= s && e <= r) { update(line, p, s, e); return; }
        if(tr[p].l == -1) tr[p].l = signed(tr.size()), tr.emplace_back();
        if(tr[p].r == -1) tr[p].r = signed(tr.size()), tr.emplace_back();
        updateAt(l, r, tr[p].l, s, m(s, e), line);
        updateAt(l, r, tr[p].r, m(s, e)+1, e, line);
    }
    void update(const Line& line, long long p, long long s, long long e) {
        Line low = tr[p].line, high = line;
        if(low[s] > high[s]) std::swap(low, high);
        if(low[e] <= high[e]) { tr[p].line = low; return; }
        if(low[m(s, e)] < high[m(s, e)]) {
            tr[p].line = low;
            if(tr[p].r == -1) tr[p].r = signed(tr.size()), tr.emplace_back();
            update(high, tr[p].r, m(s, e)+1, e);
        } else {
            tr[p].line = high;
            if(tr[p].l == -1) tr[p].l = signed(tr.size()), tr.emplace_back();
            update(low, tr[p].l, s, m(s, e));
        }
    }
    long long query(long long x, long long p, long long s, long long e) const {
        if(p == -1) { return 9223372036854775807; }
        if(x <= m(s, e)) return std::min(tr[p].line[x], query(x, tr[p].l, s, m(s, e)));
        return std::min(tr[p].line[x], query(x, tr[p].r, m(s, e)+1, e));
    }
};

// Example : BOJ 12795. 반평면 땅따먹기
#include <iostream>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    LiChaoTree lct(-2000000000000, 2000000000000, true);
    int Q; cin >> Q;
    for(int i = 0; i < Q; i++) {
        int op; cin >> op;
        if(op == 1) {
            long long a, b; cin >> a >> b;
            lct.update({a, b});
        } else {
            long long x; cin >> x;
            cout << lct.query(x) << '\n';
        }
    }
}

template <typename T = bool>
class LiChaoTreeT {
    static inline long long m(long long s, long long e) { return s + (e - s) / 2; }
public:
    struct Line { long long a = 0, b = 9223372036854775807; inline long long operator[](long long x) const { return a*x+b; } };
    using Type = std::conditional_t<std::is_same_v<T, bool>, Line, T>;
    LiChaoTreeT() : left(0), right(0) {}
    LiChaoTreeT(long long l, long long r, bool useMaxQuery = false) : left(l), right(r) { tr.emplace_back(); if(useMaxQuery) mode = -1; }
    void update(const Type& line) { update({mode*line.a, mode*line.b}, 0, left, right); }
    void update(long long a, long long b) { update({mode*a, mode*b}, 0, left, right); }
    void updateAt(long long l, long long r, const Type& line) { updateAt(l, r, 0, left, right, {mode*line.a, mode*line.b}); }
    long long query(long long x) const { return mode*query(x, 0, left, right); }
    long long operator[](long long x) const { return mode*query(x, 0, left, right); }
private:
    struct Node { signed l = -1, r = -1; Type line = Type(); };
    std::vector<Node> tr; long long left, right; long long mode = 1;
    void updateAt(long long l, long long r, long long p, long long s, long long e, const Type& line) {
        if(r < s || e < l) return;
        if(l <= s && e <= r) { update(line, p, s, e); return; }
        if(tr[p].l == -1) tr[p].l = signed(tr.size()), tr.emplace_back();
        if(tr[p].r == -1) tr[p].r = signed(tr.size()), tr.emplace_back();
        updateAt(l, r, tr[p].l, s, m(s, e), line);
        updateAt(l, r, tr[p].r, m(s, e)+1, e, line);
    }
    void update(const Type& line, long long p, long long s, long long e) {
        Type low = tr[p].line, high = line;
        if(low[s] > high[s]) std::swap(low, high);
        if(low[e] <= high[e]) { tr[p].line = low; return; }
        if(low[m(s, e)] < high[m(s, e)]) {
            tr[p].line = low;
            if(tr[p].r == -1) tr[p].r = signed(tr.size()), tr.emplace_back();
            update(high, tr[p].r, m(s, e)+1, e);
        } else {
            tr[p].line = high;
            if(tr[p].l == -1) tr[p].l = signed(tr.size()), tr.emplace_back();
            update(low, tr[p].l, s, m(s, e));
        }
    }
    long long query(long long x, long long p, long long s, long long e) const {
        if(p == -1) { return 9223372036854775807; }
        if(x <= m(s, e)) return std::min(tr[p].line[x], query(x, tr[p].l, s, m(s, e)));
        return std::min(tr[p].line[x], query(x, tr[p].r, m(s, e)+1, e));
    }
};
