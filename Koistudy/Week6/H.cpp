#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
/// 문제에서 주어짐.
i64 h, n;

/// @param c 현재 노드의 번호
/// @param l 현재 노드가 루트인 서브트리 안의 방문 순서 최솟값
/// @param r 서브트리 안의 방문 순서 값의 최댓값
i64 f(i64 c, i64 l, i64 r) {
    i64 m = (l + r) / 2; /// 현재 노드의 방문 순서
    if(m == n) return c;
    if(n < m) return f(c*2, l, m-1);
    return f(c*2+1, m+1, r);
}

int main() {
    cin >> h >> n;
    cout << f(1, 1, (1LL<<(h+1))-1);
}
