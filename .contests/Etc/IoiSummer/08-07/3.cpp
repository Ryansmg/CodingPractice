#include <bits/stdc++.h>
using namespace std;

namespace integer {
    template<size_t sz = 32>
    class bitint {
    public:
        using r_bi = bitint<sz>;
        using r_bs = bitset<sz>;
        bitset<sz> bits;
        [[nodiscard]] bool sign() const { return bits[sz - 1]; }

        // constructors & convertions

        bitint() = default;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "google-explicit-constructor"
        bitint(r_bs a) : bits(a) {}

        template<typename T>
        bitint(T t) {
            bool s = t < 0;
            if (t < 0) t = -t;
            bits = t;
            if (s) flip();
        }
#pragma clang diagnostic pop

        explicit operator bool() const { return bits.any(); }

        template<typename T>
        explicit operator T() const {
            T t = 0, temp = 1;
            r_bi h = *this;
            bool s = h.sign();
            h.set_abs();
            size_t sz2 = min(sizeof(T) * 8, sz);

            for (int i = 0; i < sz2; i++) {
                if (h.bits[i]) t += temp;
                temp <<= 1;
            }

            if (s) {
                return -t;
            } else {
                return t;
            }
        }

        //unary operators

        r_bi operator~() const {
            r_bi ret = *this;
            ret.bits = ~ret.bits;
            return ret;
        }

        r_bi operator+() const { return *this; }

        r_bi operator-() const {
            r_bi ret = *this;
            ret.flip();
            return ret;
        }

        r_bi operator!() const { return !bits.any(); }

        // binary operators
        // - bitwise operators
        template<typename T>
        r_bi operator<<(const T &i) const {
            r_bi ret = *this;
            ret.bits <<= i;
            return ret;
        }

        template<typename T>
        r_bi operator>>(const T &i) const {
            r_bi ret = *this;
            ret.bits >>= i;
            return ret;
        }

        // - calculations

        r_bi operator+(const r_bi &t) const {
            r_bs carry = bits & t.bits;
            r_bs result = bits ^ t.bits;
            while (carry.any()) {
                r_bs s_carry = carry << 1;
                carry = result & s_carry;
                result ^= s_carry;
            }
            return r_bi(result);
        }

        template<typename T>
        r_bi operator+(const T &i) const {
            return *this + r_bi(i);
        }

        r_bi operator-(r_bi t) const {
            t.flip();
            return *this + t;
        }

        template<typename T>
        r_bi operator-(const T &i) const {
            return *this - r_bi(i);
        }

#pragma clang diagnostic push
#pragma ide diagnostic ignored "ConstantFunctionResult"
        r_bi operator*(r_bi i) const {
            r_bi th = *this;
            r_bi ans = 0;
            bool s = sign() != i.sign();
            if (sign()) th.flip();
            if (i.sign()) i.flip();
            while (i) {
                if (i.bits[0]) ans += th;
                th.bits <<= 1;
                i.bits >>= 1;
            }
            if (s) ans.flip();
            return ans;
        }
#pragma clang diagnostic pop

        r_bi operator/(r_bi aa) const {
            if (*this == aa) return 1;
            bitint<sz * 2> a = convert_to<sz * 2>(abs()), q = 0, temp = 0;
            bitint<sz * 2> b = aa.convert_to<sz * 2>(), one = 1;
            if (!b) throw exception();
            bool s = sign() != b.sign();
            b.set_abs();
            if (a == b) return -1;
            for (long long i = sz - 1; i >= 0; i--) {
                if ((temp + (b << i)) <= a) {
                    temp += b << i;
                    q += one << i;
                }
            }
            if (s) q.flip();
            return convert_to<sz>(q);
        }


        template<typename T>
        r_bi operator/(const T &i) const { return *this / r_bi(i); }

        r_bi operator%(const r_bi &o) const { return *this - ((*this / o) * o); }

        // - comparisons

        bool operator==(const r_bi &i) const { return bits == i.bits; }

        bool operator!=(const r_bi &i) const { return bits != i.bits; }

        bool operator<=(const r_bi &i) const {
            if (*this == i) return true;
            return *this < i;
        }

        bool operator<(r_bi i) const {
            if (sign() && !i.sign()) return true;
            if (!sign() && i.sign()) return false;
            bool s = sign() != i.sign();
            bool t;
            int k = 1;
            while (true) {
                int a = this->nth_bit(k), b = i.nth_bit(k++);
                assert(a != -1 || b != -1);
                if (a != b) {
                    t = a < b;
                    break;
                }
            }
            return s == !t;
        }

        bool operator>(const r_bi &i) const { return !(*this < i); }

        bool operator>=(const r_bi &i) const {
            if(*this==i) return true;
            return *this > i;
        }

        //assignment operators

