#include <bits/stdc++.h>
#define int long long
#define INF 1000000000000000000 // INF * INF > 2^63
#define inf 3000000000 // inf > 2^31, inf * inf < 2^63
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define filein freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/input.txt", "r", stdin)
#define fileout freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/output.txt", "w", stdout)
#define all(vec) (vec).begin(), (vec).end()
#define forn(name, val) for(int name = 0; name < val; name++)
using namespace std;
template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
signed main() {
    random_device rd;
    mt19937 gen(rd());
    fastio; fileout;
    cout << "50000 1 49999\n1 50000 100000\n";
    for(int i=0; i<49999; i++)
        cout << 1 << ' ' << i+1 << ' ' << i+1 << '\n';
}
