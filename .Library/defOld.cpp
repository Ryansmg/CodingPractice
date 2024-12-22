#include <bits/stdc++.h>
using namespace std;
#define Tpl template <typename T>
using i64 = long long; Tpl using v = std::vector<T>; using str = string;
using i32 = signed;
#define forn(i, n) for(i64 i=0; i<n; i++)

///
#define pf push_front
#define ef emplace_front

template <typename T = i64> inline v<T> inputArr(i64 sz) { v<T> a; forn(i,sz) a.eb(input<T>()); return a; }
template <typename T = i64> inline void inputArr(v<T> &arr, i64 sz, bool clear = true) { if(clear) arr.clear(); forn(i,sz) arr.eb(input<T>()); }
Tpl inline void printArr(const v<T> &v, const str &sep = " ", const str &end = "\n") {
    if(v.empty()) return;
    i64 paSz_ = v.size(); forn(i, paSz_-1) cout << v[i] << sep; cout << v[paSz_-1] << end;
}
inline void fixPrecision(i32 a_) { cout << std::fixed; cout.precision(a_); }
Tpl inline void printSep(const T& a_) { cout << a_; }
template <typename T1, typename ...T2> inline void printSep(const T1& a_, const T2&... b_) { cout << a_ << ' '; printSep(b_...); }
template <typename ...T> inline void printSepLn(const T&... a_) { printSep(a_...); cout << '\n'; }
template <typename ...T> inline void printExit(const T&... a_) { (cout << ... << a_); cout << '\n'; exit(0); }

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
Tpl using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
Tpl using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
Tpl bool contains(ordered_set<T> &oset_, T val_) { if(oset_.empty()) { return false; } return *oset_.find_by_order(oset_.order_of_key(val_)) == val_; }
Tpl bool contains(ordered_multiset<T> &omset_, T val_) { if(omset_.empty()) { return false; } return *omset_.find_by_order(omset_.order_of_key(val_)) == val_; }
Tpl void erase_one(ordered_multiset<T> &omset_, T val_) { int index = omset_.order_of_key(val_); auto it = omset_.find_by_order(index); if(*it == val_) omset_.erase(it); }
Tpl void erase_all(ordered_multiset<T> &omset_, T val_) { while(contains(omset_, val_)) erase_one(omset_, val_); }

namespace temp {

    namespace boj6515 {
        struct tr {
            i64 val = 0;
            tr operator+(const tr& b) const { return tr(max(val, b.val)); }
            void operator+=(ci64 i) { val += i; }
        };

        void solve() {
            while(true) {
                invar(n);
                if(!n) break;
                invar(q); moQuerySortVal = sqrt(n);
                vl arr = inArr(n);
                for(i64& i : arr) i += 100001;
                v<moQuery> queries;
                forn(i, q) { invar(l, r); queries.eb(l-1, r-1, i); }
                sort(queries);
                vl ans(q);
                iterSeg<tr> seg(200010);
                i64 l = queries[0].i, r = queries[0].j;
                forf(i, l, r) seg.add(arr[i], 1);
                ans[queries[0].order] = seg.query(1, 200009).val;
                forf(i, 1, q-1) {
                    i64 nl = queries[i].i, nr = queries[i].j;
                    while(l < nl) seg.add(arr[l++], -1);
                    while(nl < l) seg.add(arr[--l], 1);
                    while(r < nr) seg.add(arr[++r], 1);
                    while(nr < r) seg.add(arr[r--], -1);
                    ans[queries[i].order] = seg.query(1, 200009).val;
                }
                for(ci64 i : ans) cout << i << '\n';
            }
        }
    }

    namespace boj12895 {
        struct tr {
            i64 colors = 0;
            tr operator+(const tr& o) const { return tr(colors|o.colors); }
        };

        struct lz {
            i64 color = 0;
            lz operator+(ci64 i) { return lz(i); }
            lz operator+(const Lazyprop<tr, lz, i64>::iter& i) const {
                if(i.lazy.color == 0) return lz(color);
                return lz(i.lazy.color);
            }
        };

        tr operator+(const tr& a, const Lazyprop<tr, lz, i64>::iter &b) {
            if(b.lazy.color == 0) return tr(a.colors);
            return tr(b.lazy.color);
        }

        void solve() {
            fastio;
            invar(n, t, q);
            Lazyprop<tr, lz, i64> lp(v<tr>(n, tr(2)));
            rep(q) {
                if(input<char>() == 'C') {
                    invar(x, y, z);
                    if(x > y) swap(x, y);
                    lp.update(x, y, 1LL<<z);
                } else {
                    invar(x, y);
                    if(x > y) swap(x, y);
                    tr r = lp.query(x, y);
                    i64 ans = 0;
                    forn(i, 40) if(r.colors & (1LL<<i)) ans++;
                    println(ans);
                }
            }
        }
    }

}