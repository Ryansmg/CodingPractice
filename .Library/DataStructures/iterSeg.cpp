/* Update : 2025-02-11 */

/// 교환법칙이 성립하지 않는 연산을 지원
/// i > j인 i와 j에 대해 operator+(arr[i], arr[j])가 호출될 수 있으나,
/// 그 결과는 query 함수에서 사용하지 않음.

#include <vector>
#include <span>

/// requirements: (T + T), add -> (T += UpdateType)
template <typename T = long long, typename UpdateType = T>
struct iterSeg {
    std::vector<T> tree; signed n = -1;
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
    std::span<T> getLeafs() { return std::span<T>(tree.begin() + n, tree.begin() + 2 * n - 1); }
};

// Example : BOJ 2042. 구간 합 구하기
#include <iostream>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    vector<long long> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    iterSeg seg(arr);
    for(int i = 0; i < m + k; i++) {
        int a, b, c; cin >> a >> b >> c;
        if(a == 1) seg.set(b, c);
        else cout << seg.query(b, c) << '\n';
    }
}