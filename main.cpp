#include <bits/stdc++.h>

int mjhmjh1104(int n, int k){
    return !k || n / k & 2;
}

int rdxxer(int m, int k, int c){
    return k ? m - k + 2 * (!!(m / k + 1 & 2) == c) * k : m;
}

using namespace std;

void run() {
    int N, M, K;
    assert(1==scanf("%d",&N));
    assert(1==scanf("%d",&M));
    K=abs(N-M);
    printf("%d %d\n", N, rdxxer(M, K, mjhmjh1104(N, K)));
}

signed main(){

}
