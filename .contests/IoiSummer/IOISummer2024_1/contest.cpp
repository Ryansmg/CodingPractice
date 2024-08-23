#include <cstdio>
#include <string>
#include <cassert>
#include <utility>

extern void init(int, std::string);
extern long long contest_time(long long, long long, long long);

static int N, Q;
static std::string S;
static char str[1000005];

void assertion(bool x) {
    if (x) return;
    else { printf("Wrong Input\n"); exit(0); }
}
int main() {
    assertion(scanf("%d", &N) == 1);
    assertion(scanf("%s", str) == 1);
    S = std::string(str);
    init(N, S);
    assertion(scanf("%d", &Q) == 1);
    for (int i = 0; i < Q; i++) {
        long long A, L, R;
        assertion(scanf("%lld %lld %lld", &A, &L, &R) == 3);
        printf("%lld\n", contest_time(A, L, R));
    }
    return 0;
}

///////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#ifndef LOCAL
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#else
#define fastio
#endif
#define all(vec) (vec).begin(), (vec).end()
using i64 = long long;
using i32 = int;
template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
const i64 inf = 3000000000;
#define forn(i, n) for(i64 i=0; i<n; i++)
#define forf(i, s, e) for(i64 i=s; i<=e; i++)

string t;
i32 len;
unordered_set<char> chs;
map<pair<char, char>, i32> m;
v2<i32> poss;
i32 permCnt = 0;

void init(int n, std::string s) {
    t = std::move(s);
    len = n;
    chs.insert(t[0]);
    forf(i, 1, len-1) {
        chs.insert(t[i]);
        char a = t[i-1], b = t[i];
        if(a==b) continue;
        m[{a, b}]++;
    }
    v<char> p;
    for(const char& c : chs) p.push_back(c);
    sort(all(p));
    do {
        v<i32> pos(32);
        for(i32 i=0; i<p.size(); i++) pos[p[i]-'A'] = i;
        permCnt++;
        poss.push_back(pos);
    } while(next_permutation(all(p)));
}

long long contest_time(long long A, long long L, long long R) {
    i64 ret = 9223372036854775807;
    forn(ii, permCnt) {
        i64 ans = 0;
        for(const auto &i : m) {
            i32 d = poss[ii][i.first.first-'A'] - poss[ii][i.first.second-'A'];
            if(d<0) ans += R*(-d)*i.second;
            else ans += L*d*i.second;
        }
        ret = min(ret, ans);
    }
    return ret + A*len;
}