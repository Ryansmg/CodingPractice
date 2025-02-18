/* Update : 2025-02-19 */

#include <numeric>
#include <iostream>
#include <cassert>

/// 1/0 == infinity, -1/0 == -infinity (only comparisons are available)
class Frac {
    inline void reduction() { long long g = std::gcd(numerator, denominator); numerator /= g; denominator /= g; }
    inline void checkDivZ() const { if(denominator == 0) { std::cerr << "Cannot divide by zero!\n"; exit(1); } }
    inline void checkDivZ(const Frac& a) const { checkDivZ(); a.checkDivZ(); }
public:
    long long numerator = 0; // 분자
    long long denominator = 1; // 분모 (항상 >= 0, 0인 경우 abs(분자) == 1)
    Frac() = default;
    explicit Frac(long long i) : numerator(i), denominator(1) {}
    Frac(long long Numerator, long long Denominator) : numerator(Numerator), denominator(Denominator) {
        if(denominator < 0) numerator *= -1, denominator *= -1;
        reduction();
    }
    template <typename T> explicit operator T() { return static_cast<T>(numerator) / static_cast<T>(denominator); }
    inline Frac& operator+=(const Frac& b) { checkDivZ(b);
        long long l = std::lcm(denominator, b.denominator);
        numerator *= l / denominator; numerator += b.numerator * (l / b.denominator);
        denominator = l; reduction(); return *this;
    }
    inline Frac& operator+=(const long long& i) { checkDivZ(); numerator += i * denominator; return *this; }
    inline Frac operator+(const Frac& b) const { checkDivZ(b); Frac ret = *this; ret += b; return ret; }
    inline Frac operator+(const long long& i) const { checkDivZ(); Frac ret = *this; ret += i; return ret; }
    inline Frac& operator-=(const Frac& b) {checkDivZ(b);
        long long l = std::lcm(denominator, b.denominator);
        numerator *= l / denominator; numerator -= b.numerator * (l / b.denominator);
        denominator = l; reduction(); return *this;
    }
    inline Frac& operator-=(const long long& i) { checkDivZ(); numerator -= i * denominator; return *this; }
    inline Frac operator-(const Frac& b) const { checkDivZ(b);  Frac ret = *this; ret -= b; return ret; }
    inline Frac operator-(const long long& i) const { checkDivZ(); Frac ret = *this; ret -= i; return ret; }
    inline Frac& operator*=(const Frac& b) { checkDivZ(b);
        numerator *= b.numerator; denominator *= b.denominator;
        reduction(); return *this;
    }
    inline Frac& operator*=(const long long& i) { checkDivZ(); numerator *= i; reduction(); return *this; }
    inline Frac operator*(const Frac& b) const { checkDivZ(b); Frac ret = *this; ret *= b; return ret; }
    inline Frac operator*(const long long& i) const { checkDivZ(); Frac ret = *this; ret *= i; return ret; }
    inline Frac& operator/=(const Frac& b) { checkDivZ(b);
        assert(b.numerator); // cannot divide by 0
        numerator *= b.denominator; denominator *= b.numerator;
        reduction(); return *this;
    }
    inline Frac& operator/=(const long long& i) { checkDivZ();
        assert(i); // cannot divide by 0
        denominator *= i; reduction(); return *this;
    }
    inline Frac operator/(const Frac& b) const { checkDivZ(b); Frac ret = *this; ret /= b; return ret; }
    inline Frac operator/(const long long& i) const { checkDivZ(); Frac ret = *this; ret /= i; return ret; }
    inline bool operator==(const Frac& b) const { return numerator == b.numerator && denominator == b.denominator; }
    inline bool operator!=(const Frac& b) const { return numerator != b.numerator || denominator != b.denominator; }
    inline bool operator<(const Frac& b) const {
        if(!denominator && !b.denominator) return numerator < b.numerator;
        return numerator * b.denominator < b.numerator * denominator;
    }
    inline bool operator<=(const Frac& b) const {
        if(!denominator && !b.denominator) return numerator <= b.numerator;
        return numerator * b.denominator <= b.numerator * denominator;
    }
    inline bool operator>(const Frac& b) const {
        if(!denominator && !b.denominator) return numerator > b.numerator;
        return numerator * b.denominator > b.numerator * denominator;
    }
    inline bool operator>=(const Frac& b) const {
        if(!denominator && !b.denominator) return numerator >= b.numerator;
        return numerator * b.denominator >= b.numerator * denominator;
    }

    inline bool operator==(const long long& b) const { return numerator == b && denominator == 1; }
    inline bool operator!=(const long long& b) const { return numerator != b || denominator != 1; }
    inline bool operator<(const long long& b) const { return !denominator ? numerator < 0 : numerator < b * denominator; }
    inline bool operator<=(const long long& b) const { return denominator && numerator <= b * denominator; }
    inline bool operator>(const long long& b) const { return !denominator ? numerator > 0 : numerator > b * denominator; }
    inline bool operator>=(const long long& b) const { return denominator && numerator >= b * denominator; }
    friend inline Frac operator+(const long long& a, const Frac& b) { Frac ret(a); ret += b; return ret; }
    friend inline Frac operator-(const long long& a, const Frac& b) { Frac ret(a); ret -= b; return ret; }
    friend inline Frac operator*(const long long& a, const Frac& b) { Frac ret(a); ret *= b; return ret; }
    friend inline Frac operator/(const long long& a, const Frac& b) { Frac ret(a); ret /= b; return ret; }
    friend inline bool operator==(const long long &a, const Frac& b) { return b.numerator == a && b.denominator == 1; }
    friend inline bool operator!=(const long long &a, const Frac& b) { return b.numerator != a || b.denominator != 1; }
    friend inline bool operator<(const long long &a, const Frac& b) { return !b.denominator ? 0 < b.numerator : a * b.denominator < b.numerator; }
    friend inline bool operator<=(const long long &a, const Frac& b) { return b.denominator && a * b.denominator <= b.numerator; }
    friend inline bool operator>(const long long &a, const Frac& b) { return !b.denominator ? 0 > b.numerator : a * b.denominator > b.numerator; }
    friend inline bool operator>=(const long long &a, const Frac& b) { return b.denominator && a * b.denominator >= b.numerator; }
};

