/* Update : 2025-02-04 */

#include <bits/stdc++.h>

/// Graph & DGraph 클래스의 일부분
namespace TwoSatRequirements {
    struct SimpleEdge { signed start, end; };
    template<typename T> concept isEdge1_ = requires(const T &a) { a.s; a.e; };
    template<typename T> concept isEdge2_ = requires(const T &a) { a.start; a.end; };
    template<typename T> concept isEdge = isEdge1_<T> || isEdge2_<T>;
    template<isEdge EdgeType = SimpleEdge> class Graph {
        #define defGCFs_ static long long es_(const EdgeType& edge) { if constexpr(isEdge1_<EdgeType>) { return edge.s; } return edge.start; }\
                         static long long ee_(const EdgeType& edge) { if constexpr(isEdge1_<EdgeType>) { return edge.e; } return edge.end; }\
                         static long long ed_(const EdgeType& edge) {\
                             if constexpr(requires{edge.d;}) return edge.d;\
                             if constexpr(requires{edge.dist;}) return edge.dist;\
                             if constexpr(requires{edge.distance;}) return edge.distance;\
                             return 1;\
                         }
        defGCFs_
    public:
        long long nodeCnt = 0; // (maxNodeNumber) + 1
        std::vector<std::vector<EdgeType>> child, parent, undir;
        Graph() = default;
        explicit Graph(long long maxNodeNum) {
            nodeCnt = maxNodeNum + 1;
            child.resize(nodeCnt, std::vector<EdgeType>()); parent.resize(nodeCnt, std::vector<EdgeType>()); undir.resize(nodeCnt, std::vector<EdgeType>());
        }
        template<typename... Args>
        void makeDEdge(Args &&... args) { EdgeType edge(std::forward<Args>(args)...); child[es_(edge)].emplace_back(edge); parent[ee_(edge)].emplace_back(edge); }
    };
    template<isEdge EdgeType = SimpleEdge>
    class DGraph : public Graph<EdgeType> { defGCFs_
    public:
        explicit DGraph() = default; explicit DGraph(long long maxNodeNum) : Graph<EdgeType>(maxNodeNum) {}
        std::vector<std::vector<long long>> getScc(const std::set<long long> &ignore = {}) {
            std::vector<bool> finished(this->nodeCnt, false); std::vector<long long> id(this->nodeCnt, -1);
            long long curId = 0;
            std::vector<long long> st; std::vector<std::vector<long long>> ret;
            std::function<long long(long long)> f = [&](long long node) {
                id[node] = ++curId; st.push_back(node);
                long long parent = id[node];
                for(const auto &e: this->child[node]) { long long i = ee_(e);
                    if(id[i] == -1) parent = std::min(parent, f(i));
                    else if(!finished[i]) parent = std::min(parent, id[i]);
                }
                if(parent == id[node]) { std::vector<long long> scc;
                    while(true) { long long top = st.back(); st.pop_back();
                        scc.emplace_back(top); finished[top] = true;
                        if(top == node) break; }
                    std::ranges::sort(scc); ret.emplace_back(scc); }
                return parent;
            };
            for(long long i = 0; i < this->nodeCnt; i++) { if(ignore.contains(i) || finished[i]) {continue;} f(i); }
            std::ranges::reverse(ret); return ret;
        }
    };
}
using namespace TwoSatRequirements;

/// 1 ~ n
class TwoSat {
    long long n = 0; DGraph<SimpleEdge> g;
public:
    TwoSat() = default;
    explicit TwoSat(long long boolCount) : n(boolCount), g(boolCount*2+1) {}
    /// a or b, a : true, -a : false
    /// 1 <= a, b <= n
    void add(long long a, long long b) { a = a < 0 ? (-a) * 2 + 1 : a * 2; b = b < 0 ? (-b) * 2 + 1 : b * 2;
        g.makeDEdge(a^1, b); g.makeDEdge(b^1, a); }
    void add(long long a) { add(a, a); } void addTrue(long long a) { add(a, a); } void addFalse(long long a) { add(-a, -a); } void addOr(long long a, long long b) { add(a, b); }
    /// a != b이도록 조건을 설정
    void addXor(long long a, long long b) { add(a, b); add(-a, -b); }
    /// a == b이도록 조건을 설정
    void addXnor(long long a, long long b) { add(a, -b); add(-a, b); }
    /// a : true, -a : false
    /// 1 <= a, b <= n
    bool possible() {
        std::vector<std::vector<long long>> sccs = g.getScc({0}); std::vector<long long> sccId(n*2+2, -1);
        for(long long i = 0; i < std::ssize(sccs); i++) for(long long j : sccs[i]) sccId[j] = i;
        for(long long i = 1; i <= n; i++) if(sccId[2*i] == sccId[2*i+1]) return false;
        return true;
    }
    /// @returns an empty vector if not possible
    /// <br> returns arr[i] = (answer for i) if possible
    std::vector<bool> getAns() {
        std::vector<std::vector<long long>> sccs = g.getScc({0}); std::vector<long long> sccId(n*2+2, -1);
        for(long long i = 0; i < std::ssize(sccs); i++) for(long long j : sccs[i]) sccId[j] = i;
        for(long long i = 1; i <= n; i++) if(sccId[2*i] == sccId[2*i+1]) return {};
        std::vector<signed> ansi(n, -1);
        for(const std::vector<long long>& scc : sccs) for(long long i : scc) if(ansi[i/2-1] == -1) ansi[i/2-1] = (i&1) ? 1 : 0;
        std::vector<bool> ans(1, false); for(signed i : ansi) ans.emplace_back(i);
        return ans;
    }
};

// Example : BOJ 11280. 2-SAT - 3
int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long n, m; cin >> n >> m;
    TwoSat ts(n);
    for(long long i = 0; i < m; i++) {
        long long a, b; cin >> a >> b;
        ts.add(a, b);
    }
    cout << ts.possible() << '\n';
}
