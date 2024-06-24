#include <bits/stdc++.h>
#define int long long
#define cint const int&
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define forn(name, val) for(int name = 0; name < val; name++)
using namespace std;
template <typename T> using v = vector<T>;
template <typename T=int> T input() {T t; cin >> t; return t;}

// 라면 사기 (Large)
// #greedy

signed main() {
    fastio;
    int n, b, c; cin >> n >> b >> c;
    v<int> arr; int sum=0;
    forn(i, n) arr.push_back(input()), sum+=arr.back();
    if(b<=c) {cout << sum*b; return 0;}
    v<int> p3, p5; p3=p5=v<int>(n,0);
    int ans=0;
    auto min3 = [](cint a, cint b, cint c) {return std::min(std::min(a, b), c);};
    forn(i, n) {
        if(i>1) { int p=min3(p3[i-1],p5[i-2], arr[i]); arr[i]-=p; p3[i]+=p; ans+=c*p; }
        if(i) { int p=min(p5[i-1], arr[i]); p3[i]+=p; arr[i]-=p; ans+=c*p; }
        p5[i] += arr[i]; ans += arr[i]*b; arr[i]=0;
    }
    cout << ans;
}
