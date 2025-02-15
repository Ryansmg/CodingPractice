/* Update : 2025-02-11 */

#include <vector>
#include <functional>
#include <array>
#include <iostream>

/// [minValue, maxValue] 범위의 수를 저장.
/// 연산의 시간복잡도는 수의 범위를 L이라 할 때 O(log L) => 수의 범위가 좁을수록 성능이 향상됨.
/// 공간복잡도는 추가된 수의 종류를 K라 하면 min(K log L, 4 * L)
/// 범위를 벗어나는 수에 대한 동작은 정의되어 있지 않음. (따로 처리하지 않음)
/// 2^30개 이상의 수는 저장 불가
class SegSet {
    struct DynamicSeg_ {
        static inline long long m(long long s, long long e) { return s + (e - s) / 2; }
        std::vector<signed> tree; long long ln, rn; std::vector<signed> l, r;
        inline signed next() { tree.emplace_back(); l.emplace_back(-1); r.emplace_back(-1); return ((signed)tree.size())-1; }
        explicit DynamicSeg_(long long li, long long ri) : ln(li), rn(ri) { next(); }
        inline void add(long long tar, const signed& val) { add(0, ln, rn, tar, val); }
        inline void set(long long tar, const signed& val) { set(0, ln, rn, tar, val); }
        inline signed query(long long left, long long right) const { return query(0, ln, rn, left, right); }
        signed& add(signed p, long long s, long long e, long long t, const signed& v) {
            if(s == e) return tree[p] = tree[p] + v;
            if(t <= m(s, e)) {
                if(l[p] == -1) l[p] = next();
                return tree[p] = add(l[p], s, m(s, e), t, v) + (r[p] == -1 ? 0 : tree[r[p]]);
            }
            if(r[p] == -1) r[p] = next();
            return tree[p] = (l[p] == -1 ? 0 : tree[l[p]]) + add(r[p], m(s, e)+1, e, t, v);
        }
        signed& set(signed p, long long s, long long e, long long t, const signed& v) {
            if(s == e) return tree[p] = v;
            if(t <= m(s, e)) {
                if(l[p] == -1) l[p] = next();
                return tree[p] = set(l[p], s, m(s, e), t, v) + (r[p] == -1 ? 0 : tree[r[p]]);
            }
            if(r[p] == -1) r[p] = next();
            return tree[p] = (l[p] == -1 ? 0 : tree[l[p]]) + set(r[p], m(s, e)+1, e, t, v);
        }
        signed query(signed p, long long s, long long e, long long ql, long long qr) const {
            if(p == -1 || qr < s || e < ql) return 0;
            if(ql <= s && e <= qr) return tree[p];
            return query(l[p], s, m(s, e), ql, qr) + query(r[p], m(s, e)+1, e, ql, qr);
        }
        std::pair<signed, signed> getIter(signed p, long long s, long long e, long long t, signed lSum) const { // returns {ptr, idx}
            if(p == -1 || tree[p] == 0) {return {-1, 0};} if(s == e) return {p, lSum};
            if(m(s, e) <= t) return getIter(l[p], s, m(s, e), t, lSum);
            else return getIter(r[p], m(s, e)+1, e, t, lSum + (l[p] == -1 ? 0 : tree[l[p]]));
        }
        std::pair<signed, signed> lb_(signed p, long long s, long long e, long long t, signed lSum) const { // returns {ptr, idx}
            if(p == -1 || e < t || tree[p] == 0) return {-1, 0};
            if(s == e) return {p, lSum};
            auto tmp = lb_(l[p], s, m(s, e), t, lSum);
            if(tmp.first != -1) return tmp;
            return lb_(r[p], m(s, e) + 1, e, t, lSum + (l[p] == -1 ? 0 : tree[l[p]]));
        }
        std::array<long long, 3> ub_(signed p, long long s, long long e, long long t, signed lSum) const { // returns {ptr, idx, s}
            if(p == -1 || e <= t || tree[p] == 0) return {-1, 0, 0};
            if(s == e) return {p, lSum, s};
            auto tmp = ub_(l[p], s, m(s, e), t, lSum);
            if(tmp[0] != -1) return tmp;
            return ub_(r[p], m(s, e) + 1, e, t, lSum + (l[p] == -1 ? 0 : tree[l[p]]));
        }
        std::array<long long, 3> kth(signed p, long long s, long long e, signed t, signed lSum) const {
            if(p == -1 || tree[p] == 0) return {-1, 0, 0};
            if(s == e) return {p, lSum, s};
            if(l[p] == -1) return kth(r[p], m(s, e) + 1, e, t, lSum);
            if(tree[l[p]] >= t) return kth(l[p], s, m(s, e), t, lSum);
            return kth(r[p], m(s, e) + 1, e, t - tree[l[p]], lSum + tree[l[p]]);
        }
        void forEach(signed p, long long s, long long e, const std::function<void(long long)>& f) const {
            if(p == -1 || tree[p] == 0) return;
            if(s == e) for(signed i = 0; i < tree[p]; i++) f(s);
            else forEach(l[p], s, m(s, e), f), forEach(r[p], m(s, e)+1, e, f);
        }
    };
    DynamicSeg_ mem; bool isMultiSet;
public:
    explicit SegSet(bool multiSet = false, long long minValue = -4000000000000000000, long long maxValue = 4000000000000000000)
            : mem(minValue, maxValue), isMultiSet(multiSet) {}
    /// insert나 erase 시행 후에도 계속 유효함이 보장되지 않음.
    /// 단, (이전에 erase되지 않은 iter라면) erase(iter)는 안전하게 동작함.
    class iter { friend SegSet;
        /// end : {0, ptr, -1, 0, 0}, rend : {0, ptr, -2, 0, 0}
        long long v = 0; // value
        const SegSet* ptr = nullptr;
        signed p = -1, c = 0, i = 0; // pointer, currentIdx, idx
        iter()=default;
        iter(long long v, const SegSet* ptr, signed p, signed c, signed i) : v(v), ptr(ptr), p(p), c(c), i(i) {}
        inline signed i_() const { if(p == -2) { return -1; } if(p == -1) { return ptr->size(); } return i; }

