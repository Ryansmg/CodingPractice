/* Update : 2025-02-04 */

#include <bits/stdc++.h>

/// Union-Find with Rollback
class UFR {
    signed n; std::vector<signed> parent, rank; std::stack<std::tuple<signed, signed, bool>> history;
public:
    explicit UFR(signed maxNodeNum) : n(maxNodeNum+1), parent(n), rank(n, 1) { iota(parent.begin(), parent.end(), 0); }
    inline signed group(signed x) { return x == parent[x] ? x : group(parent[x]); }
    inline signed operator[](signed x) { return group(x); } inline signed find(signed x) { return group(x); }
    void merge(signed a, signed b) {
        a = group(a); b = group(b);
        if(a == b) { history.emplace(a, b, false); return; }
        if(rank[a] < rank[b]) std::swap(a, b);
        bool rankIncrement = rank[a] == rank[b];
        history.emplace(a, b, rankIncrement);
        parent[b] = a; rank[a] += rankIncrement;
    }
    void rollback(signed cnt = 1) {
        for(long long k = 0; k < cnt; k++) {
            auto [a, b, i] = history.top(); history.pop();
            if(a != b) parent[b] = b, rank[a] -= i;
        }
    }
};

/// Offline Dynamic Connectivity
class ODC {
    std::vector<std::vector<std::array<long long, 2>>> lines;
    std::vector<std::vector<std::array<long long, 3>>> queries; // {a, b, idx}
    UFR ufr; signed n; signed queryCnt = 0, curTime = 1; std::map<std::array<long long, 2>, signed> addedLines;
    void addLine(signed p, signed s, signed e, signed tl, signed tr, const std::array<long long, 2>& line) {
        if(e < tl || tr < s) return;
        if(tl <= s && e <= tr) { lines[p].push_back(line); return; }
        addLine(p*2, s, (s+e)>>1, tl, tr, line);
        addLine(p*2+1, ((s+e)>>1)+1, e, tl, tr, line);
    }
    void solve(signed p, signed s, signed e, std::vector<bool>& ans) {
        for(const auto &[a, b] : lines[p]) ufr.merge(a, b);
        if(s == e) {
            for(const auto& [a, b, i] : queries[s])
                ans[i] = ufr[a] == ufr[b];
        }
        else solve(p*2, s, (s+e)>>1, ans), solve(p*2+1, ((s+e)>>1)+1, e, ans);
        ufr.rollback(std::ssize(lines[p]));
    }
public:
    ODC(signed maxNode, signed maxTime) : lines(maxTime*4, std::vector<std::array<long long, 2>>()),
        queries(maxTime+3, std::vector<std::array<long long, 3>>()), ufr(maxNode), n(maxTime) { }
    void addLine(const std::array<long long, 2>& line, signed tl, signed tr) { addLine(1, 1, n, tl, tr, line); }
    void addLine(signed ll, signed lr, signed tl, signed tr) { addLine(1, 1, n, tl, tr, {ll, lr}); }
    void addQuery(signed a, signed b, signed t) { queries[t].push_back({a, b, queryCnt++}); }
    /// 위 함수들이랑 아래 함수들이랑 섞어 쓰면 인생 망해요
    /// O(logN)
    void addLine(signed a, signed b) { addedLines.insert({{std::min(a, b), std::max(a, b)}, curTime++}); }
    void removeLine(signed a, signed b, bool allowNonexistentEdge = false) {
        auto iter = addedLines.find({std::min(a, b), std::max(a, b)});
        if(iter == addedLines.end()) {
            if(!allowNonexistentEdge) std::cerr << "Removed before add\n", exit(1);
            return;
        }
        addLine(iter->first, iter->second, curTime++);
        addedLines.erase(iter);
    }
    void addQuery(signed a, signed b) { queries[curTime++].push_back({a, b, queryCnt++}); }
    std::vector<bool> solve() {
        for(const auto& [line, t] : addedLines) addLine(line, t, n);
        addedLines.clear();
        std::vector<bool> ans(queryCnt); solve(1, 1, n, ans); return ans;
    }
};

// Example : BOJ 16911. 그래프와 쿼리
int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long n, m; cin >> n >> m;
    ODC odc(n, m);
    for(long long i = 0; i < m; i++) {
        long long op, a, b; cin >> op >> a >> b;
        if(op == 1) odc.addLine(a, b);
        else if(op == 2) odc.removeLine(a, b);
        else odc.addQuery(a, b);
    }
    auto ans = odc.solve();
    for(bool b : ans) cout << b << '\n';
}