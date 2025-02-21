/* Update : 2025-02-21 */

#include <bits/stdc++.h>


struct SimpleEdge { signed start, end; };
struct DistEdge { signed start, end; long long dist; };
template <typename T> concept isEdge1_ = requires(const T& a) { a.s; a.e; };
template <typename T> concept isEdge2_ = requires(const T& a) { a.start; a.end; };
template <typename T> concept isEdge = isEdge1_<T> || isEdge2_<T>;

/// node >= 0
/// requirements : (EdgeType.s && EdgeType.e) || (EdgeType.start && EdgeType.end)
/// detects : start/s, end/e, distance/dist/d/weight/w
template <isEdge EdgeType = SimpleEdge>
class Graph {
#define defGCFs_ inline static constexpr long long es_(const EdgeType& edge) { if constexpr(isEdge1_<EdgeType>) { return edge.s; } else return edge.start; }\
                 inline static constexpr long long ee_(const EdgeType& edge) { if constexpr(isEdge1_<EdgeType>) { return edge.e; } else return edge.end; }\
                 inline static constexpr long long ed_(const EdgeType& edge) {\
                     if constexpr(requires{edge.d;}) return edge.d;\
                     if constexpr(requires{edge.dist;}) return edge.dist;\
                     if constexpr(requires{edge.distance;}) return edge.distance;\
                     if constexpr(requires{edge.weight;}) return edge.weight;\
                     if constexpr(requires{edge.w;}) return edge.w;\
                     return 1;\
                 }
    defGCFs_
    inline static EdgeType revEdge_(EdgeType e) {
        if constexpr(isEdge1_<EdgeType>) std::swap(e.s, e.e);
        else if constexpr(isEdge2_<EdgeType>) std::swap(e.start, e.end);
        return e;
    }
public:
    long long nodeCnt = 0; // (maxNodeNumber) + 1
    std::vector<std::vector<EdgeType>> child, parent, undir;
    /// disables all error check if true
    /// increases performance
    bool unsafe = false;

    Graph() = default;
    explicit Graph(long long maxNodeNum) {
        if(!unsafe && nodeCnt > maxNodeNum) { std::cerr << "Invalid resizing"; exit(1); }
        nodeCnt = maxNodeNum + 1;
        child.resize(nodeCnt, std::vector<EdgeType>()); parent.resize(nodeCnt, std::vector<EdgeType>()); undir.resize(nodeCnt, std::vector<EdgeType>());
    }
    /// reset
    virtual void clear() { child = parent = undir = std::vector<std::vector<EdgeType>>(); nodeCnt = 0; unsafe = false; }

    virtual void resize(long long maxNodeNum) {
        if(!unsafe && nodeCnt > maxNodeNum) { std::cerr << "Invalid resizing"; exit(1); }
        nodeCnt = maxNodeNum + 1;
        child.resize(nodeCnt, std::vector<EdgeType>()); parent.resize(nodeCnt, std::vector<EdgeType>()); undir.resize(nodeCnt, std::vector<EdgeType>());
    }
    virtual void addUEdge(const EdgeType& edge) { undir[es_(edge)].emplace_back(edge); undir[ee_(edge)].emplace_back(revEdge_(edge)); }
    template <typename... Args> void makeUEdge(Args&&... args) { EdgeType edge(std::forward<Args>(args)...);
        undir[es_(edge)].emplace_back(edge); undir[ee_(edge)].emplace_back(revEdge_(edge)); }
    virtual void addDEdge(const EdgeType& edge) { child[es_(edge)].emplace_back(edge); parent[ee_(edge)].emplace_back(edge); }
    template <typename... Args> void makeDEdge(Args&&... args) { EdgeType edge(std::forward<Args>(args)...);
        child[es_(edge)].emplace_back(edge); parent[ee_(edge)].emplace_back(edge); }
    void removeDuplicateEdge() {
        std::function<void(std::vector<std::vector<EdgeType>>&)> f = [&](std::vector<std::vector<EdgeType>>& k) {
            for(auto &arr : k) {
                sort(arr, [&](const EdgeType& a, const EdgeType& b) {
                    if(es_(a) == es_(b)) {
                        if(ee_(a) == ee_(b)) return ed_(a) < ed_(b);
                        return ee_(a) < ee_(b);
                    }
                    return es_(a) < es_(b);
                });
                arr.erase(std::unique(arr.begin(), arr.end(), [&](const EdgeType& a, const EdgeType& b) {
                    return es_(a) == es_(b) && ee_(a) == ee_(b) && ed_(a) == ed_(b);
                }), arr.end());
            }
        };
        f(child); f(parent); f(undir);
    }
    /// child와 undir에 대한 forEach문을 지원
    class Connection {
        Graph<EdgeType>* g; long long n;
    public:
        explicit Connection(Graph<EdgeType>* gp, long long node) : g(gp), n(node) { }
        class Iter {
            friend class Connection;
            Graph<EdgeType>* g; std::vector<EdgeType>::iterator cur; long long n;
            Iter(Graph<EdgeType>* gp, std::vector<EdgeType>::iterator i, long long N) : g(gp), cur(i), n(N) {}
        public:
            Iter& operator++() { ++cur; if(cur == g->child[n].end()) { cur = g->undir[n].begin(); } return *this; }
            bool operator!=(const Iter& o) const { return cur != o.cur; }
            EdgeType& operator*() { return *cur; }
        };
        Iter begin() { return g->child[n].empty() ? Iter(g, g->undir[n].begin(), n) : Iter(g, g->child[n].begin(), n); }
        Iter end() { return Iter(g, g->undir[n].end(), n); }
    };
    Connection getConnection(long long node) { return Connection(this, node); }

