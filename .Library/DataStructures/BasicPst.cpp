#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long val = 0; // 노드의 값
    Node* l = nullptr; // 왼쪽 자식 노드의 주소
    Node* r = nullptr; // 오른쪽 자식 노드의 주소
};
vector<Node*> roots; // 루트 노드들의 주소를 담을 배열

vector<long long> arr; // 리프 노드에 들어갈 값들

void init(Node* p, int s, int e) {
    // 리프 노드일 경우 값을 할당하고 리턴
    if(s == e) {
        p->val = arr[s - 1];
        return;
    }
    // 아니면 두 자식 노드를 생성
    int m = (s + e) / 2;
    p->l = new Node(); init(p->l, s, m);
    p->r = new Node(); init(p->r, m + 1, e);
	p->val = p->l->val + p->r->val;
}

// l ~ r 범위의 쿼리, 현재 노드가 담당하는 범위는 s ~ e
long long query(Node* p, int s, int e, int l, int r) {
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return p->val;
    int m = (s + e) / 2;
    return query(p->l, s, m, l, r) + query(p->r, m + 1, e, l, r);
}

// 현재 노드 담당 범위 s ~ e, i번째 값을 v로 변경
void update(Node* prv, Node* cur, int s, int e, int i, long long v) {
    if(s == e) {
        cur->val = v;
        return;
    }
    int m = (s + e) / 2;
    if(i <= m) {
        cur->l = new Node();
        cur->r = prv->r;
        update(prv->l, cur->l, s, m, i, v);
    } else {
        cur->l = prv->l;
        cur->r = new Node();
        update(prv->r, cur->r, m + 1, e, i, v);
    }
    cur->val = cur->l->val + cur->r->val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m; cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    Node* t = new Node();
    init(t, 1, n);
    roots.push_back(t);

    cin >> m;
    for(int q = 0; q < m; q++) {
        int op; cin >> op;
        if(op == 1) {
            int i, v; cin >> i >> v;
            t = new Node();
            update(roots.back(), t, 1, n, i, v);
            roots.push_back(t);
        } else {
            int k, i, j; cin >> k >> i >> j;
            cout << query(roots[k], 1, n, i, j) << '\n';
        }
    }
}
