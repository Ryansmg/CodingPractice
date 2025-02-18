/* Update : 2025-02-17 */
/// 최신 코드는 cppp.cpp를 참고하세요.

#include <vector>
#include <iostream>
#include <algorithm>

template <typename T = long long>
class vec : public std::vector<T> {
public:
    vec() = default;
    explicit vec(unsigned size) : std::vector<T>(size) {}
    static vec fromArr(const std::vector<T>& arr) {
        vec ret(arr.size()); for(long long i = 0; i < arr.size(); i++) ret[i] = arr[i];
        return ret;
    }
    vec(unsigned size, const T& value) : std::vector<T>(size, value) {}
    inline T& operator[](long long idx) {
        if(idx < 0 || idx >= sz()) [[unlikely]] { std::cerr << "vec::OutOfBounds\n"; exit(43301); }
        return *(this->begin() + idx);
    }
    inline const T& operator[](long long idx) const {
        if(idx < 0 || idx >= sz()) [[unlikely]] { std::cerr << "vec::OutOfBounds\n"; exit(43301); }
        return *(this->begin() + idx);
    }
    template <typename Cmp> inline void sort(const Cmp& cmp) { std::sort(this->begin(), this->end(), cmp); }
    inline void sort() { sort(std::less<T>()); }
    template <typename Cmp> inline vec sorted(const Cmp& cmp) const { vec r = *this; r.sort(cmp); return r; }
    inline vec sorted() const { return sorted(std::less<T>()); }
    inline void reverse() { std::reverse(this->begin(), this->end()); }
    inline vec reversed() const { vec r = *this; r.reverse(); return r; }
    inline T pop() {
        if(mt()) [[unlikely]] { std::cerr << "vec::EmptyPop\n"; exit(43302); }
        T r = this->back(); this->pop_back(); return r;
    }
    inline void unique() { this->erase(std::unique(this->begin(), this->end()), this->end()); }
    template <typename Cmp> inline void compress(const Cmp& cmp) { sort(cmp); unique(); }
    inline void compress() { compress(std::less<T>()); }
    template <typename Cmp> inline vec compressed(const Cmp& cmp) const { vec r = *this; r.compress(cmp); return r; }
    inline vec compressed() const { return compressed(std::less<T>()); }
    template <typename Cmp> inline auto lb(const T& v, const Cmp& cmp) const {
        return std::lower_bound(this->begin(), this->end(), v, cmp);
    }
    inline auto lb(const T& v) const { return lb(v, std::less<T>()); }
    template <typename Cmp> inline auto lower_bound(const T& v, const Cmp& cmp) { return lb(v, cmp); }
    inline auto lower_bound(const T& v) const { return lb(v); }
    template <typename Cmp> inline auto ub(const T& v, const Cmp& cmp) const {
        return std::upper_bound(this->begin(), this->end(), v, cmp);
    }
    inline auto ub(const T& v) const { return ub(v, std::less<T>()); }
    template <typename Cmp> inline auto upper_bound(const T& v, const Cmp& cmp) const { return ub(v, cmp); }
    inline auto upper_bound(const T& v) const { return ub(v); }
    inline signed idx(const T& v) const { return lb(v) - this->begin(); }
    template <typename Cmp> inline signed idx(const T& v, const Cmp& cmp) const { return lb(v, cmp) - this->begin(); }
    inline long long sz() const { return this->size(); }
    inline bool mt() const { return this->empty(); }
    template <typename T2> vec<T2> to() {
        vec<T2> ret; for(const auto& t : *this) ret.emplace_back(t);
        return ret;
    }
    static vec<T> iota(long long size, long long offset = 0) {
        vec<T> ret(size); for(long long i = 0; i < size; i++) ret[i] = offset + i;
        return ret;
    }
    void concat(const std::vector<T>& v) { for(const T& t : v) this->push_back(t); }
    void accumulate() { for(long long i = 1; i < sz(); i++) this->operator[](i) += this->operator[](i-1); }
    void revAccumulate() { for(long long i = sz()-2; i >= 0; i--) this->operator[](i) += this->operator[](i+1); }
};
template<> class vec<bool> : public std::vector<bool> {
public:
    vec() = default;
    explicit vec(unsigned size) : std::vector<bool>(size) {}
    vec(unsigned size, bool value) : std::vector<bool>(size, value) {}
    inline long long sz() const { return this->size(); }
    inline bool mt() const { return this->empty(); }
    template <typename T2> vec<T2> to() {
        vec<T2> ret; for(const bool t : *this) ret.emplace_back(t);
        return ret;
    }
    inline void reverse() { std::reverse(this->begin(), this->end()); }
    inline vec reversed() const { vec r = *this; r.reverse(); return r; }
    inline bool pop() {
        if(mt()) [[unlikely]] { std::cerr << "vec::EmptyPop\n"; exit(43302); }
        bool r = this->back(); this->pop_back(); return r;
    }
    inline auto operator[](long long idx) {
        if(idx < 0 || idx >= sz()) [[unlikely]] { std::cerr << "vec::OutOfBounds\n"; exit(43301); }
        return this->begin()[idx];
    }
    inline auto operator[](long long idx) const {
        if(idx < 0 || idx >= sz()) [[unlikely]] { std::cerr << "vec::OutOfBounds\n"; exit(43301); }
        return this->begin()[idx];
    }
};

#pragma region VEC_IF_CPPP
#ifdef CPPP
template <typename T> struct isVector_Struct_<vec<T>> : std::true_type {};
template <typename T> struct isVector2_Struct_<vec<vec<T>>> : std::true_type {};
template <typename T = long long> using vec2 = vec<vec<T>>;
using vl = vec<long long>; using vi = vec<signed>; using vb = vec<bool>;
using v2l = vec<vec<long long>>; using v2i = vec<vec<signed>>; using v2b = vec<vec<bool>>;

template <typename T = long long> inline vec<T> inVec(long long sz) {
    vec<T> a;
    for(long long i = 0; i<sz; i++) { T t; std::cin >> t; a.push_back(t); }
    return a;
}

template <typename T = long long> inline void inVec(vec<T> &arr, long long sz, bool clear = false) {
    if(clear) arr.clear();
    for(long long i = 0; i < sz; i++) { T t; std::cin >> t; arr.push_back(t); }
}
template <typename T = long long> inline vec<T> inVec() { return inVec<T>(input()); }
#define inArr inVec

template <typename T2, typename T1> inline vec<T2> castVec(const vec<T1>& arr) { vec<T2> ret; for(const auto& t : arr) { ret.emplace_back(t); } return ret; }
#endif
#pragma endregion
