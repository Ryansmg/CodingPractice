/* Update : 2025-10-11 */

#include <vector>
#include <iostream>
#include <cstdint>

class Bitset {
    size_t l = 0, wl = 0; std::vector<unsigned __int128> m;
public:
    class ref {
        Bitset* p; size_t wi, bi;
    public:
        inline explicit ref(Bitset* p, size_t idx) : p(p), wi(idx >> 7), bi(idx & 127) {}
        inline ref& flip() { p->m[wi] ^= (__int128(1) << bi); return *this; }
        // ReSharper disable once CppNonExplicitConversionOperator
        inline operator bool() const { return p->m[wi] & (__int128(1) << bi); } // NOLINT(*-explicit-constructor)
        inline ref& operator=(bool b) {
            if(b) p->m[wi] |= (__int128(1) << bi);
            else p->m[wi] &= ~(__int128(1) << bi);
            return *this;
        }
        inline ref& operator=(const ref& b) { operator=(static_cast<bool>(b)); return *this; }
    };
    Bitset() = default;
    explicit Bitset(size_t sz) : l(sz), wl((sz + 127) >> 7), m((sz + 127) >> 7, 0) { }
    explicit Bitset(size_t sz, __int128 value) : Bitset(sz) { m[0] = value; }
    static Bitset of(__int128 value) { return Bitset(128, value); }
    static Bitset of(unsigned __int128 value) { return Bitset(128, value); }
    static Bitset of(long long value) { return Bitset(64, value); }
    static Bitset of(unsigned long long value) { return Bitset(64, value); }
    static Bitset of(signed value) { return Bitset(32, value); }
    static Bitset of(unsigned value) { return Bitset(32, value); }
    Bitset& flip() { for(auto& i : m) i = ~i; return *this; }
    inline Bitset& flip(size_t pos) { m[pos >> 7] ^= __int128(1) << (pos & 127); return *this; }
    inline bool operator[](size_t i) const { return !!(m[i >> 7] & (__int128(1) << (i & 127))); }
    inline ref operator[](size_t i) { return ref(this, i); }

    inline void reset() {
        for(size_t i = 0; i < wl; i++) m[i] = 0;
    }

    bool any() const {
        for(const auto& i : m) if(i) return true;
        return false;
    }

    inline long long size() const { return l; }
    inline long long length() const { return l; }

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

    Bitset& operator<<=(long long shift) {
        if(shift < 0) {
            *this >>= -shift;
            return *this;
        }
        if (shift == 0) return *this;
        long long ws = shift >> 7, bs = shift & 127;
        if (ws >= static_cast<long long>(wl)) { std::fill(m.begin(), m.end(), 0); return *this; }
        for (long long i = wl - 1; i >= ws; --i) {
            m[i] = m[i - ws] << bs;
            if (i > ws && bs) m[i] |= m[i - ws - 1] >> (128 - bs);
        }
        std::fill_n(m.begin(), ws, 0);
        return *this;
    }

    Bitset& operator>>=(long long shift) {
        if(shift < 0) {
            *this <<= -shift;
            return *this;
        }
        if (shift == 0) return *this;
        long long ws = shift >> 7, bs = shift & 127;
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
        for(long long i=v.l-1; i>=0; i--) out << ((v.m[i >> 7] & (__int128(1) << (i & 127))) ? 1 : 0);
        return out;
    }

    std::string toDecimal() const { // GPT
        if (l == 0) return "0";
        std::vector<uint32_t> decimal; decimal.push_back(0);
        for (ssize_t i = l - 1; i >= 0; i--) {
            uint32_t carry = (*this)[i];
            for (unsigned int & j : decimal) {
                uint64_t cur = static_cast<uint64_t>(j) * 2 + carry;
                j = cur % 1000000000;
                carry = cur / 1000000000;
            }
            if (carry) decimal.push_back(carry);
        }
        std::string result = std::to_string(decimal.back());
        for (ssize_t i = decimal.size() - 2; i >= 0; i--) {
            std::string part = std::to_string(decimal[i]);
            result += std::string(9 - part.size(), '0') + part;
        }
        return result;
    }

    static Bitset fromDecimal(const std::string& s, long long sz = -1) { // GPT
        if (s == "0") return Bitset(1);
        std::vector<uint32_t> dec;
        int len = s.size(), firstDigits = len % 9;
        if (firstDigits == 0) firstDigits = 9;
        dec.push_back(std::stoul(s.substr(0, firstDigits)));
        for (int i = firstDigits; i < len; i += 9)
            dec.push_back(std::stoul(s.substr(i, 9)));
        std::vector<bool> bits;
        constexpr uint64_t base = 1000000000;
        while (!dec.empty()) {
            uint64_t carry = 0;
            for (unsigned int & i : dec) {
                uint64_t cur = carry * base + i;
                i = static_cast<uint32_t>(cur >> 1);
                carry = cur & 1;
            }
            bits.push_back(carry);
            while (!dec.empty() && dec[0] == 0) dec.erase(dec.begin());
        }
        Bitset result(sz == -1 ? bits.size() : sz);
        for (size_t i = 0; i < bits.size(); i++) result[i] = bits[i];
        return result;
    }
};