    /// Complexity : O(ElogV)
    /// @returns {minDist, parent}
    std::pair<std::vector<long long>, std::vector<long long>> dijkstra(long long startNode) {
        std::vector<long long> dist(nodeCnt, 1000000000000000000), par(nodeCnt, -1);
        std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long>>, std::greater<>> q;
        q.emplace(0, startNode); dist[startNode] = 0;
        while(!q.empty()) {
            auto [d, cur] = q.top(); q.pop(); if(d > dist[cur]) continue;
            for(const auto& i : getConnection(cur)) {
                if(!unsafe && ed_(i) < 0) { std::cerr << "Negative distance is not allowed."; exit(1); }
                long long nxt = ee_(i), nxtCost = d + ed_(i);
                if(nxtCost < dist[nxt]) { dist[nxt] = nxtCost; q.emplace(nxtCost, nxt); par[nxt] = cur; }
            }
        }
        return {dist, par};
    }
    /// Complexity : O(N)
    std::vector<EdgeType> getConnectionArr(long long node) {
        std::vector<EdgeType> ret; for(const auto& e : child[node]) ret.emplace_back(e); for(const auto& e : undir[node]) ret.emplace_back(e); return ret;
    }
    Graph& setUnsafe(bool _ = true) { unsafe = _; return *this; }
};

template <typename EdgeType>
class Tree : public Graph<EdgeType> { defGCFs_
    bool usingHld = false;
public:
    long long root = -1; std::vector<long long> sz, dep, top, in, out, inRev;
    void clear() override {
        Graph<EdgeType>::clear(); sz = dep = top = in = out = inRev = std::vector<long long>(); usingHld = false; root = 0;
        logH = 0; usingSparse = false; sparsePar = sparseDist = std::vector<std::vector<long long>>();
    }
    Tree() = default; // creates empty tree
    Tree(long long rootNode, const Graph<EdgeType>& graph) : Graph<EdgeType>(graph), root(rootNode) {
        if(!this->unsafe) { // check cycle
            std::vector<bool> vis(this->nodeCnt, false);
            bool hasCycle = false;
            std::function<void(long long, long long)> dfs_ = [&](long long cur, long long par) {
                if(hasCycle) return;
                if(vis[cur]) { hasCycle = true; return; }
                vis[cur] = true;
                for(const auto& e : this->child[cur]) if(ee_(e) != par) dfs_(ee_(e), cur);
                for(const auto& e : this->undir[cur]) if(ee_(e) != par) dfs_(ee_(e), cur);
            };
            dfs_(rootNode, -1);
            if(hasCycle) { std::cerr << "Cycle detected while constructing Tree"; exit(1); }
        }
        std::function<void(long long, long long)> dfs2_ = [&](long long cur, long long par) { // move undir -> child & parent
            for(const auto& e : this->child[cur]) if(ee_(e) != par) dfs2_(ee_(e), cur);
            for(const auto& e : this->undir[cur]) if(ee_(e) != par) {
                    this->child[cur].emplace_back(e); this->parent[ee_(e)].emplace_back(e);
                    dfs2_(ee_(e), cur);
                }
        };
        dfs2_(rootNode, -1);
        this->undir.clear();
    }

