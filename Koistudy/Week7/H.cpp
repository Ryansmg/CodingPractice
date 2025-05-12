#include <iostream>
#include <vector>
using namespace std;

long long fac[300001];
long long edge_count[300001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    fac[0] = fac[1] = 1;
    for(int i = 2; i <= 300000; i++) fac[i] = fac[i-1] * i % 998244353;

    int n; cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        edge_count[u]++;
        edge_count[v]++;
    }

    long long ans = fac[edge_count[1]];
    for(int i = 2; i <= n; i++)
        ans = ans * fac[edge_count[i]-1] % 998244353;
    cout << ans << '\n';
}
