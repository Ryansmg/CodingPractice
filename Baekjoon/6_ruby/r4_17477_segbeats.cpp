// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <cassert>

#define filein freopen(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\z.etcBJ\input.txt)", "r", stdin)
#define fileout freopen(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\z.etcBJ\output.txt)", "w", stdout)

#define Tpl template <typename T>
#define Tpl64 template <typename T = i64>
#define elif else if

using namespace std;

using i32 = signed; using i64 = long long;
Tpl using v = std::vector<T>;
using vl = v<i64>; using vb = v<bool>;
#define ci64 const i64 &

constexpr i64 INF = 1000000000000000000, inf = 2000000000;

#define forn(name, val) for(i64 name = 0; (name) < val; name++)
#define forf(name, start, end) for(i64 name = start; name <= end; name++)
#define rep(n) forn(rep_mac_name_1_, n)
i64 iR_v_;
#define inRep() input(iR_v_); forn(iR_v3_, iR_v_)

#ifdef LOCAL
#define lfastio print()
#else
#define lfastio fastio
#endif
#define fastio std::ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
Tpl64 inline T input() {T t; cin >> t; return t;}

template <typename ...T> inline void println(const T&... a_) { (cout << ... << a_); cout << '\n'; } inline void println() { cout << '\n'; }
template <typename ...T> inline void input(T&... a_) { (cin >> ... >> a_); }
#define in64(...) i64 __VA_ARGS__; input(__VA_ARGS__)

struct tr {
    i64 mx = -INF, mn = INF; i64 bsum = 0;
    i64 mx2 = -INF, mn2 = INF, mxcnt = 0, mncnt = 0;
    tr()=default;
    tr(i64 v, i64 s) : mx(v), mn(v), mxcnt(1), mncnt(1) {}
    tr(i64 a, i64 b, i64 c, i64 d, i64 e, i64 f, i64 g) : mx(a), mn(b), bsum(c), mx2(d), mn2(e), mxcnt(f), mncnt(g) {}
    tr operator+(const tr& b) const {
        tr ret;
        ret.bsum = bsum + b.bsum;
        if(mx == b.mx) {
            ret.mx = mx; ret.mxcnt = mxcnt + b.mxcnt;
            ret.mx2 = max(mx2, b.mx2);
        } elif(mx > b.mx) {
            ret.mx = mx; ret.mxcnt = mxcnt;
            ret.mx2 = max(mx2, b.mx);
        } else {
            ret.mx = b.mx; ret.mxcnt = b.mxcnt;
            ret.mx2 = max(mx, b.mx2);
        }
        if(mn == b.mn) {
            ret.mn = mn; ret.mncnt = mncnt + b.mncnt;
            ret.mn2 = min(mn2, b.mn2);
        } elif(mn < b.mn) {
            ret.mn = mn; ret.mncnt = mncnt;
            ret.mn2 = min(mn2, b.mn);
        } else {
            ret.mn = b.mn; ret.mncnt = b.mncnt;
            ret.mn2 = min(mn, b.mn2);
        }
        return ret;
    }
};

struct lz {
    bool useAdd = false; i64 add = 0;
    bool useSet = false; i64 set = INF;
    bool useMx = false; i64 mx = INF; // min Query, updates mx value
    bool useMn = false; i64 mn = INF; // max Query, updates mn value
    i64 bcntAll = 0; i64 mxocnt = 0, mnocnt = 0;
};

v<tr> tree(2000010, tr());
v<lz> lazy(2000010, lz());
v<i64> arr(500010);

tr& init(i64 node, i64 start, i64 end) {
    assert(1 <= node && node < 2000010);
    assert(1 <= start && start <= 500000);
    if(start == end) return tree[node] = {arr[start], 0};
    return tree[node] = init(node*2, start, (start+end)/2)
        + init(node*2+1, (start+end)/2+1, end);
}

tr tempPush(i64 node, i64 start, i64 end) {
    tr ret = tree[node];
    ret.bsum += (end - start + 1) * lazy[node].bcntAll;
    ret.bsum += ret.mxcnt * lazy[node].mxocnt;
    ret.bsum += ret.mncnt * lazy[node].mnocnt;
    if(lazy[node].useAdd) {
        assert(!lazy[node].useSet);
        ret.mx += lazy[node].add; ret.mn += lazy[node].add;
        if(ret.mx2 != -INF) ret.mx2 += lazy[node].add;
        if(ret.mn2 != INF) ret.mn2 += lazy[node].add;
    }
    if(lazy[node].useSet) {
        assert(!lazy[node].useAdd);
        assert(lazy[node].set < ret.mn || ret.mx < lazy[node].set); // fails
        ret.mx = ret.mn = lazy[node].set;
        ret.mx2 = -INF; ret.mn2 = INF;
        ret.mxcnt = ret.mncnt = (end - start + 1);
    }
    if(lazy[node].useMx) {
        assert(!lazy[node].useSet);
        ret.mn = lazy[node].mn;
    }
    if(lazy[node].useMn) {
        assert(!lazy[node].useSet);
        ret.mx = lazy[node].mx;
    }

    return ret;
}

