#pragma region macros
#include <bits/stdc++.h>
#define cint const int &
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define all(vec) (vec).begin(), (vec).end()
#define forn(name, val) for(int name = 0; name < val; name++)
using namespace std;
template <typename T> using v = vector<T>;
int input() { int t; cin >> t; return t;}
#pragma endregion

class pnd { // pointer_based_node
public:
    pnd *l = nullptr, *r = nullptr;
    int val = 0;
    pnd()=default;
    ~pnd(){ delete l; delete r; }
};
class dynamicSeg {
public:
    explicit dynamicSeg(int treeSize) : dynamicSeg() { n = treeSize; }
    ~dynamicSeg() { delete root; }
    void update(cint tar, cint val) {
        assert(tar>0);
        update(root, 1, n, tar, val);
    }
    int query(const int &left, const int &right) {
        assert(left <= right && left > 0);
        return query(root, 1, n, left, right);
    }
private:
    explicit dynamicSeg() { root = new pnd(); }
    pnd *root; int n = -1;
    void update(pnd *node, int start, int end, cint tar, cint val) {
        if(start==end) {
            node->val = val; return;
        }
        if(tar <= (start+end)/2) {
            if(!node->l) node->l = new pnd();
            update(node->l, start, (start+end)/2, tar, val);
        } else {
            if(!node->r) node->r = new pnd();
            update(node->r, (start+end)/2+1, end, tar, val);
        }
        int lv = node->l ? node->l->val : 0;
        int rv = node->r ? node->r->val : 0;
        node->val = lv + rv;
    }
    int query(pnd *node, int start, int end, cint left, cint right) {
        if(!node) return 0;
        if(right < start || end < left) return 0;
        if(left <= start && end <= right) return node->val;
        return query(node->l, start, (start+end)/2, left, right) +
            query(node->r, (start+end)/2+1, end, left, right);
    }
};

class lpnd {
public:
    lpnd *l = nullptr, *r = nullptr;
    int val = 0, lazy = 0;
    lpnd()=default;
    ~lpnd(){ delete l; delete r; }
};
class sparseSeg {
public:
    explicit sparseSeg(int treeSize) : sparseSeg() { n = treeSize; }
    ~sparseSeg() { delete root; }
    void update(cint left, cint right, cint val) {
        assert(left <= right && left > 0);
        update(root, 1, n, left, right, val);
    }
    int query(cint left, cint right) {
        assert(left <= right && left > 0);
        return query(root, 1, n, left, right);
    }
private:
    explicit sparseSeg() { root = new lpnd(); }
    lpnd *root; int n = -1;
    static void push(lpnd *node, cint start, cint end) {
        node->val += (end-start+1) * node->lazy;
        if(start != end) {
            if(!node->l) node->l = new lpnd();
            node->l->lazy += node->lazy;
            if(!node->r) node->r = new lpnd();
            node->r->lazy += node->lazy;
        }
        node->lazy = 0;
    }
    void update(lpnd *node, int start, int end, cint left, cint right, cint val) {
        push(node, start, end);
        if(right < start || end < left) return;
        if(left <= start && end <= right) {
            node->lazy += val;
            push(node, start, end);
            return;
        }
        int mid = (start+end)/2;
        if(node->l || left <= mid) {
            if (!node->l) node->l = new lpnd();
            update(node->l, start, mid, left, right, val);
        }
        if(node->r || mid+1 <= right) {
            if (!node->r) node->r = new lpnd();
            update(node->r, mid + 1, end, left, right, val);
        }
        int lv = node->l ? node->l->val : 0;
        int rv = node->r ? node->r->val : 0;
        node->val = lv + rv;
    }
    int query(lpnd *node, int start, int end, cint left, cint right) {
        if(!node) return 0;
        if(right < start || end < left) return 0;
        push(node, start, end);
        if(left <= start && end <= right) return node->val;
        return query(node->l, start, (start+end)/2, left, right) +
               query(node->r, (start+end)/2+1, end, left, right);
    }
};

signed main() {
    fastio;
    int q = input();
    v<array<int, 5>> queries; // 시간, 타입, i, j, k
    sparseSeg ss(1000000000);
    int onecnt = 0, twocnt=0;
    forn(qi, q) {
        int a, i, j, k;
        cin >> a >> i >> j >> k;
        if(a==1) queries.push_back({++onecnt, 1, i, j, k});
        else queries.push_back({k, 2, i, j, twocnt++});
    }
    v<int> answers(twocnt);
    sort(all(queries));
    for(auto query : queries) {
        if(query[1] == 1) {
            ss.update(query[2], query[3], query[4]);
        } else {
            answers[query[4]] = ss.query(query[2], query[3]);
        }
    }
    for(int i : answers) cout << i << '\n';
}
