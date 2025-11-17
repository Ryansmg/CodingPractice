#include <utility>
#include <vector>
#include <functional>
#include <cassert>
#include <memory>
#include <iostream>

// implement: T, merge_T, push, update
namespace wbt {
    struct T {
        int val = 0;
        bool flip = false;
    };

    T merge_T(const T&, const T&) {
        return {};
    }

    // alpha >= 3이어야 함
    constexpr long long alpha = 3;
    constexpr long long mem_allocate = 15571557;
    constexpr bool use_garbage_collection = true;

    struct node {
        signed l = 0, r = 0, sz = 0, ref_cnt = 0;
        T val{};
    };

    node mem[mem_allocate]{};
    // next available position
    signed mi = 1;
    std::vector<signed> free;

    inline void remove_ref(signed p) {
        assert(p);
        mem[p].ref_cnt--;
        if(!mem[p].ref_cnt) {
            if(mem[p].l) remove_ref(mem[p].l);
            if(mem[p].r) remove_ref(mem[p].r);
            if constexpr(use_garbage_collection) free.push_back(p);
        }
    }

    inline signed allocate_() {
        if(use_garbage_collection && !free.empty()) {
            signed ret = free.back();
            free.pop_back();
            return ret;
        }
        if(mi == mem_allocate) {
            while(true) {
                std::cout << "memory allocation failed.\n";
            }
        }
        return mi++;
    }

    template <typename... Args>
    inline signed allocate(Args&&... args) {
        signed i = allocate_();
        mem[i] = { args... };
        if(mem[i].l) mem[mem[i].l].ref_cnt++;
        if(mem[i].r) mem[mem[i].r].ref_cnt++;
        return i;
    }

    inline void push(signed p) {
        if(!p) return;
        if(mem[p].l && mem[mem[p].l].ref_cnt > 1) {
            signed i = allocate(mem[mem[p].l].l, mem[mem[p].l].r, mem[mem[p].l].sz, 1, mem[mem[p].l].val);
            remove_ref(mem[p].l);
            mem[p].l = i;
        }

        if(mem[p].r && mem[mem[p].r].ref_cnt > 1) {
            signed i = allocate(mem[mem[p].r].l, mem[mem[p].r].r, mem[mem[p].r].sz, 1, mem[mem[p].r].val);
            remove_ref(mem[p].r);
            mem[p].r = i;
        }

        // implement here
        // 자식 노드의 값과 lazy 변수 모두를 업데이트해야 함.
        // 현재 노드의 값은 이미 업데이트됨.
        // 초기화 잊지 않기
        if(mem[p].val.flip) {
            if(mem[p].l) {
                mem[mem[p].l].val.flip ^= 1;
                std::swap(mem[mem[p].l].l, mem[mem[p].l].r);
            }
            if(mem[p].r) {
                mem[mem[p].r].val.flip ^= 1;
                std::swap(mem[mem[p].r].l, mem[mem[p].r].r);
            }
            mem[p].val.flip = false;
        }
    }

    inline void pull(signed p) {
        if(!p) return;
        if(!mem[p].l && !mem[p].r) {
            mem[p].sz = 1;
            return;
        }
        mem[p].sz = mem[mem[p].l].sz + mem[mem[p].r].sz;
        mem[p].val = merge_T(mem[mem[p].l].val, mem[mem[p].r].val);
    }

    inline signed copy(signed p) {
        return allocate(mem[p].l, mem[p].r, mem[p].sz, 0, mem[p].val);
    }

    inline signed join(signed l, signed r) {
        signed i = allocate(l, r, 0, 0, T());
        pull(i);
        return i;
    }

    signed init_(const std::vector<T>& arr, signed s, signed e) {
        if(s == e) return allocate(0, 0, 1, 0, arr[s]);
        signed m = (s + e) >> 1;
        signed l = init_(arr, s, m), r = init_(arr, m + 1, e);
        return join(l, r);
    }

    inline bool ok_(signed sz1, signed sz2) {
        return sz1 <= alpha * sz2 && sz2 <= alpha * sz1;
    }

    static inline bool ok(signed a, signed b) {
        return ok_(mem[a].sz, mem[b].sz);
    }

