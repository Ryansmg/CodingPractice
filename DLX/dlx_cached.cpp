#include <bits/stdc++.h>
#include <chrono>
#define int long long
#define pb push_back

using namespace std;
constexpr int inf = 1e18;


/// requirements: (T + T), add -> (T += UpdateType)
template <typename T = long long, typename UpdateType = T>
struct iterSeg {
    std::vector<T> tree; signed n = -1;
    iterSeg() = default;
    explicit iterSeg(const std::vector<T> &arr) {
        n = signed(arr.size()); tree = std::vector<T>(2 * n + 10, T());
        for(signed i = n, j = 0; i < 2 * n; i++, j++) tree[i] = arr[j];
        for(signed i = n - 1; i > 0; i--) tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
    explicit iterSeg(signed i) { tree = std::vector<T>(i * 2 + 10, T()); n = i; }
    void add(signed tar, const UpdateType& val) { tar--;
        tree[n + tar] += val;
        for(signed i = (n + tar) >> 1; i; i >>= 1) tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
    void set(signed tar, const T &val) { tar--;
        tree[n + tar] = val;
        for(signed i = (n + tar) >> 1; i; i >>= 1) tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
    T query(signed left, signed right) { left--;
        signed l = n + left, r = n + right;
        T ansL = T(), ansR = T();
        for(; l < r; l >>= 1, r >>= 1) {
            if(l & 1) { ansL = ansL + tree[l++]; }
            if(r & 1) { ansR = tree[--r] + ansR; }
        }
        return ansL + ansR;
    }
    T query(signed tar) { return tree[n + tar - 1]; }
};

iterSeg seg;

struct node {
    int row = 0, size = 0;
    node *col = nullptr;
    node *u = nullptr, *d = nullptr, *l = nullptr, *r = nullptr;
};

int n, m, cnt; // n이 행 개수 m이 열 개수
bool b[1003][1003];
int idx[1003][1003];
node dat[1000003];

void init() {

    dat[0].l = dat[0].r = dat[0].u = dat[0].d = dat[0].col = &dat[0];
    cnt = m;
    for (int i = 1; i <= m; i++) {
        dat[i].u = dat[i].d = &dat[i];
        dat[i].r = &dat[0];
        dat[i].l = &dat[i-1];
        dat[i-1].r = &dat[i];
        dat[0].l = &dat[i];
        dat[i].col = &dat[i];
    }

    map<int, vector<int>> row_to_nodes;
    for (int i = 1; i <= m; i++) { 
        for (int j = 1; j <= n; j++) { 
            if (b[j][i]) {
                cnt++;
                dat[i].size++;
                dat[cnt].row = j;
                dat[cnt].col = &dat[i];

                dat[cnt].u = dat[i].u;
                dat[cnt].d = &dat[i];
                dat[i].u->d = &dat[cnt];
                dat[i].u = &dat[cnt];

                row_to_nodes[j].push_back(cnt);
            }
        }
    }

    for (auto const& [row_idx, nodes_in_row] : row_to_nodes) {
        if (!nodes_in_row.empty()) {
            for (size_t k = 0; k < nodes_in_row.size(); ++k) {
                int current_node_idx = nodes_in_row[k];
                int prev_node_idx = nodes_in_row[(k + nodes_in_row.size() - 1) % nodes_in_row.size()];
                int next_node_idx = nodes_in_row[(k + 1) % nodes_in_row.size()];
                
                dat[current_node_idx].l = &dat[prev_node_idx];
                dat[current_node_idx].r = &dat[next_node_idx];
            }
        }
    }
}

void cover(node *cur) { // 열의 head 입력 시 그 열 제거

    cur->r->l = cur->l; // 양 옆에서 여기 가르키는 포인터 제거
    cur->l->r = cur->r;

    for (node *it = cur->d; it != cur; it = it->d) {

        for (node *jt = it->r; jt != it; jt = jt->r) {

            jt->d->u = jt->u;
            jt->u->d = jt->d;
            jt->col->size--;

        } // 해당 행 제거

    }

}

void uncover(node *cur) { // cover 반대

    for (node *it = cur->u; it != cur; it = it->u) {

        for (node *jt = it->l; jt != it; jt = jt->l) {

            jt->d->u = jt;
            jt->u->d = jt;
            jt->col->size++;

        }

    }

    cur->r->l = cur;
    cur->l->r = cur;

}

vector<int> ans;
int search_count = 0;
bool search(node *head) {

    search_count++;
    if (head->r == head) return true; // 빈 행렬일 때 성공

    node *lhd = nullptr;
    int low = inf;
    for (node *it = head->r; it != head; it = it->r) {

        if (it->size < low) {

            if (it->size == 0) return false;
            low = it->size;
            lhd = it;

        }

    } // 가장 작은 size의 열 찾기 / ptr은 해당 head

    cover(lhd);

    for (node *it = lhd->d; it != lhd; it = it->d) {
        
        ans.pb(it->row);
        for (node *jt = it->r; jt != it; jt = jt->r) cover(jt->col); //

        if (search(head)) return true;
        else { // 여기서 실패 -> 되돌려야됨

            ans.pop_back();
            for (node *jt = it->l; jt != it; jt = jt->l) uncover(jt->col);

        }

    }
    uncover(lhd);
    return false;

}

signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int j = 1; j <= n; j++)
        for (int i = 1; i <= m; i++) cin >> b[j][i];
    init();

    auto start = chrono::high_resolution_clock::now();
    search(dat);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;

    for (int i : ans) cout << i << ' ';
    cout << '\n' << "search count: " << search_count << '\n';
    cout << "execution time: " << fixed << setprecision(6) << diff.count() << " seconds" << '\n';

}
