/* Update : 2025-03-24 */

#include <vector>
#include <iostream>

class Bitset {
    size_t l = 0, wl = 0; std::vector<unsigned __int128> m;
public:
    class ref {
        Bitset* p; size_t wi, bi;
    public:
        inline explicit ref(Bitset* p, size_t idx) : p(p), wi(idx/128), bi(idx%128) {}
        inline ref& flip() { p->m[wi] ^= (__int128(1) << bi); return *this; }
        inline operator bool() const { return p->m[wi] & (__int128(1) << bi); } // NOLINT(*-explicit-constructor)
        inline ref& operator=(bool b) {
            if(b) p->m[wi] |= (__int128(1) << bi);
            else p->m[wi] &= ~(__int128(1) << bi);
            return *this;
        }
        inline ref& operator=(const ref& b) { operator=(static_cast<bool>(b)); return *this; }
    };
    Bitset() = default;
    explicit Bitset(size_t sz) : l(sz), wl((sz+127)/128), m((sz+127)/128, 0) { }
    explicit Bitset(size_t sz, __int128 value) : Bitset(sz) { m[0] = value; }
    static Bitset of(__int128 value) { return Bitset(128, value); }
    static Bitset of(unsigned __int128 value) { return Bitset(128, value); }
    static Bitset of(long long value) { return Bitset(64, value); }
    static Bitset of(unsigned long long value) { return Bitset(64, value); }
    static Bitset of(signed value) { return Bitset(32, value); }
    static Bitset of(unsigned value) { return Bitset(32, value); }
    Bitset& flip() { for(auto& i : m) i = ~i; return *this; }
    inline Bitset& flip(size_t pos) { m[pos/128] ^= (__int128(1) << (pos % 128)); return *this; }
    inline bool operator[](size_t i) const { return !!(m[i/128] & (__int128(1) << (i%128))); }
    inline ref operator[](size_t i) { return ref(this, i); }

    long long count() const {
        long long r = 0; using ull = unsigned long long;
        for(size_t i = 0; i < wl; i++)
            r += __builtin_popcountll(static_cast<ull>(m[i]))
                 + __builtin_popcountll(static_cast<ull>(m[i] >> 64));
        return r;
    }

#define bs_op_(o) \
    Bitset& operator o (const Bitset& v) { \
        size_t ml = std::min(wl, v.wl);           \
        for(size_t i = 0; i < ml; i++) m[i] o v.m[i]; \
        return *this; \
    }
    bs_op_(&=) bs_op_(|=) bs_op_(^=)
#define bs_op_2_(o) \
    inline Bitset operator o (const Bitset& v) const { \
        Bitset r = *this; r o##= v; return r; \
    }

    Bitset operator~() const { Bitset r(*this); r.flip(); return r; }

    Bitset& operator+=(const Bitset& v) {
        size_t ml = std::min(wl, v.wl);
        bool carry = false;
        for (size_t i = 0; i < ml; i++) {
            unsigned __int128 t;
            bool of = __builtin_add_overflow(m[i], v.m[i], &t);
            if (carry) of |= __builtin_add_overflow(t, 1, &t);
            m[i] = t; carry = of;
        }
        return *this;
    }

    Bitset& operator-=(const Bitset& v) {
        size_t ml = std::min(wl, v.wl);
        bool br = false;
        for (size_t i = 0; i < ml; i++) {
            unsigned __int128 t;
            bool of = __builtin_sub_overflow(m[i], v.m[i], &t);
            if (br) of |= __builtin_sub_overflow(t, 1, &t);
            m[i] = t; br = of;
        }
        return *this;
    }

    Bitset& operator<<=(size_t shift) {
        if (shift == 0) return *this;
        long long ws = shift / 128, bs = shift % 128;
        if (ws >= static_cast<long long>(wl)) { std::fill(m.begin(), m.end(), 0); return *this; }
        for (long long i = wl - 1; i >= ws; --i) {
            m[i] = m[i - ws] << bs;
            if (i > ws && bs) m[i] |= m[i - ws - 1] >> (128 - bs);
        }
        std::fill(m.begin(), m.begin() + ws, 0);
        return *this;
    }

    Bitset& operator>>=(size_t shift) {
        if (shift == 0) return *this;
        long long ws = shift / 128, bs = shift % 128;
        if (ws >= static_cast<long long>(wl)) { std::fill(m.begin(), m.end(), 0); return *this; }
        for (long long i = 0; i < static_cast<long long>(wl - ws); ++i) {
            m[i] = m[i + ws] >> bs;
            if (i + ws + 1 < static_cast<long long>(wl) && bs) m[i] |= m[i + ws + 1] << (128 - bs);
        }
        std::fill(m.end() - ws, m.end(), 0);
        return *this;
    }

    bs_op_2_(&) bs_op_2_(|) bs_op_2_(^) bs_op_2_(+) bs_op_2_(-)

    inline Bitset operator<<(size_t shift) const { Bitset r(*this); r <<= shift; return r; }
    inline Bitset operator>>(size_t shift) const { Bitset r(*this); r >>= shift; return r; }

    friend std::ostream& operator<<(std::ostream& out, const Bitset& v) {
        for(long long i=v.l-1; i>=0; i--) out << ((v.m[i/128] & (__int128(1) << (i % 128))) ? 1 : 0);
        return out;
    }
};
