#pragma region macros
#include <bits/stdc++.h>
#define int long long
#define lint __int128
#define double long double
#define llmax 9223372036854775807
#define INF 1000000000000000000
#define inf 3000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define all(vec) (vec).begin(), (vec).end()
#define forn(name, val) for(int name = 0; name < val; name++)
#define forf(name, start, end) for(int name = start; name <= end; name++)
using namespace std;
template <typename T> using v = vector<T>; template <typename T> using v2 = v<v<T>>;
template <typename T> using pq = priority_queue<T>;
using ii = array<int, 2>; using iii = array<int, 3>;
template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
template <typename T> T input() {T t; cin >> t; return t;} int input() { int t; cin >> t; return t;}
#pragma endregion

#define zero_stl(v, sz) fill(v.begin(), v.begin()+(sz), 0)
template<const int MAX_V, typename flow_t, typename cost_t, flow_t FLOW_INF, cost_t COST_INF, const int SCALE = 16>
class CostScalingMCMF {
public:
	struct Edge {
		int v;
		flow_t c;
		cost_t d;
		int r; // next, residual capacity, weight, reverse edge
		Edge() = default;
		Edge(int v, flow_t c, cost_t d, int r) : v(v), c(c), d(d), r(r) {}
	};
	CostScalingMCMF() {
		negativeSelfLoop = 0;
		static_assert(numeric_limits<flow_t>::is_signed, "flow_t must be signed");
		static_assert(numeric_limits<cost_t>::is_signed, "cost_t must be signed");
		static_assert(SCALE >= 2, "scaling factor must be at least 2");
	}
	void clear() {
		negativeSelfLoop = 0;
		for(int i=0; i<MAX_V; i++) g[i].clear();
	}
	void addEdge(int s, int e, flow_t cap, cost_t dst) {
		if(s == e) {
			if(dst < 0) negativeSelfLoop += cap * dst;
			return;
		}
		g[s].emplace_back(e, cap, dst, (int)(g[e].size()));
		g[e].emplace_back(s, 0, -dst, (int)(g[s].size())-1);
	}
	flow_t getMaxFlow(int V, int S, int T) {
		auto BFS = [&]() {
			zero_stl(level, V);
			queue<int> q;
			q.push(S);
			level[S] = 1;
			while(q.size()) {
				int v = q.front();
				q.pop();
				for(const auto &e : g[v]) if(!level[e.v] && e.c) q.push(e.v), level[e.v] = level[v] + 1;
			}
			return level[T];
		};
		function<flow_t(int,flow_t)> DFS = [&](int v, flow_t fl) {
			if(v == T || fl == 0) return fl;
			for(int &i=ptr[v]; i<g[v].size(); i++) {
				Edge &e = g[v][i];
				if(level[e.v] != level[v] + 1 || !e.c) continue;
				flow_t delta = DFS(e.v, min(fl, e.c));
				if(delta) {
					e.c -= delta;
					g[e.v][e.r].c += delta;
					return delta;
				}
			}
			return flow_t(0);
		};

		flow_t maxFlow = 0, tmp = 0;
		while(BFS()) {
			zero_stl(ptr, V);
			while((tmp = DFS(S, FLOW_INF))) maxFlow += tmp;
		}
		return maxFlow;
	}
	pair<flow_t, cost_t> run(int V, int S, int T) {
		flow_t maxFlow = 0;
		cost_t minCost = 0, eps = 0;

		auto active_ins = [&](int v) {
			active_stk[active_top++] = v;
		};
		auto active_del = [&]() {
			return active_stk[--active_top];
		};
		auto c_pi = [&](int v, const Edge &e) {
			return e.d + pi[v] - pi[e.v];
		};
		auto push = [&](int v, Edge &e, flow_t delta, bool pushStack) {
			delta = min(delta, e.c);
			e.c -= delta;
			g[e.v][e.r].c += delta;
			excess[v] -= delta;
			excess[e.v] += delta;
			if(pushStack && 0 < excess[e.v] && excess[e.v] <= delta) active_ins(e.v);
		};
		auto relabel = [&](int v, cost_t delta) {
			pi[v] -= delta + eps;
		};
		auto discharge = [&](int v) {
			cost_t delta = COST_INF;
			for(auto &e : g[v]) {
				if(e.c <= 0) continue;
				cost_t reduced = c_pi(v, e);
				if(reduced < 0) {
					push(v, e, excess[v], true);
					if(excess[v] == 0) return;
				} else delta = min(delta, reduced);
			}
			relabel(v, delta);
			active_ins(v);
		};

		zero_stl(pi, V);
		zero_stl(excess, V);
		for(int v=0; v<V; v++) for(auto &e : g[v]) minCost += e.c * e.d, e.d *= V+1, eps = max(eps, abs(e.d));
		maxFlow = getMaxFlow(V, S, T);
		while(eps > 1) {
			eps /= SCALE;
			if(eps < 1) eps = 1;
			active_top = 0;
			for(int v=0; v<V; v++) for(auto &e : g[v]) if(e.c > 0 && c_pi(v, e) < 0) push(v, e, e.c, false);
			for(int v=0; v<V; v++) if(excess[v] > 0) active_ins(v);
			while(active_top > 0) discharge(active_del());
		}
		for(int v=0; v<V; v++) for(auto &e : g[v]) e.d /= V+1, minCost -= e.c * e.d;
		minCost = minCost / 2 + negativeSelfLoop;
		return {maxFlow, minCost};
	}

private:
	vector<Edge> g[MAX_V];
	cost_t negativeSelfLoop;
	array<flow_t, MAX_V> excess;
	array<cost_t, MAX_V> pi;
	array<int, MAX_V> active_stk;
	int active_top;

	array<int, MAX_V> level, ptr;
};
// 노드가 5001개 있음 
CostScalingMCMF<5001, int, int, INF, INF> flow;

/*
// 정점, 간선, start, end 
int N, M, S, T;
    cin >> N >> M >> S >> T;
    for(int i=0; i<M; i++){
    	// a->b , c유량, d 컷 비용 
        int a, b; ll c, d; cin >> a >> b >> c >> d;
        // 노드번호는 0부터 시작 
        flow.addEdge(--a, --b, c, d);
    }
    auto [fl,cst] = flow.run(N, --S, --T);
*/