    long long par(long long node) { if(!this->unsafe) assert(this->parent[node].size() == 1);
        return es_(this->parent[node][0]); }

    /// euler tour technique (range: [1, n])
    /// saves results at in & out. new edges does not update the results.
    /// Complexity : O(N)
    std::pair<std::vector<long long>, std::vector<long long>> getInOut() {
        in = std::vector<long long>(this->nodeCnt, -1), out = in; long long cur = 0;
        std::function<void(long long)> f = [&](long long p) { in[p] = ++cur;
            for(const auto& e : this->child[p]) f(ee_(e));
            out[p] = cur; };
        f(root); return {in, out};
    }

    /// heavy_light decomposition
    /// 'in' range : [1..n]
    void initHld() {
        sz = dep = top = in = out = inRev = vl(this->nodeCnt, 0); usingHld = true;
        long long pv = 0; top[this->root] = this->root;
        // sz & dep & par, reconstruct
        std::function<void(long long)> dfs1 = [&](long long v) {
            sz[v] = 1;
            for(auto &i : this->child[v]) {
                long long j = ee_(i); dep[j] = dep[v] + 1; dfs1(j); sz[v] += sz[j];
                if(sz[j] > sz[ee_(this->child[v][0])]) std::swap(i, this->child[v][0]);
            }
        }; dfs1(this->root);
        // in & out & top
        std::function<void(long long)> dfs2 = [&](long long v) {
            in[v] = ++pv;
            for(const auto& i : this->child[v]) {
                long long j = ee_(i); top[j] = (j == ee_(this->child[v][0])) ? top[v] : j; dfs2(j); }
            out[v] = pv;
        }; dfs2(this->root);
        for(long long i = 0; i < this->nodeCnt; i++) inRev[in[i]] = i;
    }

    /// calls func(ettNum1, ettNum2) (ettNum1 <= ettNum2)
    /// for decomposed chains for a ~ b
    /// calls initHld() automatically if you didn't
    /// @returns lca(a, b)
    long long hld(long long a, long long b, const std::function<void(long long, long long)> &func, bool excludeLca = false) {
        if(!usingHld) initHld();
        while(top[a] != top[b]) {
            if(dep[top[a]] < dep[top[b]]) std::swap(a, b);
            long long st = top[a]; func(in[st], in[a]); a = par(st);
        }
        if(dep[a] > dep[b]) std::swap(a, b);
        if(!excludeLca) func(in[a], in[b]);
        else if(in[a] != in[b]) func(in[a] + 1, in[b]);
        return a;
    }

    long long hld(long long a, long long b, const std::function<void(long long, long long)> &lFunc, const std::function<void(long long, long long)> &rFunc) {
        if(!usingHld) initHld();
        while(top[a] != top[b]) {
            if(dep[top[a]] > dep[top[b]]) {
                lFunc(in[top[a]], in[a]);
                a = par(top[a]);
            } else {
                rFunc(in[top[b]], in[b]);
                b = par(top[b]);
            }
        }
        if(dep[a] > dep[b]) lFunc(in[b], in[a]);
        else rFunc(in[a], in[b]);
        return dep[a] > dep[b] ? b : a;
    }

private:
    long long logH = 0; std::vector<std::vector<long long>> sparsePar, sparseDist; bool usingSparse = false;
    void initSparse() {
        if(usingSparse) return;
        usingSparse = true; sparsePar.resize(this->nodeCnt, std::vector<long long>()); sparseDist.resize(this->nodeCnt, std::vector<long long>());
        dep = std::vector<long long>(this->nodeCnt, 0);
        std::function<void(long long)> dfs = [&](long long v) {
            logH = std::max(logH, static_cast<long long>(log2(dep[v]+1)));
            for(auto &i : this->child[v]) { long long j = ee_(i); dep[j] = dep[v] + 1; dfs(j); }
        }; dfs(this->root);
        for(long long v = 0; v <= this->nodeCnt-1; v++) {
            if(this->parent[v].empty()) sparsePar[v].emplace_back(v), sparseDist[v].push_back(0);
            else sparsePar[v].emplace_back(par(v)), sparseDist[v].emplace_back(ed_(this->parent[v][0]));
        }
        for(long long i = 0; i < logH+1; i++) for(long long v = 0; v <= this->nodeCnt-1; v++) {
                sparsePar[v].emplace_back(sparsePar[sparsePar[v][i]][i]);
                sparseDist[v].emplace_back(sparseDist[v][i] + sparseDist[sparsePar[v][i]][i]);
            }
    }
public:
    std::pair<long long, long long> sparseLca(long long a, long long b) { initSparse();
        if(dep[a] > dep[b]) std::swap(a, b);
        long long depDiff = dep[b] - dep[a], dist = 0;
        for(long long i = logH; depDiff && i >= 0; i--)
            if(depDiff & (1<<i)) dist += sparseDist[b][i], b = sparsePar[b][i], depDiff ^= (1<<i);
        for(long long i = logH; i >= 0; i--)
            if(sparsePar[a][i] != sparsePar[b][i])
                dist += sparseDist[a][i] + sparseDist[b][i], a = sparsePar[a][i], b = sparsePar[b][i];
        if(a == b) return {a, dist};
        return {sparsePar[a][0], dist + sparseDist[a][0] + sparseDist[b][0]};
    }

