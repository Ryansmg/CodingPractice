#include "hack.h"
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <map>
#include <set>

static long long n = 0;
static int total_cost = 0;

long long collisions(std::vector<long long> x){
    total_cost += (int) x.size();
    if (total_cost > 110000){
        printf("Total cost exceeded 1,000,000\n");
        exit(0);
    }
    
    long long res = 0;

    std::map<int, int> table;
    std::set<long long> seen;
    for (long long v : x){
        if (v < 1 || v > (long long)1e18){
            printf("x[i] is out of range\n");
            exit(0);
        }

        if (seen.find(v) != seen.end()){
            printf("x has a duplicate element\n");
            exit(0);
        }

        seen.insert(v);
        
        res += table[v % n];
        table[v % n]++;
    }

    return res;
}

int main(){
    int l, r, step;
    scanf("%d %d %d", &l, &r, &step);

    for (int i = l; i <= r; i += step){
        total_cost = 0;
        n = i;
        int ans = hack();
        if(ans != n) {
            printf("ans: %d, n: %d\n", ans, n);
            assert(ans == n);
        } else {
            printf("correct: %d\n", ans);
            fflush(stdout);
        }
    }

    return 0;
}
