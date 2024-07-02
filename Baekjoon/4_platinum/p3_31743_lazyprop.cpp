#include <bits/stdc++.h>
#define int long long
using namespace std;

// 31743. Grand Escape
// #lazyprop #coordinate_compression #offline_queries #sweeping

struct pair4 {
    int a, b, c, type;
    //wall => l, r, y, 0
    //person => x, y, ind, 1
    pair4(int x, int y, int z, int w) : a(x),b(y),c(z),type(w){}
};
bool cmp(const pair4 &a, const pair4 &b) {
    int n1, n2;
    n1 = a.type ? a.b : a.c;
    n2 = b.type ? b.b : b.c;
    return n1 < n2;
}
struct segtree {
    segtree()= default;
    vector<int> tree, lazy;
    int n, size; // 리프 노드의 개수, 총 노드의 개수
    void update_lazy(int node, int start, int end) {
        tree[node] += lazy[node];
        if(start!=end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    void updatelr(int node, int left, int right, int start, int end, int diff)
    {
        update_lazy(node, start, end);
        if(end<left || right < start) return;
        if(left <= start && end <= right) {
            tree[node] += diff;
            if(start!=end) {
                lazy[node*2] += diff;
                lazy[node*2+1] += diff;
            }
            return;
        }
        updatelr(node*2, left, right, start, (start+end)/2, diff);
        updatelr(node*2+1, left, right, (start+end)/2+1, end, diff);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    int query(int node, int tar, int start, int end) {
        update_lazy(node, start, end);
        if(tar < start || end < tar) return 0;
        if(start==end) return tree[node];
        return query(node*2, tar, start, (start+end)/2) + query(node*2+1, tar, (start+end)/2+1, end);
    }
};
int comp(int tar, vector<int> &vec) {
    return lower_bound(vec.begin(), vec.end(), tar) - vec.begin();
}
void print_tree(vector<int> &tree, int n)
{
    int a = 1, cnt=0;
    cout << "==tree==\n";
    for(int i=1; i<4*n; i++)
    {
        cout << tree[i] << " ";
        if(++cnt==a) {
            cout << "\n"; a*=2; cnt=0;
        }
    }
    cout << "\n========\n";
}
signed main()
{
    int n; //벽의 수
    cin >> n;
    vector<pair4> tinputs, inputs;
    vector<int> xcomp;
    for(int i=0; i<n; i++) 
    {
        int a, b, c;
        cin >> a >> b >> c;
        tinputs.emplace_back(a, b, c, 0);
        xcomp.push_back(a);
        xcomp.push_back(b);
    }
    int m; // 사람의 수
    cin >> m;
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        tinputs.emplace_back(a, b, i, 1);
        xcomp.push_back(a);
    }
    vector<int> ans(m);
    sort(xcomp.begin(), xcomp.end());
    xcomp.erase(unique(xcomp.begin(), xcomp.end()), xcomp.end());
    for(pair4 w : tinputs) {
        if(w.type) inputs.emplace_back(comp(w.a, xcomp), w.b, w.c, 1);
        else inputs.emplace_back(comp(w.a, xcomp), comp(w.b, xcomp), w.c, 0);
    }
    tinputs.clear();
    sort(inputs.begin(), inputs.end(), cmp);
    segtree height;
    height.n = xcomp.size();
    int segsize = 4*height.n;
    vector<int> tvec(segsize, 0);
    height.tree = tvec;
    height.lazy = tvec;
    height.size = segsize;
    for(pair4 i : inputs)
    {
        //wall => l, r, y, 0
        //person => x, y, ind, 1
        if(i.type) ans[i.c] = height.query(1, i.a+1, 1, height.n) + i.b;
        else height.updatelr(1, i.a+1, i.b+1, 1, height.n, i.c);
    }
    for(int i : ans) cout << i << "\n";
}
