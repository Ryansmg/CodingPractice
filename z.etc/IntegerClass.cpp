#include <bits/stdc++.h>
using namespace std;
namespace integer {
    class Integer {
    public:
        int v = 0;
        Integer() = default;
        Integer(const int &i) : v(i) {}
        operator int() { return v; }
        bool operator<(const Integer &a) const { return v < a.v; }
        bool operator>(const Integer &a) const { return v > a.v; }
        bool operator<=(const Integer &a) const { return v <= a.v; }
        bool operator>=(const Integer &a) const { return v >= a.v; }
        bool operator==(const Integer &a) const { return v == a.v; }
        bool operator!=(const Integer &a) const { return v != a.v; }

        Integer &operator<=>(Integer &a) { swap(v, a.v); return *this; }
        Integer &operator<=>(int &a) { swap(v, a); return *this; }

        Integer operator+() const { return {v}; }
        Integer operator-() const { return {-v}; }
        Integer operator~() const { return {~v}; }
        bool operator!() const { return !v; }

        bool operator&&(const Integer &a) const { return v && a.v; }
        bool operator||(const Integer &a) const { return v || a.v; }

        Integer operator+(const Integer &a) const { return {v + a.v}; }
        Integer operator-(const Integer &a) const { return {v - a.v}; }
        Integer operator*(const Integer &a) const { return {v * a.v}; }
        Integer operator/(const Integer &a) const { return {v / a.v}; }
        Integer operator%(const Integer &a) const { return {v % a.v}; }
        Integer operator&(const Integer &a) const { return {v & a.v}; }
        Integer operator|(const Integer &a) const { return {v | a.v}; }
        Integer operator^(const Integer &a) const { return {v ^ a.v}; }
        Integer operator<<(const Integer &a) const { return {v << a.v}; }
        Integer operator>>(const Integer &a) const { return {v >> a.v}; }

        Integer &operator=(const Integer &a) = default;
        Integer &operator+=(const Integer &a) { v += a.v; return *this; }
        Integer &operator-=(const Integer &a) { v -= a.v; return *this; }
        Integer &operator*=(const Integer &a) { v *= a.v; return *this; }
        Integer &operator/=(const Integer &a) { v /= a.v; return *this; }
        Integer &operator%=(const Integer &a) { v %= a.v; return *this; }
        Integer &operator&=(const Integer &a) { v &= a.v; return *this; }
        Integer &operator|=(const Integer &a) { v |= a.v; return *this; }
        Integer &operator^=(const Integer &a) { v ^= a.v; return *this; }
        Integer &operator<<=(const Integer &a) { v <<= a.v; return *this; }
        Integer &operator>>=(const Integer &a) { v >>= a.v; return *this; }

        Integer &operator++() { ++v; return *this; }
        Integer &operator--() { --v; return *this; }
        Integer operator++(signed) { Integer ret = *this; v++; return ret; }
        Integer operator--(signed) { Integer ret = *this; v--; return ret; }

        Integer &operator()() { cout << v; return *this; }
        Integer &operator[](Integer &a) { return *this; }
    };
    istream &operator>>(istream &in, Integer &l) { in >> l.v; return in; }
    ostream &operator<<(ostream &out, const Integer &i) { out << i.v; return out; }
    int &operator<=>(int &b, Integer &a) { swap(b, a.v); return b; }
    using Int = Integer;
}
using namespace integer;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    Int T,a,b; cin >> T;
    while(T--) { cin >> a >> b; cout << a + b << '\n'; }
}