void mergeLazy(i64 p1, i64 s1, i64 e1, i64 p2, i64 s2, i64 e2) {
    lazy[p2].bcntAll += lazy[p1].bcntAll;
    if(tree[p2].mx == tree[p1].mx) lazy[p2].mxocnt += lazy[p1].mxocnt;
    if(tree[p2].mn == tree[p1].mn) lazy[p2].mnocnt += lazy[p1].mnocnt;
    if(lazy[p1].useAdd) {
        assert(!lazy[p1].useSet);
        if(lazy[p2].useSet) {
            assert(!lazy[p2].useAdd && !lazy[p2].useMn && !lazy[p2].useMx);
            lazy[p2].set += lazy[p1].add;
        } else {
            lazy[p2].useAdd = true;
            lazy[p2].add += lazy[p1].add;
            lazy[p2].mx += lazy[p1].add;
            lazy[p2].mn += lazy[p1].add;
        }
    }
    if(lazy[p1].useSet) {
        lazy[p2].useSet = true;
        lazy[p2].useAdd = false; lazy[p2].add = 0;
        lazy[p2].useMx = lazy[p2].useMn = false; lazy[p2].mn = lazy[p2].mx = INF;
        lazy[p2].set = lazy[p1].set;
    }
    while(lazy[p1].useMx) {
        tr temp = tempPush(p2, s2, e2);
        if(lazy[p1].mx >= temp.mx) break;
        // assert(temp.mx > lazy[p1].mx && lazy[p1].mx >= temp.mx2);
        if(temp.mx == temp.mn) {
            lazy[p2].useSet = true; lazy[p2].set = lazy[p1].mx;
            lazy[p2].bcntAll++; lazy[p2].mxocnt -= lazy[p1].mxocnt;
            lazy[p2].useAdd = lazy[p2].useMn = lazy[p2].useMx = false;
        } else {
            lazy[p2].useMx = true;
            lazy[p2].mx = lazy[p1].mx;
        }
        break;
    }
    while(lazy[p1].useMn) {
        tr temp = tempPush(p2, s2, e2);
        if(temp.mn >= lazy[p1].mn) break;
        // assert(temp.mn < lazy[p1].mn && lazy[p1].mn <= temp.mn2);
        if(temp.mx == temp.mn) {
            lazy[p2].useSet = true; lazy[p2].set = lazy[p1].mn;
            lazy[p2].bcntAll++; lazy[p2].mnocnt -= lazy[p1].mnocnt;
            lazy[p2].useAdd = lazy[p2].useMn = lazy[p2].useMx = false;
        } else {
            lazy[p2].useMn = true;
            lazy[p2].mn = lazy[p1].mn;
        }
        break;
    }
}

void push(i64 node, i64 start, i64 end) {
    if(start != end) {
        mergeLazy(node, start, end, node*2, start, (start+end)/2);
        mergeLazy(node, start, end, node*2+1, (start+end)/2+1, end);
    }
    tree[node] = tempPush(node, start, end);
    lazy[node] = lz();
}

i64 queryB(i64 node, i64 start, i64 end, i64 left, i64 right) {
    // assert(1 <= node && node < 2000010);
    push(node, start, end);
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return tree[node].bsum;
    return queryB(node*2, start, (start+end)/2, left, right)
        + queryB(node*2+1, (start+end)/2+1, end, left, right);
}

tr& add(i64 p, i64 s, i64 e, i64 l, i64 r, i64 v) {
    // assert(1 <= p && p < 2000010);
    if(v == 0) return tree[p];
    push(p, s, e);
    if(r < s || e < l) return tree[p];
    if(l <= s && e <= r) {
        lazy[p].add = v; lazy[p].bcntAll = 1;
        lazy[p].useAdd = true;
        push(p, s, e);
        return tree[p];
    }

    return tree[p] = add(p*2, s, (s+e)/2, l, r, v)
                        + add(p*2+1, (s+e)/2+1, e, l, r, v);
}

tr& mxu(i64 p, i64 s, i64 e, i64 l, i64 r, i64 v) {
    // assert(1 <= p && p < 2000010);
    push(p, s, e);
    if(r < s || e < l) return tree[p];
    if(tree[p].mn >= v) return tree[p];

    bool tag1 = tree[p].mx < v;
    if(l <= s && e <= r && tag1) {
        lazy[p].set = v; lazy[p].bcntAll = 1;
        lazy[p].useSet = true;
        push(p, s, e);
        return tree[p];
    }

    bool tag2 = tree[p].mn < v && v <= tree[p].mn2;
    if(l <= s && e <= r && tag2) {
        lazy[p].useMn = true; lazy[p].mn = v; lazy[p].mnocnt = 1;
        push(p, s, e);
        return tree[p];
    }

    return tree[p] = mxu(p*2, s, (s+e)/2, l, r, v)
                    + mxu(p*2+1, (s+e)/2+1, e, l, r, v);
}

tr& mnu(i64 p, i64 s, i64 e, i64 l, i64 r, i64 v) {
    // assert(1 <= p && p < 2000010);
    push(p, s, e);
    if(r < s || e < l) return tree[p];
    if(tree[p].mx <= v) return tree[p];

    bool tag = tree[p].mn > v;
    if(l <= s && e <= r && tag) {
        lazy[p].set = v; lazy[p].bcntAll = 1;
        lazy[p].useSet = true;
        push(p, s, e);
        return tree[p];
    }

    bool tag2 = tree[p].mx > v && v >= tree[p].mx2;
    if(l <= s && e <= r && tag2) {
        lazy[p].useMx = true;
        lazy[p].mx = v;

        lazy[p].mxocnt = 1;
        push(p, s, e);
        return tree[p];
    }

    return tree[p] = mnu(p*2, s, (s+e)/2, l, r, v)
                    + mnu(p*2+1, (s+e)/2+1, e, l, r, v);
}


i32 main() {
    fastio;
    // filein; fileout;
    i64 N = input();
    forf(i, 1, N) input(arr[i]);
    init(1, 1, N);
    inRep() {
        in64(op, l, r);
        if(op == 1) add(1, 1, N, l, r, input());
        elif(op == 2) mxu(1, 1, N, l, r, input());
        elif(op == 3) mnu(1, 1, N, l, r, input());
        else println(queryB(1, 1, N, l, r));
    }
}