    /// if hld is made => returns lca using hld
    /// else => makes sparse tree
    long long lca(long long a, long long b) {
        if(usingHld) return hld(a, b, [&](long long, long long){});
        return sparseLca(a, b).first;
    }

    /// uses sparse table
    long long dist(long long a, long long b) { return sparseLca(a, b).second; }
};

template <isEdge EdgeType = SimpleEdge>
class DGraph : public Graph<EdgeType> { defGCFs_
public:
    explicit DGraph() = default;
    explicit DGraph(long long maxNodeNum) : Graph<EdgeType>(maxNodeNum) {}
    explicit DGraph(const Graph<EdgeType>& g) : Graph<EdgeType>(g) {
        if(!this->unsafe) for(const auto& arr : this->undir) if(!arr.empty()) { std::cerr << "Not a valid DGraph.\n"; exit(1); }
    }
    /// SCC들은 위상 정렬되어 반환됨
    /// SCC 안 노드들은 번호 순서대로 정렬됨
    std::vector<std::vector<long long>> getScc(const std::set<long long>& ignore = {}) {
        std::vector<bool> finished(this->nodeCnt, false);
        std::vector<long long> id(this->nodeCnt, -1); long long curId = 0;
        std::vector<long long> st; std::vector<std::vector<long long>> ret;
        std::function<long long(long long)> f = [&](long long node) {
            id[node] = ++curId; st.push_back(node);
            long long parent = id[node];
            for(const auto& e : this->child[node]) {
                long long i = ee_(e);
                if(id[i] == -1) parent = std::min(parent, f(i));
                else if(!finished[i]) parent = std::min(parent, id[i]);
            }
            if(parent == id[node]) {
                std::vector<long long> scc;
                while(true) {
                    long long top = st.back(); st.pop_back();
                    scc.emplace_back(top); finished[top] = true;
                    if(top == node) break;
                }
                std::ranges::sort(scc); ret.emplace_back(scc);
            }
            return parent;
        };
        for(long long i = 0; i < this->nodeCnt; i++) {
            if(ignore.contains(i)) continue;
            if(finished[i]) continue;
            f(i);
        }
        std::ranges::reverse(ret); return ret;
    }
};

template <isEdge EdgeType = SimpleEdge>
class Dag : public DGraph<EdgeType> {
public:
    /// does not check cycles.
    explicit Dag(const DGraph<EdgeType>& g) : DGraph<EdgeType>(g) { }
    std::vector<long long> topologySort(const std::set<long long>& ignore = {}) {
        std::vector<long long> ret, inDegree(this->nodeCnt); long long n = 0;
        for(long long i = 0; i < this->nodeCnt; i++) inDegree[i] = Size(this->parent[i]);
        std::queue<long long> q;
        for(long long i = 0; i < this->nodeCnt; i++) { if(ignore.contains(i)) { continue; } ++n; if(!inDegree[i]) q.emplace(i); }
        for(long long t = 0; t < n; t++) {
            if(q.empty()) { std::cerr << "Dag has cycles!\n"; exit(1); }
            long long x = q.front(); q.pop(); ret.emplace_back(x);
            for(const auto& [X, i] : this->child[x]) if(--inDegree[i] == 0) q.emplace(i);
        }
        return ret;
    }
};

