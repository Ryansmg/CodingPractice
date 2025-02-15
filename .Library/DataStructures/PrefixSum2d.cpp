/* Update : 2025-02-11 */

#include <vector>

template <typename T = long long>
struct PrefixSum2d {
    std::vector<std::vector<T>> data;
    PrefixSum2d()=default;
    explicit PrefixSum2d(const std::vector<std::vector<T>>& arr) {
        long long yn = std::ssize(arr), xn = std::ssize(arr[0]);
        data.resize(yn, std::vector<T>());
        for(long long i = 0; i < yn; i++) for(long long j = 0; j < xn; j++) {
            if(!j) data[i].emplace_back(arr[i][j]);
            else data[i].emplace_back(data[i][j-1] + arr[i][j]);
        }
        for(long long j = 0; j < xn; j++) for(long long i = 1; i < yn; i++) data[i][j] += data[i-1][j];
    }
    inline T operator()(long long ly, long long ry, long long lx, long long rx) {
        T ret = data[ry][rx];
        if(lx) ret -= data[ry][lx-1];
        if(ly) ret -= data[ly-1][rx];
        if(lx&&ly) ret += data[ly-1][lx-1];
        return ret;
    }
};


// Example : BOJ 2167. 2차원 배열의 합
#include <iostream>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long n, m; cin >> n >> m;
    vector arr = vector(n, vector<long long>(m));
    for(long long r = 0; r < n; r++) for(long long c = 0; c < m; c++) cin >> arr[r][c];
    PrefixSum2d ps(arr);
    long long k; cin >> k;
    for(long long t = 0; t < k; t++) {
        long long i, j, x, y; cin >> i >> j >> x >> y; i--; j--; x--; y--;
        cout << ps(i, x, j, y) << '\n';
    }
}