    signed merge(signed l, signed r) {
        if(!l && !r) return 0;
        if(!l) return copy(r);
        if(!r) return copy(l);
        if(ok(l, r)) return join(l, r);
        push(l); push(r);
        if(mem[l].sz > mem[r].sz) {
            signed x = mem[l].l, y = merge(mem[l].r, r);
            if(ok(x, y)) return join(x, y);
            push(y);
            if(ok(x, mem[y].l) && ok_(mem[x].sz + mem[mem[y].l].sz, mem[mem[y].r].sz))
                return join(join(x, mem[y].l), mem[y].r);
            push(mem[y].l);
            return join(
                join(x, mem[mem[y].l].l),
                join(mem[mem[y].l].r, mem[y].r)
            );
        }
        signed x = merge(l, mem[r].l), y = mem[r].r;
        if(ok(x, y)) return join(x, y);
        push(x);
        if(ok(mem[x].r, y) && ok_(mem[mem[x].l].sz, mem[mem[x].r].sz + mem[y].sz))
            return join(mem[x].l, join(mem[x].r, y));
        push(mem[x].r);
        return join(
            join(mem[x].l, mem[mem[x].r].l),
            join(mem[mem[x].r].r, y)
        );
    }

    std::pair<signed, signed> split(signed p, signed sz) {
        if(!sz) return {0, copy(p)};
        if(sz == mem[p].sz) return {copy(p), 0};
        push(p);
        if(sz <= mem[mem[p].l].sz) {
            auto [l, r] = split(mem[p].l, sz);
            return {l, merge(r, mem[p].r)};
        }
        auto [l, r] = split(mem[p].r, sz - mem[mem[p].l].sz);
        return {merge(mem[p].l, l), r};
    }

    signed left(signed p, signed sz) {
        if(!sz) return 0;
        if(sz == mem[p].sz) return copy(p);
        push(p);
        if(sz <= mem[mem[p].l].sz)
            return left(mem[p].l, sz);
        return merge(
            mem[p].l,
            left(mem[p].r, sz - mem[mem[p].l].sz)
        );
    }

    signed right(signed p, signed sz) {
        if(!sz) return 0;
        if(sz == mem[p].sz) return copy(p);
        push(p);
        if(sz <= mem[mem[p].r].sz)
            return right(mem[p].r, sz);
        return merge(
            right(mem[p].l, sz - mem[mem[p].r].sz),
            mem[p].r
        );
    }

    signed copy(signed p, signed l, signed r) {
        if(l > r) return 0;
        push(p);
        if(l == 1) return left(p, r);
        if(r == mem[p].sz) return right(p, r - l + 1);
        signed m = mem[mem[p].l].sz;
        if(r <= m) return copy(mem[p].l, l, r);
        if(l > m) return copy(mem[p].r, l - m, r - m);
        return merge(
            right(mem[p].l, m - l + 1),
            left(mem[p].r, r - m)
        );
    }


    T query(signed p, signed l, signed r) {
        push(p);
        if(l == 1 && r == mem[p].sz) return mem[p].val;
        signed m = mem[mem[p].l].sz;
        if(r <= m) return query(mem[p].l, l, r);
        if(m < l) return query(mem[p].r, l - m, r - m);
        return merge_T(query(mem[p].l, l, m), query(mem[p].r, 1, r - m));
    }

    using update_type = long long;

    void update(signed p, signed l, signed r, const update_type& x) {
        push(p);
        if(1 == l && r == mem[p].sz) {
            // implement tag here
            mem[p].val.flip = true;
            std::swap(mem[p].l, mem[p].r);
            return;
        }
        signed m = mem[mem[p].l].sz;
        if(l <= m) update(mem[p].l, l, std::min(r, m), x);
        if(m < r) update(mem[p].r, std::max(m + 1, l) - m, r - m, x);
        pull(p);
    }

    void getLeafs_(signed p, signed s, signed e, std::vector<T>& arr) {
        push(p);
        if(s == e) {arr.push_back(mem[p].val); return;}
        signed m = mem[mem[p].l].sz;
        if(s <= m) getLeafs_(mem[p].l, s, std::min(e, m), arr);
        if(m < e) getLeafs_(mem[p].r, std::max(m + 1, s) - m, e - m, arr);
    }

