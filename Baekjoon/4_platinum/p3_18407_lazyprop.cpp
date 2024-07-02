#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ui long long
#define vec vector<ui>
using namespace std;

//18407. 가로 블럭 쌓기 
//#lazyprop #coordinate_compression (값/좌표 압축)

void update_lazy(vec &tree, vec &set_lazy, ui node, int start, int end) {
    if(set_lazy[node] != -1) {
        tree[node] = set_lazy[node];
        if(start!=end) {
            set_lazy[node*2] = set_lazy[node*2+1] = set_lazy[node];
        }
        set_lazy[node] = -1;
    }
}

void set_range(vec &tree, vec &set_lazy, ui node, int start, int end, int left, int right, int set) {
    update_lazy(tree, set_lazy, node, start, end);
    if(right < start || end < left) return;
    if(left <= start && end <= right) {
        tree[node] = set;
        if(start != end) {
            set_lazy[node*2] = set_lazy[node*2+1] = set;
        }
    } else {
        set_range(tree, set_lazy, node*2, start, (start+end)/2, left, right, set);
        set_range(tree, set_lazy, node*2+1, (start+end)/2+1, end, left, right, set);
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }
}

int query_max(vec &tree, vec &set_lazy, ui node, int start, int end, int left, int right) {
    update_lazy(tree, set_lazy, node, start, end);
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    else return max(query_max(tree, set_lazy, node*2, start, (start+end)/2, left, right),
        query_max(tree, set_lazy, node*2+1, (start+end)/2+1, end, left, right));
}

bool cmp(int a, int b) { return a<b; }

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
        compression.push_back(a+b-1);
        compression.push_back(b);
        preinput.emplace(b, a+b-1);
    }

    //좌표 압축
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

    //vec == vector<long long>
    vec tree(size*4, 0);
    vec set_lazy(size*4, -1);
    for(int i=0; i<n; i++) {
        auto fr = input.front(); input.pop();
        int a = fr.first, b = fr.second;
        ui maxi = query_max(tree, set_lazy, 1, 1, size, a, b);
        set_range(tree, set_lazy, 1, 1, size, a, b, maxi+1);
    }
    cout << tree[1];
}