template <typename EdgeType = SimpleEdge>
class UGraph : public Graph<EdgeType> { defGCFs_
    bool useUnionFind = false; std::vector<long long> groupNum, groupSize;
    long long uf_find(long long tar) { if(groupNum[tar] == tar) return tar;
        return groupNum[tar] = uf_find(groupNum[tar]); }
    void uf_union(long long a, long long b) {
        if(uf_find(a) == uf_find(b)) return;
        if(groupSize[uf_find(a)] < groupSize[uf_find(b)]) std::swap(a, b);
        groupSize[uf_find(a)] += groupSize[uf_find(b)]; groupSize[uf_find(b)] = 0; groupNum[uf_find(b)] = uf_find(a);
    }
    void uf_init() {
        if(useUnionFind) { return; } useUnionFind = true;
        std::vector<bool> vis(this->nodeCnt, false); groupNum.resize(this->nodeCnt, -1); groupSize.resize(this->nodeCnt, 0);
        for(long long i = 0; i < this->nodeCnt; i++) groupNum[i] = i;
        for(long long i = 0; i < this->nodeCnt; i++) {
            if(vis[i]) { continue; } std::queue<long long> bfs; bfs.emplace(i); vis[i] = true; groupSize[i]++;
            while(!bfs.empty()) {
                long long cur = bfs.front(); bfs.pop();
                for(const auto& e : this->undir[cur]) {
                    long long dest = ee_(e); if(vis[dest]) continue;
                    vis[dest] = true; groupNum[dest] = i; groupSize[i]++; bfs.emplace(dest);
                } } } }
public:
    void clear() { Graph<EdgeType>::clear(); useUnionFind = false; groupNum = groupSize = std::vector<long long>(); }
    void addEdge(const EdgeType& edge) { Graph<EdgeType>::addUEdge(edge); if(useUnionFind) uf_union(es_(edge), ee_(edge)); }
    template <typename... Args> void makeEdge(Args&&... args) { EdgeType edge(std::forward<Args>(args)...);
        Graph<EdgeType>::addUEdge(edge); if(useUnionFind) uf_union(es_(edge), ee_(edge)); }
    UGraph() = default;
    explicit UGraph(long long maxNodeNum) : Graph<EdgeType>(maxNodeNum) { this->child = this->parent = std::vector<std::vector<EdgeType>>(); }
    explicit UGraph(const Graph<EdgeType>& g) : Graph<EdgeType>(g) { if(this->unsafe) return;
        for(const auto& arr : this->child) if(Size(arr)) { std::cerr << "Not a valid UGraph."; exit(1); }
        this->child = this->parent = v2<EdgeType>(); }
    void resize(long long maxNodeNum) { if(!this->unsafe && this->nodeCnt >= maxNodeNum) { std::cerr << "Invalid resizing"; exit(1); }
        long long preNodeCnt = this->nodeCnt; this->nodeCnt = maxNodeNum + 1; this->undir.resize(this->nodeCnt, std::vector<EdgeType>());
        if(useUnionFind) for(long long i = preNodeCnt; i <= maxNodeNum; i++) { groupNum.emplace_back(i); groupSize.emplace_back(1); } }
    /// union-find ( 0 <= parent < nodeCnt ), O(N) (calls uf_find for all nodes)
    /// @return {[node] = parent}
    [[nodiscard]] std::vector<long long> getAllGroup() { uf_init(); for(long long i = 0; i < this->nodeCnt; i++) groupNum[i] = uf_find(i);
        return groupNum; }
    std::vector<long long> getAllGroupSize() { uf_init(); return groupSize; }
    /// union-find ( 0 <= parent < nodeCnt ), O(1) (O(N) at first uf call)
    long long getGroup(long long node) { uf_init(); return uf_find(node); }
    /// union-find ( 0 <= parent < nodeCnt ), O(1) (O(N) at first uf call)
    long long getGroupSize(long long group) { uf_init(); return groupSize[group]; }
};
