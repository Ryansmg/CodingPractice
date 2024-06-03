#pragma region macros
#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr) // enables fast input/output
#define all(vec) (vec).begin(), (vec).end()
#define forn(name, val) for(int name = 0; name < val; name++)
#define forf(name, start, end) for(int name = start; name <= end; name++)
using namespace std;
template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
using ii = array<int, 2>;
int input() { int t; cin >> t; return t;}
#pragma endregion

// 18227. 성대나라의 물탱크
// #segtree #euler_path_technique

void update(v<int> &tree, int node, int start, int end, const int &index, int val)
{
    if(index<start || end<index) return;
    if(start==end) {
        tree[node] += val;
    } else {
        update(tree, node*2, start, (start+end)/2, index, val);
        update(tree, node*2+1, (start+end)/2+1, end, index, val);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

int query(v<int> &tree, int node, int start, int end, const int &left, const int &right) {
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    return query(tree, node*2, start, (start+end)/2, left, right)
           + query(tree, node*2+1, (start+end)/2+1, end, left, right);
}

int curEn = 0;
void dfs(int top, int d, v<bool> &visited, v<int> &en, v<ii> &range, v2<int> &con, v<int> &dist) {
    en[top] = ++curEn;
    dist[top] = d;
    for(int i : con[top]) {
        if(visited[i]) continue;
        visited[i] = true;
        dfs(i, d+1, visited, en, range, con, dist);
    }
    range[top] = {en[top], curEn};
}

signed main() {
    fastio;
    int n, c; cin >> n >> c;
    v2<int> con(n+1, v<int>());
    v<int> en(n+1);
    v<ii> range(n+1);
    v<int> dist(n+1); // 수도까지의 거리 + 1
    forn(i, n-1) {
        int x, y; cin >> x >> y;
        con[x].push_back(y);
        con[y].push_back(x);
    }

    // dfs를 통해 부모 노드 - 자식 노드에 연속한 수를 부여, 자신 + 자식 노드의 수 범위를 저장
    v<bool> visited(n+1, false); visited[c] = true;
    dfs(c, 1, visited, en, range, con, dist);
    assert(curEn == n);

    // 쿼리 처리
    v<int> tree(4*n+10, 0);
    int q = input();
    forn(qi, q) {
        int type, a; cin >> type >> a;
        if(type == 1) { //update
            update(tree, 1, 1, n, en[a], 1);
        } else {
            cout << query(tree, 1, 1, n, range[a][0], range[a][1]) * dist[a] << '\n';
        }
    }
}
