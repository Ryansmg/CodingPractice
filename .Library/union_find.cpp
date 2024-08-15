#include <bits/stdc++.h>
using namespace std;
template <typename T> using v = vector<T>;

int findRoot(v<int> &parent, int n) {
    if(parent[n] == n) return n;
    return parent[n] = findRoot(parent, parent[n]);
}
/**
 * par[b] = par[a]
 */
bool unionRoot(v<int> &parent, int a, int b) {
    if(findRoot(parent, a) == findRoot(parent, b)) return false;
    parent[findRoot(parent,b)] = findRoot(parent, a); return true;
}
