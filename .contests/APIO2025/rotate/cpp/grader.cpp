#include "rotate.h"
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>

static int total_cost = 0;

static std::vector<int> v;

static FILE *file_log;

static void fprintf_vector(std::vector<int> vec){
    fprintf(file_log, "[");
    for (int i = 0; i < (int) vec.size(); i++){
        if (i > 0) fprintf(file_log, ", ");
        fprintf(file_log, "%d", vec[i]);
    }
    fprintf(file_log, "]");
}

static long long calc_energy(){
    long long res = 0;
    for (int i = 0; i < (int) v.size(); i++){
        for (int j = i + 1; j < (int) v.size(); j++){
            int d = abs(v[i] - v[j]);
            res += std::min(d, 50000 - d);
        }
    }
    return res;
}

static long long last_energy;

void rotate(std::vector<int> t, int x){
    int k = (int) t.size();
    total_cost += k;

    if (total_cost > 2000000){
        printf("Too many rotations\n");
        exit(0);
    }
    
    std::set<int> seen;
    for (int i = 0; i < k; i++){
        if (t[i] < 0 || t[i] >= (int) v.size()){
            printf("Invalid index\n");
            exit(0);
        }
        if (seen.find(t[i]) != seen.end()){
            printf("t has duplicate element\n");
            exit(0);
        }
        v[t[i]] = (v[t[i]] + x) % 50000;
        seen.insert(t[i]);
    }

    fprintf(file_log, "rotate(");
    fprintf_vector(t);
    fprintf(file_log,", %d)\n", x);

    fprintf(file_log, "v <- ");
    fprintf_vector(v);
    fprintf(file_log, "\n");

    long long cur_energy = calc_energy();
    fprintf(file_log, "New energy: %lld\n", cur_energy);
    fprintf(file_log, "\n");

    if (cur_energy < last_energy){
        printf("Energy decreased\n");
        exit(0);
    }

    last_energy = cur_energy;
}

int main(){
    int n;
    scanf("%d", &n);

    v.resize(n);
    for (int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    last_energy = calc_energy();

    file_log = fopen("log.txt", "w");
    fprintf(file_log, "Initial energy: %lld\n\n", last_energy);

    energy(n, v);

    fclose(file_log);

    printf("%lld\n", calc_energy());

    return 0;
}