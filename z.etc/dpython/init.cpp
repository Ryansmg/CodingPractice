#include <bits/stdc++.h>

#define int(i) dpy_to_int_(i)
#define str(i) std::to_string(i)
#define len(i) dpy_len_(i)
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
constexpr bool True = true;
constexpr bool False = false;

class List {
    std::vector<std::any> data;
public:
    List(const std::initializer_list<std::any> &dpy_l_) {
        for(const std::any &dpy_a_ : dpy_l_) {
            if(dpy_a_.type() == typeid(const char*) ) data.emplace_back(std::string(std::any_cast<const char*>(dpy_a_)));
            else if(dpy_a_.type() == typeid(signed)) data.emplace_back(static_cast<long long>(std::any_cast<signed>(dpy_a_)));
            else data.emplace_back(dpy_a_);
        }
    }
    List()=default;
    auto begin() const { return data.begin(); }
    auto end() const { return data.end(); }
    auto size() const { return data.size(); }
    std::any& operator[](long long tar) { return data[tar]; }
};

std::ostream& operator<<(std::ostream& dpy_out_, const std::any& dpy_a_) {
    if(dpy_a_.type() == typeid(long long)) dpy_out_ << std::any_cast<long long>(dpy_a_);
    else if(dpy_a_.type() == typeid(std::string)) dpy_out_ << std::any_cast<std::string>(dpy_a_);
    else if(dpy_a_.type() == typeid(bool)) dpy_out_ << std::any_cast<bool>(dpy_a_);
    return dpy_out_;
}

template <typename ...T> void print(const T&... dpy_a_) { (std::cout << ... << dpy_a_); }
void print() {}
template <typename ...T> void println(const T&... dpy_a_) { (std::cout << ... << dpy_a_); std::cout << '\n'; }
void println() { std::cout << '\n'; }
template <typename T> void print(const std::vector<T> &dpy_arr_) {
    for(auto &a : dpy_arr_) std::cout << a << ' ';
}
template <typename T> void println(const std::vector<T> &dpy_arr_) {
    for(auto &a : dpy_arr_) std::cout << a << ' ';
    std::cout << '\n';
}

template <typename T>
long long dpy_len_(const T& dpy_t_) { return dpy_t_.size(); }

long long dpy_to_int_(const std::string &dpy_s_) {
    return std::stoll(dpy_s_);
}

long long dpy_to_int_(const std::any &dpy_a_) {
    return std::any_cast<long long>(dpy_a_);
}

template <typename T>
long long dpy_to_int_(const T &dpy_t_) { return static_cast<long long>(dpy_t_); }

template <typename T>
T dpy_construct_(const T &dpy_t_) { return dpy_t_; }

List dpy_construct_(const std::initializer_list<std::any> &dpy_l_) {
    return {dpy_l_};
}

std::vector<long long> range(long long dpy_n_) {
    std::vector<long long> ret;
    for(long long i = 0; i < dpy_n_; i++) ret.emplace_back(i);
    return ret;
}

std::string input() {
    char c = '\n';
    while(c == '\n') std::cin.get(c);
    std::string s; getline(std::cin, s);
    s = c + s;
    return s;
}
