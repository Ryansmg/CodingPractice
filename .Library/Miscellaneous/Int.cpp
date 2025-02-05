/* Updated : 2025-02-06 */

#include <bits/stdc++.h>

class Int {
    struct Int_Compare_ {
        bool valid = true;
        long long left, right;
        Int_Compare_(Int a) : left(a.v), right(a.v) {} //NOLINT (*-explicit-constructor)
        Int_Compare_(bool a, long long b, long long c) : valid(a), left(b), right(c) {}
        operator bool() { return valid; } //NOLINT (*-explicit-constructor)
        Int_Compare_ operator==(const Int_Compare_& b) const { if(!valid || !b.valid || right != b.left) { return {false,0,0}; } return {true, left, b.right}; }
        Int_Compare_ operator!=(const Int_Compare_& b) const { if(!valid || !b.valid || right == b.left) { return {false,0,0}; } return {true, left, b.right}; }
        Int_Compare_ operator<(const Int_Compare_& b) const { if(!valid || !b.valid) { return {false, 0, 0}; } if(right < b.left) { return {true, left, b.right}; } return {false, 0, 0}; }
        Int_Compare_ operator<=(const Int_Compare_& b) const { if(!valid || !b.valid) { return {false, 0, 0}; } if(right <= b.left) { return {true, left, b.right}; } return {false, 0, 0}; }
        Int_Compare_ operator>(const Int_Compare_& b) const { if(!valid || !b.valid) { return {false, 0, 0}; } if(right > b.left) { return {true, left, b.right}; } return {false, 0, 0}; }
        Int_Compare_ operator>=(const Int_Compare_& b) const { if(!valid || !b.valid) { return {false, 0, 0}; } if(right >= b.left) { return {true, left, b.right}; } return {false, 0, 0}; }
        Int_Compare_ operator||(const Int_Compare_& b) const { if(valid || b.valid) { return {true, left, b.right}; } return {false, 0, 0}; }
        Int_Compare_ operator&&(const Int_Compare_& b) const { if(!valid || !b.valid) { return {false, 0, 0}; } return {true, left, b.right}; }
    };
public:
    long long v = 0;
    Int() = default;
    Int(long long value) : v(value) {} //NOLINT (*-explicit-constructor)
    explicit operator long long() const { return v; }
    Int& operator++() { ++v; return *this; } Int operator++(signed) { Int ret = *this; v++; return ret; }
    Int& operator--() { --v; return *this; } Int operator--(signed) { Int ret = *this; v--; return ret; }
    Int& operator+=(const Int& b) { v += b.v; return *this; } Int& operator-=(const Int& b) { v -= b.v; return *this; }
    Int& operator*=(const Int& b) { v *= b.v; return *this; } Int& operator/=(const Int& b) { v /= b.v; return *this; }
    Int operator+(const Int& b) const { Int ret = *this; ret += b; return ret; } Int operator-(const Int& b) const { Int ret = *this; ret -= b; return ret; }
    Int operator*(const Int& b) const { Int ret = *this; ret *= b; return ret; } Int operator/(const Int& b) const { Int ret = *this; ret /= b; return ret; }
    Int_Compare_ operator<(const Int& b) const { return Int_Compare_(*this) < Int_Compare_(b); }
    Int_Compare_ operator<=(const Int& b) const { return Int_Compare_(*this) <= Int_Compare_(b); }
    Int_Compare_ operator>(const Int& b) const { return Int_Compare_(*this) > Int_Compare_(b); }
    Int_Compare_ operator>=(const Int& b) const { return Int_Compare_(*this) >= Int_Compare_(b); }
    Int_Compare_ operator==(const Int& b) const { return Int_Compare_(*this) == Int_Compare_(b); }
    Int_Compare_ operator!=(const Int& b) const { return Int_Compare_(*this) != Int_Compare_(b); }
};
Int operator""_I(unsigned long long i) { return Int(i); } // NOLINT(*-return-braced-init-list)
#ifdef CPPP
defStructIO_(Int)
#define In64(...) Int __VA_ARGS__; input(__VA_ARGS__)
#endif

// Example : BOJ 6764. Sounds fishy!
void printExit(const std::string& s) { std::cout << s; exit(0); }
int main() {
    Int A, B, C, D; std::cin >> A.v >> B.v >> C.v >> D.v;
    if(A < B < C < D) printExit("Fish Rising");
    if(A > B > C > D) printExit("Fish Diving");
    if(A == B == C == D) printExit("Fish At Constant Depth");
    printExit("No Fish");
}
