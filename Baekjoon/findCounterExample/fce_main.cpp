#pragma region macros
//@formatter:off
#define GCC_OPTIMIZE_ENABLE false
#define DISABLE_KOISTUDY_ERROR false

#if GCC_OPTIMIZE_ENABLE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif

#include <bits/stdc++.h>

// keyword reassign ///////////////////////////////////////////////////////////////
#define Tpl template <typename T>
#if DISABLE_KOISTUDY_ERROR
using namespace std;
#else
using std::cin, std::cout, std::cerr, std::endl, std::istream, std::ostream, std::ifstream, std::ofstream;
using std::array, std::vector, std::stack, std::queue, std::deque, std::list, std::pair, std::tuple;
using std::set, std::multiset, std::map, std::initializer_list, std::bitset;
using std::max, std::min, std::gcd, std::lcm, std::pow, std::swap;
using std::less, std::greater, std::all_of, std::hash;
using std::stoi, std::stol, std::stoll, std::stoul, std::stoull, std::stof, std::stod, std::stold;
using std::sort, std::stable_sort, std::shuffle, std::uniform_int_distribution, std::mt19937, std::random_device;
using std::iota, std::prev, std::next, std::prev_permutation, std::next_permutation;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template <typename Type, typename Cmp = less<>>
using pbds = __gnu_pbds::tree<Type, __gnu_pbds::null_type, Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
#endif

using i16 = short; using i32 = signed; using i64 = long long; using i128 = __int128;
using u16 = unsigned short; using u32 = unsigned; using u64 = unsigned long long; using u128 = unsigned __int128;
using f32 = float; using f64 = double; using f128 = long double;
using str = std::string;
template <typename T, typename T2> using umap = std::unordered_map<T, T2>;
Tpl using uset = std::unordered_set<T>;
Tpl using v = std::vector<T>; Tpl using v2 = v<v<T>>;
using vl = v<i64>; using v2l = v2<i64>; using vi = v<i32>; using vb = v<bool>;
using ii = array<i64, 2>; using iii = array<i64, 3>;
Tpl using lim = std::numeric_limits<T>;
template <typename Signature> using fun = std::function<Signature>;
#define int i64
#define uint u64
#define ci64 const i64 &
#define cint ci64
#define ci32 const i32 &
#define cast static_cast

// consts ///////////////////////////////////////////////////////////////
constexpr i64
    i64max = lim<i64>::max(),
    llmax  = i64max,
    INF    = 1000000000000000000,
    inf    = 3000000000;

// basic cpp macros ///////////////////////////////////////////////////////////////
#define forn(name, val) for(i64 name = 0; name < val; name++)
#define forf(name, start, end) for(i64 name = start; name <= end; name++)
#define forr(name, start, end) for(i64 name = start; name >= end; name--)
#define rep(n) forn(bit_Ly_S_, n)
#define rep2(n) forn(la_sh_Discord_, n)

i64 iR_v_, iR_v2_;
#define inRep() input(iR_v_); forn(iR_v3_, iR_v_)
#define inRep2() input(iR_v2_); forn(iR_v4_, iR_v2_)

// STL macros ///////////////////////////////////////////////////////////////
#if !DISABLE_KOISTUDY_ERROR
template <typename T=i64, typename T3=less<>> using pq = std::priority_queue<T, v<T>, T3>;
template <typename T, typename T3> T pop(pq<T, T3> &pq) { T t = pq.top(); pq.pop(); return t; }
#endif

#define all(vec) (vec).begin(), (vec).end()
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ef emplace_front
Tpl auto lb(const v<T> &r_, T i_) { return lower_bound(all(r_), i_); }
Tpl auto ub(const v<T> &r_, T i_) { return upper_bound(all(r_), i_); }
Tpl i64 Size(const T &t_) { return static_cast<i64>(t_.size()); }

Tpl T pop(stack<T> &st) { T t = st.top(); st.pop(); return t; }
Tpl T pop(queue<T> &q) { T t = q.front(); q.pop(); return q; }
Tpl void reverse(T &v) { reverse(all(v)); }
Tpl void sort(T &v) { sort(all(v)); }
Tpl void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
Tpl T reversed_copy(T arr) { reverse(all(arr)); return arr; }
Tpl T sorted_copy(T arr) { sort(all(arr)); return arr; }
Tpl T compressed_copy(T arr, const bool &autosort=true) { compress(arr, autosort); return arr; }
Tpl T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
Tpl T pow_(T a, T b, T mod=lim<T>::max()) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
Tpl T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }

