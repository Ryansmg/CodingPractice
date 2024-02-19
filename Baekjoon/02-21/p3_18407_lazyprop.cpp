#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ui unsigned int
#define vec vector<ui>
using namespace std;

//18407. 가로 블럭 쌓기 
//#lazyprop #coordinate_compression (값/좌표 압축)

void update_lazy(vec &tree, vec &lazy, vec &set_lazy, ui node, int start, int end) {
    if(set_lazy[node] != 0) {
        lazy[node] = 0;
        tree[node] = set_lazy[node];
        if(start!=end) {
            set_lazy[node*2] = set_lazy[node*2+1] = set_lazy[node];
            lazy[node*2] = lazy[node*2+1] = 0;
        }
        set_lazy[node] = 0;
    } else {
        tree[node] += lazy[node];
        if(start!=end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node]=0;
    }
}

//left, right : 고정
void update_range(vec &tree, vec &lazy, vec &set_lazy, ui node, int start, int end, int left, int right, int diff) {
    update_lazy(tree, lazy, set_lazy, node, start, end);
    if(right < start || end < left) return;
    if(left <= start && end <= right) {
        tree[node] += diff;
        if(start != end) {
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
    } else {
        update_range(tree, lazy, set_lazy, node*2, start, (start+end)/2, left, right, diff);
        update_range(tree, lazy, set_lazy, node*2+1, (start+end)/2+1, end, left, right, diff);
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }
}

void set_range(vec &tree, vec &lazy, vec &set_lazy, ui node, int start, int end, int left, int right, int set) {
    update_lazy(tree, lazy, set_lazy, node, start, end);
    if(right < start || end < left) return;
    if(left <= start && end <= right) {
        tree[node] = set;
        if(start != end) {
            lazy[node*2] = lazy[node*2+1] = 0;
            set_lazy[node*2] = set_lazy[node*2+1] = set;
        }
    } else {
        set_range(tree, lazy, set_lazy, node*2, start, (start+end)/2, left, right, set);
        set_range(tree, lazy, set_lazy, node*2+1, (start+end)/2+1, end, left, right, set);
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }
}

int query_max(vec &tree, vec &lazy, vec &set_lazy, ui node, int start, int end, int left, int right) {
    update_lazy(tree, lazy, set_lazy, node, start, end);
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    else return max(query_max(tree, lazy, set_lazy, node*2, start, (start+end)/2, left, right),
        query_max(tree, lazy, set_lazy, node*2+1, (start+end)/2+1, end, left, right));
}

void print_tree(vector<ui> &tree, int n)
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

bool cmp(int a, int b) {
    return a<b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ui n; //블럭 개수
    cin >> n;
    queue<pair<int, int>> input;
    queue<pair<int, int>> preinput;
    vector<int> compression;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        compression.push_back(a);
        compression.push_back(b);
        preinput.emplace(a, b);
    }
    sort(compression.begin(), compression.end(), cmp);
    compression.erase(unique(compression.begin(), compression.end()), compression.end());
    for(int i=0; i<n; i++) {
        auto fr = preinput.front();
        preinput.pop();
        int a = lower_bound(compression.begin(), compression.end(), fr.first) - compression.begin() + 1;
        int b = lower_bound(compression.begin(), compression.end(), fr.second) - compression.begin() + 1;
        input.emplace(a, b);
    }
    int size = compression.size();
    vec tree(size*4, 0);
    vec lazy(size*4, 0);
    vec set_lazy(size*4, 0);
    for(int i=0; i<n; i++) {
        auto fr = input.front(); input.pop();
        int a = fr.first, b = fr.second;
        ui maxi = query_max(tree, lazy, set_lazy, 1, 1, size, b, a+b-1);
        set_range(tree, lazy, set_lazy, 1, 1, size, b, a+b-1, maxi+1);
    }
    cout << tree[1];
}
