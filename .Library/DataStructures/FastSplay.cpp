// Update: 2025-10-25

#include <bits/stdc++.h>
using namespace std;

// 0-based index
using T = long long;

struct Node {
    T v{};
    int l = 0, r = 0, p = 0, cnt = 1;
    bool flip = false;
};

Node x[155717];
int tree = 0, nxt = 1, sz = 0;

void push(int i) {
    if(x[i].flip) {
        swap(x[i].l, x[i].r);
        if(x[i].l) x[x[i].l].flip ^= 1;
        if(x[i].r) x[x[i].r].flip ^= 1;
        x[i].flip = false;
    }

    // implement here
}

void pull(int i) {
    if(x[i].l) push(x[i].l);
    if(x[i].r) push(x[i].r);

    x[i].cnt = 1 + x[x[i].l].cnt + x[x[i].r].cnt;

    // implement here
}


void rotate(int i) {
    int p = x[i].p, b;
    if(!p) return;
    push(p); push(i);
    if(i == x[p].l) x[p].l = b = x[i].r, x[i].r = p;
    else x[p].r = b = x[i].l, x[i].l = p;
    x[i].p = x[p].p; x[p].p = i;
    if(b) x[b].p = p;
    (x[i].p ? p == x[x[i].p].l ? x[x[i].p].l : x[x[i].p].r : tree) = i;
    pull(p); pull(i);
}

void splay(int i, int g = 0) {
    while(x[i].p != g) {
        int p = x[i].p, pp = x[p].p;
        if(pp == g) { rotate(i); break; }
        rotate((i == x[p].l) == (p == x[pp].l) ? p : i);
        rotate(i);
    }
}

int insert(int pos, bool left, const T& val) {
    sz++;
    int& t = left ? x[pos].l : x[pos].r;
    t = nxt; x[nxt] = Node{val};
    x[t].p = pos; nxt++;
    splay(t); return t;
}

void erase(int p) {
    sz--;
    splay(p);
    if(x[p].l) {
        tree = x[p].l; x[tree].p = 0;
        if(x[p].r) {
            int k = tree;
            while(x[k].r) k = x[k].r;
            x[k].r = x[p].r; x[x[p].r].p = k;
            splay(k); // x[p].l = x[p].r = 0; delete p;
            return;
        }
        // x[p].l = x[p].r = 0; delete p;
        return;
    }
    if(x[p].r) {
        tree = x[p].r; x[tree].p = 0;
        // x[p].l = x[p].r = 0; delete p;
        return;
    }
    // delete p;
    tree = 0;
}

void init(const std::vector<T>& arr) {
    x[0].cnt = 0;
    auto len = arr.size();
    sz = len;
    int k = tree = nxt++;
    x[tree] = Node{arr[0]};
    for(int i = 1; i < len; i++) {
        x[k].r = nxt; x[nxt++] = Node{arr[i]};
        x[x[k].r].p = k;
        k = x[k].r;
    }
    while(k) pull(k), k = x[k].p;
}

int kth(int k) {
    int t = tree;
    push(t);
    while(true) {
        while(x[t].l && x[x[t].l].cnt > k)
            t = x[t].l, push(t);
        if(x[t].l) k -= x[x[t].l].cnt;
        if(!k--) break;
        t = x[t].r; push(t);
    }
    splay(t);
    return t;
}

int gather(int s, int e) {
    if(s == 0 && e == sz - 1) { kth(0); return tree; }
    if(s == 0) {
        int tmp = kth(0);
        kth(e + 1);
        splay(tmp, tree);
        return x[tree].l;
    }
    if(e == sz - 1) {
        int tmp = kth(sz - 1);
        kth(s - 1);
        splay(tmp, tree);
        return x[tree].r;
    }
    int tmp = kth(e + 1);
    kth(s - 1);
    splay(tmp, tree);
    return x[x[tree].r].l;
}

void flip(int l, int r) {
    x[gather(l, r)].flip = true;
}

void shift(int s, int e, int k) {
    if(k >= 0) {
        k %= e - s + 1; if(!k) return;
        flip(s, e); flip(s, s+k-1); flip(s+k, e);
    } else {
        k *= -1; k %= e - s + 1; if(!k) return;
        flip(s, e); flip(s, e-k); flip(e-k+1, e);
    }
}

int idxOf(int tar) {
    int p = tar, idx = 0;
    bool addLS = true;
    while(p) {
        if(addLS && x[p].l) idx += x[x[p].l].cnt;
        if(x[p].p && x[x[p].p].r == p) addLS = true, idx++;
        else addLS = false;
        p = x[p].p;
    }
    kth(idx);
    return idx;
}
