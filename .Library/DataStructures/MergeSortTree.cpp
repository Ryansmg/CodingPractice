/* Update : 2025-02-21 */

#include <vector>
#include <algorithm>

template <typename T = long long>
class MergeSortTree {
    static inline std::vector<T> merge(const std::vector<T>&a, const std::vector<T>&b) {
        std::vector<T> ret(a.size()+b.size()); std::merge(a.begin(), a.end(), b.begin(), b.end(), ret.begin()); return ret;
    }
public:
    std::vector<std::vector<T>> tree; signed n = -1; signed offset = 1;
    MergeSortTree() = default;
    explicit MergeSortTree(const std::vector<T> &arr) {
        n = signed(arr.size()); tree = std::vector<std::vector<T>>(2 * n, std::vector<T>(1));
        for(signed i = n, j = 0; i < 2 * n; i++, j++) tree[i][0] = arr[j];
        for(signed i = n - 1; i > 0; i--) tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
    }
    std::vector<std::vector<T>*> query(signed left, signed right) { left -= offset; right -= offset;
        std::vector<std::vector<T>*> ret;
        signed l = n + left, r = n + right + 1;
        for(; l < r; l >>= 1, r >>= 1) {
            if(l & 1) ret.push_back(&tree[l++]);
            if(r & 1) ret.push_back(&tree[--r]);
        }
        return ret;
    }
};

// Example : BOJ 13537. 수열과 쿼리 1
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long n; cin >> n;
    vector<long long> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    MergeSortTree seg(arr);

    long long m; cin >> m;
    for(int i = 0; i < m; i++) {
        long long a, b, k, ans = 0; cin >> a >> b >> k;
        for(auto p : seg.query(a, b)) {
            ans += p->end() - upper_bound(p->begin(), p->end(), k);
        }
        cout << ans << '\n';
    }
}
