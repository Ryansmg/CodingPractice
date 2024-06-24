#include <bits/stdc++.h>
#define int __int128
#define lf __float128
#define double long double
using namespace std;
vector<int> weightTree, weightLazy, sumTree, sumLazy, comp, sumW(1, 0), weightW(1, 0);
int tl;
int idx(const int &val) { return lower_bound(comp.begin(), comp.end(), val) - comp.begin(); }
int range_sum(int a, int b) { if(a>b) return 0; return (a+b)*(b-a+1)/2; }
void update_lazy_sum(int node, int start, int end) {
    if(sumLazy[node] == 0) return;
    sumTree[node] += (sumW[end] - sumW[start-1]) * sumLazy[node];
    if(start != end) sumLazy[node*2] += sumLazy[node], sumLazy[node*2+1] += sumLazy[node];
    sumLazy[node] = 0;
}
void update_range_sum(int node, int start, int end, const int &left, const int &right, int diff) {
    update_lazy_sum(node, start, end);
    if(right<start || end<left) return;
    if(left <= start && end <= right) {
        sumTree[node] += (sumW[end] - sumW[start-1]) * diff;
        if (start != end) sumLazy[node*2] += diff, sumLazy[node*2+1] += diff;
    } else {
        update_range_sum(node * 2, start, (start + end) / 2, left, right, diff);
        update_range_sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
        sumTree[node] = sumTree[node*2] + sumTree[node*2+1];
    }
}
int query_sum(int node, int start, int end, const int &left, const int &right) {
    update_lazy_sum(node, start, end);
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return sumTree[node];
    return query_sum(node * 2, start, (start + end) / 2, left, right) + query_sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
void update_lazy_weight(int node, int start, int end) {
    if(weightLazy[node] == 0) return;
    weightTree[node] += (weightW[end] - weightW[start-1]) * weightLazy[node];
    if(start != end) weightLazy[node*2] += weightLazy[node], weightLazy[node*2+1] += weightLazy[node];
    weightLazy[node] = 0;
}
void update_range_weight(int node, int start, int end, const int &left, const int &right, int diff) {
    update_lazy_weight(node, start, end);
    if(right<start || end<left) return;
    if(left <= start && end <= right) {
        weightTree[node] += (weightW[end] - weightW[start-1]) * diff;
        if (start != end) weightLazy[node*2] += diff, weightLazy[node*2+1] += diff;
    } else {
        update_range_weight(node * 2, start, (start + end) / 2, left, right, diff);
        update_range_weight(node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
        weightTree[node] = weightTree[node*2] + weightTree[node*2+1];
    }
}
int query_weight(int node, int start, int end, const int &left, const int &right) {
    update_lazy_weight(node, start, end);
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return weightTree[node];
    return query_weight(node * 2, start, (start + end) / 2, left, right) + query_weight(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
int input() { long long a; cin >> a; return (int) a; }
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.precision(8); cout << fixed;
    int l, n, m, a, b, k, t; l = input(); n = input(); m = input();
    vector<array<int, 5>> queries;
    for(int i=1; i<=n; i++) {
        a = input(); b = input(); k = input();
        queries.push_back({i, 1, a, b, k});
        comp.push_back(a); comp.push_back(b);
    }
    for(int i=1; i<=m; i++) {
        t = input(); a = input(); b = input();
        queries.push_back({t, 2, a, b, i-1});
        comp.push_back(a); comp.push_back(b);
    }
    vector<lf> answers(m);
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    tl = (int) comp.size();
    sumW.push_back(1); weightW.push_back(comp[0]);
    for(int i=1; i<tl; i++) {
        weightW.push_back(range_sum(comp[i-1]+1, comp[i]-1));
        weightW.push_back(comp[i]);
        t = comp[i] - comp[i-1] - 1;
        sumW.push_back(t); sumW.push_back(1);
    }
    tl = tl*2-1;
    for(int i=2; i<=tl; i++) {
        sumW[i] += sumW[i-1]; weightW[i] += weightW[i-1];
    }
    sumTree = sumLazy = weightTree = weightLazy = vector<int>(4*tl, 0);
    sort(queries.begin(), queries.end());
    for(auto &query : queries) {
        query[2] = idx(query[2]); query[3] = idx(query[3]);
        if(query[1] == 1) {
            update_range_sum(1, 1, tl, query[2]*2+1, query[3]*2+1, query[4]);
            update_range_weight(1, 1, tl, query[2]*2+1, query[3]*2+1, query[4]);
        } else {
            int sum = query_sum(1, 1, tl, query[2]*2+1, query[3]*2+1);
            int weight = query_weight(1, 1, tl, query[2]*2+1, query[3]*2+1);
            if(sum==0) answers[query[4]] = -1;
            else answers[query[4]] = abs(((lf)weight / ((lf) sum)) - ((lf)(comp[query[2]]+comp[query[3]])/((lf)2)));
        }
    }
    for(const lf& i : answers) cout << (double)i << '\n';
}
