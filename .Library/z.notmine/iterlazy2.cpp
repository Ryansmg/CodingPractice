#include <bits/stdc++.h>
using namespace std;
using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using i128 = __int128_t;
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using u128 = __uint128_t;
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define var auto
#define iter(arr) arr.begin(), arr.end()

struct lazy_segtree {
    i32 size, lg;
    vector<i64> tree, lazy;
    static i32 ulog2(i32 n) { i32 res = 0; while (1<<res<n) res++; return res; }
    explicit lazy_segtree(i32 n) {
        lg = ulog2(n);
        size = 1 << lg;
        tree = vector<i64>(size*2, 0);
        lazy = vector<i64>(size*2, 0);
    }
    
    i64 prop(i32 idx, i32 depth) {
        tree[idx] += lazy[idx]*(1<<depth);
        if (idx < size) {
            lazy[idx*2] += lazy[idx];
            lazy[idx*2+1] += lazy[idx];
        }
        lazy[idx] = 0;
        return tree[idx];
    }
    
    i64 query(i32 l, i32 r) {
        l += size, r += size;
        for (i32 i = lg; i>0; i--) {
            if (l>>i<<i != l) prop(l>>i, i);
            if (r>>i<<i != r) prop(r>>i, i);
        }
        i64 res = 0;
        for (i32 ll=l, rr=r, depth=0; ll<rr; ll/=2, rr/=2, depth++) {
            if (ll&1) res += prop(ll++, depth);
            if (rr&1) res += prop(--rr, depth);
        }
        return res;
    }
    
    void update(i32 l, i32 r, i64 value) {
        l += size, r += size;
        for (i32 i = lg; i>0; i--) {
            if (l>>i<<i != l) prop(l>>i, i);
            if (r>>i<<i != r) prop(r>>i, i);
        }
        for (i32 ll=l, rr=r, depth=0; ll<rr; ll/=2, rr/=2, depth++) {
            if (ll&1) lazy[ll] += value, prop(ll++, depth);
            if (rr&1) lazy[--rr] += value, prop(rr, depth);
        }
        for (i32 i = 1; i <= lg; i++) {
            if (l>>i<<i != l) tree[l>>i] = prop(l>>i<<1, i-1) + prop(l>>i<<1|1, i-1);
            if (r>>i<<i != r) tree[r>>i] = prop(r>>i<<1, i-1) + prop(r>>i<<1|1, i-1);
        }
    }
};
