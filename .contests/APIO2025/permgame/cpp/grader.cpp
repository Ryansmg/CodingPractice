#include "permgame.h"
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <random>

static int m, e, n;
static std::vector<int> u, v, p;

static int moves_taken;

int Bob(std::vector<int> t){
    moves_taken++;
    if (t.size() != m){
        printf("Invalid interaction, t is not size m\n");
        exit(0);
    }

    std::vector<int> cnt(n, 0);
    for (int i = 0; i < m; i++){
        int ind = t[i];
        if (ind < 0 || ind >= n){
            printf("Invalid interaction, t[i] out of range\n");
            exit(0);
        }

        if (cnt[ind]){
            printf("Invalid interaction, t has duplicate elements\n");
            exit(0);
        }

        cnt[ind]++;
    }

    int j = rand() % e;

    std::swap(p[t[u[j]]], p[t[v[j]]]);

    return j;
}

int main(){
    srand(time(NULL));

    scanf("%d %d", &m, &e);

    u.resize(e);
    v.resize(e);
    for (int i = 0; i < e; i++){
        scanf("%d %d", &u[i], &v[i]);
    }

    scanf("%d", &n);
    p.resize(n);
    for (int i = 0; i < n; i++){
        scanf("%d", &p[i]);
    }

    moves_taken = 0;
    int optimal_score = Alice(m, e, u, v, n, p);
    
    int actual_score = 0;
    for (int i = 0; i < n; i++){
        actual_score += (p[i] == i);
    }
    
    for (int i = 0; i < n; i++) printf("%d ", p[i]);
    printf("\n");
    
    printf("%d\n", optimal_score);
    printf("%d\n", actual_score);
    printf("%d\n", moves_taken);

    return 0;
}
