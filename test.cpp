#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 h, n;

// c : 현재 노드의 번호
// l~r : 현재 노드를 루트 노드로 하는 서브트리의 순회 순서 범위
i64 f(i64 c, i64 l, i64 r) {
    i64 m = (l + r) / 2; // 현재 노드의 순회 순서
    if(n == m) return c; // 현재 노드가 찾는 노드인 경우 번호를 반환
    if(n < m) return f(c*2, l, m-1); // 찾는 노드가 왼쪽 서브트리에 있는 경우
    return f(c*2+1, m+1, r); // 찾는 노드가 오른쪽 서브트리에 있는 경우
}

int main() {

}
