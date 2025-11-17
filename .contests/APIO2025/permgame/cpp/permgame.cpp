#include "permgame.h"
#include <vector>
#include <utility>

int Alice(int m, int e, std::vector<int> u, std::vector<int> v, int n, std::vector<int> p) {
    std::vector<int> t(m);
    for (int i = 0; i < m; i++){
        t[i] = i;
    }

    int j = Bob(t);
    std::swap(p[t[u[j]]], p[t[v[j]]]);

    return 42;
}