    public:
        inline bool nul() const { return p == -1 || p == -2; }
        inline auto operator<=>(const iter& b) const { return i_() <=> b.i_(); }
        inline bool operator==(const iter& b) const { return i_() == b.i_(); }
        inline signed operator-(const iter& b) const { return i_() - b.i_(); }
        iter& operator++() {
            if(p == -2) return *this = ptr->begin();
            ++i;
            if(++c == ptr->mem.tree[p]) {
                iter nxt = ptr->upper_bound(v);
                v = nxt.v; p = nxt.p; c = nxt.c; i = nxt.i;
            }
            return *this;
        }
        iter& operator--() {
            if(p == -1) {
                iter nxt = ptr->kth_iter_(ptr->size()-1);
                v = nxt.v; p = nxt.p; c = nxt.c; i = nxt.i;
            } else { --i;
                if(i == -1) return *this = {0, ptr, -2, 0, 0};
                if(c) c--;
                else { iter nxt = ptr->kth_iter_(i); v = nxt.v; p = nxt.p; c = nxt.c; }
            }
            return *this;
        }
        inline iter& operator+=(signed k) { return *this = ptr->kth_iter_(i_() + k); }
        inline iter& operator-=(signed k) { return *this = ptr->kth_iter_(i_() - k); }
        inline iter operator++(signed) { iter ret = *this; operator++(); return ret; }
        inline iter operator--(signed) { iter ret = *this; operator--(); return ret; }
        inline iter operator+(signed k) const { iter ret = *this; ret += k; return ret; }
        inline iter operator-(signed k) const { iter ret = *this; ret -= k; return ret; }
        inline long long operator*() const { return v; }

        friend iter prev(const iter& b) { iter ret = b; return --ret; }
        friend iter next(const iter& b) { iter ret = b; return ++ret; }
    };
private:
    /// k >= 0
    inline iter kth_iter_(signed k) const { k++;
        iter ret; ret.ptr = this;
        auto [p, ls, v] = mem.kth(0, mem.ln, mem.rn, k, 0);
        if(p == -1) return ret;
        ret.v = v; ret.p = p; ret.i = k - 1; ret.c = k - 1 - ls;
        return ret;
    }
public:
    inline void insert(long long v) {
        if(isMultiSet) mem.add(v, 1);
        else mem.set(v, 1);
    }
    /// 모든 v를 제거함.
    inline void erase(long long v) { mem.set(v, 0); }
    inline void erase_one(long long v) { if(contains(v)) mem.add(v, -1); }
    inline void erase(const iter& iter) { mem.add(iter.v, -1); }
    inline iter find(long long v) const {
        iter ret{}; ret.v = v; ret.c = 0; ret.ptr = this;
        std::tie(ret.p, ret.i) = mem.getIter(0, mem.ln, mem.rn, v, 0);
        return ret;
    }
    inline bool contains(long long v) const { return mem.query(v, v); }
    inline signed count(long long left, long long right) const { return mem.query(left, right); }
    inline iter lower_bound(long long v) const {
        iter ret{}; ret.v = v; ret.c = 0; ret.ptr = this;
        std::tie(ret.p, ret.i) = mem.lb_(0, mem.ln, mem.rn, v, 0);
        return ret;
    }
    inline iter upper_bound(long long v) const {
        iter ret{}; ret.c = 0; ret.ptr = this;
        auto t = mem.ub_(0, mem.ln, mem.rn, v, 0);
        ret.p = t[0]; ret.i = t[1]; ret.v = t[2];
        return ret;
    }
    inline iter find_first(long long v) const { return find(v); }
    inline iter find_last(long long v) const {
        iter ret = find(v); if(ret.p == -1) return ret;
        ret.i += mem.tree[ret.p] - 1 - ret.c;
        ret.c = mem.tree[ret.p] - 1;
        return ret;
    }
    /// k >= 0
    inline long long operator[](signed k) const { k++;
        auto [p, ls, v] = mem.kth(0, mem.ln, mem.rn, k, 0);
        if(p == -1) {  std::cerr << "SegSet::OutOfBounds"; exit(235235); }
        return v;
    }
    inline signed size() const { return mem.tree[0]; }
    inline bool empty() const { return mem.tree[0] == 0; }
    inline iter begin() const { return kth_iter_(0); }
    inline iter end() const { iter ret; ret.ptr = this; return ret; }
    /// for(auto i : SegSet)은 iter++이 O(logL)이므로 O(NlogL) 시간복잡도를 가지고,
    /// 이 함수는 O(N+L)에 동작함. (이때 L은 수의 범위)
    inline void forEach(const std::function<void(long long)>& func) const { mem.forEach(0, mem.ln, mem.rn, func); }
};

// Example : BOJ 1572. 중앙값

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // 멀티셋 설정 (중복되는 수 허용), 수 범위는 [0, 65536]
    SegSet s(true, 0, 65536);
    int n, k; cin >> n >> k; long long ans = 0;
    vector<long long> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < k; i++) s.insert(arr[i]);
    ans += s[(k+1)/2-1];
    for(int i = k; i < n; i++) {
        s.erase_one(arr[i-k]); s.insert(arr[i]);
        ans += s[(k+1)/2-1];
    }
    cout << ans;
}