        r_bi &operator=(const r_bi &t) {
            bits = t.bits;
            return *this;
        }

        r_bi &operator+=(const r_bi &t) {
            r_bs carry = bits & t.bits;
            bits = bits ^ t.bits;
            while (carry.any()) {
                r_bs s_carry = carry << 1;
                carry = bits & s_carry;
                bits ^= s_carry;
            }
            return *this;
        }

        r_bi &operator-=(const r_bi &t) {
            r_bi t2 = t;
            t2.flip();
            return *this += t2;
        }

        template<typename T>
        r_bi &operator-=(const T &t) {
            return *this += -t;
        }

        r_bi &operator*=(r_bi i) {
            *this = *this * i;
            return *this;
        }

        r_bi &operator-=(r_bi i) {
            *this = *this / i;
            return *this;
        }

        template<typename T>
        r_bi &operator<<=(const T &i) {
            bits <<= i;
            return *this;
        }

        template<typename T>
        r_bi &operator>>=(const T &i) {
            bits >>= i;
            return *this;
        }

        r_bi &operator|=(const r_bi &i) {
            bits |= i.bits;
            return *this;
        }

        //functions

        r_bi &setFrom(istream &in = cin) {
            *this = 0;
            string s;
            in >> s;
            size_t len = s.size();
            bool sign = false;
            int st = 0;
            if (s[0] == '-') sign = true, st = 1;
            for (int i = st; i < len; i++) {
                (*this) *= 10;
                (*this) += s[i] - '0';
            }
            if (sign) flip();
            return *this;
        }

        static r_bi getFrom(istream &in = cin) {
            r_bi a = 0;
            string s;
            in >> s;
            size_t len = s.size();
            bool sign = false;
            int st = 0;
            if (s[0] == '-') sign = true, st = 1;
            for (int i = st; i < len; i++) {
                a *= 10;
                a += s[i] - '0';
            }
            if (sign) a.flip();
            return a;
        }

        bool isZero() { return !bits.any(); }

        /// multiplies this by -1
        void flip() {
            bits = ~bits;
            *this += 1;
        }

        /// set *this to positive
        r_bi &set_abs() {
            if (sign()) flip();
            return *this;
        }

        [[nodiscard]] r_bi abs() const {
            r_bi ret = *this;
            if (sign()) ret.flip();
            return ret;
        }

        static r_bi abs(r_bi i) {
            if (i.sign()) i.flip();
            return i;
        }

        //-1 if err
        [[nodiscard]] long long nth_bit(int n) const {
            if (n <= 0) return -1;
            int cnt = 0;
            for (long long i = sz - 1; i >= 0; i--)
                if (bits[i]) if (++cnt == n) return i;
            return -1;
        }

        template<size_t size>
        [[nodiscard]] bitint<size> convert_to() const {
            bitint<size> i;
            long long size2 = min(size, sz);
            for (long long j = 0; j < size2; j++)
                i.bits[j] = bits[j];
            for (long long j = size2; j < size; j++)
                i.bits[j] = sign();
            return i;
        }

        template<size_t size, size_t osize>
        static bitint<size> convert_to(bitint<osize> r) {
            bitint<size> i;
            long long size2 = min(size, osize);
            for (long long j = 0; j < size2; j++)
                i.bits[j] = r.bits[j];
            for (long long j = size2; j < size; j++)
                i.bits[j] = r.sign();
            return i;
        }

        [[nodiscard]] r_bi div10() const {
            r_bi q, r;
            q = (*this >> 1) + (*this >> 2);
            q = q + (q >> 4);
            q = q + (q >> 8);
            q = q + (q >> 16);
            q = q >> 3;
            r = *this - (((q << 2) + q) << 1);
            return q + (r >> 9);
            assert(!sign());
        }
    };

    template<size_t T>
    ostream &operator<<(ostream &out, bitint<T> i) {
        if (!i) {
            out << 0;
            return out;
        }
        bitint<T> div = 10000000000000000000ull;
        if (i.sign()) {
            out << '-';
            i.set_abs();
        }
        stack<unsigned long long> st;
        while (i) {
            st.push((unsigned long long) (i % div));
            i = i / div;
        }
        bool m = false;
        while (!st.empty()) {
            auto len = to_string(st.top()).length();
            out << st.top();
            if (m) for (int k = 19; k > len; k--) out << '0';
            m = true;
            st.pop();
        }
        return out;
    }
}
using namespace integer;

template <typename T> T pow_(T a, T b, T mod) {
    a = a % mod;
    T ans = 1;
    while (b) {
        if (b.bits[0]) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

int main() {
    long long a, b, m;
    cin >> a >> b >> m;
    bitint<128> c, d, e;
    c = a, d = b, e = m;
    cout << pow_(c, d, e);
}
