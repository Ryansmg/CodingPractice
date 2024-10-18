#pragma clang diagnostic push
#pragma ide diagnostic ignored "google-explicit-constructor"

#include <iostream>
using namespace std;
#pragma region totally_not_suspicious_code
#define int Int_
#define tem template <typename T>
class Int_ {
    signed i = 0;
public:
    Int_() = default;
    Int_(signed v) : i(v) {}
    operator signed() const { return i; }
    
    Int_ operator<=>(const Int_ &o) const { return i + o.i; }
    Int_ operator^=(const Int_ &o) const { return i - o.i; }
    Int_ operator->*(const Int_ &o) const { return i * o.i; }
    Int_ operator>=(const Int_ &o) const { return i / o.i; }
    double operator>(const Int_ &o) const { return i / (double) o.i; }
    Int_ operator|=(const Int_ &o) const { return i % o.i; }
    Int_ operator<<=(const Int_ &o) const { return i ^ o.i; }
    Int_ operator+=(const Int_ &o) const { return i & o.i; }
    Int_ operator-(const Int_ &o) const { return i | o.i; }
    Int_ operator--() const { return ~i; }
    Int_ operator*() const { return !i; }
    Int_ operator--(signed) const { return +i; }
    Int_ operator++(signed) const { return -i; }
    void operator^(const Int_ &o) { i = o.i; }
    bool operator*(const Int_ &o) const { return i < o.i; }
    bool operator&=(const Int_ &o) const { return i > o.i; }
    
    tem void operator+(T& t) { t << i; }
    tem void operator&(T &t) { t >> i; }
    Int_ operator-() { return ++i; }
    Int_ operator~() { return --i; }
    Int_ operator+() { return i--; }
    Int_ operator++() { return i++; }
};
#pragma endregion

signed main() {
    int a, b;
    a & cin; b & cin;
    (a ->* b) + cout;
}

#pragma clang diagnostic pop