    void setLeafs_(signed p, signed s, signed e, std::vector<T>& arr) {
        push(p);
        if(s == e) { mem[p].val = arr.back(); arr.pop_back(); return; }
        signed m = mem[mem[p].l].sz;
        if(m < e) setLeafs_(mem[p].r, std::max(m + 1, s) - m, e - m, arr);
        if(s <= m) setLeafs_(mem[p].l, s, std::min(e, m), arr);
        pull(p);
    }

    struct root {
        signed p;
        root(signed p_) : p(p_) {
            if(p) mem[p].ref_cnt++;
        }

        root(const root& o) : p(o.p) { if(p) mem[p].ref_cnt++; }
        root(root&& o) noexcept : p(o.p) { o.p = 0; }
        root& operator=(const root& o) {
            if (this == &o) return *this;
            if(p) remove_ref(p);
            p = o.p;
            if(p) mem[p].ref_cnt++;
            return *this;
        }
        root& operator=(root&& o) noexcept {
            if (this == &o) return *this;
            if(p) remove_ref(p);
            p = o.p; o.p = 0;
            return *this;
        }
        ~root() { if(p) remove_ref(p); }

        inline root copy() const { return wbt::copy(p); }
        inline std::pair<root, root> split(signed sz) const {
            assert(p && 0 <= sz && sz <= mem[p].sz);
            auto [a, b] = wbt::split(p, sz);
            return {root(a), root(b)};
        }

        inline root left(signed sz) const {
            assert(p && 0 <= sz && sz <= mem[p].sz);
            return {wbt::left(p, sz)};
        }

        inline root right(signed sz) const {
            assert(p && 0 <= sz && sz <= mem[p].sz);
            return {wbt::right(p, sz)};
        }

        inline root copy(signed l, signed r) const {
            assert(p);
            if(l > r) return 0;
            assert(1 <= l && l <= r && r <= mem[p].sz);
            return {wbt::copy(p, l, r)};
        }

        inline T query(signed l, signed r) const {
            assert(1 <= l && l <= r && r <= mem[p].sz);
            return wbt::query(p, l, r);
        }

        inline void update(signed l, signed r, const update_type& x) const {
            if(l > r) return;
            assert(1 <= l && l <= r && r <= mem[p].sz);
            wbt::update(p, l, r, x);
        }

        inline std::vector<T> getLeafs(signed l, signed r) const {
            std::vector<T> res;
            res.reserve(r - l + 1);
            getLeafs_(p, l, r, res);
            return res;
        }

        inline void setLeafs(signed l, signed r, std::vector<T> arr) const {
            assert(arr.size() == r - l + 1);
            setLeafs_(p, l, r, arr);
        }
    };

    inline root init(const std::vector<T>& arr) {
        assert(!arr.empty());
        return {init_(arr, 0, std::ssize(arr) - 1)};
    }

    inline root merge(const root& a, const root& b) {
        return {merge(a.p, b.p)};
    }

    template <typename... Args>
    inline root merge(const root& a, const root& b, const root& c, Args... args) {
        return merge(merge(a, b), c, args...);
    }

}

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    long long n, q; cin >> n >> q;
    vector<wbt::T> iarr(n);
    for(int i = 0; i < n; i++) iarr[i].val = i + 1;
    auto root = wbt::init(iarr);

    while(q--) {
        long long t, x, y;
        cin >> t >> x >> y;
        if(t == 1) {
            root.update(1, y, 0);
            root.update(1, y - x + 1, 0);
            root.update(y - x + 2, y, 0);
        }
        else if(t == 2) {
            root.update(x, n, 0);
            root.update(n - (y - x), n, 0);
            root.update(x, n - (y - x) - 1, 0);
        } else {
            auto lf = root.getLeafs(x, y);
            auto nxt = lf;
            auto m = (y - x + 2) / 2;
            for(int i = 0; i < m; i++)
                nxt[i * 2] = lf[i];
            for(int i = m; i < lf.size(); i++) {
                nxt[(i - m) * 2 + 1] = lf[i];
            }
            root.setLeafs(x, y, nxt);
        }
    }

    for(auto i : root.getLeafs(1, n))
        cout << i.val << ' ';
}
