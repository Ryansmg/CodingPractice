#include <iostream>
#include <vector>
#define ll long long
#define mid (start+end)/2
using namespace std;

vector<ll> tree;
//lazy에는 시작 index들의 합, 개수
vector<pair<ll, ll>> lazy;
vector<ll> a;

void update_lazy(int node, int start, int end) {
    if(start==end) {
        a[start-1] += lazy[node].second * (start+1) - lazy[node].first;
    } else {
        lazy[node*2].first += lazy[node].first;
        lazy[node*2].second += lazy[node].second;
        lazy[node*2+1].first += lazy[node].first;
        lazy[node*2+1].second += lazy[node].second;
    }
    lazy[node].first = 0;
    lazy[node].second = 0;
}
void print_tree(int n)
{
    int a = 1, cnt=0;
    cout << "==tree==\n";
    for(int i=1; i<4*n; i++)
    {
        cout << "(" << lazy[i].first << "," << lazy[i].second << ")";
        if(++cnt==a) {
            cout << "\n"; a*=2; cnt=0;
        }
    }
    cout << "\n========\n";
}

void update(int node, int start, int end, int cleft, int cright, int startidx) {
    update_lazy(node, start, end);
    if(end < cleft || cright < start) return;
    if(cleft <= start && end <= cright) {
        //if(start == end) tree[node] += start + 1 - startidx;
        if(start == end) a[start-1] += start + 1 - startidx;
        else {
            lazy[node*2].first += startidx;
            lazy[node*2].second++;
            lazy[node*2+1].first += startidx;
            lazy[node*2+1].second++;
        }
    } else {
        update(node*2, start, mid, cleft, cright, startidx);
        update(node*2+1, mid+1, end, cleft, cright, startidx);
        //tree[node] = tree[node*2] + tree[node*2+1];
    }
}

ll query(int node, int start, int end, int tar) {
    update_lazy(node, start, end);
    if(tar < start || end < tar) return 0;
    //if(start == tar) return tree[node];
    if(start == tar) return a[start-1];
    return query(node*2, start, mid, tar) + query(node*2+1, mid+1, end, tar);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    //vector<ll> temp(4*n, 0);
    vector<pair<ll, ll>> temp2(4*n, {0, 0});
    //tree = temp;
    lazy = temp2;
    int b;
    for(int i=0; i<n; i++) {
        cin >> b; a.push_back(b);
    }
    //init(1, 1, n, a);
    int q; cin >> q;
    int x, y, z;
    for(int i=0; i<q; i++) {
        cin >> x >> y;
        if(x == 1) {
            cin >> z;
            update(1, 1, n, y, z, y);
            print_tree(n);
            for(int asdf : a) cout << asdf << " ";
            cout << endl;
        } else {
            cout << query(1, 1, n, y) << "\n";
        }
    }
}
