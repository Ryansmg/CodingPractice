/* Update : 2025-02-04 */

#include <bits/stdc++.h>

struct StringHash {
    std::vector<long long> hash, pc; long long p, q;
    explicit StringHash(const std::string& s, long long p = 998244353, long long mod = 1000000007, long long offset = 0)
    : p(p), q(mod) {
        pc.reserve(std::ssize(s)+2); pc.resize(1, 1);
        hash.reserve(std::ssize(s)+2); hash.resize(1, 0);
        for(const char &c : s) {
            hash.emplace_back((hash.back() * p + c - offset) % q);
            pc.emplace_back(pc.back() * p % q);
        }
    }
    /// 0-based index
    inline long long operator()(long long l, long long r) const {
        return (hash[r+1] - hash[l] * pc[r-l+1] % q + q) % q;
    }
};

// Example : BOJ 1605. 반복 부분문자열
int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long n; string s; cin >> n >> s;
    StringHash hash(s, 73, 999999937, 'a'), hash2(s);
    long long ans = 0;
    for(long long l = 1, r = n; l <= r;) {
        long long m = (l + r) / 2;
        set<array<int, 2>> v;
        for(long long i = 0; i + m - 1 < n; i++) {
            array<int, 2> h = { int(hash(i, i + m - 1)), int(hash2(i, i + m - 1))};
            if(v.contains(h)) { ans = m, l = m + 1; goto end; }
            v.insert(h);
        }
        r = m - 1;
        end:;
    }
    cout << ans;
}
