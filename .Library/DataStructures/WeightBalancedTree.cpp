#include <utility>
#include <vector>
#include <functional>
#include <cassert>
#include <utility>
#include <memory>

/// T + T 연산 필요
/// 1-based index 사용
/// push, pull (노드 전파 / 업데이트 함수) 초기화 필요
template <typename T>
class weight_balanced_tree {

    /// 유지할 비율
    static constexpr long long alpha = 4;

public:
    class node : public std::enable_shared_from_this<node> {
    public:
        node(weight_balanced_tree* origin_, std::shared_ptr<node> l_, std::shared_ptr<node> r_, int sz_, const T& val_)
            : origin(origin_), l(std::move(l_)), r(std::move(r_)), sz(sz_), val(val_) {}
        weight_balanced_tree* origin = nullptr;
        std::shared_ptr<node> l = nullptr, r = nullptr;
        signed sz = 0;

        // value 값은 항상 옳아야 함.
        // 즉, lazy 값 전파 시 자식 노드 업데이트 수행
        T val;

        inline void push() {
            if(l && !l.unique()) l = std::make_shared<node>(*l);
            if(r && !r.unique()) r = std::make_shared<node>(*r);

            if(origin->push)
                origin->push(this->shared_from_this());
        }

        inline void pull() {
            sz = !(l || r);
            if(l) sz += l->sz;
            if(r) sz += r->sz;

            if(origin->pull)
                origin->pull(this->shared_from_this());
        }
    };

    using ptr = std::shared_ptr<node>;

    std::function<void(ptr)> push, pull;

    weight_balanced_tree() = default;

    /**
     * @returns push되지 않은 상태의 노드
     */
    inline ptr copy_(const ptr& nd) {
        ptr ret = std::make_shared<node>(*nd);
        return ret;
    }

    inline ptr join(const ptr& l, const ptr& r) {
        ptr ret = std::make_shared<node>(this, l, r, 0, T());
        ret->pull();
        return ret;
    }

private:
    inline ptr init_(std::vector<T>& arr, int s, int e) {
        if(s == e) return std::make_shared<node>(this, nullptr, nullptr, 1, arr[s]);
        int m = (s + e) >> 1;
        auto l = init_(arr, s, m), r = init_(arr, m + 1, e);
        return join(l, r);
    }

    static inline bool ok_(int sz1, int sz2) {
        return sz1 <= alpha * sz2 && sz2 <= alpha * sz1;
    }

    static inline bool ok(const ptr& a, const ptr& b) {
        return ok_(a->sz, b->sz);
    }

public:
    inline ptr init(std::vector<T>& arr) {
        assert(!arr.empty());
        return init_(arr, 0, std::ssize(arr) - 1);
    }

    inline ptr merge(const ptr& l, const ptr& r) {
        if(!l && !r) return ptr(nullptr);
        if(!l) return copy_(r);
        if(!r) return copy_(l);
        assert(l.unique() && r.unique());
        if(ok(l, r)) return join(l, r);
        l->push(); r->push();
        if(l->sz > r->sz) {
            auto x = l->l, y = merge(l->r, r);
            if(ok(x, y)) return join(x, y);
            y->push();
            if(ok(x, y->l) && ok_(x->sz + y->l->sz, y->r->sz))
                return join(join(x, y->l), y->r);
            if(!y->l) return join(x, y);
            return y->l->push(), join(
                join(x, y->l->l),
                join(y->l->r, y->r)
            );
        }
        auto x = merge(l, r->l), y = r->r;
        if(ok(x, y)) return join(x, y);
        x->push();
        if(ok(x->r, y) && ok_(x->l->sz, x->r->sz + y->sz))
            return join(x->l, join(x->r, y));
        if(!x->r) return join(x, y);
        return x->r->push(), join(
            join(x->l, x->r->l),
            join(x->r->r, y)
        );
    }

    template <typename... Args>
    inline ptr merge(const ptr& a, const ptr& b, const ptr& c, const Args&... args) {
        return merge(merge(a, b), c, args...);
    }

    // root가 루트인 서브트리를 (sz, root.sz - sz) 크기의 두 서브트리로 나눔
    inline std::pair<ptr, ptr> split(const ptr& root, int sz) {
        assert(root && 0 <= sz && sz <= root->sz);
        assert(root.unique());
        if(!sz) return {0, copy_(root)};
        if(sz == root->sz) return {copy_(root), 0};
        root->push();
        if(sz <= root->l->sz) {
            auto [l, r] = split(root->l, sz);
            return {l, merge(r, root->r)};
        }
        auto [l, r] = split(root->r, sz - root->l->sz);
        return {merge(root->l, l), r};
    }

    // root 서브트리의 왼쪽 sz 범위를 복사 후 반환
    inline ptr left(const ptr& root, int sz) {
        assert(root && 0 <= sz && sz <= root->sz);
        assert(root.unique());
        if(!sz) return nullptr;
        if(sz == root->sz) return copy_(root);
        root->push();
        if(sz <= root->l->sz)
            return left(root->l, sz);
        return merge(
            root->l,
            left(root->r, sz - root->l->sz)
        );
    }

