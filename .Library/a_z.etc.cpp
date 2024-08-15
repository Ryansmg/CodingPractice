#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
using u64 = unsigned long long;
template <class T> using v = vector<T>;

template <class T>
class cntMap {
    map<T, u64> m;
public:
    void add(const T &target, u64 count = 1) {
        if(m.find(target) == m.end()) m.insert({target, count});
        else m.find(target)->second += count;
    }
    void subtract(const T &target, u64 count = 1) {
        auto ptr = m.find(target);
        assert(ptr != m.end() && ptr->second >= count);
        ptr->second -= count;
    }
    u64 cnt(const T &target) {
        if(m.find(target) == m.end()) return 0;
        else return m.find(target)->second;
    }
    void operator+=(const T &target) { add(target); }
    void operator-=(const T &target) { subtract(target); }
    u64 operator[](const T &target) { return cnt(target); }
};

int main() {

}