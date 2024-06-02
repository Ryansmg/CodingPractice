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

// 2188. 축사 배정
// #bipartite_matching

int n, m;
v<int> acon, bcon;
v2<int> con;
v<bool> visited;

bool dfs(int a) {
	visited[a] = true;
	for(int b : con[a]) {
		if(bcon[b] == -1 || !visited[bcon[b]] && dfs(bcon[b])) {
			acon[a] = b;
			bcon[b] = a;
			return true;
		}
	}
	return false;
}

signed main() {
	fastio;
	cin >> n >> m;
	con = v2<int>(n, v<int>());
	int k;
	forn(i,n) {
		cin >> k;
		forn(j, k) con[i].push_back(input()-1);
	}
	int ans = 0;
	acon = v<int>(n, -1);
	bcon = v<int>(m, -1);
	visited.resize(n);
	forn(i, n) {
		if(acon[i] == -1) {
			fill(all(visited), false);
			if(dfs(i)) ans++;
		}
	}
	cout << ans;
}
