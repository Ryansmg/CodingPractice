#include <bits/stdc++.h>
using namespace std;
template <class t> using v = vector<t>;
template <class t> using v2 = v<v<t>>;
using i32 = int;
using i64 = long long;
#define all(vec) (vec).begin(), (vec).end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(i, j) for(i32 i=0; i<j; i++)
#define forf(i, j, k) for(i32 i=j; i<=k; i++)
template <class T=i64> T input() { T i; cin >> i; return i; }
template <typename T> v<T> inputArr(i64 sz) { v<T> a; forn(i,sz)a.push_back(input<T>()); return a; }

v2<i32> video;
i32 sz;

string compress(i32 posr, i32 posc, i32 range) {
    bool is0 = true, is1 = true;
    forf(r, posr, posr+range-1) {
        forf(c, posc, posc+range-1) {
            if(video[r][c]) is0 = false;
            else is1 = false;
        }
    }
    if(is0) return "0";
    if(is1) return "1";
    else return "(" + compress(posr, posc, range/2) + compress(posr, posc+range/2, range/2)
    + compress(posr+range/2, posc, range/2) + compress(posr+range/2, posc+range/2, range/2) + ")";
}

i32 main() {
    fastio;
    cin >> sz;
    video = v2<i32>();
    forn(i, sz) video.push_back(inputArr<i32>(sz));
    cout << compress(0, 0, sz);
}