template <typename Tp> Tp gcd(initializer_list<Tp> l_) {
    auto iter = l_.begin(); Tp ret = *iter; i64 sz_ = l_.size();
    forf(i_, 1, sz_-1) ret = std::gcd(ret, *(++iter)); return ret;
}
Tpl T lcm(initializer_list<T> l_) {
    auto iter = l_.begin(); T ret = *iter / gcd(l_); i64 sz_ = l_.size();
    forf(i_, 1, sz_-1) ret *= *(++iter); return ret;
}
Tpl T max(const v<T> v_) {
    T ret = lim<T>::min(); for(const T &t_ : v_) ret = max(ret, t_);
    return ret;
}
Tpl T min(const v<T> v_) {
    T ret = lim<T>::max(); for(const T &t_ : v_) ret = min(ret, t_);
    return ret;
}

Tpl T lcm_(T a, T b) { return a / gcd_(a, b) * b; }
Tpl T sq_(const T &i) { return i * i; }

random_device macro_random_device_;
mt19937 mt19937_gen_(macro_random_device_());
uniform_int_distribution<i32> uni_i_dis_i32_(0, lim<i32>::max());
uniform_int_distribution<i64> uni_i_dis_i64_(0, lim<i64>::max());
#define rand() randi()
i32 randi() { return uni_i_dis_i32_(mt19937_gen_); }
i64 randl() { return uni_i_dis_i64_(mt19937_gen_); }
i64 randInt(ci64 l_, ci64 r_) { return randl() % (r_ - l_ + 1) + l_; } // inclusive

// I/O macros ///////////////////////////////////////////////////////////////
#ifdef LOCAL
#define lfastio print()
#else
#define lfastio fastio
#endif
#define fastio std::ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#ifdef LOCAL
#define fileio filein; fileout
#define filein freopen(R"(C:\Users\ryans\Desktop\Coding\Baekjoon\z.etcBJ\input.txt)", "r", stdin)
#define fileout freopen(R"(C:\Users\ryans\Desktop\Coding\Baekjoon\z.etcBJ\output.txt)", "w", stdout)
#define inputout freopen(R"(C:\Users\ryans\Desktop\Coding\Baekjoon\z.etcBJ\input.txt)", "w", stdout)
#define outputin freopen(R"(C:\Users\ryans\Desktop\Coding\Baekjoon\z.etcBJ\output.txt)", "r", stdin)
#define ansout freopen(R"(C:\Users\ryans\Desktop\Coding\Baekjoon\z.etcBJ\ans.txt)", "w", stdout)
#else
#define fileio print()
#define filein print()
#define fileout print()
#define ansout print()
#define inputout print()
#define outputin print()
#endif
template <typename T = i64> T input() {T t; cin >> t; return t;}
template <typename T = i64> v<T> inputArr(i64 sz) { v<T> a; forn(i,sz) a.eb(input<T>()); return a; }
Tpl void inputArr(v<T> &arr, i64 sz, bool clear = true) { if(clear) arr.clear(); forn(i,sz) arr.eb(input<T>()); }
Tpl void inArr(v<T> &arr, i64 sz, bool clear = true) { inputArr(arr, sz, clear); }
template <typename T = i64> v<T> inArr(i64 sz) { v<T> a; forn(i,sz) a.eb(input<T>()); return a; }
template <typename T = i64> v<T> inArr() { return inArr(input()); }
str readline() { char c = '\n'; while(c == '\n') cin.get(c); str s; getline(cin, s); s = c + s; return s; }
Tpl void printArr(const v<T> &v, const str &sep = " ", const str &end = "\n") {
    if(v.empty()) return;
    i64 paSz_ = v.size(); forn(i, paSz_-1) cout << v[i] << sep; cout << v[paSz_-1] << end;
}
void fixPrecision(i32 a_) { cout << std::fixed; cout.precision(a_); }

