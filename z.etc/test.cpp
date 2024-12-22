#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(i64 i=0; i<n; i++)
template <typename> struct isVecStruct : std::false_type {};
template <typename T> struct isVecStruct<vector<T>> : std::true_type {};
template <typename T> concept isVector = isVecStruct<T>::value;
using i32 = signed; using i64 = long long; using str = std::string;

struct Printf {
    str sep = " ", end;
    i32 prec = -1;
    i32 width = -1; char fill = ' ';
    void operator()() {}
    template <typename ...T> void operator()(const T&... _) { prf_imp_(_...); }
    Printf& appendEnd(const str& end_) { end += end_; return *this; }
private:
    inline void prf_imp_preset_() const {
        if(prec != -1) cout << std::fixed, cout.precision(prec);
        if(width != -1) cout << std::setw(width) << std::setfill(fill);
    }
    template <typename T> void prf_imp_(const T& _) const { prf_imp_preset_(); cout << _ << end; }
    template <isVector T> void prf_imp_(const T& _) const {
        i64 len_ = Size(_);
        forn(i, len_-1) { prf_imp_preset_(); cout << _[i] << sep; }
        if(len_) prf_imp_preset_(), cout << _[len_-1] << end;
    }
    template <typename T1, typename ...T2> void prf_imp_(const T1& _, const T2&... b_) const {
        prf_imp_preset_(); cout << _ << sep; prf_imp_(b_...);
    }
    template <isVector T1, typename ...T2> void prf_imp_(const T1& _, const T2&... b_) const {
        for(const auto& v_ : _) { prf_imp_preset_(); cout << v_ << sep; } prf_imp_(b_...);
    }
};
#define printf(...) Printf({__VA_ARGS__})
#define printfln(...) printf(__VA_ARGS__).appendEnd("\n")

int main() {

}

