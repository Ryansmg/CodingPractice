#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
vector<long long> tree(MAX * 4);
vector<long long> arr(MAX);

void init(int node, int start, int end) {
    if(start == end) {
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int node, int start, int end, int idx, long long diff) {
    if(idx < start || idx > end) return;
    tree[node] += diff;
    if(start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, diff);
        update(node * 2 + 1, mid + 1, end, idx, diff);
    }
}

long long query(int node, int start, int end, int left, int right) {
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) +
           query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    init(1, 0, n - 1);

    for(int i = 0; i < m + k; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;

        if(a == 1) {
            long long diff = c - arr[b - 1];
            arr[b - 1] = c;
            update(1, 0, n - 1, b - 1, diff);
        } else {
            cout << query(1, 0, n - 1, b - 1, c - 1) << '\n';
        }
    }
}