    // root 서브트리의 오른쪽 sz 범위를 복사 후 반환
    // @return push되지 않은 노드
    inline ptr right(const ptr& root, int sz) {
        assert(root && 0 <= sz && sz <= root->sz);
        assert(root.unique());
        if(sz == root->sz) return copy_(root);
        if(!sz) return nullptr;
        root->push();
        if(sz <= root->r->sz)
            return right(root->r, sz);
        return merge(
            right(root->l, sz - root->r->sz),
            root->r
        );
    }

    // root 서브트리의 l ~ r 범위를 복사
    inline ptr copy(const ptr& root, int l, int r) {
        assert(root);
        if(l > r) return nullptr;
        assert(1 <= l && l <= r && r <= root->sz);
        assert(root.unique());
        root->push();
        if(l == 1) return left(root, r);
        if(r == root->sz) return right(root, r - l + 1);
        int m = root->l->sz;
        if(r <= m) return copy(root->l, l, r);
        if(l > m) return copy(root->r, l - m, r - m);
        return merge(
            right(root->l, m - l + 1),
            left(root->r, r - m)
        );
    }

    // root 서브트리 전체를 복사
    inline ptr copy(const ptr& root) {
        assert(root && root.unique());
        return copy(root, 1, root->sz);
    }

    // l ~ r 범위 쿼리
    inline T query(const ptr& root, int l, int r) {
        assert(root && 1 <= l && l <= r && r <= root->sz);
        assert(root.unique());
        root->push();
        if(l == 1 && r == root->sz) {
            return root->val;
        }
        int m = root->l->sz;
        if(r <= m) return query(root->l, l, r);
        if(m < l) return query(root->r, l - m, r - m);
        return query(root->l, l, m) + query(root->r, 1, r - m);
    }

    /**
     * @param tag void(ptr) 타입의 함수. lazy를 사용할 경우, 값과 lazy 변수 모두를 변경해야 한다.
     */
    template <typename Function>
    inline void update(ptr& root, int l, int r, const Function& tag) {
        assert(root && 1 <= l && l <= r && r <= root->sz);
        assert(root.unique());
        root->push();
        if(1 == l && r == root->sz) {
            tag(root); return;
        }
        int m = root->l->sz;
        if(l <= m) update(root->l, l, std::min(r, m), tag);
        if(m < r) update(root->r, std::max(m + 1, l) - m, r - m, tag);
        root->pull();
    }

    inline std::vector<T> getLeafs(const ptr& root, int l, int r) {
        std::vector<T> res;
        std::function<void(const ptr&, int, int)> f = [&](const ptr& p, int s, int e) {
            p->push();
            if(s == e) { res.push_back(p->val); return; }
            int m = p->l->sz;
            if(s <= m) f(p->l, s, std::min(e, m));
            if(m < e) f(p->r, std::max(m + 1, s) - m, e - m);
        };
        f(root, l, r);
        return res;
    }

    inline void setLeafs(const ptr& root, int l, int r, std::vector<T> arr) {
        std::function<void(const ptr&, int, int)> f = [&](const ptr& p, int s, int e) {
            p->push();
            if(s == e) {
                p->val = arr.back();
                arr.pop_back();
                return;
            }
            int m = p->l->sz;
            if(m < e) f(p->r, std::max(m + 1, s) - m, e - m);
            if(s <= m) f(p->l, s, std::min(e, m));
            p->pull();
        };
        f(root, l, r);
    }
};


// BOJ 17486. 수열과 쿼리 30

#include <iostream>
using namespace std;

struct val {
    long long sum = 0, lazy = 0;
    val operator+(const val& b) const {
        return {sum + b.sum, 0};
    }
};

using wbt = weight_balanced_tree<val>;

void push(const wbt::ptr& t) {
    if(t->val.lazy) {
        if(t->l) {
            t->l->val.sum += t->l->sz * t->val.lazy;
            t->l->val.lazy += t->val.lazy;
        }
        if(t->r) {
            t->r->val.sum += t->r->sz * t->val.lazy;
            t->r->val.lazy += t->val.lazy;
        }
        t->val.lazy = 0;
    }
}

void pull(const wbt::ptr& t) {
    if(!t->l && !t->r) return;
    if(!t->l) { t->val.sum = t->r->val.sum; return; }
    if(!t->r) { t->val.sum = t->l->val.sum; return; }
    t->val = t->l->val + t->r->val;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    long long n, q; cin >> n;
    vector<val> iarr(n);
    for(int i = 0; i < n; i++) cin >> iarr[i].sum;
    cin >> q;

    wbt tree;
    tree.push = push; tree.pull = pull;
    wbt::ptr root = tree.init(iarr);

    while(q--) {
        long long t, l, r, s, e, x;
        cin >> t;
        if(t == 1) {
            cin >> l >> r >> x;
            tree.update(root, l, r, [&](const wbt::ptr& nd) {
                nd->val.sum += nd->sz * x;
                nd->val.lazy += x;
            });
        }
        if(t == 2) {
            cin >> l >> r >> s >> e;
            auto a = tree.copy(root, 1, l - 1),
                 b = tree.copy(root, s, e),
                 c = tree.copy(root, r + 1, n);
            root = tree.merge(a, b, c);
        }
        if(t == 3) {
            cin >> l >> r;
            cout << tree.query(root, l, r).sum << '\n';
        }
    }
}
