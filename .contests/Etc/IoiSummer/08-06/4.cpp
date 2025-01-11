#include <bits/stdc++.h>
using namespace std;

#define i64 long long
#ifdef LOCAL
#define MAX 1000
#else
#define MAX 10000000
#endif
#define forf(i,s,e) for(i64 i=s;i<=e;i++)

i64 l, mod=1000000007;

i64 fact[MAX + 10], inv_fact[MAX + 10], inv[MAX + 10];
void init(int L) {
    l = L;
    fact[1] = inv[1] = inv_fact[1] = 1;
    forf(i, 2, l) {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = (mod - mod/i) * inv[mod%i] % mod;
        inv_fact[i] = inv_fact[i-1] * inv[i] % mod;
    }
}

int ncm(int N, int M) {
    if(!M || N==M) return 1;
    return (int) (fact[N] * inv_fact[M] % mod * inv_fact[N-M] % mod);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int K, L; cin >> K >> L;
    init(L);
    forf(i, 1, K) {
        int N, M; cin >> N >> M;
        cout << ncm(N, M) << '\n';
    }
}