#if !DISABLE_KOISTUDY_ERROR
template <typename ...T> void print(const T&... a_) { (cout << ... << a_); }
void print() {}
template <typename ...T> void println(const T&... a_) { (cout << ... << a_); cout << '\n'; }
void println() { cout << '\n'; }
Tpl void printSep(const T& a_) { cout << a_; }
template <typename T1, typename ...T2> void printSep(const T1& a_, const T2&... b_) { cout << a_ << ' '; printSep(b_...); }
template <typename ...T> void printSepLn(const T&... a_) { printSep(a_...); println(); }
template <typename ...T> void printExit(const T&... a_) { (cout << ... << a_); cout << '\n'; exit(0); }
template <typename ...T> void input(T&... a_) { (cin >> ... >> a_); }
#endif
#define invar(...) i64 __VA_ARGS__; input(__VA_ARGS__)

// conversions ///////////////////////////////////////////////////////////////
Tpl str tostr(const T &t) { return std::to_string(t); }
Tpl i128 toi128(const T &t) { return static_cast<i128>(t); }
i128 toi128(const str &t) { return static_cast<i128>(stoull(t)); }
Tpl i64 toi64(const T &t) { return static_cast<i64>(t); }
i64 toi64(const str &t) { return stoll(t); }
Tpl i32 toi32(const T &t) { return static_cast<i32>(t); }
i32 toi32(const str &t) { return stoi(t); }
Tpl u64 tou64(const T &t) { return static_cast<u64>(t); }
u64 tou64(const str &t) { return stoull(t); }
Tpl f64 tof64(const T &t) { return static_cast<f64>(t); }
f64 tof64(const str &t) { return stod(t); }
Tpl f128 tof128(const T &t) { return static_cast<f128>(t); }
f128 tof128(const str &t) { return stold(t); }

//@formatter:on
#pragma endregion

i32 main() {
    // how to use:
    // 1. set timeLimit (ms)
    // 2. set generator.exe, solution.exe, target.exe
    //   generator.exe generates random testcase at input.txt,
    //   solution.exe generates answer at ans.txt,
    //   target.exe generates wrong answer at output.txt
    // 3. wait
    
    i64 timeLimit = 4000;
    
    // settings
    constexpr bool stop_at_TLE_encounter = true;
    constexpr bool use_generated_input = true;
    constexpr bool use_generated_answer = false;
    constexpr i64 log_flush_rate = 1;
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////
    fastio;
    timeLimit = timeLimit * 3 + 100; i64 tc = 0;
    while(true) {
        tc++;
        i64 genCl, solCl, tarCl, chCl, cl = clock();
        // generate input
        if(!use_generated_input) system(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\findCounterExample\generator.exe)");
        genCl = clock() - cl; cl = clock();
        // generate answer
        if (!use_generated_answer) system(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\findCounterExample\solution.exe)");
        solCl = clock() - cl; cl = clock();
        // generate (possibly) wrong answer
        system(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\findCounterExample\target.exe)");
        tarCl = clock() - cl; cl = clock();
        
        ifstream ans(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\z.etcBJ\ans.txt)"),
            output(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\z.etcBJ\output.txt)");
        str s1, s2;
        long long line = 1;
        while(!ans.eof()) {
            if(output.eof()) { cout << "short output\n"; }
            assert(!output.eof());
            getline(ans, s1); getline(output, s2);
            if(s1 != s2) {
                cout << "line " << line << "\n";
                cout << "output   : " << s2 << '\n';
                cout << "expected : " << s1 << '\n';
            }
            assert(s1 == s2);
            line++;
        }
        if(!output.eof()) { cout << "long output\n"; }
        assert(output.eof());
        ans.close();
        output.close();
        chCl = clock() - cl;
        cout << "Testcase " << tc << " : Accepted, " << line << " lines, " << "gen/sol/tar/chk (ms) : " <<
            genCl << "/" << solCl << "/" << tarCl << "/" << chCl << "\n";
        if(tc % log_flush_rate == 0) cout.flush();
        if(tarCl > timeLimit && stop_at_TLE_encounter) cerr << "Time Limit Exceeded" << endl;
        if(stop_at_TLE_encounter) assert(tarCl <= timeLimit);
    }
}
